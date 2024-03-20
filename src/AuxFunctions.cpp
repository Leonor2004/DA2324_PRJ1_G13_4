#include "AuxFunctions.h"
#include <cmath>

vector<vector<string>> AuxFunctions::maxWaterPerCity;
vector<vector<string>> AuxFunctions::maxWaterPerCityBalanced;

AuxFunctions::AuxFunctions() = default;

void AuxFunctions::testAndVisit(std::queue<Vertex*> &q, Edge* e, Vertex* w, double residual) {
    if (!w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

bool AuxFunctions::findAugmentingPaths(Vertex* s, Vertex* t) {
    for(Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        v->setVisited(false);
    }
    s->setVisited(true);
    std::queue<Vertex*> q;
    q.push(s);
    while(!q.empty() && !t->isVisited()) {
        auto v = q.front();
        q.pop();
        for(Edge* e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }
        for(Edge* e: v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
    return t->isVisited();
}

double AuxFunctions::findMinResidualAlongPath(Vertex* s, Vertex* t) {
    double f = INF;
    for (Vertex* v = t; v != s;) {
        Edge* e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
        }
        else {
            f = std::min(f, e->getFlow());
            v = e->getDest();
        }
    }
    return f;
}

void AuxFunctions::augmentFlowAlongPath(Vertex* s, Vertex* t) {
    double f = findMinResidualAlongPath(s, t);
    for (Vertex* v = t; v != s;) {
        Edge* e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(std::min(flow + f, e->getWeight()));
            v = e->getOrig();
        }
        else {
            e->setFlow(std::max(flow - f, 0.0));
            v = e->getDest();
        }
    }
}

void AuxFunctions::edmondsKarp(string source, string target) {
    Vertex* s = csvInfo::pipesGraph.findVertex(source);
    Vertex* t = csvInfo::pipesGraph.findVertex(target);
    while (findAugmentingPaths(s, t)) {
        augmentFlowAlongPath(s, t);
    }
}

void AuxFunctions::MaxWaterCity() {
    vector<string>  aux;
    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        for (Edge* e : v->getAdj()) {
            e->setFlow(0);
        }
    }

    AuxFunctions::edmondsKarp("super_source", "super_sink");

    for (int idx = 0; idx < csvInfo::citiesVector.size(); idx++) {
        Vertex* s = csvInfo::pipesGraph.findVertex(csvInfo::citiesVector[idx].getCode());
        double flow = s->getAdj()[0]->getFlow();
        aux.clear();
        aux.push_back(csvInfo::citiesVector[idx].getCity());
        aux.push_back(csvInfo::citiesVector[idx].getCode());
        aux.push_back(std::to_string(static_cast<long long>(std::round(flow))));
        maxWaterPerCity.push_back(aux);
    }
}

void AuxFunctions::MaxFlow(bool csv) {
    maxWaterPerCity.clear();

    // add super sink
    csvInfo::pipesGraph.addVertex("super_sink", -1, -1);
    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        if (v->getType() == 0) {
            csvInfo::pipesGraph.addEdge(v->getInfo(), "super_sink", csvInfo::citiesVector[v->getPos()].getDemand() * 1.0);
        }
    }

    // add super source
    csvInfo::pipesGraph.addVertex("super_source", -1, -1);
    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        if (v->getType() == 1) {
            csvInfo::pipesGraph.addEdge("super_source", v->getInfo(), csvInfo::reservoirsVector[v->getPos()].getMaxDelivery() * 1.0);
        }
    }

    AuxFunctions::MaxWaterCity();
    if (csv) csvInfo::writeToMaxWaterPerCity(maxWaterPerCity);

    csvInfo::pipesGraph.removeVertex("super_sink");
    csvInfo::pipesGraph.removeVertex("super_source");
}

void AuxFunctions::simulateReservoirRemoval(const std::string& reservoirCode) {
    Vertex* reservoirVertex = csvInfo::pipesGraph.findVertex(reservoirCode);

    for (Edge* edge : reservoirVertex->getAdj()) {
        edge->setWeight(0);
    }

    MaxFlow(false);

    for (Edge* edge : reservoirVertex->getAdj()) {
        edge->setWeight(edge->getCapacity());
    }
}

void AuxFunctions::simulatePumpingStationRemoval(string code){
    Vertex* v = csvInfo::pipesGraph.findVertex(code);
    for(auto e : v->getAdj()){
            e->setWeight(0);
    }

    MaxFlow(false);

    for(auto e : v->getAdj()){
          e->setWeight(e->getCapacity());
    }
}

void AuxFunctions::simulatePipelineFailure(Edge* e){
    e->setWeight(0);

    MaxFlow(false);

    e->setWeight(e->getCapacity());
}

vector<double> AuxFunctions::compute_metrics() {
    double num = 0.0;
    double sum = 0.0;
    double max = 0.0;
    double aux = 0.0;
    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        for (Edge* e : v->getAdj()) {
            aux = e->getWeight() - e->getFlow();
            sum += aux;
            num++;
            if (aux > max) max = aux;
        }
    }

    double avg = sum * 1.0 / num;
    double var_diff = 0;
    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        for (Edge* e : v->getAdj()) {
            var_diff += pow(e->getWeight() - e->getFlow() - avg, 2);
        }
    }
    var_diff /= num;

    vector<double> metrics;
    metrics = {avg, var_diff, max};
    return metrics;
}

void AuxFunctions::print_metrics(vector<double> i, vector<double> f) {
    cout << "          initial >> final" << endl;
    cout << "average:  " << i[0] << " >> " << f[0] << endl;
    cout << "variance: " << i[1] << " >> " << f[1] << endl;
    cout << "max diff: " << i[2] << " >> " << f[2] << endl;
}

void AuxFunctions::balanceNetwork() {
    maxWaterPerCity.clear();

    // add super sink
    csvInfo::pipesGraph.addVertex("super_sink", -1, -1);
    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        if (v->getType() == 0) {
            csvInfo::pipesGraph.addEdge(v->getInfo(), "super_sink", csvInfo::citiesVector[v->getPos()].getDemand() * 1.0);
        }
    }

    // add super source
    csvInfo::pipesGraph.addVertex("super_source", -1, -1);
    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        if (v->getType() == 1) {
            csvInfo::pipesGraph.addEdge("super_source", v->getInfo(), csvInfo::reservoirsVector[v->getPos()].getMaxDelivery() * 1.0);
        }
    }

    MaxWaterCity();

    //TODO


    csvInfo::pipesGraph.removeVertex("super_sink");
    csvInfo::pipesGraph.removeVertex("super_source");
}