
#ifndef _TASK_H
#define _TASK_H

class Task {
public: 
    Task();
    virtual void process()= 0;
    virtual ~Task();
};

#endif //_TASK_H
