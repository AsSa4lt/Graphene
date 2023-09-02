//
// Created by Rostyslav on 27.08.2023.
//

#include "UIBarFileButton.hpp"
#include "Helpers/FIleLoader.hpp"


void UIBarFileButton::actionOnClick() {
    FileLoader fileLoader(m_gui);
    std::string filePath = fileLoader.selectOneFile("");  // Replace this with your actual file selection method

    // Check the file extension
    if (filePath.substr(filePath.find_last_of('.') + 1) != "gph") {

        // Create the child window
        auto childWindow = tgui::ChildWindow::create();
        childWindow->setSize({"50%", "20%"});
        childWindow->setTitle("Error");

        // Create the error label
        auto label = tgui::Label::create();
        label->setText("The selected file extension is not accepted.");
        label->setPosition({"50%", "40%"});
        label->setSize({"90%", "18%"});

        // Center the label within the child window
        label->setPosition("(&.width - width) / 2", "(&.height - height) / 2");

        // Add the label to the child window
        childWindow->add(label);

        // Add the child window to the main GUI
        m_gui.add(childWindow);
    }
}




UIBarFileButton::UIBarFileButton(tgui::Gui& gui) : m_gui(gui) {

}
