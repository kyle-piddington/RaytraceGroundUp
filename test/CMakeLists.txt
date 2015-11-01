file (GLOB BRFD_TESTS
      "BRFDs/*.cpp")

file (GLOB BTDF_TESTS
      "BTDFs/*.cpp")

file (GLOB CAMERA_TESTS
      "Cameras/*.cpp")

file (GLOB GEOMETRIC_TESTS
      "GeometricObjects/*.cpp")

file (GLOB LIGHT_TESTS
      "Lights/*.cpp")
file (GLOB MAPPING_TESTS
      "Mappings/*.cpp")

file (GLOB MATERIAL_TESTS
      "Materials/*.cpp")

file (GLOB NOISE_TESTS
      "Noises/*.cpp")

file (GLOB TEXTURE_TESTS
      "Textures/*.cpp")

file (GLOB TRACER_TESTS
      "Tracers/*.cpp")

file (GLOB UTILITIES_TESTS
      "Utilities/*.cpp")

file (GLOB WORLD_TESTS
      "World/*.cpp")



# Properties->C/C++->General->Additional Include Directories
include_directories (${PROJECT_SOURCE_DIR}/include)
include_directories (${PROJECT_SOURCE_DIR}/libs)

# Set Properties->General->Configuration Type to Dynamic Library(.dll)
# Creates saa-application.dll with the listed TESTS collected in the variables
# Also adds TESTS to the Solution Explorer
add_executable(raytracerTest ${BRFD_TESTS} ${BTDF_TESTS} ${CAMERA_TESTS} ${GEOMETRIC_TESTS} 
                             ${LIGHT_TESTS} ${MATERIAL_TESTS} ${NOISE_TESTS} ${TEXTURE_TESTS} 
                             ${TRACER_TESTS} ${UTILITIES_TESTS} ${WORLD_TESTS} main.cpp)

target_link_libraries (raytracerTest  raytracerCore)

# Creates a folder "executables" and adds target 
# project (raytracerTest.vcproj) under it
set_property(TARGET raytracerTest PROPERTY FOLDER "executables")

# Adds logic to INSTALL.vcproj to copy raytracerTest.exe to destination directory
install (TARGETS raytracerTest
       RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
