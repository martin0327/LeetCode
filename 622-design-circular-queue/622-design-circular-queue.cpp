class MyCircularQueue {
public:
    vector<int> a;
    int l = 0, r = 0, k = 0, sz = 0;
    
    MyCircularQueue(int k) {
        a.resize(k);    
        this->k = k;
    }
    
    bool enQueue(int value) {
        if (sz < k) {
            a[r] = value;
            r = (r+1) % k;
            sz++;
            return true;
        }
        else return false;
        
    }
    
    bool deQueue() {
        if (sz > 0) {
            l = (l+1) % k;
            sz--;
            return true;
        }
        else return false;
    }
    
    int Front() {
        if (sz>0) return a[l];
        else return -1;
    }
    
    int Rear() {
        if (sz>0) return a[(r-1+k)%k];
        else return -1;
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==k;
    }
};   

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */