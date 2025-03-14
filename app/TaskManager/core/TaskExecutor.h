#ifndef TASK_EXECUTOR_H
#define TASK_EXECUTOR_H

#include "TaskManager.h"

class TaskExecutor {
public:
    void executeTasks(TaskManager& manager);

private:
    void executeFunctions(void** functions);
};

#endif // TASK_EXECUTOR_H