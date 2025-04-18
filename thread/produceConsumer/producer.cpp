/**
 * Project C++
 */


#include "producer.h"
#include "TaskQueue.h"
#include <time.h>
#include <iostream>
#include <unistd.h>
using std::endl;
using std::cout;
/**
 * producer implementation
 */


/**
 * @param taskQueue
 * @return void
 */
void producer::produce(TaskQueue& taskQueue) {
    int cnt = 20;
    srand(clock());
    
    while(--cnt){
        size_t number = rand()%100;
        taskQueue.push(number);
        cout << "produce:" << number << endl;
        sleep(1);
    }
}
