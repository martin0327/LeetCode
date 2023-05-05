class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        set<char> sc;
        {
            string t = "aeiou";
            for (auto c : t) sc.insert(c);
        }
        int cnt = 0;
        for (int i=0; i<k; i++) {
            if (sc.count(s[i])) cnt++;
        }
        int ans = cnt;
        for (int i=k; i<n; i++) {
            if (sc.count(s[i-k])) cnt--;
            if (sc.count(s[i])) cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};