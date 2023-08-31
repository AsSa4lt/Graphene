//
// Created by Rostyslav on 30.08.2023.
//

#include "FIleLoader.h"
#include "tinyfiledialogs.h"
#include "../../../external/portable-file-dialogs.h"
#include <string>
#include <TGUI/TGUI.hpp>


FileLoader::FileLoader(tgui::Gui& gui, const std::string& extension) : m_gui(gui) {
    auto f = pfd::open_file("Choose files to read", pfd::path::home(),
                            { "Text Files (.txt .text)", "*.txt *.text",
                              "All Files", "*" },
                            pfd::opt::multiselect);
}

void FileLoader::populateFileList(tgui::ListBox::Ptr listBox, const std::string& extension) {

}

