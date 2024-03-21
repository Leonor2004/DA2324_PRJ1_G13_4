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
#include <cmath>
#include "src/AuxFunctions.h"

void clearMenus();

int main();
void mainMenu();
void amountWaterEachCity();
void amountWaterOneCity();
void waterNeedCheck();
void simulateReservoirRemoval();
void pumpingStationRemoval();
void pipelineFailures();
void balanceNetwork();

bool verifyCity(string basicString);
bool verifyReservoir(string code);

map<string, int> m = {{"main", 0}, {"waterEach", 1}, {"waterSpecific", 2}, {"waterNeedCheck", 3}, {"balanceNetwork", 4}, {"reservoirRemoval", 5}, {"stationRemoval",6}, {"pipelineFailures", 7}};
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
 * Complexity: O(n)
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
                break;
            case 4:
                balanceNetwork();
                break;
            case 5:
                simulateReservoirRemoval();
                break;
            case 6:
                pumpingStationRemoval();
                break;
            case 7:
                pipelineFailures();
                break;
            default:
                quit = true;
        }
        if (over) {
            int op = 0;
            cout << endl;
            cout << "1 - Return to Main Menu" << endl;
            cout << "0 - Exit." << endl;
            while (true) {
                cout << "Write the number of what you want to do: ";
                if (cin >> op) {
                    if (op == 1) {
                        clearMenus();
                        menus.emplace("main");
                        break;
                    }
                    else if (op == 0) {
                        quit = true;
                        break;
                    }
                    else {
                        cout << "Invalid number! The number should be 0 or 1." << endl;
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
    cout << "1 - (T2.1) Maximum amount of water that can reach each city." << endl;
    cout << "2 - (T2.1) Maximum amount of water that can reach a specific city." << endl;
    cout << "3 - (T2.2) Can an existing network configuration meet the water needs of its costumer?" << endl;
    cout << "4 - (T2.3) Balance Network." << endl;
    cout << "5 - (T3.1) Delivery capacity of the network if one specific water reservoir is out of comission. " << endl;
    cout << "6 - (T3.2) Pumping stations removal consequences." << endl;
    cout << "7 - (T3.3) Pipeline failures consequences." << endl;
    cout << "0 - Quit." << endl;
    cout << endl;
    cout << "Note: If you enter a 'q' when asked for an input," << endl;
    cout << "you will return to the main menu." << endl;
    cout << endl;

    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            cout << endl;
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
                case 4:
                    menus.emplace("balanceNetwork");
                    return;
                case 5:
                    menus.emplace("reservoirRemoval");
                    return;
                case 6:
                    menus.emplace("stationRemoval");
                    return;
                case 7:
                    menus.emplace("pipelineFailures");
                    return;
                case 0:
                    quit = true;
                    return;
                default:
                    cout << "Invalid number! The number should be between 0 and 7." << endl;
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
 * Complexity: O(n^2)
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

    AuxFunctions::MaxFlow(true);
    cout << AuxFunctions::maxWaterPerCity[csvInfo::cityMap[city]][0] << "," << AuxFunctions::maxWaterPerCity[csvInfo::cityMap[city]][1] << "," << AuxFunctions::maxWaterPerCity[csvInfo::cityMap[city]][2] << endl;
    over = true;
}

/**
 * @brief Function to get the maximum amount of water that can reach each city.
 *
 * Complexity: O(n)
 */
void amountWaterEachCity() {
    AuxFunctions::MaxFlow(true);
    for (int i = 0; i < AuxFunctions::maxWaterPerCity.size(); i++) {
        cout << AuxFunctions::maxWaterPerCity[i][0] << "," << AuxFunctions::maxWaterPerCity[i][1] << "," << AuxFunctions::maxWaterPerCity[i][2] << endl;
    }
    over = true;
}

/**
 * @brief Checks if the water that is reaching the citys is enough for the demand of the city
 *
 * Complexity: O(n^2)
 */
void waterNeedCheck(){
    AuxFunctions::MaxFlow(false);
    vector<string> final;
    stringstream  aux;

    unsigned int t = AuxFunctions::maxWaterPerCity.size();
    for (int i = 0; i<t;i++){
        if (csvInfo::citiesVector[i].getDemand() > stoi(AuxFunctions::maxWaterPerCity[i][2])) {
            aux << csvInfo::citiesVector[i].getCity() << "," << csvInfo::citiesVector[i].getCode() << "," << csvInfo::citiesVector[i].getDemand() - stod(AuxFunctions::maxWaterPerCity[i][2]);
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
    over = true;

}

/**
 * @brief Simulate specific reservoir removal
 *
 * Complexity: O(n^2)
 */
void simulateReservoirRemoval(){
    AuxFunctions::MaxFlow(false);

    string code;
    getline(cin, code);
    while (true) {
        cout << "Enter the Reservoir Code: ";
        if (getline(cin, code)) {
            if (verifyReservoir(code)) {
                break;  // Input is valid, exit the loop
            }
            else if (code == "q") {
                menus.pop();
                return;
            }
            else {
                cout << "Invalid Reservoir code!" << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid Reservoir code." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    cout << endl;

    auto maxWaterPerCityInicial = AuxFunctions::maxWaterPerCity;
    AuxFunctions::simulateReservoirRemoval(code);
    for (auto a: AuxFunctions::maxWaterPerCity) {
        for (auto b: maxWaterPerCityInicial) {
            if (a[0] == b[0] && stoi(a[2]) < stoi(b[2])) {
                int d = stoi(b[2]) - stoi(a[2]);
                cout << a[0] << ", " << a[1] << " : -" << d << endl;
                break;
            }
        }
    }
    over = true;

}

/**
 * @brief Pumping station removal
 *
 * Complexity: O(n^3)
 */
void pumpingStationRemoval(){
    AuxFunctions::MaxFlow(false);
    auto maxWaterPerCityInicial = AuxFunctions::maxWaterPerCity;
    unsigned int t = csvInfo::stationsVector.size();
    for (int i = 0; i<t; i++){
        AuxFunctions::simulatePumpingStationRemoval(csvInfo::stationsVector[i].getCode());
        for (auto a : AuxFunctions::maxWaterPerCity){
            for(auto b : maxWaterPerCityInicial){
                if(a[0] == b[0] && stoi(a[2])< stoi(b[2])){
                    int d = stoi(b[2]) - stoi(a[2]);
                    cout << csvInfo::stationsVector[i].getCode() << " - " << a[0] << ", " << a[1] << " : -" << d << endl;
                    break;
                }
            }
        }
    }
    over = true;
}

/**
 * @brief Pipeline failures
 *
 * Complexity: O(n^4)
 */
void pipelineFailures() {
    AuxFunctions::MaxFlow(false);
    auto maxWaterPerCityInicial = AuxFunctions::maxWaterPerCity;

    for (Vertex* v : csvInfo::pipesGraph.getVertexSet()) {
        for (Edge* e : v->getAdj()) {
            bool failure = false;
            AuxFunctions::simulatePipelineFailure(e);
            cout << e->getOrig()->getInfo() << " -> " << e->getDest()->getInfo() << ": " << endl;
            for (auto a : AuxFunctions::maxWaterPerCity){
                for(auto b : maxWaterPerCityInicial){
                    if(a[0] == b[0] && stoi(a[2])< stoi(b[2])) {
                        failure = true;
                        int d = stoi(b[2]) - stoi(a[2]);
                        cout << a[0] << ": -" << d << endl;
                        break;
                    }
                }
            }
            if (!failure) cout << "   There are no consequences." << endl;
            cout << endl;
        }
    }

    over = true;
}

/**
 * @brief Balance Network
 *
 * Complexity: O(VE)
 */
void balanceNetwork() {
    AuxFunctions::MaxFlow(false);
    auto maxWaterPerCityInicial = AuxFunctions::maxWaterPerCity;

    vector<double> initial_metrics = AuxFunctions::compute_metrics();

    AuxFunctions::balanceNetwork();

    vector<double> final_metrics = AuxFunctions::compute_metrics();
    AuxFunctions::print_metrics(initial_metrics, final_metrics);
    over = true;
}

/**
 * @brief Checks if the city exists
 *
 * Complexity: O(log(n))
 *
 * @param city : City's name
 * @return True or false
 */
bool verifyCity(string city) {
    if (csvInfo::cityNameSet.find(city) == csvInfo::cityNameSet.end()) return false;
    return true;
}

/**
 * @brief Checks if the reservoir exists
 *
 * Complexity: O(log(n))
 *
 * @param code : Reservoir code
 * @return True or false
 */
bool verifyReservoir(string code) {
    if (csvInfo::reservoirSet.find(code) == csvInfo::reservoirSet.end()) return false;
    return true;
}