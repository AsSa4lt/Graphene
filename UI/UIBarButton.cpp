//
// Created by Rostyslav on 27.08.2023.
//

#include "UIBarButton.h"

tgui::Button UIBarButton::GetGuiButton() {
    return tgui::Button();
}

const Vector2 &UIBarButton::getPosition() const {
    return position;
}

void UIBarButton::setPosition(int x, int y) {
    UIBarButton::position = {x, y};
}

const Vector2 &UIBarButton::getSize() const {
    return size;
}

void UIBarButton::setSize(int width, int height) {
    UIBarButton::size = {width, height};
}

const std::string &UIBarButton::getText() const {
    return text;
}

void UIBarButton::setText(const std::string &text) {
    UIBarButton::text = text;
}
