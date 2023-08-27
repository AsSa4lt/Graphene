// Window.cpp
#include "Window.h"
#include <TGUI/Widgets/Button.hpp>

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

void Window::CreateWindow() {
    window.create(sf::VideoMode(width, height), "Graphene");
    gui.setTarget(window);
}



sf::RenderWindow& Window::getWindow() {
    return window;
}

void Window::Update() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            gui.handleEvent(event); // Optional: pass the event to tgui
        }

        window.clear();
        gui.draw();  // Optional: draw the gui
        window.display();
    }
}
