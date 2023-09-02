//
// Created by Rostyslav on 02.09.2023.
//

#ifndef GRAPHENE_ERRORWINDOW_H
#define GRAPHENE_ERRORWINDOW_H

#include <TGUI/TGUI.hpp>

class ErrorWindow {
public:
    ErrorWindow(tgui::Gui& gui);
    void showError(const std::string& message);
private:
    tgui::Gui& m_gui;
    tgui::ChildWindow::Ptr m_errorWindow; // smart pointer to the ChildWindow
    tgui::Label::Ptr m_errorLabel;  // smart pointer to the Label
};


#endif //GRAPHENE_ERRORWINDOW_H
