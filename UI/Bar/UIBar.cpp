//
// Created by Rostyslav on 27.08.2023.
//

#include "UIBar.h"

UIBar::UIBar() {
    std::shared_ptr<UIBarButton> fileButton = std::make_shared<UIBarFileButton>();
    fileButton->setSize(20.0f, 5.0f);
    fileButton->setText("File");
    buttons.push_back(fileButton);
}
