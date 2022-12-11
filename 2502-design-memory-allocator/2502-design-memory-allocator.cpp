class Allocator {
public:
    using vi = vector<int>;
    vi a;
    int n;
    Allocator(int _n) {
        n = _n;
        a.resize(n);
    }
    
    int allocate(int size, int mID) {
        int cnt = 0;
        int idx = -1;
        for (int i=0; i<n; i++) {
            if (!a[i]) cnt++;
            else cnt = 0;
            if (cnt==size) {
                idx = i - size + 1;
                break;
            }
        }
        if (idx==-1) return -1;
        for (int i=idx; i<idx+size; i++) {
            a[i] = mID;
        }
        return idx;
    }
    
    int free(int mID) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (a[i] == mID) {
                cnt++;
                a[i] = 0;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */