//
// Created by Rostyslav on 03.09.2023.
//

#include "GraphPoint.hpp"

GraphPoint::GraphPoint(sf::RenderWindow& window, float x, float y)
        : m_window(window),
          m_radius(10.f),
          m_hoverRadius(20.f),
          m_originalPosition(x, y) {
    m_circle.setRadius(m_radius);
    m_circle.setPosition(x - m_radius, y - m_radius); // Position should be set so the circle is centered
    m_circle.setFillColor(sf::Color::Green);

    // Load font (ensure this font file exists)
    if (!m_font.loadFromFile("../SRC/Arial.ttf")) {
        // Handle font loading error
        //std::cout << "Failed to load font from ../SRC/Arial.ttf" << std::endl;
        throw std::runtime_error("Failed to load font.");
    }
    m_coordinatesText.setFont(m_font);
    m_coordinatesText.setPosition(m_originalPosition.x, m_originalPosition.y + m_hoverRadius + 5);
    m_textBackground.setPosition(m_originalPosition.x, m_originalPosition.y + m_hoverRadius + 5);

    m_coordinatesText.setCharacterSize(15);
    m_textBackground.setFillColor(sf::Color::Cyan);
    m_coordinatesText.setFillColor(sf::Color::White);
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
            m_circle.setPosition(m_originalPosition.x - m_hoverRadius, m_originalPosition.y - m_hoverRadius); // Adjust position for larger radius
        }

        // Update the coordinate text
        std::string coordStr = "(" + std::to_string(m_originalPosition.x) + ", " + std::to_string(m_originalPosition.y) + ")";
        m_coordinatesText.setString(coordStr);

        // Update the background for the text
        m_textBackground.setSize(sf::Vector2f(m_coordinatesText.getLocalBounds().width, m_coordinatesText.getLocalBounds().height));
        m_textBackground.setPosition(m_originalPosition.x, m_originalPosition.y);

        // Position the text over the circle
        m_coordinatesText.setPosition(m_originalPosition.x, m_originalPosition.y);
    } else {
        if (m_circle.getRadius() != m_radius) {
            // Revert to original radius only if not already at original radius
            m_circle.setRadius(m_radius);
            m_circle.setPosition(m_originalPosition.x - m_radius, m_originalPosition.y - m_radius); // Adjust position back to the center
        }
    }
}


sf::Vector2f GraphPoint::getPosition() const {
    return m_originalPosition;
}
