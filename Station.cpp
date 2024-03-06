#include "Station.h"
#include <utility>

Station::Station(int i, string c) {
    Id = i;
    code = std::move(c);
}

int Station::getId() {
    return Id;
}

string Station::getCode() {
    return code;
}
