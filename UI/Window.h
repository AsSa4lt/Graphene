#ifndef GRAPHENE_WINDOW_H
#define GRAPHENE_WINDOW_H

#include <SFML/Graphics.hpp>
#include "TGUI/TGUI.hpp"
#include "Bar/UIBar.h"

class Window {
public:
    Window();
    int getWidth();
    void setWidth(int _width);
    int getHeight();
    void setHeight(int _height);

    sf::RenderWindow& getWindow();

    void CreateWindow();
    void Update();

private:
    int height = 0;
    int width = 0;
    sf::RenderWindow window;
    tgui::Gui gui;
    UIBar windowUIBar;  // This line will be modified
};

#endif //GRAPHENE_WINDOW_H
