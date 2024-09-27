cmake_minimum_required(VERSION 3.5)

project(countryCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


add_executable(countryCpp main.cpp)
file(GLOB_RECURSE OTHER_FILES "./*.h*")
add_subdirectory(world)
add_subdirectory(tests)

target_link_libraries(${PROJECT_NAME} PUBLIC world)
add_dependencies(${PROJECT_NAME}  world)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/world
        )


include(GNUInstallDirs)


install(TARGETS countryCpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
