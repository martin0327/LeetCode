class MyCircularDeque {
public:
    deque<int> dq;
    int k;
    MyCircularDeque(int k) {
        this->k = k;
    }
    
    bool insertFront(int x) {
        if (dq.size() < k) {
            dq.push_front(x);
            return true;
        }
        return false;
    }
    
    bool insertLast(int x) {
        if (dq.size() < k) {
            dq.push_back(x);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if (dq.size()) {
            dq.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if (dq.size()) {
            dq.pop_back();
            return true;
        }
        return false;        
    }
    
    int getFront() {
        if (dq.size()) return dq.front();
        else return -1;
    }
    
    int getRear() {
        if (dq.size()) return dq.back();
        else return -1;        
    }
    
    bool isEmpty() {
        return dq.empty();
        
    }
    
    bool isFull() {
        return dq.size() == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */