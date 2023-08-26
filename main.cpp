#include "Window.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    Window::setWidth(desktop.width);
    Window::setHeight(desktop.height);
    Window::CreateWindow();

    sf::RenderWindow& window = Window::getWindow();

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}

