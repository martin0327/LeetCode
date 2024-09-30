class CustomStack {
public:
    int sz;
    vector<int> a;
    CustomStack(int sz) {
        this->sz = sz;
    }
    
    void push(int x) {
        if (a.size() < sz) a.push_back(x);
    }
    
    int pop() {
        if (a.empty()) return -1;
        int ret = a.back();
        a.pop_back();
        return ret;
    }
    
    void increment(int k, int val) {
        int lim = a.size();
        if (lim > k) lim = k;
        for (int i=0; i<lim; i++) a[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */