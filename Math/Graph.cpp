//
// Created by Rostyslav on 05.09.2023.
//

#include "Graph.hpp"

Graph::Graph(const std::vector<Vector2>& points)
        : m_lines(sf::LinesStrip, points.size()) {
    m_window.create(sf::VideoMode(500, 500), "Graphene");
    // Initialize lines connecting points
    for (size_t i = 0; i < points.size(); ++i) {
        m_lines[i].position = {points[i].x, points[i].y};
        m_lines[i].color = sf::Color::Red;
    }
    for(int i = 0; i < points.size(); i ++){
        m_points.emplace_back(m_window, gui ,points[i].x, points[i].y);
    }
    gui.setTarget(m_window);

}

void Graph::draw() {
    m_window.clear(sf::Color::White);
    // Draw lines
    gui.draw();

    m_window.draw(m_lines);
    // Draw each point
    for (auto& point : m_points) {
        point.draw();
    }

    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    for (auto& point : m_points) {
        point.handleMouseHover(mousePos);
    }

    sf::Event event{};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        gui.handleEvent(event);
    }
    m_window.display();
}

