#ifndef DA2324_PRJ1_G13_4_STATION_H
#define DA2324_PRJ1_G13_4_STATION_H

#include <string>
using namespace std;

class Station {
private:
    int Id;
    string code;
public:
    Station(int i, string c);
    int getId();
    string getCode();
};


#endif //DA2324_PRJ1_G13_4_STATION_H
