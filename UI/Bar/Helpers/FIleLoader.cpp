//
// Created by Rostyslav on 30.08.2023.
//

#include "FIleLoader.h"

#include <string>
#include <TGUI/TGUI.hpp>

namespace fs = std::filesystem;

FileLoader::FileLoader(tgui::Gui& gui, const std::string& extension) : m_gui(gui) {

}

void FileLoader::populateFileList(tgui::ListBox::Ptr listBox, const std::string& extension) {

}

