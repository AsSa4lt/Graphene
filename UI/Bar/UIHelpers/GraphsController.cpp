//
// Created by Rostyslav on 09.09.2023.
//

#include "GraphsController.hpp"

void GraphsController::Update() {
    for(int i = 0; i < graphs.size(); i++){
        if(graphs[i].isOpened)
            graphs[i].Update();
    }
}
