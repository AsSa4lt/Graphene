#ifndef GRAPHENE_WINDOW_HPP
#define GRAPHENE_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include "TGUI/TGUI.hpp"
#include "Bar/UIBar.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

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
    UIBar windowUIBar;
    static const int fps = 60;
};

#endif //GRAPHENE_WINDOW_HPP
