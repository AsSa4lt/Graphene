#include "UI/Window.hpp"
#include <SFML/Graphics.hpp>

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    Window mainWindow;
    mainWindow.setWidth(desktop.width);
    mainWindow.setHeight(desktop.height);
    mainWindow.CreateWindow();
    mainWindow.Update();
}
