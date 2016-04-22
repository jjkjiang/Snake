cmake_minimum_required(VERSION 3.5)
project(snake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB snake_SRC
        "*.h"
        "*.cpp"
        "GameLogic/*.cpp"
        "GameLogic/*.h"
        "GameObjects/*.cpp"
        "GameObjects/*.h"
        "GameStates/*.cpp"
        "GameStates/*.h"
        "Definitions/*.h"
)

add_executable(snake ${snake_SRC})

set(CMAKE_PREFIX_PATH PATH "C:\\SFML-2.3.2")

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(snake ${SFML_LIBRARIES})
endif()

target_link_libraries(snake ${SFML-2.3.2_LIBRARIES})
