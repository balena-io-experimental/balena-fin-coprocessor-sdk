# Balena CMake file
#
# Configures the balena library and adds it to the build

##### Files #####

# Headers
include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/inc
    ${CMAKE_CURRENT_LIST_DIR}/config
)

# Source files
FILE(GLOB BALENA_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

##### Outputs #####

# Create balena library
add_library(balena ${BALENA_SOURCES})

# Link to emlib
target_link_libraries(balena emlib)

# Link to emdrv
target_link_libraries(balena emdrv)

# Add library to build
set(LIBS ${LIBS} balena)