//
// Created by Rostyslav on 09.09.2023.
//

#include "GraphsController.hpp"



void GraphsController::Update() {
    for(int i = 0; i < graphs.size(); i++){
        if(graphs[i]->isOpened)
            graphs[i]->Update();
    }
}

void GraphsController::AddGraph(std::unique_ptr<Graph> newGraph) {
    if (newGraph) {
        newGraph->SetIndex(graphs.size() + 1);
        graphs.push_back(std::move(newGraph));
    }
}

GraphsController::GraphsController() {

}

GraphsController &GraphsController::getInstance() {
        static GraphsController instance;
        return instance;
}

