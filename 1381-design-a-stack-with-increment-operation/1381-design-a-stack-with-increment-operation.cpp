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
        // cout << "push" << endl;
        // cout << i << endl;
        if (i < sz) a[i++] = x;
    }
    
    int pop() {
        // cout << "pop" << endl;
        // cout << i << endl;
        if (i==0) return -1;
        int ret = a[i-1];
        ret += b[i-1];
        if (i >= 2) b[i-2] += b[i-1];
        b[i-1] = 0;
        i--;
        return ret;
    }
    
    void increment(int k, int val) {
        // cout << "increment" << endl;
        // cout << i << endl;
        int j = i-1;
        if (j > k-1) j = k-1;
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