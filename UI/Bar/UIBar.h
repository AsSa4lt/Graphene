// UIBar.h
#ifndef GRAPHENE_UIBAR_H
#define GRAPHENE_UIBAR_H

#include <vector>
#include "UIBarButton.h"
#include "UIBarFileButton.h"

class UIBar {
public:
    UIBar();
    std::vector<std::shared_ptr<UIBarButton>> buttons;
};

#endif //GRAPHENE_UIBAR_H
