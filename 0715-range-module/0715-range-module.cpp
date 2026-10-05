class RangeModule {
public:
    map<int,int> mp;
    RangeModule() {
        
    }
    
    void addRange(int l, int r) {
        auto it = mp.upper_bound(l);
        if (it != mp.begin()) {
            auto [l1,r1] = *prev(it);
            // l1 <= l
            if (r1 >= l) {
                mp.erase(prev(it));
                l = min(l,l1), r = max(r,r1);
                mp[l] = r;
                it = mp.upper_bound(l);
            }
            else {
                mp[l] = r;
                it = mp.upper_bound(l);
            }
        }
        else {
            mp[l] = r;
            it = mp.upper_bound(l);
        }

        while (it != mp.end()) {
            auto [l2,r2] = *it;
            if (r2 <= r) {
                it++;
                mp.erase(prev(it));
            }
            else {
                if (l2 <= r) {
                    mp.erase(it);
                    mp[l] = r2;
                }
                break;
            }
        }
    }
    
    bool queryRange(int l, int r) {
        auto it = mp.upper_bound(l);
        if (it != mp.begin()) {
            auto [l1,r1] = *prev(it);
            // l1 <= l
            if (r <= r1) return true;
            else return false;
        }
        return false;
    }
    
    void removeRange(int l, int r) {
        auto it = mp.lower_bound(l);
        if (it != mp.begin()) {
            auto [l1,r1] = *prev(it);
            // l1 < l
            if (l < r1) {
                mp.erase(prev(it));
                mp[l1] = l;
                if (r < r1) mp[r] = r1;
                it = mp.lower_bound(l);
            }
        }
        while (it != mp.end()) {
            auto [l2,r2] = *it;
            if (r2 <= r) {
                it++;
                mp.erase(prev(it));
            }
            else {
                if (l2 < r) {
                    mp.erase(it);
                    mp[r] = r2;
                }
                break;
            }
        }
    }
};