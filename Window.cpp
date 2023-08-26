#include "Window.h"

int Window::height = 0;
int Window::width = 0;
sf::RenderWindow Window::window;

int Window::getWidth() {
    return width;
}

void Window::setWidth(int _width) {
    Window::width = _width;
}

int Window::getHeight() {
    return height;
}

void Window::setHeight(int _height) {
    Window::height = _height;
}

void Window::CreateWindow() {
    window.create(sf::VideoMode(Window::getWidth(), Window::getHeight()), "DinoRunner");
}

sf::RenderWindow& Window::getWindow() {
    return window;
}
