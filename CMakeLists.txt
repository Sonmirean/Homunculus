#################################################
# The principal CMakeLists file for the project #
#################################################

# Minimum version of CMake required to use this library
cmake_minimum_required(VERSION 3.0)
# Standard of C++ for the project
set (CMAKE_CXX_STANDARD 20)
# Project declaration. Includes version in form of
# MAJOR.MINOR.PATCH.BUILD and involved languages.
project(Homunculus VERSION 0.0.0.3 LANGUAGES "CXX")

# Creates a list of all source files in folder src/ and subfolders.
file(GLOB_RECURSE PUBLIC_SOURCE "src/*.cpp")
# Creates a list of all header files in folder include/ and subfolders.
file(GLOB_RECURSE PUBLIC_HEADER "include/*.hpp")
# This line builds the project as a static library.
add_library(Homunculus STATIC ${PUBLIC_SOURCE} ${PUBLIC_HEADER})

# Declaration of include directories for the library
# (where to look for headers)
target_include_directories(Homunculus PRIVATE "include")
target_include_directories(
	Homunculus 
	PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<INSTALL_INTERFACE:include>
)

# Installation of the library.
# Installation refers to packaging a ready-to-use library
# in a specific folder.
install(
	TARGETS Homunculus
	EXPORT HomunculusTargets
	ARCHIVE DESTINATION "lib"
)
install(
	DIRECTORY "include/" 
	DESTINATION include
)
install(
	EXPORT HomunculusTargets
	FILE HomunculusTargets.cmake
	NAMESPACE Homunculus::
	DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake/Homunculus"
)

# Including CMake config helper extension
include(CMakePackageConfigHelpers)

# HomunculusConfig is used to find the library by other CMake users.
configure_package_config_file(
	"HomunculusConfig.cmake.in" 
	"${CMAKE_CURRENT_BINARY_DIR}/HomunculusConfig.cmake"
	INSTALL_DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake/Homunculus/"
)
# Declaration of version so users can check it before including.
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/HomunculusConfigVersion.cmake"
  VERSION 0.0.3
  COMPATIBILITY SameMajorVersion
)

# final installation
install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/HomunculusConfig.cmake"
		  "${CMAKE_CURRENT_BINARY_DIR}/HomunculusConfigVersion.cmake"
	DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake/Homunculus"
)
