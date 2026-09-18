cmake_minimum_required(VERSION 3.20)
project(cafe-in CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate wxWidgets package and required components
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Define your source files and executable
add_executable(cafe-in main.cpp)
add_library(sqlite3 STATIC 
    third_party/sqlite/sqlite3.c
    third_party/sqlite/sqlite3.h
)


# Link against the resolved wxWidgets libraries
target_link_libraries(cafe-in PRIVATE ${wxWidgets_LIBRARIES})
target_link_libraries(cafe-in PRIVATE sqlite3)


# Указываем путь к заголовочным файлам
target_include_directories(sqlite3 PUBLIC 
    SQLite/sqlite3.h
)
# На платформах Linux/macOS часто требуется поддержка потоков и dl
find_package(Threads REQUIRED)
target_link_libraries(cafe-in PRIVATE Threads::Threads ${CMAKE_DL_LIBS})
