const int mx = 2e5;
using vi = vector<int>;
class LRUCache {
    public:
    int cap;
    int sz = 0;
    int front = 0;
    int back = 0;
    vi r2k, k2r, k2v;
    LRUCache(int capacity) {
        cap = capacity;
        r2k = k2r = k2v = vi(mx+1,-1);
    }
    
    int get(int key) {
        if (k2v[key] == -1) return -1;
        r2k[front] = key;
        k2r[key] = front++;
        return k2v[key];
    }
    
    void put(int key, int value) {
        if (k2v[key] == -1) {
            if (sz==cap) {
                while (k2r[r2k[back]] != back) back++;
                k2v[r2k[back++]] = -1; 
            }
            else sz++;
        }
        k2v[key] = value;
        r2k[front] = key;
        k2r[key] = front++;
    }
};
