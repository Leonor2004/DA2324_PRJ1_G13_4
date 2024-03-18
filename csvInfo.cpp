#include <map>
#include "csvInfo.h"

vector<Reservoir> csvInfo::reservoirsVector;
vector<Station> csvInfo::stationsVector;
vector<City> csvInfo::citiesVector;
Graph csvInfo::pipesGraph;
std::set<std::string> csvInfo::reservoirSet;
std::set<std::string> csvInfo::stationSet;
std::set<std::string> csvInfo::cityNameSet;
std::map<std::string, int> csvInfo::cityMap;

csvInfo::csvInfo() = default;

void csvInfo::createReservoir() {
    reservoirSet.clear();
    reservoirsVector.clear();
    fstream file;
    file.open("../Project1LargeDataSet/Reservoir.csv");
//    file.open("../Project1DataSetSmall/Reservoirs_Madeira.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }

    string line;
    string reservoir;
    string municipality;
    string id;
    string code;
    string delivery;
    getline(file, line);    // discard header line
    while(getline(file, line)) {
        stringstream s(line);
        getline(s, reservoir, ',');
        getline(s, municipality, ',');
        getline(s, id, ',');
        getline(s, code, ',');
        getline(s, delivery);

        Reservoir res = Reservoir(reservoir, municipality, stoi(id), code, stoi(delivery));
        reservoirSet.insert(code);
        reservoirsVector.push_back(res);
        int aux = reservoirsVector.size();
        Reservoir* r = &reservoirsVector[aux - 1];
        pipesGraph.addVertex(code, 1, nullptr, r, nullptr);
    }
    file.close();
}

void csvInfo::createStations() {
    stationSet.clear();
    stationsVector.clear();
    fstream file;
    file.open("../Project1LargeDataSet/Stations.csv");
//    file.open("../Project1DataSetSmall/Stations_Madeira.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }

    string line;
    string id;
    string code;
    getline(file, line);    // discard header line
    while(getline(file, line)) {
        stringstream s(line);
        getline(s, id, ',');
        getline(s, code);

        Station sta = Station(stoi(id), code);
        stationSet.insert(code);
        stationsVector.push_back(sta);
        int aux = stationsVector.size();
        Station* st = &stationsVector[aux - 1];
        pipesGraph.addVertex(code, 2, nullptr, nullptr, st);
    }
    file.close();
}

void csvInfo::createCities() {
    cityMap.clear();
    cityNameSet.clear();
    citiesVector.clear();
    fstream file;
    file.open("../Project1LargeDataSet/Cities.csv");
//    file.open("../Project1DataSetSmall/Cities_Madeira.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }

    int i = 0;
    string line;
    string city;
    string id;
    string code;
    string demand;
    string none;
    string population;
    getline(file, line);    // discard header line
    while(getline(file, line)) {
        stringstream s(line);
        getline(s, city, ',');
        getline(s, id, ',');
        getline(s, code, ',');
        getline(s, demand, ',');
        getline(s, population);

        City res = City(city, stoi(id), code, stod(demand), stoi(population));
        cityMap[city] = i;
        cityNameSet.insert(city);
        citiesVector.push_back(res);
        int aux = citiesVector.size();
        City* c = &citiesVector[aux - 1];
        pipesGraph.addVertex(code, 0, c, nullptr, nullptr);
        i++;
    }
    file.close();
}

void csvInfo::createPipes() {
    fstream file;
    file.open("../Project1LargeDataSet/Pipes.csv");
//    file.open("../Project1DataSetSmall/Pipes_Madeira.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }

    string line;
    string A;
    string B;
    string capacity;
    string direction;

    getline(file, line);    // discard header line
    while(getline(file, line)) {
        stringstream s(line);
        getline(s, A, ',');
        getline(s, B, ',');
        getline(s, capacity, ',');
        getline(s, direction);

        if (direction == "0") pipesGraph.addBidirectionalEdge(A, B, stoi(capacity));
        else pipesGraph.addEdge(A, B, stoi(capacity));
    }
    file.close();
}
