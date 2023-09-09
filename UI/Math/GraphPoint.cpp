//
// Created by Rostyslav on 03.09.2023.
//

#include "GraphPoint.hpp"

GraphPoint::GraphPoint(sf::RenderWindow& window, tgui::Gui& gui, float x, float y, float x_show, float y_show)
        : m_window(window),
          m_gui(gui),
          m_radius(10.f),
          m_hoverRadius(20.f),
          m_originalPosition(x, y),
          m_shownPosition(x_show, y_show){

    m_circle.setRadius(m_radius);
    m_circle.setPosition(x - m_radius, y - m_radius);
    m_circle.setFillColor(sf::Color::Green);

    m_coordinatesLabel = tgui::Label::create();
    m_coordinatesLabel->setPosition(m_originalPosition.x, m_originalPosition.y + m_hoverRadius + 5);
    m_coordinatesLabel->getRenderer()->setTextColor(tgui::Color::Black);
    m_gui.add(m_coordinatesLabel);
}

void GraphPoint::setPosition(float x, float y) {
    m_circle.setPosition(x - m_radius, y - m_radius);
}

void GraphPoint::draw() {
    m_window.draw(m_circle);
}

void GraphPoint::handleMouseHover(const sf::Vector2i& mousePos) {
    sf::FloatRect bounds = m_circle.getGlobalBounds();

    if (bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        if (m_circle.getRadius() != m_hoverRadius) {
            m_circle.setRadius(m_hoverRadius);
            m_circle.setPosition(m_originalPosition.x - m_hoverRadius, m_originalPosition.y - m_hoverRadius);
        }

        // Update the coordinate text for the TGUI Label
        std::string coordStr = "(" + formatCoord(m_shownPosition.x) + ", " + formatCoord(m_shownPosition.y) + ")";
        m_coordinatesLabel->setText(coordStr);

        m_coordinatesLabel->setVisible(true);  // make visible label

    } else {
        if (m_circle.getRadius() != m_radius) {
            m_circle.setRadius(m_radius);
            m_circle.setPosition(m_originalPosition.x - m_radius, m_originalPosition.y - m_radius);
        }
        m_coordinatesLabel->setVisible(false);  // hide the label

    }
}



sf::Vector2f GraphPoint::getPosition() const {
    return m_originalPosition;
}

std::string GraphPoint::formatCoord(float value) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(8) << value;  // Convert to string with sufficient precision
    std::string str = out.str();

    // Erase trailing zeros and unnecessary decimal point
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }

    return str;}
