class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> ret;
        if (n < m) return ret;
        
        vector<int> target(26);
        for (int i=0; i<m; i++) {
            int x = p[i] - 'a';
            target[x]++;
        }
        vector<int> cnt(26);
        for (int i=0; i<m; i++) {
            int x = s[i] - 'a';
            cnt[x]++;
        }
        if (target==cnt) ret.push_back(0);
        for (int i=1; i+m-1<n; i++) {
            int x = s[i-1] - 'a';
            cnt[x]--;
            int y = s[i+m-1] - 'a';
            cnt[y]++;
            if (target==cnt) ret.push_back(i);
        }
        return ret;        
    }
};