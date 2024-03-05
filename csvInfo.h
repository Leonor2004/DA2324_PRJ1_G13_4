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
    static std::set<std::string> reservoirSet;
    /**
     * Set with the code of all stations
     */
    static std::set<std::string> stationSet;
    /**
     * Set with the code of all cities
     */
    static std::set<std::string> citySet;
    /**
     * @brief csvInfo::createReservoir()
     * Creates a set with the code of all reservoirs and a vector with the info of all reservoirs
     *
     * Complexity: ???
     */
    static void createReservoir();
    /**
     * @brief csvInfo::createStations()
     * Creates a set with the code of all stations and a vector with the info of all stations
     *
     * Complexity: ???
     */
    static void createStations();
    /**
     * @brief csvInfo::createCity()
     * Creates a set with the code of all cities and a vector with the info of all cities
     *
     * Complexity: ???
     */
    static void createCities();
    /**
     * @brief csvInfo::createpipes()
     * Adds the pipes as edges of the graph
     *
     * Complexity: ???
     */
    static void createPipes();
};

#endif //DA2324_PRJ1_G13_4_CSVINFO_H
