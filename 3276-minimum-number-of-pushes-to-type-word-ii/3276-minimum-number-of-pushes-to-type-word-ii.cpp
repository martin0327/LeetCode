class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (auto c : word) cnt[c-'a']++;
        
        sort(cnt.rbegin(), cnt.rend());
        long long ans = 0;
        long long y = 0;
        for (auto x : cnt) {
            if (x == 0) continue;
            y++; 
            if (y<=8) ans += x;
            else if (y<=16) ans += 2*x;
            else if (y<=24) ans += 3*x;
            else ans += 4*x;
        }
        return ans;
    }
};