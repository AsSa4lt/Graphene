//
// Created by Rostyslav on 09.09.2023.
//

#include "Graph.h"

void Graph::Update() {
    graphDisplay.draw();
    coordTable.run();
}

void Graph::SetIndex(unsigned short _index) {
    index = _index;
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::ostringstream timeStream;
    timeStream << std::put_time(now, "%Y-%m-%d %H:%M:%S");
    name = "Graph " + std::to_string(index) + " - " + timeStream.str();
}

Graph::Graph(GraphDisplay& _graphDisplay, CoordTable& _coordTable, unsigned short _index)
        : graphDisplay(_graphDisplay), coordTable(_coordTable) {
    isOpened = true;
    SetIndex(_index);
}
