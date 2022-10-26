class Solution {
public:
  bool checkSubarraySum(vector<int>& a, int k) {
    int n = a.size();
    vector<int> pre(n+1);
    for (int i=1; i<=n; i++) pre[i] = (pre[i-1] + a[i-1]) % k;
    // for (auto x : pre) cout << x << " ";
    // cout << endl;
    set<int> s = {0};
    for (int i=2; i<=n; i++) {
      if (s.count(pre[i])) return true;
      s.insert(pre[i-1]);
    }    
    return false;          
  }
};
