//
// Created by Rostyslav on 27.08.2023.
//

#include "UIBarButton.hpp"

tgui::Button::Ptr UIBarButton::GetGuiButton() {
    auto button = tgui::Button::create();
    button->setText(text);
    // Set position
    button->setPosition({(std::to_string((int)position.x) + "%").c_str(), (std::to_string((int)position.y) + "%").c_str()});
    // Set size
    button->setSize((std::to_string((int)size.x) + "%").c_str(), (std::to_string((int)size.y) + "%").c_str());
    // Connect the button's 'pressed' signal to a lambda function
    button->onPress([this](){
        actionOnClick();
    });
    return button;
}

const Vector2 &UIBarButton::getPosition() const {
    return position;
}

void UIBarButton::setPosition(float x, float y) {
    UIBarButton::position = {x, y};
}

const Vector2 &UIBarButton::getSize() const {
    return size;
}

void UIBarButton::setSize(float width, float height) {
    UIBarButton::size = {width, height};
}

const std::string &UIBarButton::getText() const {
    return text;
}

void UIBarButton::setText(const std::string &text) {
    UIBarButton::text = text;
}

