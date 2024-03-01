#include "City.h"

City::City(string ct, int i, string c, int d, int p) {
    city = ct;
    Id = i;
    code = c;
    demand = d;
    population = p;
}

string City::getCity() {
    return city;
}

int City::getId() {
    return Id;
}

string City::getCode() {
    return code;
}

int City::getDemand() {
    return demand;
}

int City::getPopulation() {
    return population;
}
