//
// Created by Rostyslav on 30.08.2023.
//

#include "FIleLoader.hpp"
#include "../../../external/portable-file-dialogs.h"
#include <string>
#include <TGUI/TGUI.hpp>


FileLoader::FileLoader(tgui::Gui& gui) : m_gui(gui) {
}

std::string FileLoader::selectOneFile(const std::string& extension) {
    auto f = pfd::open_file("Choose a file", pfd::path::home(),
                            { "Allowed Files", "*" + extension,
                              "All Files", "*" },
                            pfd::opt::none).result();

    if (f.empty()) {
        return "";  // No file was selected.
    }
    return f[0];  // Only the first selected file.
}

std::vector<std::string> FileLoader::selectMultipleFiles(const std::vector<std::string>& extensions) {
    std::string filter = "Allowed Files (";
    for (const auto& ext : extensions) {
        filter += "*" + ext + " ";
    }
    filter += ")";

    auto f = pfd::open_file("Choose files", pfd::path::home(),
                            { filter, filter,
                              "All Files", "*" },
                            pfd::opt::multiselect).result();

    return f;  // Vector of selected file paths.
}


