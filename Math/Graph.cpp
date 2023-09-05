//
// Created by Rostyslav on 05.09.2023.
//

#include "Graph.hpp"

Graph::Graph(sf::RenderWindow& window, const std::vector<GraphPoint>& points)
        : m_window(window), m_points(points), m_lines(sf::LinesStrip, points.size()) {

    // Initialize lines connecting points
    for (size_t i = 0; i < points.size(); ++i) {
        m_lines[i].position = points[i].getPosition();
    }
}

void Graph::draw() {
    // Draw lines
    m_window.draw(m_lines);


    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    for (auto& point : m_points) {
        point.handleMouseHover(mousePos);
    }
    // Draw each point
    for (auto& point : m_points) {
        point.draw();
    }

}
