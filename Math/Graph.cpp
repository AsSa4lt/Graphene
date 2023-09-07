//
// Created by Rostyslav on 05.09.2023.
//

#include "Graph.hpp"

Graph::Graph(const std::vector<GraphPoint>& points)
        :  m_points(points), m_lines(sf::LinesStrip, points.size()) {
    m_window.create(sf::VideoMode(500, 500), "Graphene");
    // Initialize lines connecting points
    for (size_t i = 0; i < points.size(); ++i) {
        m_lines[i].position = points[i].getPosition();
    }
    for (auto& point : m_points) {
        point.setWindow(m_window);
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
    sf::Event event{};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }

}
void Graph::handleMouseHover(const sf::Vector2i& mousePos) {
    for (auto& point : m_points) {
        point.handleMouseHover(mousePos);
    }
}

