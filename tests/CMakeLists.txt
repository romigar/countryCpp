project(tests)

# ------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ------------------------------------------------------------------------------

add_executable(${PROJECT_NAME} "test-distance.cpp" )

aux_source_directory(. SRCS)
file(GLOB_RECURSE OTHER_FILES "./*.h*")

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../world
        )

target_link_libraries(${PROJECT_NAME} PUBLIC
    world
    )

add_dependencies(${PROJECT_NAME} world)

# ------------------------------------------------------------------------------

add_executable(test-liste "test-liste.cpp" )
aux_source_directory(. SRCS)
file(GLOB_RECURSE OTHER_FILES "./*.h*")
target_include_directories(test-liste PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../world
        )
target_link_libraries(test-liste PUBLIC
    world
    )
add_dependencies(${PROJECT_NAME} world )

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------

add_executable(test-squarejoker "test-squarejoker.cpp" )
aux_source_directory(. SRCS)
file(GLOB_RECURSE OTHER_FILES "./*.h*")
target_include_directories(test-squarejoker PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../game
        )
target_link_libraries(test-squarejoker PUBLIC
    game
    )
add_dependencies(${PROJECT_NAME} game )

# ------------------------------------------------------------------------------




