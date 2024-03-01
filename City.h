#ifndef DA2324_PRJ1_G13_4_CITY_H
#define DA2324_PRJ1_G13_4_CITY_H

#include <string>
using namespace std;

class City {
private:
    string city;
    int Id;
    string code;
    int demand;
    int population;
public:
    City(string ct, int i, string c, int d, int p);
    string getCity();
    int getId();
    string getCode();
    int getDemand();
    int getPopulation();
};


#endif //DA2324_PRJ1_G13_4_CITY_H
