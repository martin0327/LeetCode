class MyQueue {
public:
  vector<int> a,b;
  MyQueue() {

  }

  void push(int x) {
    a.push_back(x);
  }

  int pop() {
    if (b.empty()) {
      while (a.size()) {
        b.push_back(a.back());
        a.pop_back();
      }
    }
    int ret = b.back();
    b.pop_back();
    return ret;
  }

  int peek() {
    if (b.empty()) return a.front();
    else return b.back();
  }

  bool empty() {
    return a.empty() && b.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */