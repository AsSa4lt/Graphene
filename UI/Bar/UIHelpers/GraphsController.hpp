//
// Created by Rostyslav on 09.09.2023.
//
#include "iostream"
#include "Graph.h"

#ifndef GRAPHENE_GRAPHSCONTROLLER_HPP
#define GRAPHENE_GRAPHSCONTROLLER_HPP

// usage
// GraphsController& controller = GraphsController::getInstance();
// i am stupid a bit, sorry
class GraphsController {
private:
    GraphsController();
public:
    static GraphsController& getInstance();
    std::vector<Graph*> graphs;  // Use raw pointers
    void Update();
    void AddGraph(Graph* newGraph);  // Take raw pointer
    GraphsController(GraphsController const&) = delete;
    void operator=(GraphsController const&) = delete;
};



#endif //GRAPHENE_GRAPHSCONTROLLER_HPP
