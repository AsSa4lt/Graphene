//
// Created by Rostyslav on 03.09.2023.
//

#include "GraphPoint.hpp"

GraphPoint::GraphPoint(sf::RenderWindow& window, float x, float y) : m_window(window), m_radius(10.f), m_hoverRadius(20.f) {
    m_circle.setRadius(m_radius);
    m_circle.setPosition(x - m_radius, y - m_radius); // Position should be set so the circle is centered
    m_circle.setFillColor(sf::Color::Red);

    // Load font (ensure this font file exists)
    if (!m_font.loadFromFile("../SRC/Arial.ttf")) {
        // Handle font loading error
    }

    m_coordinatesText.setFont(m_font);
    m_coordinatesText.setCharacterSize(12);
    m_coordinatesText.setFillColor(sf::Color::Black);

    m_textBackground.setFillColor(sf::Color::White);
    m_originalPosition = sf::Vector2f(x, y);  // Set the original position

}

void GraphPoint::setPosition(float x, float y) {
    m_circle.setPosition(x - m_radius, y - m_radius);
}

void GraphPoint::draw() {
    m_window.draw(m_circle);

    if (m_circle.getRadius() == m_hoverRadius) { // Draw text only when hovered
        m_window.draw(m_textBackground);
        m_window.draw(m_coordinatesText);
    }
}

void GraphPoint::handleMouseHover(const sf::Vector2i& mousePos) {
    sf::FloatRect bounds = m_circle.getGlobalBounds();

    if (bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        if (m_circle.getRadius() != m_hoverRadius) {
            // Update to hover radius only if not already at hover radius
            m_circle.setRadius(m_hoverRadius);
            m_circle.setPosition(m_originalPosition.x - (m_hoverRadius - m_radius), m_originalPosition.y - (m_hoverRadius - m_radius)); // Adjust position for larger radius
        }

        // Update the coordinate text
        //std::string coordStr = "(" + std::to_string(m_circle.getPosition().x + m_hoverRadius) + ", " + std::to_string(m_circle.getPosition().y + m_hoverRadius) + ")";
        std::string coordStr = "(" + std::to_string(m_circle.getPosition().x + m_hoverRadius/2) + ", " + std::to_string(m_circle.getPosition().y + m_hoverRadius/2) + ")";

        m_coordinatesText.setString(coordStr);

        // Update the background for the text
        m_textBackground.setSize(sf::Vector2f(m_coordinatesText.getLocalBounds().width, m_coordinatesText.getLocalBounds().height));
        m_textBackground.setPosition(m_circle.getPosition().x + m_hoverRadius, m_circle.getPosition().y + m_hoverRadius);

        // Position the text over the circle
        m_coordinatesText.setPosition(m_circle.getPosition().x + m_hoverRadius, m_circle.getPosition().y + m_hoverRadius);
    } else {
        if (m_circle.getRadius() != m_radius) {
            // Revert to original radius only if not already at original radius
            m_circle.setRadius(m_radius);
            m_circle.setPosition(m_originalPosition); // Revert to original position
        }
    }
}
