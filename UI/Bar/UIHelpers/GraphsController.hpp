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
    std::vector<std::unique_ptr<Graph>> graphs;
    void Update();
    void AddGraph(std::unique_ptr<Graph> newGraph);
    GraphsController(GraphsController const&) = delete;
    void operator=(GraphsController const&) = delete;
};


#endif //GRAPHENE_GRAPHSCONTROLLER_HPP
