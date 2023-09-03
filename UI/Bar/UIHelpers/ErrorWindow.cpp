//
// Created by Rostyslav on 02.09.2023.
//

#include "ErrorWindow.hpp"

ErrorWindow::ErrorWindow(tgui::Gui& gui) : m_gui(gui) {
    // Create the error window but don't show it yet
    m_errorWindow = tgui::ChildWindow::create();

    // Set the size to be 30% of the parent width and 15% of the parent height
    m_errorWindow->setSize({"30%", "15%"});

    // Set the position to be centered within the parent window
    m_errorWindow->setPosition("(&.width - width) / 2", "(&.height - height) / 2");
    m_errorWindow->setTitle("Error");

    // Add an image (picture) to the left of the window
    m_errorImage = tgui::Picture::create("../SRC/error.png");
    m_errorImage->setSize({"15%", "60%"});
    m_errorImage->setPosition({"5%", "20%"});


    m_errorWindow->add(m_errorImage);

    // Create and add the error label
    m_errorLabel = tgui::Label::create();
    //m_errorLabel->setTextSize(24);

    // Make text bold
    m_errorLabel->setAutoSize(true);

    // Center the label within the child window, to the right of the image
    m_errorLabel->setPosition("20% + 5%", "(&.height - height) / 2");
    m_errorLabel->setSize({"70%", "18%"});

    // Add the label to the child window
    m_errorWindow->add(m_errorLabel);
}


void ErrorWindow::showError(const std::string& message) {
    // Update the label's text
    m_errorLabel->setText(message);

    // Add the child window to the main GUI
    m_gui.add(m_errorWindow);
}
