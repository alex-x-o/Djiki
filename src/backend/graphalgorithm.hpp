#ifndef GRAPHALGORITHM_HPP
#define GRAPHALGORITHM_HPP
#include "graphstate.hpp"
#include "../graph/graph.hpp"

class GraphAlgorithm
{
public:
    GraphAlgorithm(Graph *g);

    virtual void solve() = 0;

    QString getOutcome() const;
    QVector<GraphState> getStates() const;
protected:
    void addState(Node* currentNode, unsigned currentLine);
    void addState(Node* currentNode, Edge* currentEdge, unsigned currentLine);

    Node* start;
    Node* end;
    Graph graph;
    QVector<GraphState> states;
    QString outcome;
};

#endif // GRAPHALGORITHM_HPP
