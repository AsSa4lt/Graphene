//
// Created by Rostyslav on 03.09.2023.
//

#ifndef GRAPHENE_GRAPHPOINT_H
#define GRAPHENE_GRAPHPOINT_H

#include <SFML/Graphics.hpp>

class GraphPoint {
public:
    GraphPoint(sf::RenderWindow& window, float x, float y);

    void draw();
    void handleMouseHover(const sf::Vector2i& mousePos);

    // Setter for position
    void setPosition(float x, float y);

private:
    sf::RenderWindow& m_window;
    sf::CircleShape m_circle;
    sf::RectangleShape m_textBackground;
    sf::Text m_coordinatesText;
    sf::Font m_font;
    sf::Vector2f m_originalPosition;

    float m_radius; // Circle radius
    float m_hoverRadius; // Radius when hovered
};

#endif // GRAPHENE_GRAPHPOINT_H
