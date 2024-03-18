/**
 * @file main.cpp
 *
 * @mainpage DA project1
 * @section intro_sec Introduction
 * This project was made in the context of the Algorithm Design class.
 *
 * DESCRIÇÃO DO PROJETOOOOOOOOO
 *
 * This project was made by: Filipa Fidalgo (up202208039), Leonor Couto (up202205796) and Frederica Pereira (up202108167).
 */

#include <map>
#include <stack>
#include <chrono>
#include "AuxFunctions.h"

void clearMenus();

int main();
void mainMenu();
void amountWaterEachCity();
void amountWaterOneCity();
void waterNeedCheck();

bool verifyCity(string basicString);

map<string, int> m = {{"main", 0}, {"waterEach", 1}, {"waterSpecific", 2}, {"waterNeedCheck", 3}};
stack<string> menus;
bool over = false;
bool quit = false;


/**
 * @brief Clears all the menus
 *
 * Complexity: O(n)
 */
void clearMenus() {
    while (!menus.empty()) {
        menus.pop();
    }
}

/**
 * @brief Main function to initialize data and run the program.
 *
 * Complexity: ???
 *
 * @return Program exit status.
 */
int main() {
    auto start = chrono::high_resolution_clock::now();
    csvInfo::createReservoir();
    csvInfo::createStations();
    csvInfo::createCities();
    csvInfo::createPipes();

    cout << csvInfo::reservoirSet.size() << endl;
    cout << csvInfo::reservoirsVector.size() << endl;
    cout << csvInfo::stationSet.size() << endl;
    cout << csvInfo::stationsVector.size() << endl;
    cout << csvInfo::cityNameSet.size() << endl;
    cout << csvInfo::cityMap.size() << endl;
    cout << csvInfo::citiesVector.size() << endl;
    cout << csvInfo::pipesGraph.getVertexSet().size() << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> dif = end - start;
    cout << dif.count() << " seconds" << endl;

    menus.emplace("main");
    while (true) {
        string next = menus.top();
        switch (m.at(next)) {
            case 0:
                mainMenu();
                break;
            case 1:
                amountWaterEachCity();
                break;
            case 2:
                amountWaterOneCity();
                break;
            case 3:
                waterNeedCheck();
            default:
                quit = true;
        }
        if (over) {
            int op = 0;
            cout << endl;
            cout << "1 - Return to last Menu" << endl;
            cout << "2 - Return to Main Menu" << endl;
            cout << "0 - Exit." << endl;
            while (true) {
                cout << "Write the number of what you want to do: ";
                if (cin >> op) {
                    if (op == 1) break;
                    else if (op == 2) {
                        clearMenus();
                        menus.emplace("main");
                        break;
                    }
                    else if (op == 0) {
                        quit = true;
                        break;
                    }
                    else {
                        cout << "Invalid number! The number should be between 0 and 2." << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid number." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX, '\n'); // Ignore the invalid input
                }
            }
            over = false;
        }
        if (quit) break;
    }
    system("exit");
    return 0;
}

/**
 * @brief Main Menu
 *
 * Complexity: O(n)
 */

void mainMenu() {
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Maximum amount of water that can reach each city." << endl;
    cout << "2 - Maximum amount of water that can reach a specific city." << endl;
    cout << "3 - Can an existing network configuration meet the water needs of its costumer?" << endl;
    cout << "0 - Quit." << endl;
    cout << endl;
    cout << "Note: If you enter a 'q' when asked for a city," << endl;
    cout << "you will return to the main menu." << endl;
    cout << endl;

    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            switch (op) {
                case 1 :
                    menus.emplace("waterEach");
                    return;
                case 2:
                    menus.emplace("waterSpecific");
                    return;
                case 3:
                    menus.emplace("waterNeedCheck");
                    return;
                case 0:
                    menus.pop();
                    return;
                default:
                    cout << "Invalid number! The number should be between 0 and 3." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
}

/**
 * @brief Function to get the maximum amount of water that can reach a specific city.
 *
 * Complexity: ???
 *
 * @return 0 quit / 1 main menu / 2 request menu.
 */

void amountWaterOneCity() {
    string city;
    getline(cin, city);
    while (true) {
        cout << "Enter the name of the city: ";
        if (getline(cin, city)) {
            if (verifyCity(city)) {
                break;  // Input is valid, exit the loop
            }
            else if (city == "q") {
                menus.pop();
                return;
            }
            else {
                cout << "Invalid city name!" << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid city name." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }

    AuxFunctions::maxWaterPerCity.clear();
    AuxFunctions::MaxWaterCity(csvInfo::cityMap[city]);
    cout << AuxFunctions::maxWaterPerCity[0] << endl;
    csvInfo::writeToMaxWaterPerCity(AuxFunctions::maxWaterPerCity);
    over = true;
}

/**
 * @brief Function to get the maximum amount of water that can reach each city.
 *
 * Complexity: ???
 */

void amountWaterEachCity() {
    AuxFunctions::maxWaterPerCity.clear();
    for (int i = 0; i < csvInfo::cityNameSet.size(); i++) {
        AuxFunctions::MaxWaterCity(i);
    }
    csvInfo::writeToMaxWaterPerCity(AuxFunctions::maxWaterPerCity);
    for (string i : AuxFunctions::maxWaterPerCity) {
        cout << i << endl;
    }
    over = true;
}


void waterNeedCheck(){
    for (int i = 0; i < csvInfo::cityNameSet.size(); i++) {
        AuxFunctions::MaxWaterCity(i);
    }
    csvInfo::readMaxWaterPerCity();
    vector<string> final;
    stringstream  aux;

    unsigned int t = csvInfo::maxWatterPerCity.size();
    for (int i = 0; i<t;i++){
        if (csvInfo::citiesVector[i].getDemand() > stoi(csvInfo::maxWatterPerCity[i][1])) {
            aux << csvInfo::citiesVector[i].getCity() << "," << csvInfo::citiesVector[i].getCode() << "," << csvInfo::citiesVector[i].getDemand() - stoi(csvInfo::maxWatterPerCity[i][1]);
            final.push_back(aux.str());
            aux.str("");
        }
    }

    if (final.empty()) {
        cout << "An existing network configuration meet the water needs of all the delivery sites.";
    }

    for (const string& i : final) {
        cout << i << endl;
    }
}


/**
 * @brief Checks if the city exists.
 *
 * Complexity: ???
 *
 * @return
 */

bool verifyCity(string city) {
    if (csvInfo::cityNameSet.find(city) == csvInfo::cityNameSet.end()) return false;
    return true;
}

