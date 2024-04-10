#ifndef DA2324_PRJ1_G13_4_CITY_H
#define DA2324_PRJ1_G13_4_CITY_H

#include <string>
using namespace std;

/**
 * @brief Represents a City
 */
class City {
private:
    string city;
    int Id;
    string code;
    double demand;
    int population;
public:

    /**
     * @brief Constructor of the City class
     *
     * @param ct : City´s name
     * @param i : Id
     * @param c : Code
     * @param d : Demand
     * @param p : Population
     */
    City(string ct, int i, string c, double d, int p);

    /**
     * @brief Get the name of the City
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the City's name
     */
    string getCity();

    /**
     * @brief Get the Id of the City
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the City's Id
     */
    int getId() const;

    /**
     * @brief Get the code of the City
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the City's code
     */
    string getCode();

    /**
     * @brief Get the demand of the City
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the City's demand
     */
    double getDemand() const;

    /**
     * @brief Get the population of the City
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the City's population
     */
    int getPopulation() const;
};


#endif //DA2324_PRJ1_G13_4_CITY_H
