// Window.cpp
#include "Window.h"

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

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

// ... (your other includes)

void Window::Update() {
    sf::Clock clock;  // Start a timer
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / fps);  // 60 frames per second

    while (window.isOpen()) {
        sf::Time elapsedTime = clock.restart();  // Restart the clock and return the time elapsed
        timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;

            // Process events
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                gui.handleEvent(event);
            }
        }

        // Clear screen and draw
        window.clear();
        gui.draw();
        window.display();
    }
}


Window::Window() : windowUIBar(gui) {

}
