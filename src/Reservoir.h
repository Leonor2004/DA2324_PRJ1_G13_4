#ifndef DA2324_PRJ1_G13_4_RESERVOIR_H
#define DA2324_PRJ1_G13_4_RESERVOIR_H

#include <string>
using namespace std;

/**
 * @brief Represents a Reservoir
 */
class Reservoir {
private:
    string reservoir;
    string municipality;
    int Id;
    string code;
    int maxDelivery;
public:
    /**
     * @brief Constructor of the Station class
     *
     * @param r : Reservoir's name
     * @param m : Municipality
     * @param i : Id
     * @param c : Code
     * @param md : Maximum delivery
     */
    Reservoir(string r, string m, int i, string c, int md);

    /**
     * @brief Get the name of the Reservoir
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the Reservoir's Name
     */
    string getReservoir();

    /**
     * @brief Get the municipality of the Reservoir
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the Reservoir's municipality
     */
    string getMunicipality();

    /**
     * @brief Get the Id of the Reservoir
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the Reservoir's Id
     */
    int getId() const;

    /**
     * @brief Get the code of the Reservoir
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the Reservoir's code
     */
    string getCode();

    /**
     * @brief Get the max delivery of the Reservoir
     *
     * Complexity : O(1)
     *
     * @return Returns the value of the max delivery of the Reservoir
     */
    int getMaxDelivery() const;
};


#endif //DA2324_PRJ1_G13_4_RESERVOIR_H
