class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> cnt(26);
        for (auto c : s) cnt[c-'a']++;
        int mx = 0;
        for (auto x : cnt) mx = max(mx,x);
        if (2*mx>n+1) return "";
        vector<pair<int,char>> a;
        for (int i=0; i<26; i++) a.push_back({cnt[i],'a'+i});
        sort(a.rbegin(), a.rend());
        s.clear();
        for (auto [x,c] : a) {
            while (x--) s += c;
        }
        string ans(n, 'a');
        int j=0;
        for (int i=0; i<n; i+=2) ans[i] = s[j++];
        for (int i=1; i<n; i+=2) ans[i] = s[j++];
        return ans;        
    }
}; 