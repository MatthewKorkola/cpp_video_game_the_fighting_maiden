cmake_minimum_required(VERSION 3.14)
project(TheFightingMaiden)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game.cpp headers/Game.h tester.cpp Player.cpp headers/Player.h Enemy.cpp headers/Enemy.h Character.cpp headers/Character.h Armour.cpp headers/Armour.h ArmourTestCase.cpp headers/ArmourTestCase.h MovementTestCase.cpp MovementTestCase.h HitboxTestCase.cpp headers/HitboxTestCase.h AttackTestCase.cpp sfmlFiles/AttackTestCase.h)
add_executable(TheFightingMaiden ${SOURCE_FILES} HitboxTestCase.cpp headers/HitboxTestCase.h AttackTestCase.cpp sfmlFiles/AttackTestCase.h)
include_directories(headers textures /usr/include c:SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics audio network)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(TheFightingMaiden ${SFML_LIBRARIES})

file(COPY textures DESTINATION ${CMAKE_BINARY_DIR})

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
# target_link_libraries(TheFightingMaiden sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

if(WIN64)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
