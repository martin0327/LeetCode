class Solution {
public:
    int minDeletions(string ss) {
        map<char,int> cnt;
        for (auto c : ss) cnt[c]++;
        map<int,int> mp;
        for (auto [k,v] : cnt) mp[v]++;

        set<int> s;
        int max_val = (*mp.rbegin()).first;
        for (int i=1; i<max_val; i++) {
            if (!mp.count(i)) s.insert(i);
        }
        int ans = 0;
        while (!mp.empty()) {
            auto [k,v] = *mp.rbegin();
            mp.erase(k);
            for (int i=0; i<v-1; i++) {
                auto it = s.lower_bound(k);
                if (it == s.begin()) {
                    ans += k;
                }
                else {
                    it = prev(it);
                    ans += k - *it;
                    s.erase(it);
                }
            }
        }        
        
        return ans;
    }
};