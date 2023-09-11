// Window.cpp
#include "Window.hpp"
#include "Math/GraphPoint.hpp"
#include "Math/GraphDisplay.hpp"
#include "Math/CoordTable.hpp"
#include "Bar/UIHelpers/GraphsController.hpp"

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

    GraphsController& controller = GraphsController::getInstance();


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

        // Display everything
        window.display();

        // GraphDisplay
        controller.Update();
    }
}



Window::Window() : windowUIBar(gui) {}
