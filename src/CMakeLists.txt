
file (GLOB BRFD_SOURCES
      "BRFDs/*.cpp")

file (GLOB BTDF_SOURCES
      "BTDFs/*.cpp")

file (GLOB CAMERA_SOURCES
      "Cameras/*.cpp")

file (GLOB GEOMETRIC_SOURCES
      "GeometricObjects/*.cpp")

file (GLOB LIGHT_SOURCES
      "Lights/*.cpp")

file (GLOB MAPPING_SOURCES
      "Mappings/*.cpp")

file (GLOB MATERIAL_SOURCES
      "Materials/*.cpp")

file (GLOB NOISE_SOURCES
      "Noises/*.cpp")

file (GLOB SAMPLER_SOURCES
      "Samplers/*.cpp")

file (GLOB TEXTURE_SOURCES
      "Textures/*.cpp")

file (GLOB TRACER_SOURCES
      "Tracers/*.cpp")

file (GLOB UTILITIES_SOURCES
      "Utilities/*.cpp")
file (GLOB WORLD_SOURCES
      "World/*.cpp")



# Properties->C/C++->General->Additional Include Directories
include_directories (${PROJECT_SOURCE_DIR}/include)
include_directories (${PROJECT_SOURCE_DIR}/libs)

# Set Properties->General->Configuration Type to Dynamic Library(.dll)
# Creates saa-application.dll with the listed sources collected in the variables
# Also adds sources to the Solution Explorer
add_library(raytracerCore  ${BRFD_SOURCES} ${BTDF_SOURCES} ${CAMERA_SOURCES} ${GEOMETRIC_SOURCES} 
                           ${LIGHT_SOURCES} ${MATERIAL_SOURCES} ${NOISE_SOURCES} ${SAMPLER_SOURCES} ${TEXTURE_SOURCES} 
                           ${TRACER_SOURCES} ${UTILITIES_SOURCES} ${WORLD_SOURCES})

# Creates a folder "libraries" and adds target project (saa-application.vcproj) under it
set_property(TARGET raytracerCore PROPERTY FOLDER "libraries")

# Adds logic to INSTALL.vcproj to copy sa--application.dll to the destination directory
install (TARGETS raytracerCore
       RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin
       LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/bin
       ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/bin)