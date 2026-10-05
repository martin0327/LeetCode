class RangeModule {
public:
    map<int,int> mp;
    RangeModule() {
        
    }
    
    void addRange(int l, int r) {
        if (mp.empty()) {
            mp[l] = r;
            return;
        }
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
            // auto l2 = it->first, r2 = it->second;
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
        if (mp.empty()) return;

        auto it = mp.lower_bound(l);
        if (it != mp.begin()) {
            auto [l1,r1] = *prev(it);
            // l1 < l
            if (l < r1) {
                mp.erase(prev(it));
                mp[l1] = l;
                if (r < r1) {
                    mp[r] = r1;
                }
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


// void solve() {
//     auto rm = RangeModule();
//     // vs names = {"addRange", "removeRange", "queryRange", "queryRange", "queryRange"};
//     // vvi args = {{10, 20}, {14, 16}, {10, 14}, {13, 15}, {16, 17}};

//     vs names = {"addRange","removeRange","removeRange","addRange","removeRange","addRange","queryRange","queryRange","queryRange"};
//     vvi args = {{6,8},{7,8},{8,9},{8,9},{1,3},{1,8},{2,4},{2,9},{4,6}};




//     int n = names.size();
//     int m = args.size();
//     assert(n == m);
//     for (int i=0; i<n; i++) {
//         auto name = names[i];
//         auto l = args[i][0], r = args[i][1];
//         debug(name,l,r);
//         if (name == "addRange") {
//             rm.addRange(l,r);
//         }
//         else if (name == "removeRange") {
//             rm.removeRange(l,r);
//         }
//         else {
//             auto ans = rm.queryRange(l,r);
//             debug(ans);
//         }
//         debug(rm.mp);
//     }



// }