// UIBar.h
#ifndef GRAPHENE_UIBAR_HPP
#define GRAPHENE_UIBAR_HPP

#include <vector>
#include "UIBarButton.hpp"
#include "UIBarFileButton.hpp"

#include "TGUI/TGUI.hpp"

class UIBar {
public:
    explicit UIBar(tgui::Gui& gui);
    std::vector<std::shared_ptr<UIBarButton>> buttons;
private:
    tgui::Gui& m_gui;
};


#endif //GRAPHENE_UIBAR_HPP
