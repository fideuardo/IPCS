#include "Task.h"
#include "TaskManager.h"
#include "TaskExecutor.h"
#include <iostream>

void initFunc1() { std::cout << "Init func 1\n"; }
void runFunc1() { std::cout << "Run func 1\n"; }

int main() {
    void* initFuncs[] = {reinterpret_cast<void*>(&initFunc1), nullptr};
    void* runFuncs[] = {reinterpret_cast<void*>(&runFunc1), nullptr};

    Task task1(1, 1000, initFuncs, runFuncs, nullptr, nullptr);
    Task task2(2, 2000, nullptr, runFuncs, nullptr, nullptr);

    TaskManager manager;
    manager.addTask(task1);
    manager.addTask(task2);

    TaskExecutor executor;
    executor.executeTasks(manager);

    return 0;
}
