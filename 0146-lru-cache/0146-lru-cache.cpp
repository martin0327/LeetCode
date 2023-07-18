using vi = vector<int>;
class LRUCache {
public:
    int i=0, j=0, cap;
    vi r2k, k2r, k2v;
    LRUCache(int capacity) {
        cap = capacity;
        r2k = vi(2e5+1,-1);
        k2r = k2v = vi(1e4+1,-1);
    }
    
    int get(int key) {
        if (k2v[key] != -1) {
            r2k[j] = key;
            k2r[key] = j++;
        }
        return k2v[key];
    }
    
    void put(int key, int value) {
        if (k2v[key] == -1) {
            if (cap) cap--;
            else {
                while (k2r[r2k[i]] != i) i++;
                k2v[r2k[i++]] = -1; 
            }
        }
        k2v[key] = value;
        r2k[j] = key;
        k2r[key] = j++;
    }
};