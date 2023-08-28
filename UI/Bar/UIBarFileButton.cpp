//
// Created by Rostyslav on 27.08.2023.
//

#include "UIBarFileButton.h"


void UIBarFileButton::actionOnClick() {
}



UIBarFileButton::UIBarFileButton(tgui::Gui& gui) : m_gui(gui) {
    // Create a simple button and add it to the GUI
    auto button = tgui::Button::create("Test Button");
    button->setPosition(10, 10);
    button->setSize(500,500);
    button->onPress([this]{
        std::cout << "Button pressed" << std::endl;
    });
    m_gui.add(button);
}
