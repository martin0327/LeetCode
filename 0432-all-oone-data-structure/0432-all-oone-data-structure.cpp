template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class AllOne {
public:
    map<string,int> mp;
    min_pq<pair<int,string>> pq1;
    max_pq<pair<int,string>> pq2;
    
    AllOne() {
        
    }
    
    void inc(string key) {
        int cnt = ++mp[key];
        pq1.push({cnt,key});
        pq2.push({cnt,key});        
    }
    
    void dec(string key) {
        if (--mp[key] == 0) mp.erase(key);
    }
    
    string getMaxKey() {
        while (pq2.size()) {
            auto [cnt,s] = pq2.top();
            // cout << cnt << " " << s << endl;
            if (mp.count(s) && mp[s] == cnt) {
                return s;
            }
            else pq2.pop();
        }
        return "";
    }
    
    string getMinKey() {
        while (pq1.size()) {
            auto [cnt,s] = pq1.top();
            if (mp.count(s) && mp[s] == cnt) {
                return s;
            }
            else pq1.pop();
        }
        return "";        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */