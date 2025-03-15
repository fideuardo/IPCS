#include "TaskManager.h"

void TaskManager::addTask(const Task& task) {
    tasks_.push_back(task);
}

Task& TaskManager::getTask(size_t index) {
    return tasks_.at(index);
}

size_t TaskManager::getTaskCount() const {
    return tasks_.size();
}