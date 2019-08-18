#include <iostream>
#include <vector>
using namespace std;

class PrioriyQueue {
public:
  PrioriyQueue() {

  }
  void EnQueue(int data) {
    queue_.push_back(data);
    ++len_;
    maxHeapUp();
  }

  int DeQueue() {
    if (len_ <= 0) return -1;
    auto head = queue_[0];
    queue_[0] = queue_[len_ - 1];
    --len_;
    maxHeapDown();
    return head;
  }
private:
  void maxHeapUp() {
    int child = len_ - 1;
    int parent = (child - 1) / 2;
    int target = queue_[child];
    while (child > 0 && target > queue_[parent]) {
      queue_[child] = queue_[parent];
      child = parent;
      parent /= 2;
    }
    queue_[child] = target;
  }
  void maxHeapDown() {
    int parent = 0;
    int child = 2 * parent + 1;
    for (; child < len_; child = 2 * child + 1) {
      if (child + 1 < len_ && queue_[child + 1] > queue_[child]) {
        ++child;
      }
      if (queue_[parent] >= queue_[child]) {
        break;
      }
      swap(queue_[child], queue_[parent]);
      parent = child;
    }
  }
  vector<int> queue_;
  int len_ = 0;
};

int main() {
  PrioriyQueue queue;
  queue.EnQueue(3);
  queue.EnQueue(1);
  queue.EnQueue(2);
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
}