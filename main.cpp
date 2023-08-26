#include "UI/Window.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    Window::setWidth(desktop.width);
    Window::setHeight(desktop.height);
    Window::CreateWindow();
    Window::Update();
}

