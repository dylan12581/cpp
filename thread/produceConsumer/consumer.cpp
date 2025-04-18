/**
 * Project C++
 */
#include "consumer.h"
#include "TaskQueue.h"
using std::endl;
using std::cout;
#include <unistd.h>

/**
 * consumer implementation
 */


/**
 * @param taskQueue
 * @return goodsType
 */
void consumer::consume(TaskQueue& taskQueue) {

   int cnt = 20;
   while(--cnt){
        goodsType tmp =  taskQueue.pop();
        cout <<"consume:"<< tmp << endl;
   } 

}
