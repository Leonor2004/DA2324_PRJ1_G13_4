#include "csvInfo.h"

vector<Reservoir> csvInfo::reservoirsVector;
vector<Station> csvInfo::stationsVector;
vector<City> csvInfo::citiesVector;
Graph csvInfo::pipesGraph;
std::set<std::string> csvInfo::ReservoirSet;
std::set<std::string> csvInfo::StationSet;
std::set<std::string> csvInfo::CitySet;

csvInfo::csvInfo() = default;
