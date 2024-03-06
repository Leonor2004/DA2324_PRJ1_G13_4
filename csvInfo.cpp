#include "csvInfo.h"

vector<Reservoir> csvInfo::reservoirsVector;
vector<Station> csvInfo::stationsVector;
vector<City> csvInfo::citiesVector;
Graph csvInfo::pipesGraph;
std::set<std::string> csvInfo::reservoirSet;
std::set<std::string> csvInfo::stationSet;
std::set<std::string> csvInfo::citySet;

csvInfo::csvInfo() = default;

void csvInfo::createReservoir() {
    reservoirSet.clear();
    reservoirsVector.clear();
    fstream file;
    file.open("../Project1DataSetSmall/Reservoirs_Madeira.csv");
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
        getline(s, delivery, ',');

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
    file.open("../Project1DataSetSmall/Stations_Madeira.csv");
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
        getline(s, code, ',');
        if (id == ",") break;

        Station sta = Station(stoi(id), code);
        stationSet.insert(code);
        stationsVector.push_back(sta);
        int aux = stationsVector.size();
        Station* r = &stationsVector[aux - 1];
        pipesGraph.addVertex(code, 2, nullptr, nullptr, s);
    }
    file.close();
}

void csvInfo::createCities() {
    reservoirSet.clear();
    reservoirsVector.clear();
    fstream file;
    file.open("../Project1DataSetSmall/Cities_Madeira.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }

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
        getline(s, none, '"');
        getline(s, population, '"');

        City res = City(city, stoi(id), code, stod(demand), stoi(population));
        citySet.insert(code);
        citiesVector.push_back(res);
        int aux = citiesVector.size();
        City* c = &citiesVector[aux - 1];
        pipesGraph.addVertex(code, 0, c, nullptr, nullptr);
    }
    file.close();
}

void csvInfo::createPipes() {
    pipesGraph.clear();
    fstream file;
    file.open("../Project1DataSetSmall/Pipes_Madeira.csv");
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
        getline(s, direction, ',');

        // TODO
    }
    file.close();
}
