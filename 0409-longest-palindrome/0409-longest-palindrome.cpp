class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for (auto c : s) mp[c]++;
        
        bool odd = false;
        int ans = 0;
        for (auto [k,v] : mp) {
            odd |= (v&1);
            ans += v-(v&1);
        }
        return ans + odd;        
    }
};