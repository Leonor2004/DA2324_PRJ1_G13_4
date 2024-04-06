#ifndef DA2324_PRJ1_G13_4_CSVINFO_H
#define DA2324_PRJ1_G13_4_CSVINFO_H

#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include "Graph.h"

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
     * Map with the name of all cities and its corresponding index
     */
    static map<std::string, int> cityMap;

    /**
     * Set with the name of all cities
     */
    static std::set<std::string> cityNameSet;

    /**
     * @brief Creates a set with the code of all reservoirs and a vector with the info of all reservoirs
     *
     * Complexity: O(n log(n))
     */
    static void createReservoir();

    /**
     * @brief Creates a set with the code of all stations and a vector with the info of all stations
     *
     * Complexity: O(n log(n))
     */
    static void createStations();

    /**
     * @brief Creates a set with the name of all cities and a vector with the info of all cities
     *
     * Complexity: O(n log(n))
     */
    static void createCities();

    /**
     * @brief Adds the pipes as edges of the graph
     *
     * Complexity: O(n)
     */
    static void createPipes();

    /**
     * @brief Write information present in the vector to file MaxWaterPerCity.csv
     *
     * Complexity: O(n)
     *
     * @param v: Vector of information
     */
    static void writeToMaxWaterPerCity(const vector<vector<string>>& v);
};

#endif //DA2324_PRJ1_G13_4_CSVINFO_H
