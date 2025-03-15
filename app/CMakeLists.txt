#add executable
add_executable(IPCApp main.cpp)

target_link_libraries(IPCApp TaskManager)

target_include_directories(mi_aplicacion PRIVATE ${CMAKE_SOURCE_DIR}/pkg/TaskManager/core)