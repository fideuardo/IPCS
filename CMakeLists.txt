# CMAKE version
cmake_minimum_required(VERSION 3.27.0)

# Project Name
project(IPCS VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Agregar ejecutable directamente (sin add_subdirectory)
add_subdirectory(app)
add_subdirectory(pkg/TaskManager)