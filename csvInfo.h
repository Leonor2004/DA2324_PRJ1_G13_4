#ifndef DA2324_PRJ1_G13_4_CSVINFO_H
#define DA2324_PRJ1_G13_4_CSVINFO_H

#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <Graph.h>

/**
 * @brief Gets the info from the csv's.
 */

class csvInfo {
private:
public:
    /**
     * @brief Default constructor
     */
    csvInfo();
    /**
     * Vector of all the reservoirs
     */
    static vector<Reservoir> reservoirsVector;
    /**
     * Vector of all the stations
     */
    static vector<Station> stationsVector;
    /**
     * Vector of all the cities
     */
    static vector<City> citiesVector;
    /**
     * Graph of all the pipes
     */
    static Graph pipesGraph;
    /**
     * Set with the code of all reservoirs
     */
    static std::set<std::string> ReservoirSet;
    /**
     * Set with the code of all stations
     */
    static std::set<std::string> StationSet;
    /**
     * Set with the code of all cities
     */
    static std::set<std::string> CitySet;
};

#endif //DA2324_PRJ1_G13_4_CSVINFO_H
