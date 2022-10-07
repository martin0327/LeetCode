using pii = pair<int,int>;
class MyCalendarThree {
public:
    map<int,int> comp;
    vector<int> inv;
    vector<int> cnt;
    
    MyCalendarThree() {
        
    }
    
    int book(int s, int e) {
        comp[s] = 0;
        comp[e] = 0;
        int sz = 0;
        for (auto &[k,v] : comp) v = sz++;
        vector<int> ncnt(sz);
        if (cnt.size()) {
            for (int i=0; i<cnt.size()-1; i++) {
                int l = inv[i];
                int r = inv[i+1];
                ncnt[comp[l]] += cnt[i];
                ncnt[comp[r]] -= cnt[i];
            }    
        }
        ncnt[comp[s]]++;
        ncnt[comp[e]]--;
        for (int i=1; i<ncnt.size(); i++) ncnt[i] += ncnt[i-1];
        cnt = ncnt;
        
        while (inv.size() < sz) inv.push_back(0);
        for (auto &[k,v] : comp) inv[v] = k;
        
        int ret = 0;
        for (auto x : cnt) ret = max(ret, x);
        return ret;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */