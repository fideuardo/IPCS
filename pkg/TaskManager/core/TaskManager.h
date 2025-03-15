// task_manager.h
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "task.h"

class TaskManager {
public:
    void addTask(const Task& task);
    Task& getTask(size_t index);
    size_t getTaskCount() const;

private:
    std::vector<Task> tasks_;
};

#endif // TASK_MANAGER_H
