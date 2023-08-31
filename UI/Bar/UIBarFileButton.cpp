//
// Created by Rostyslav on 27.08.2023.
//

#include "UIBarFileButton.hpp"
#include "Helpers/FIleLoader.hpp"


void UIBarFileButton::actionOnClick() {
    FileLoader fileLoader(m_gui);
    fileLoader.selectOneFile(".txt");
}



UIBarFileButton::UIBarFileButton(tgui::Gui& gui) : m_gui(gui) {

}
