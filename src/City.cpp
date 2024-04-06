#include "City.h"

#include <utility>

City::City(string ct, int i, string c, double d, int p) {
    city = std::move(ct);
    Id = i;
    code = std::move(c);
    demand = d;
    population = p;
}

string City::getCity() {
    return city;
}

int City::getId() const {
    return Id;
}

string City::getCode() {
    return code;
}

double City::getDemand() const {
    return demand;
}

int City::getPopulation() const {
    return population;
}
