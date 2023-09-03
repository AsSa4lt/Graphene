// Window.cpp
#include "Window.hpp"
#include "../Math/GraphPoint.hpp"

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
    GraphPoint point = GraphPoint(window, 200, 200);  // Initialize the GraphPoint here

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
                gui.handleEvent(event);  // Let TGUI handle the event
            }
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            point.handleMouseHover(mousePos);
        }
        // Clear screen with white color
        window.clear(sf::Color::White);
        point.draw();

        // Draw your GUI
        gui.draw();

        // Display everything
        window.display();
    }
}


Window::Window() : windowUIBar(gui) {}
