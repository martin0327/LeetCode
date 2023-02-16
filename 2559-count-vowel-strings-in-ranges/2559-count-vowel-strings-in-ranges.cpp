class Solution {
public:
  vector<int> vowelStrings(vector<string>& a, vector<vector<int>>& qr) {
    int n = a.size();
    vector<int> b(n);
    set<char> s = {'a', 'e', 'i', 'o', 'u'};
    for (int i=0; i<n; i++) {
      if (s.count(a[i].front()) && s.count(a[i].back())) b[i] = 1;
    }
    vector<int> pre(n+1);
    for (int i=1; i<=n; i++) pre[i] = pre[i-1] + b[i-1];
    int q = qr.size();
    vector<int> ans(q);
    for (int i=0; i<q; i++) {
      ans[i] = pre[qr[i][1]+1] - pre[qr[i][0]];
    }
    return ans;
  }
};