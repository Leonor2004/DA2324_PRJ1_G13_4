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

/**
 * @brief Edge, Vertex and Graph
 */

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
     * @param in : Airport object to be associated with the vertex
     * @param type : 0,1 or 2 if City, Reservoir or Station
     * @param pos : Position in the vector of its type (citiesVector, reservoirVector, stationsVector)
     */
    Vertex(string in, int type, int pos);
    bool operator<(Vertex & vertex) const;

    string getInfo() const;
    int getType() const;
    std::vector<Edge *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    Edge *getPath() const;
    std::vector<Edge *> getIncoming() const;
    int getPos();

    void setInfo(string info);
    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(Edge *path);

    /**
     * Auxiliary function to add an outgoing edge to a vertex (this),
     * with a given destination vertex (d) and edge weight (w)
     *
     * @param d : Vertex
     * @param airline_ : Airline
     * @return Edge
     */
    Edge * addEdge(Vertex *dest, double w);

    /**
     * Auxiliary function to remove an outgoing edge (with a given destination (d))
     * from a vertex (this)
     *
     * @param d : Vertex
     * @return True if successful, and false if such edge does not exist
     */
    bool removeEdge(string in);
    void removeOutgoingEdges();

protected:
    string info;                // info node
    int type;                   // 0->City; 1->Reservoir; 2->Station
    std::vector<Edge *> adj;    // outgoing edges
    int vectorPos;              // position in the vector of its type (citiesVector, reservoirVector, stationsVector)

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge *path = nullptr;

    std::vector<Edge *> incoming; // incoming edges

    void deleteEdge(Edge *edge);
};

/* ********************* Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double w);

    Vertex * getDest() const;
    double getWeight() const;
    void setWeight(double w);
    double getCapacity() const;
    bool isSelected() const;
    Vertex * getOrig() const;
    Edge *getReverse() const;
    double getFlow() const;

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
    void setFlow(double flow);


protected:
    Vertex * dest; // destination vertex
    double weight; // edge weight
    double capacity; // edge capacity, don't change

    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    double flow; // for flow-related problems
};

/* ********************* Graph  ****************************/

class Graph {
public:
    ~Graph();
    /*
    * Auxiliary function to find a vertex with a given the content.
    */
    Vertex *findVertex(const string &in) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const string &in, int t, int pos);
    bool removeVertex(const string &in);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const string &sourc, const string &dest, double w);
    bool removeEdge(const string &source, const string &dest);
    bool addBidirectionalEdge(const string &sourc, const string &dest, double w);

    int getNumVertex() const;
    std::vector<Vertex *> getVertexSet() const;


protected:
    std::vector<Vertex *> vertexSet;    // vertex set

};


#endif /* DA_TP_CLASSES_GRAPH */