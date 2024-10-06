project(tests)

# ------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ------------------------------------------------------------------------------

add_executable(test-distance "test-distance.cpp" )

aux_source_directory(. SRCS)
file(GLOB_RECURSE OTHER_FILES "./*.h*")

target_include_directories(test-distance PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../world
        )

target_link_libraries(test-distance PUBLIC
    world
    )

add_dependencies(test-distance world)

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
add_dependencies(test-liste world )

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
add_dependencies(test-squarejoker game )

# ------------------------------------------------------------------------------




