#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "Reservoir.h"
#include "Station.h"
#include "src/City.h"

using namespace std;


class Edge;

#define INF std::numeric_limits<double>::max()

/**
 * @brief Represents a Vertex in the graph.
 */
class Vertex {
public:

    /**
     * @brief Constructor for Vertex class
     *
     * Complexity: O(1)
     *
     * @param in : Information associated with the vertex
     * @param type : 0,1 or 2 if City, Reservoir or Station
     * @param pos : Position in the vector of its type (citiesVector, reservoirVector, stationsVector)
     */
    Vertex(string in, int type, int pos);

    /**
     * @brief Get info
     *
     * Complexity: O(1)
     *
     * @return Info
     */
    string getInfo() const;

    /**
     * @brief Get type
     *
     * Complexity: O(1)
     *
     * @return Type
     */
    int getType() const;

    /**
     * @brief Get vector with adjacent edges
     *
     * Complexity: O(1)
     *
     * @return Adjacent edges
     */
    std::vector<Edge *> getAdj() const;

    /**
     * @brief Check if is visited
     *
     * Complexity: O(1)
     *
     * @return True or false
     */
    bool isVisited() const;

    /**
     * @brief Get path
     *
     * Complexity: O(1)
     *
     * @return Path
     */
    Edge *getPath() const;

    /**
     * @brief Get vector with incoming edges
     *
     * Complexity: O(1)
     *
     * @return Incoming edges
     */
    std::vector<Edge *> getIncoming() const;

    /**
     * @brief Get the value of the position in the vector of its type
     *
     * Complexity:  O(1)
     *
     * @return Position
     */
    int getPos();

    /**
     * @brief Set visited
     *
     * Complexity: O(1)
     *
     * @param visited : True or false
     */
    void setVisited(bool visited);

    /**
     * @brief Set path
     *
     * Complexity: O(1)
     *
     * @param path : Edge
     */
    void setPath(Edge *path);

    /**
     * Auxiliary function to add an outgoing edge to a vertex (this), with a given destination vertex (d) and edge weight (w)
     *
     * Complexity: O(1)
     *
     * @param d : Vertex
     * @param airline_ : Airline
     * @return Edge
     */
    Edge * addEdge(Vertex *dest, double w);

    /**
     * Auxiliary function to remove an outgoing edge (with a given destination (d)) from a vertex (this)
     *
     * Complexity: O(n^2)
     *
     * @param d : Vertex
     * @return True if successful, and false if such edge does not exist
     */
    bool removeEdge(string in);

    /**
     * @brief Auxiliary function to remove outgoing edges of a vertex.
     *
     * Complexity: O(n^2)
     */
    void removeOutgoingEdges();

protected:
    string info;                    // info node
    int type;                       // 0->City; 1->Reservoir; 2->Station
    std::vector<Edge *> adj;        // outgoing edges
    std::vector<Edge *> incoming;   // incoming edges
    int vectorPos;                  // position in the vector of its type (citiesVector, reservoirVector, stationsVector)

    // auxiliary fields
    bool visited = false;
    Edge *path = nullptr;

    /**
     * @brief Constructor for Vertex class
     *
     * Complexity: O(n)
     *
     * @param edge : Edge
     */
    void deleteEdge(Edge *edge);
};

/* ********************* Edge  ****************************/
/**
 * @brief Represents a Vertex in the graph.
 */
class Edge {
public:
    /**
     * @brief Constructor for Edge class
     *
     * Complexity: O(1)
     *
     * @param orig : Origin vertex
     * @param dest : Destination vertex
     * @param w : Edge weight
     */
    Edge(Vertex *orig, Vertex *dest, double w);

    /**
     * @brief : Get destination vertex
     *
     * Complexity: O(1)
     *
     * @return Destination vertex
     */
    Vertex * getDest() const;

    /**
     * @brief : Get weight
     *
     * Complexity: O(1)
     *
     * @return Weight
     */
    double getWeight() const;

    /**
     * @brief : Set weight
     *
     * Complexity: O(1)
     *
     * @param w : Weight
     */
    void setWeight(double w);

    /**
     * @brief : Get capacity
     *
     * Complexity: O(1)
     *
     * @return Capacity
     */
    double getCapacity() const;

    /**
     * @brief : Get origin vertex
     *
     * Complexity: O(1)
     *
     * @return Origin vertex
     */
    Vertex * getOrig() const;

    /**
     * @brief : Get reverse edge
     *
     * Complexity: O(1)
     *
     * @return Reverse edge
     */
    Edge *getReverse() const;

    /**
     * @brief : Get flow
     *
     * Complexity: O(1)
     *
     * @return Flow
     */
    double getFlow() const;

    /**
     * @brief : Set reverse
     *
     * Complexity: O(1)
     *
     * @param reverse : Reverse edge
     */
    void setReverse(Edge *reverse);

    /**
     * @brief : Get flow
     *
     * Complexity: O(1)
     *
     * @param flow : Flow
     */
    void setFlow(double flow);


protected:
    Vertex * dest; // destination vertex
    double weight; // edge weight
    double capacity; // edge capacity, don't change

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    double flow; // for flow-related problems
};

/* ********************* Graph  ****************************/
/**
 * @brief Represents a Vertex in the graph.
 */
class Graph {
public:
    /**
     * @brief Graph destructor
     */
    ~Graph();

    /**
     * @brief Auxiliary function to find a vertex with a given the content.
     *
     * Complexity: O(n)
     */
    Vertex *findVertex(const string &in) const;

    /**
     *  @brief Adds a vertex with a given content or info (in) to a graph (this).
     *
     *  Complexity: O(n)
     *
     *  @return Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const string &in, int t, int pos);

    /**
     * @brief Remove vertex
     *
     * Complexity: O(n^4)
     *
     * @param in : Info
     * @return True or false
     */
    bool removeVertex(const string &in);

    /**
     * @brief Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     *
     * Complexity: O(n)
     *
     * @return: Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const string &sourc, const string &dest, double w);

    /**
     * @brief Add bidirectional edge
     *
     * Complexity: O(n)
     *
     * @param sourc : Source vertex
     * @param dest : Destination vertex
     * @param w : Weight
     * @return True or false
     */
    bool addBidirectionalEdge(const string &sourc, const string &dest, double w);

    /**
     * @brief Get vertex vector
     *
     * Complexity: O(1)
     *
     * @return vertexSet
     */
    std::vector<Vertex *> getVertexSet() const;

protected:
    std::vector<Vertex *> vertexSet;
    double ** distMatrix = nullptr;
    int **pathMatrix = nullptr;
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);


#endif /* DA_TP_CLASSES_GRAPH */