#include "Station.h"
#include <utility>

Station::Station(int i, string c) {
    Id = i;
    code = std::move(c);
}

int Station::getId() const {
    return Id;
}

string Station::getCode() {
    return code;
}
