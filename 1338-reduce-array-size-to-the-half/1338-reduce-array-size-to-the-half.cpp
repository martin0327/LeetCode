class Solution {
public:
  int minSetSize(vector<int>& a) {
    int n = a.size();
    map<int,int> cnt;
    for (auto x : a) cnt[x]++;
    vector<int> b;
    for (auto [x,c] : cnt) b.push_back(c);
    sort(b.rbegin(), b.rend());
    
    int ans = 0;
    int cum = 0;
    int m = (n/2) + (n&1);
    for (auto x : b) {
      if (cum >= m) break;
      ans++;
      cum += x;
    }
    return ans;
  }
};