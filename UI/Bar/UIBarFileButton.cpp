//
// Created by Rostyslav on 27.08.2023.
//

#include "UIBarFileButton.h"
#include "Helpers/FIleLoader.h"


void UIBarFileButton::actionOnClick() {
    FileLoader fileLoader(m_gui);
    fileLoader.selectOneFile(".txt");
}



UIBarFileButton::UIBarFileButton(tgui::Gui& gui) : m_gui(gui) {

}
