#include "task.h"

Task::Task( int id, uint32_t timeLimit, 
            void** initFunctions,
            void** runFunctions, 
            void** deinitFunctions, 
            void** errorFunctions): 
        ID(id), state (TaskState::Off), 
        timeLimit (timeLimit), 
        initFunctions (initFunctions),
        runFunctions (runFunctions), 
        deinitFunctions (deinitFunctions),
        errorFunctions (errorFunctions) {}

TaskState Task::getState() const { 
    return state; 
}
void Task::setState(TaskState state) { 
    state = state; 
}

uint32_t Task::getTimeLimit() const { 
    return timeLimit; 
}
void** Task::getInitFunctions() const { 
    return initFunctions; 
}
void** Task::getRunFunctions() const { 
    return runFunctions; 
}
void** Task::getDeinitFunctions() const { 
    return deinitFunctions; 
}

void** Task::getErrorFunctions() const { 
    return errorFunctions; 
}
int Task::getId() const { return ID; }
