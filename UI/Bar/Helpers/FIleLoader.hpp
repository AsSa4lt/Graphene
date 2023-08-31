//
// Created by Rostyslav on 30.08.2023.
//
#ifndef GRAPHENE_FILELOADER_HPP
#define GRAPHENE_FILELOADER_HPP

#include <TGUI/TGUI.hpp>
#include <vector>
#include <string>

class FileLoader {
public:
    FileLoader(tgui::Gui& gui);

    std::string selectOneFile(const std::string& extension);
    std::vector<std::string> selectMultipleFiles(const std::vector<std::string>& extensions);

private:
    tgui::Gui& m_gui;
};

#endif // GRAPHENE_FILELOADER_HPP
