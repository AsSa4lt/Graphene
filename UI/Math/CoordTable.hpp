//
// Created by Rostyslav on 09.09.2023.
//
#include <TGUI/TGUI.hpp>

#ifndef GRAPHENE_COORDTABLE_HPP
#define GRAPHENE_COORDTABLE_HPP


class CoordTable {
public:
    CoordTable();
    void run();

private:
    sf::RenderWindow m_window;
    tgui::Gui m_gui;
};


#endif //GRAPHENE_COORDTABLE_HPP
