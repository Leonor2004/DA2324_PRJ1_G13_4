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

bool verifyCity(string basicString);

map<string, int> m = {{"main", 0}, {"waterEach", 1}, {"waterSpecific", 2}};
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
    csvInfo csvInfo;
    csvInfo::createReservoir();
    csvInfo::createStations();
    csvInfo::createCities();
    csvInfo::createPipes();
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
                case 0:
                    menus.pop();
                    return;
                default:
                    cout << "Invalid number! The number should be between 0 and 2." << endl;
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
    while (true) {
        cout << "Write the city name: ";
        if (cin >> city) {
            if (verifyCity(city)) {
                break;  // Input is valid, exit the loop
            }
            else if (city == "q") {
                over = true;
                break;
            }
            else {
                cout << "Invalid city name!" << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid city name." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n');   // Ignore the invalid input
        }
    }
    AuxFunctions::maxWaterCity(city);


}

/**
 * @brief Function to get the maximum amount of water that can reach each city.
 *
 * Complexity: ???
 *
 * @return
 */

void amountWaterEachCity() {

}

/**
 * @brief Checks if the city exists.
 *
 * Complexity: ???
 *
 * @return
 */

bool verifyCity(string city) {
    if (csvInfo::citySet.find(city) == csvInfo::citySet.end()) return false;
    return true;
}
