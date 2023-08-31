//
// Created by Rostyslav on 27.08.2023.
//

#include "UIBar.hpp"

UIBar::UIBar(tgui::Gui& gui) : m_gui(gui) {
    std::shared_ptr<UIBarButton> fileButton = std::make_shared<UIBarFileButton>(gui);
    fileButton->setSize(10.0f, 5.0f);
    fileButton->setText("File");
    buttons.push_back(fileButton);
    // Now you can add buttons to the gui, if you like, using m_gui.
}