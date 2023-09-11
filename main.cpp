#include "UI/Window.hpp"
#include "UI/Bar/UIHelpers/GraphsController.hpp"
#include <SFML/Graphics.hpp>

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    Window mainWindow;
    mainWindow.setWidth(desktop.width);
    mainWindow.setHeight(desktop.height);
    mainWindow.CreateWindow();
    mainWindow.Update();
}


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

    auto g = std::make_unique<GraphDisplay>(graphPoints, graphPointShown);
    auto t = std::make_unique<CoordTable>();

    // Use make_unique to construct the Graph
    auto graph = std::make_unique<Graph>(*g, *t, 0);

    controller.AddGraph(std::move(graph));  // Use move to transfer ownership
}
