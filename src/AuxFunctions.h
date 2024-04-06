#ifndef DA2324_PRJ1_G13_4_AUXFUNCTIONS_H
#define DA2324_PRJ1_G13_4_AUXFUNCTIONS_H

#include "csvInfo.h"

/**
 * @brief Auxiliar Functions
 */
class AuxFunctions {
private:
public:

    /**
     * @brief Vector of vectors of max water per city
     */
    static vector<vector<string>> maxWaterPerCity;

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
    static void testAndVisit(std::queue<Vertex *> &q, Edge *e, Vertex *w, double residual);

    /**
     * @brief Find augmenting paths in a graph from a given source vertex to a target vertex
     *
     * Complexity: O(n^2)
     *
     * @param s : Source vertex
     * @param t : Target vertex
     * @return True or false
     */
    static bool findAugmentingPaths(Vertex *s, Vertex *t);

    /**
     * @brief Calculates the minimum residual capacity along a path from source vertex s to target vertex t in a graph
     *
     * Complexity: O(n)
     *
     * @param s : Source vertex
     * @param t : Target vertex
     * @return Double with the minimum residual capacity along the path
     */
    static double findMinResidualAlongPath(Vertex *s, Vertex *t);

    /**
     * @brief Augments the flow along a path from source vertex s to target vertex t in a graph by the minimum residual capacity
     *
     * Complexity: O(n)
     *
     * @param s : Source vertex
     * @param t : Target vertex
     */
    static void augmentFlowAlongPath(Vertex *s, Vertex *t);

    /**
     * @brief Edmonds Karp algorithm
     *
     * Complexity: O(n^2)
     *
     * @param source : Source vertex
     * @param target : Target vertex
     */
    static void edmondsKarp(const string& source, const string& target);

    /**
     * @brief Calculate Max Water per City
     *
     * Complexity: O(n^2)
     */
    static void MaxWaterCity();

    /**
     * @brief Calculate Max Flow
     *
     * Complexity: O(n^2)
     */
    static void MaxFlow(bool csv);

    /**
     * @brief Simulate reservoir removal
     *
     * Complexity: O(n^2)
     *
     * @param reservoirCode : Reservoir Code
     */
    static void simulateReservoirRemoval(const std::string &reservoirCode);

    /**
     * @brief Simulate pumping station removal
     *
     * Complexity: O(n^2)
     *
     * @param code : Pumping station code
     */
    static void simulatePumpingStationRemoval(const string& code);

    /**
     * @brief Simulate pipeline failure
     *
     * Complexity: O(n^2)
     *
     * @param e : Pipeline edge
     */
    static void simulatePipelineFailure(Edge *e);

    /**
     * @brief Testes if the vertex w is not visited and the flow is more that 0 and then visits the vertex and adds the edge e
     *
     * Complexity: O(1)
     *
     * @param q : Queue of vertex's
     * @param e : Edge
     * @param w : Vertex
     * @param flow : Flow
     */
    static void testAndVisit_ReservoirRemovalPart(std::queue<Vertex*> &q, Edge* e, Vertex* w, double flow);

    /**
     * @brief Find augmenting paths
     *
     * Complexity: O(n^2)
     *
     * @param s : Source vertex
     * @param t : Destination vertex
     * @param residual : Path that already has flow or not
     * @return True or false
     */
    static bool findAugmentingPaths_ReservoirRemovalPart(Vertex* s, Vertex* t, bool residual);

    /**
     * @brief Find the minimum flow starting in vertex r and ending in vertex c
     *
     * Complexity; O(n)
     *
     * @param r : Origin vertex
     * @param c : Destination vertex
     * @return Minimum flow
     */
    static double findMinflow(Vertex *r, Vertex *c);

    /**
     * @brief Remove flow
     *
     * Complexity: O(n)
     *
     * @param r : Vertex
     * @param sink : Sink vertex
     */
    static void removeFlow(Vertex* r, Vertex* sink);

    /**
     * @brief Simulate reservoir removal
     *
     * Complexity: O(n^3)
     *
     * @param code : Reservoir code
     */
    static void simulateReservoirRemovalPart(const string& code);

    /**
     * @brief Compute the metrics to calculate balance network
     *
     * Complexity: O(n^2)
     *
     * @return Metrics vector
     */
    static vector<double> compute_metrics();

     /**
      * @brief Print the metrics
      *
      * Complexity: O(1)
      *
      * @param i : Initial metrics
      * @param f : Final metrics
      */
    static void print_metrics(vector<double> i, vector<double> f);

    /**
     * @brief Find augmenting paths
     *
     * Complexity: O(n^2)
     *
     * @param s : Source vertex
     * @param t : Destination vertex
     * @param delta : Delta
     * @return True or false
     */
    static bool findAugmentingPaths_balance(Vertex* s, Vertex* t, double delta);

    /**
     * @brief Balance Network
     *
     * Complexity: O(n^3)
     */
    static void balanceNetwork();

    /**
     * @brief Compute delta
     *
     * Complexity: O(n)
     *
     * @param maxW : Max weight
     * @return Delta
     */
    static double compute_delta(double maxW);

    /**
     * @brief Find the maximum weight
     *
     * Complexity: O(n^2)
     *
     * @return Max weight
     */
    static double maxWeight();

    static void augmentFlowAlongPath_CS(Vertex* s, Vertex* t);
    };

#endif //DA2324_PRJ1_G13_4_AUXFUNCTIONS_H
