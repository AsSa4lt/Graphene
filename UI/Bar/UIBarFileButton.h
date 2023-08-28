//
// Created by Rostyslav on 27.08.2023.
//

#ifndef GRAPHENE_UIBARFILEBUTTON_H
#define GRAPHENE_UIBARFILEBUTTON_H


#include "UIBar.h"

class UIBarFileButton : public UIBarButton {
public:
    void actionOnClick() override;
    UIBarFileButton(tgui::Gui& gui);
private:
    tgui::Gui& m_gui;
};


#endif //GRAPHENE_UIBARFILEBUTTON_H
