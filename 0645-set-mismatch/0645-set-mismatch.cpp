class Solution {
public:
  vector<int> findErrorNums(vector<int>& a) {
    int n = a.size();
    vector<int> cnt(n+1);
    for (auto x : a) cnt[x]++;
    vector<int> ans;
    for (int i=1; i<=n; i++) {
      if (cnt[i]==2) ans.insert(ans.begin(), i);
      if (cnt[i]==0) ans.push_back(i);
    }
    return ans;
  }
};