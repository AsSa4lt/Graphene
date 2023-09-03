//
// Created by Rostyslav on 27.08.2023.
//

#include "UIBarFileButton.hpp"
#include "Helpers/FIleLoader.hpp"
#include "UIHelpers/ErrorWindow.hpp"


void UIBarFileButton::actionOnClick() {
    static ErrorWindow errorWindow(m_gui);  // Create the ErrorWindow once and reuse it

    FileLoader fileLoader(m_gui);
    std::string filePath = fileLoader.selectOneFile("");

    // Check the file extension
    if (filePath.substr(filePath.find_last_of('.') + 1) != "gph") {
        errorWindow.showError("The selected file extension is not accepted.");
        return;
    }


}





UIBarFileButton::UIBarFileButton(tgui::Gui& gui) : m_gui(gui) {

}
