project(game)

# ------------------------------------------------------------------------------


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Qt5 COMPONENTS Core Network Sql REQUIRED)

# ------------------------------------------------------------------------------

aux_source_directory(. SRCS)
file(GLOB_RECURSE OTHER_FILES "./*.h*")

add_library(${PROJECT_NAME} STATIC
    ${SRCS}
    ${OTHER_FILES}
    )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../world
        )

target_link_libraries(${PROJECT_NAME} PUBLIC
    world
    )

add_dependencies(${PROJECT_NAME} world)


