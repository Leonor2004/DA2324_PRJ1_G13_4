#ifndef DA2324_PRJ1_G13_4_STATION_H
#define DA2324_PRJ1_G13_4_STATION_H

#include <string>
using namespace std;

/**
 * @brief Represents a Station
 */
class Station {
private:
    int Id;
    string code;
public:
    /**
     * @brief Constructor of the Station class
     *
     * @param i : Id
     * @param c : Code
     */
    Station(int i, string c);

    /**
     * @brief Get the Id of the Station
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the Station's Id
     */
    int getId();

    /**
     * @brief Get the code of the Station
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the Station's code
     */
    string getCode();
};


#endif //DA2324_PRJ1_G13_4_STATION_H
