cmake_minimum_required(VERSION 3.15)
project(grawing_way_oop_2.0)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME, "mortallCombat.exe")
set(HEADERS
        inc/Character.hpp
        inc/Skill.hpp
        )
set(SOURCES
        src/Character.cpp
        src/Skill.cpp
        main.cpp)

add_executable(${PROJECT_NAME}
        ${HEADERS}
        ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PUBLIC "inc")

#find_package(sfml REQUIRED)
#if(sfml_FOUND)
#set(TARGET_NAME )


