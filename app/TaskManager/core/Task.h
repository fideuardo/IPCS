// task.h
#ifndef TASK_H
#define TASK_H

#include <cstdint>

/*Task states*/
enum class TaskState {
    Off,
    Init,
    Running,
    Deinit,
    Error
};

class Task {
public:
    Task(int ID, uint32_t timeLimit, void** initFunctions,
         void** runFunctions, void** deinitFunctions, void** errorFunctions);

    TaskState getState() const;
    void setState(TaskState state);
    uint32_t getTimeLimit() const;
    void** getInitFunctions() const;
    void** getRunFunctions() const;
    void** getDeinitFunctions() const;
    void** getErrorFunctions() const;
    int getId() const;

private:
    int ID;
    TaskState state;
    uint32_t timeLimit;
    void** initFunctions;
    void** runFunctions;
    void** deinitFunctions;
    void** errorFunctions;
};

#endif // TASK_H