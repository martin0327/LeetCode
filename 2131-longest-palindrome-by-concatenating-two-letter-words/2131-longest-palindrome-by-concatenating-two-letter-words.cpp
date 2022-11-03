class Solution {
public:
  int longestPalindrome(vector<string>& a) {
    map<string,int> mp;
    int ans = 0;
    for (auto s : a) {
      string t = s;
      reverse(t.begin(), t.end());
      if (mp.count(t) && mp[t] > 0) {
        ans += 4;
        mp[t]--;
      }
      else mp[s]++;
    }
    for (int i=0; i<26; i++) {
      string s = "aa";
      s[0] += i;
      s[1] += i;
      if (mp[s] > 0) {
        ans += 2;
        break;
      }
    }
    return ans;
  }
};