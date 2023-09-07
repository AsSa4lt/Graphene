//
// Created by Rostyslav on 05.09.2023.
//

#ifndef GRAPHENE_GRAPH_HPP
#define GRAPHENE_GRAPH_HPP

#include <vector>
#include "GraphPoint.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

class Graph {
public:
    explicit Graph(const std::vector<GraphPoint> &points);
    void draw();
    void handleMouseHover(const sf::Vector2i& mousePos);
private:
    sf::RenderWindow m_window;
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    std::vector<GraphPoint> m_points;
    sf::VertexArray m_lines;
};




#endif // GRAPHENE_GRAPH_HPP
