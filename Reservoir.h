#ifndef DA2324_PRJ1_G13_4_RESERVOIR_H
#define DA2324_PRJ1_G13_4_RESERVOIR_H

#include <string>
using namespace std;

class Reservoir {
private:
    string reservoir;
    string municipality;
    int Id;
    string code;
    int maxDelivery;
public:
    Reservoir(string r, string m, int i, string c, int md);
    string getReservoir();
    string getMunicipality();
    int getId();
    string getCode();
    int getMaxDelivery();
};


#endif //DA2324_PRJ1_G13_4_RESERVOIR_H
