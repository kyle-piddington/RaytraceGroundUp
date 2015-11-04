file (GLOB USERINTERFACE_SOURCES
      "UserInterface/*.cpp")

include_directories (${PROJECT_SOURCE_DIR}/libs)
include_directories (${PROJECT_SOURCE_DIR}/include)


add_executable(raytracer main.cpp ${USERINTERFACE_SOURCES})

target_link_libraries(raytracer raytracerCore)

# Creates a folder "executables" and adds target 
# project (raytracerTest.vcproj) under it
set_property(TARGET raytracer PROPERTY FOLDER "executables")

# Adds logic to INSTALL.vcproj to copy raytracer.exe to destination directory
install (TARGETS raytracer
       RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
