cmake_minimum_required(VERSION 3.24)
project(Graphene)

set(CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCE_FILES main.cpp UI/Window.cpp UI/Window.h UI/Bar/UIBar.cpp UI/Bar/UIBar.h UI/Bar/UIBarButton.cpp UI/Bar/UIBarButton.h)

# Executable
add_executable(Graphene ${SOURCE_FILES})

# Include directories
include_directories(/usr/local/include)

# Find SFML
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Graphene sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Add TGUI
find_package(TGUI REQUIRED)
include_directories(${TGUI_INCLUDE_DIRS})
target_link_libraries(Graphene tgui)
