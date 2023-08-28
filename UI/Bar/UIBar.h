// UIBar.h
#ifndef GRAPHENE_UIBAR_H
#define GRAPHENE_UIBAR_H

#include <vector>
#include "UIBarButton.h"
#include "UIBarFileButton.h"

#include "TGUI/TGUI.hpp"

class UIBar {
public:
    explicit UIBar(tgui::Gui& gui);
    std::vector<std::shared_ptr<UIBarButton>> buttons;
private:
    tgui::Gui& m_gui;
};


#endif //GRAPHENE_UIBAR_H
