add_library(TaskManager
    core/Task.cpp
    core/Task.h
    core/TaskExecutor.cpp
    core/TaskExecutor.h
    core/TaskManager.cpp
    core/TaskManager.h
)

target_include_directories(TaskManager PUBLIC ${CMAKE_SOURCE_DIR}/pkg/TaskManager/core)