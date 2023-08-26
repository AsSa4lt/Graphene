#ifndef DINORUNNER_WINDOW_H
#define DINORUNNER_WINDOW_H
#include <SFML/Graphics.hpp>
#include "TGUI/TGUI.hpp"

class Window {
public:
    static int getWidth();
    static void setWidth(int _width);
    static int getHeight();
    static void setHeight(int _height);

    static sf::RenderWindow& getWindow();

    static void CreateWindow();

    static void Update();

private:
    static int height;
    static int width;
    static sf::RenderWindow window;
    static tgui::Gui gui;
};

#endif //DINORUNNER_WINDOW_H
