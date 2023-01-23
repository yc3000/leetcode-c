#include <algorithm>
#include <list>
#include <queue>

struct Entry {
  Entry(int val) : val(val), is_move(false) {}

  int val;
  bool is_move;
};

struct cmp {
  bool operator()(Entry *lhs, Entry *rhs) { return lhs->val < rhs->val; }
};

class MaxQueue {
 public:
  MaxQueue() {}

  int max_value() {
    if (lst_.empty()) return -1;

    while (pri_q_.top()->is_move) {
      pri_q_.pop();
    }
    return pri_q_.top()->val;
  }

  void push_back(int value) {
    Entry *e = new Entry(value);
    pri_q_.push(e);
    lst_.push_back(e);
  }

  int pop_front() {
    if (lst_.empty()) return -1;

    // 队列的最大值
    Entry *e = lst_.front();
    lst_.pop_front();
    e->is_move = true;
    return e->val;
  }

  std::priority_queue<Entry *, std::vector<Entry *>, cmp> pri_q_;
  std::list<Entry *> lst_;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
//
//["MaxQueue","pop_front","pop_front","pop_front","pop_front","pop_front","push_back","max_value","push_back","max_value"]
// [[],[],[],[],[],[],[15],[],[9],[]]
