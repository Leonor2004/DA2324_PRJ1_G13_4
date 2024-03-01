#ifndef DA2324_PRJ1_G13_4_CSVINFO_H
#define DA2324_PRJ1_G13_4_CSVINFO_H

#include <fstream>
#include <sstream>
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
};

#endif //DA2324_PRJ1_G13_4_CSVINFO_H
