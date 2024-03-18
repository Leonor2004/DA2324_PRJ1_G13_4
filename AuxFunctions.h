#ifndef DA2324_PRJ1_G13_4_AUXFUNCTIONS_H
#define DA2324_PRJ1_G13_4_AUXFUNCTIONS_H

#include "csvInfo.h"

class AuxFunctions {
private:
public:
    AuxFunctions();
    static void testAndVisit(std::queue<Vertex*> &q, Edge* e, Vertex* w, double residual);
    static bool findAugmentingPaths(Vertex* s, Vertex* t);
    static double findMinResidualAlongPath(Vertex* s, Vertex* t);
    static void augmentFlowAlongPath(Vertex* s, Vertex* t);
    static void edmondsKarp(string source, string target);
    static void MaxWaterCity(int idx);

};


#endif //DA2324_PRJ1_G13_4_AUXFUNCTIONS_H
