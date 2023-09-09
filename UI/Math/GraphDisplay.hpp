//
// Created by Rostyslav on 05.09.2023.
//

#ifndef GRAPHENE_GRAPHDISPLAY_HPP
#define GRAPHENE_GRAPHDISPLAY_HPP

#include <vector>
#include "GraphPoint.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <raymath.h>

class GraphDisplay {
public:
    GraphDisplay(const std::vector<Vector2> &points, const std::vector<Vector2>& shown_positions);
    void draw();
private:
    sf::RenderWindow m_window;
    [[maybe_unused]] sf::Vector2f m_position;
    [[maybe_unused]] sf::Vector2f m_size;
    std::vector<GraphPoint> m_points;
    sf::VertexArray m_lines;
    tgui::Gui gui;
};




#endif // GRAPHENE_GRAPHDISPLAY_HPP
