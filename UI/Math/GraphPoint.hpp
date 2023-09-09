//
// Created by Rostyslav on 03.09.2023.
//

#ifndef GRAPHENE_GRAPHPOINT_H
#define GRAPHENE_GRAPHPOINT_H

#include <SFML/Graphics.hpp>
#include "exception"
#include "iostream"

#include <TGUI/TGUI.hpp>

class GraphPoint {
public:
    GraphPoint(sf::RenderWindow& window, tgui::Gui& gui, float x, float y, float x_show, float y_show);

    void draw();
    void handleMouseHover(const sf::Vector2i& mousePos);

    // Setter for position
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

private:
    sf::RenderWindow& m_window;
    tgui::Gui& m_gui; // We'll pass gui reference from GraphDisplay to GraphPoint
    sf::CircleShape m_circle;
    tgui::Label::Ptr m_coordinatesLabel; // This replaces sf::Text

    sf::Vector2f m_originalPosition;
    sf::Vector2f m_shownPosition;

    float m_radius; // Circle radius
    float m_hoverRadius; // Radius when hovered
    std::string formatCoord(float value);
};

#endif // GRAPHENE_GRAPHPOINT_H
