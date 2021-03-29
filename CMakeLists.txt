cmake_minimum_required(VERSION 3.0)
project(stock_manager)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

#set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_FLAGS "-Wall -fPIC -std=c++14")

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

# Find the QtWidgets library
find_package(qt COMPONENTS Widgets Core Gui)

find_package(nlohmann_json)

set(stock_manager_SRC
  src/main.cpp
  src/stock_manager.cpp
  src/add_new.cpp
  src/sell_items.cpp
  src/add_new_sell.cpp
  src/about.cpp
  src/database.cpp
  src/settings.cpp
  src/sha256.cpp
  rc_stock_manager.cpp
)

include_directories(${qt_INCLUDE_DIRS})

include_directories(${nlohmann_json_INCLUDE_DIRS})

# Tell CMake to create the stock_manager executable
add_executable(stock_manager ${stock_manager_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(stock_manager Qt5Widgets Qt5Core Qt5Gui sqlcipher)

# Install the executable
#install(TARGETS stock_manager DESTINATION bin)
