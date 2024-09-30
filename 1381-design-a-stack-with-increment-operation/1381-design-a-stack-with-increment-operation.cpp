class CustomStack {
public:
    int sz, i;
    vector<int> a, b;
    CustomStack(int sz) {
        this->sz = sz;
        this->a = vector<int>(sz);
        this->b = vector<int>(sz);
        this->i = 0;
    }
    
    void push(int x) {
        if (i < sz) a[i++] = x;
    }
    
    int pop() {
        if (i==0) return -1;
        i--;
        int ret = a[i] + b[i];
        if (i >= 1) b[i-1] += b[i];
        b[i] = 0;
        return ret;
    }
    
    void increment(int k, int val) {
        int j = min(i-1, k-1);
        if (j >= 0) b[j] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */