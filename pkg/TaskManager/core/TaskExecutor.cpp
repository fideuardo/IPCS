#include "TaskExecutor.h"
#include <iostream>

void TaskExecutor::executeTasks(TaskManager& manager) {
    for (size_t i = 0; i < manager.getTaskCount(); ++i) {
        Task& task = manager.getTask(i);
        std::cout << "Executing task with ID: " << task.getId() << std::endl;
        switch (task.getState()) {
            case TaskState::Init:
                executeFunctions(task.getInitFunctions());
                break;
            case TaskState::Running:
                executeFunctions(task.getRunFunctions());
                break;
            case TaskState::Deinit:
                executeFunctions(task.getDeinitFunctions());
                break;
            case TaskState::Error:
                executeFunctions(task.getErrorFunctions());
                break;
            case TaskState::Off:
            default:
                break;
        }
    }
}

void TaskExecutor::executeFunctions(void** functions) {
    if (functions != nullptr) {
        void** funcPtr = functions;
        while (*funcPtr != nullptr) {
            void (*func)() = reinterpret_cast<void (*)()>(*funcPtr);
            func();
            funcPtr++;
        }
    }
}