//
// Created by Rostyslav on 30.08.2023.
//

#ifndef GRAPHENE_FILELOADER_H
#define GRAPHENE_FILELOADER_H

#include <TGUI/TGUI.hpp>

class FileLoader {
public:
    FileLoader(tgui::Gui& gui, const std::string& extension);
private:
    tgui::Gui& m_gui;
    std::string selectedFilePath;
    void populateFileList(tgui::ListBox::Ptr listBox, const std::string& extension);
};



#endif //GRAPHENE_FILELOADER_H
