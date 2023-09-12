//
// Created by Rostyslav on 09.09.2023.
//

#ifndef GRAPHENE_GRAPH_H
#define GRAPHENE_GRAPH_H


#include "../../GraphUI/GraphDisplay.hpp"
#include "../../GraphUI/CoordTable.hpp"

class Graph {
private:
    unsigned short index;
    GraphDisplay& graphDisplay;
    CoordTable& coordTable;
public:
    Graph(GraphDisplay& _graphDisplay, CoordTable& _coordTable, unsigned short _index);
    std::string name;
    bool isOpened;

    void SetIndex(unsigned short _index);
    void Update();
};


#endif //GRAPHENE_GRAPH_H
