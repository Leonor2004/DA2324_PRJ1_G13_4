#include "AuxFunctions.h"
#include <cmath>

vector<string> AuxFunctions::maxWaterPerCity;

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
    stringstream  aux;
    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        for (Edge* e : v->getAdj()) {
            e->setFlow(0);
        }
    }

    for (string i : csvInfo::reservoirSet) {
        AuxFunctions::edmondsKarp(i, "super_sink");
    }

    for (int idx = 0; idx < csvInfo::citiesVector.size(); idx++) {
        Vertex* s = csvInfo::pipesGraph.findVertex(csvInfo::citiesVector[idx].getCode());
        double flow = s->getAdj()[0]->getFlow();
        aux.str("");
        aux << csvInfo::citiesVector[idx].getCity() << ",";
        aux << csvInfo::citiesVector[idx].getCode() << ",";
        aux << std::to_string(static_cast<long long>(std::round(flow)));
        maxWaterPerCity.push_back(aux.str());
    }
}

void AuxFunctions::MaxFlow() {
    csvInfo::pipesGraph.addVertex("super_sink", -1, -1);
    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        if (v->getType() == 0) {
            csvInfo::pipesGraph.addEdge(v->getInfo(), "super_sink", csvInfo::citiesVector[v->getPos()].getDemand() * 1.0);
        }
    }

    AuxFunctions::MaxWaterCity();
    csvInfo::writeToMaxWaterPerCity(maxWaterPerCity);

    csvInfo::pipesGraph.removeVertex("super_sink");
}

void AuxFunctions::simulateReservoirRemoval(Graph& graph, const std::string& reservoirCode) {
    Vertex* reservoirVertex = graph.findVertex(reservoirCode);

    for (Edge* edge : reservoirVertex->getAdj()) {
        edge->setWeight(0);
    }

    MaxFlow();
    csvInfo::readMaxWaterPerCity();

    for (Edge* edge : reservoirVertex->getAdj()) {
        edge->setWeight(edge->getCapacity());
    }
}


void AuxFunctions::simulatePumpingStationRemoval(Graph& graph,string code){
    Vertex* v = graph.findVertex(code);
    for(auto e : v->getAdj()){
        e->setWeight(0);
    }
    maxWaterPerCity.clear();
    MaxFlow();
    csvInfo::readMaxWaterPerCity();

    for(auto e : v->getAdj()){
        e->setWeight(e->getCapacity());
    }
}