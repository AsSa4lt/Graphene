//
// Created by Rostyslav on 27.08.2023.
//

#ifndef GRAPHENE_UIBARBUTTON_H
#define GRAPHENE_UIBARBUTTON_H
#include "UIBar.h"
#include "iostream"
#include "TGUI/TGUI.hpp"

class UIBarButton {
    Vector2 position = {0, 0};
    Vector2 size = {0, 0};
    std::string text = "Button";
public:
    tgui::Button GetGuiButton();

    const Vector2 &getPosition() const;

    void setPosition(int x, int y);

    const Vector2 &getSize() const;

    void setSize(int x, int y);

    const std::string &getText() const;

    void setText(const std::string &text);
};


#endif //GRAPHENE_UIBARBUTTON_H
