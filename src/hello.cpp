#include <iostream>
#include "hello.hpp"

using namespace std;

QueueTees::QueueTees() {
front = 0;
    back = 0;
    count = 0;
    for (int i = 0; i < 10; i++) {
        cuties[i] = nullptr;
    }
}
void QueueTees::enqueue(Cutie* cutie) {
if (count == 10) {
    cout << "The queue is full." << endl;
    return;
}
    cuties[back] = cutie;
    back = (back + 1) % 10;
    count = count + 1;
}
Cutie* QueueTees::dequeue() {
if (count == 0) {
    return nullptr;
}
    Cutie* removed = cuties[front];
    cuties[front] = nullptr;
    front = (front + 1) % 10;
    count = count - 1;
    return removed;
}
int QueueTees::size() const{
return count;
}