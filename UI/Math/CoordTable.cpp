//
// Created by Rostyslav on 09.09.2023.
//

#include "CoordTable.hpp"
CoordTable::CoordTable() {
    m_window.create(sf::VideoMode(600, 400), "Coordinates Table");
    m_gui.setTarget(m_window);
}

void CoordTable::run() {
    // Create a ListView widget for the table
    auto table = tgui::ListView::create();
    table->setSize({"80%", "70%"});
    table->setPosition({"10%", "10%"});
    table->addColumn("X", 0.5f);  // Half the width
    table->addColumn("Y", 0.5f);  // Half the width

    // Add example data
    table->addItem({"100", "200"});
    table->addItem({"300", "400"});

    // Add the table to the gui
    m_gui.add(table);

    if (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }
            m_gui.handleEvent(event);
        }

        m_window.clear();
        m_gui.draw();
        m_window.display();
    }
}