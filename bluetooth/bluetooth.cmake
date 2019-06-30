# Bluetooth CMake file
#
# Configures the bluetooth library and adds it to the build

##### Files #####

# Headers
include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/ble_stack/inc/common
    ${CMAKE_CURRENT_LIST_DIR}/ble_stack/inc/soc
    ${CMAKE_CURRENT_LIST_DIR}/ble_stack/infrastructure.h
)

# Source files
FILE(GLOB BLUETOOTH_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)#

SET(OBJS
  ${CMAKE_CURRENT_LIST_DIR}/lib/EFR32BG1B/GCC/*.o
  ${CMAKE_CURRENT_LIST_DIR}/lib/EFR32BG1B/GCC/*.a
)

SET_SOURCE_FILES_PROPERTIES(
  ${OBJS}
  PROPERTIES
  EXTERNAL_OBJECT true
  GENERATED true
)

##### Outputs #####

# Create balena library
#add_library(bluetooth ${BLUETOOTH_SOURCES})

# Link to emlib
#target_link_libraries(bluetooth emlib)

# Link to emdrv
#target_link_libraries(bluetooth emdrv)

# Link to balena
#target_link_libraries(bluetooth balena)

# Add library to build
#set(LIBS ${LIBS} bluetooth)