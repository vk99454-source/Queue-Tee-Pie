#include "cutie.hpp"
using namespace std;

class QueueTees {
    private:
    Cutie* cuties[10];
    int front;
    int back;
    int count;
    public:
    QueueTees();
    void enqueue(Cutie* cutie);
    Cutie* dequeue();
    int size() const;
};