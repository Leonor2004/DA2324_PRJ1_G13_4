/**
 * @file main.cpp
 *
 * @mainpage DA project1
 * @section intro_sec Introduction
 * This project was made in the context of the Algorithm Design class.
 *
 * DESCRIÇÃO DO PROJETOOOOOOOOO
 *
 * This project was made by: Filipa Fidalgo (up202208039) and Leonor Couto (up202205796).
 */

#include "csvInfo.h"

/**
 * @brief Main function to initialize data and run the program.
 *
 * Complexity: O(1)
 *
 * @return Program exit status.
 */
int main(){
    csvInfo csvInfo;
    csvInfo::createReservoir();
    csvInfo::createStations();
    csvInfo::createCities();
    csvInfo::createPipes();
    return 0;
}