using ti3 = tuple<int,int,int>;

class LFUCache {
public:
    int cap, rec = 0;
    map<int, ti3> mp;
    set<ti3> s;
    
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp.count(key)) {
            auto [v,f,r] = mp[key];
            mp[key] = {v,f+1,rec};
            s.erase({f,r,key});
            s.insert({f+1,rec++,key});
            return v;
        }
        else return -1;
    }
    
    void put(int key, int val) {
        if (cap == 0) return;
        if (mp.count(key)) {
            auto [v,f,r] = mp[key];
            mp[key] = {val,f+1,rec};
            s.erase({f,r,key});
            s.insert({f+1,rec++,key});
        }
        else {
            if (mp.size() == cap && cap) {
                auto [f,r,k] = *s.begin();
                s.erase(s.begin());
                mp.erase(k);
            }
            mp[key] = {val,1,rec};
            s.insert({1,rec++,key});
        } 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */