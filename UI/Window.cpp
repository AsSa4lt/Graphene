// Window.cpp
#include "Window.hpp"
#include "Math/GraphPoint.hpp"
#include "Math/Graph.hpp"
#include "Math/CoordTable.hpp"

int Window::getWidth() {
    return width;
}

void Window::setWidth(int _width) {
    width = _width;
}

int Window::getHeight() {
    return height;
}

void Window::setHeight(int _height) {
    height = _height;
}

void Window::CreateWindow()  {
    window.create(sf::VideoMode(width, height), "Graphene");
    gui.setTarget(window);

    for(const auto & button : windowUIBar.buttons){
        gui.add(button->GetGuiButton());
    }

}



sf::RenderWindow& Window::getWindow() {
    return window;
}

void Window::Update() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / fps);

    // Create a vector of GraphPoint objects
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
    Graph* g = new Graph(graphPoints, graphPointShown);
    CoordTable table;

    while (window.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                gui.handleEvent(event);
            }
        }

        // Clear screen with white color
        window.clear(sf::Color::Black);
        // Draw your GUI
        gui.draw();

        // Graph
        g->draw();
        table.run();

        // Display everything
        window.display();
    }
}



Window::Window() : windowUIBar(gui) {}
