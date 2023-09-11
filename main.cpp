#include "UI/Window.hpp"
#include "UI/Bar/UIHelpers/GraphsController.hpp"
#include <SFML/Graphics.hpp>



void AddBasicGraph(){
    GraphsController& controller = GraphsController::getInstance();
    std::vector<Vector2> graphPoints = {
            Vector2({100, 100}),
            Vector2({200, 200}),
            Vector2({300, 150}),
            Vector2({400, 250})
    };
    std::vector<Vector2> graphPointShown = {
            Vector2({110, 100}),
            Vector2({200, 200}),
            Vector2({300, 150}),
            Vector2({400, 250})
    };

    GraphDisplay* g = new GraphDisplay(graphPoints, graphPointShown);
    CoordTable* t = new CoordTable();

    Graph* graph = new Graph(*g, *t, 0);

    controller.AddGraph(graph);
}

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    Window mainWindow;
    mainWindow.setWidth(desktop.width);
    mainWindow.setHeight(desktop.height);
    mainWindow.CreateWindow();
    AddBasicGraph();

    mainWindow.Update();
}


