cmake_minimum_required(VERSION 3.0)
project(stock_manager)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set(stock_manager_SRC
  src/main.cpp
  src/stock_manager.cpp
  src/add_new.cpp
  src/sell_items.cpp
)

# Tell CMake to create the helloworld executable
add_executable(stock_manager ${stock_manager_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(stock_manager Qt5::Widgets Qt5::Core)

# Install the executable
install(TARGETS stock_manager DESTINATION bin)
