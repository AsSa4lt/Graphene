//
// Created by Rostyslav on 27.08.2023.
//

#ifndef GRAPHENE_UIBARBUTTON_H
#define GRAPHENE_UIBARBUTTON_H

#include <raymath.h>
#include "iostream"
#include "TGUI/TGUI.hpp"

class UIBarButton {
    Vector2 position = {0, 0};
    Vector2 size = {0, 0};
    std::string text = "Button";
    tgui::Gui gui;
public:
    virtual ~UIBarButton() = default;  // Virtual destructor

    tgui::Button::Ptr GetGuiButton();

    [[nodiscard]] const Vector2 &getPosition() const;

    void setPosition(float x, float y);

    [[nodiscard]] const Vector2 &getSize() const;

    [[nodiscard]] const std::string &getText() const;

    void setText(const std::string &text);

    virtual void actionOnClick() = 0;

    void setSize(float x, float y);
};


#endif //GRAPHENE_UIBARBUTTON_H
