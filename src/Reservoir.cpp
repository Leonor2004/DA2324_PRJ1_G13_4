#include "Reservoir.h"
#include <utility>

Reservoir::Reservoir(string r, string m, int i, string c, int md) {
    reservoir = std::move(r);
    municipality = std::move(m);
    Id = i;
    code = std::move(c);
    maxDelivery = md;
}

string Reservoir::getReservoir() {
    return reservoir;
}

string Reservoir::getMunicipality() {
    return municipality;
}

int Reservoir::getId() {
    return Id;
}

string Reservoir::getCode() {
    return code;
}

int Reservoir::getMaxDelivery() {
    return maxDelivery;
}
