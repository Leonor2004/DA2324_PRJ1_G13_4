#ifndef DA2324_PRJ1_G13_4_AUXFUNCTIONS_H
#define DA2324_PRJ1_G13_4_AUXFUNCTIONS_H

#include "csvInfo.h"

class AuxFunctions {
private:
public:

    /**
     * @brief Vector of max water per city
     */
    static vector<string> maxWaterPerCity;

    /**
     * @brief Default constructor
     *
     * Complexity: O(1)
     */
    AuxFunctions();

    /**
     * @brief Test if vertex is visited and visit if not
     *
     * Complexity: O(1)
     *
     * @param q : Queue of vertex
     * @param e : Edge
     * @param w : Vertex
     * @param residual : Flow or the difference between the weigh and the flow of an edge
     */
    static void testAndVisit(std::queue<Vertex*> &q, Edge* e, Vertex* w, double residual);

    /**
     * @brief Find augmenting paths in a graph from a given source vertex to a target vertex
     *
     * Complexity: O(n^2)
     *
     * @param s : Source vertex
     * @param t : Target vertex
     * @return True or false
     */
    static bool findAugmentingPaths(Vertex* s, Vertex* t);

    /**
     * @brief Calculates the minimum residual capacity along a path from source vertex s to target vertex t in a graph
     *
     * Complexity: O(n)
     *
     * @param s : Source vertex
     * @param t : Target vertex
     * @return Double with the minimum residual capacity along the path
     */
    static double findMinResidualAlongPath(Vertex* s, Vertex* t);

    /**
     * @brief Augments the flow along a path from source vertex s to target vertex t in a graph by the minimum residual capacity
     *
     * Complexity: ???
     *
     * @param s : Source vertex
     * @param t : Target vertex
     */
    static void augmentFlowAlongPath(Vertex* s, Vertex* t);

    /**
     * @brief Edmonds Karp algorithm
     *
     * Complexity: O(n^2)
     *
     * @param source : Source vertex
     * @param target : Target vertex
     */
    static void edmondsKarp(string source, string target);

    /**
     * @brief ??? T2.1
     *
     * Complexity: O(n^3)
     *
     * @param idx : Id of the city
     */
    static void MaxWaterCity(int idx);

    /**
     * @brief ???
     *
     * Complexity : ???
     *
     * @param graph
     * @param reservoirCode
     */
    static void simulateReservoirRemoval(Graph& graph, const std::string& reservoirCode);


    static void simulatePumpingStationRemoval(int id);

};


#endif //DA2324_PRJ1_G13_4_AUXFUNCTIONS_H
