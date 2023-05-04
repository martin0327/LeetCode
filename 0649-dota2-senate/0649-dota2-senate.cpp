class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.size();
        set<int> s1, s2;
        for (int i=0; i<n; i++) {
            if (s[i]=='R') s1.insert(i);
            else s2.insert(i);
        }
        s1.insert(n);
        s2.insert(n);
        int idx = 0;
        while (s1.size() && s2.size()) {
            auto it1 = s1.lower_bound(idx);
            auto it2 = s2.lower_bound(idx);
            if (*it1 == n && *it2 == n) {
                idx = 0;
            }
            else if (*it1 < *it2) {
                auto it = s2.lower_bound(idx);
                if (*it == n) s2.erase(s2.begin());
                else s2.erase(it);
                idx = (*it1+1)%n;
            }
            else {
                auto it = s1.lower_bound(idx);
                if (*it == n) s1.erase(s1.begin());
                else s1.erase(it);
                idx = (*it2+1)%n;
            }
        }
        if (s1.size()) return "Radiant";
        else return "Dire";
    }
};