class Solution {
public:
  int similarPairs(vector<string>& a) {
    int ans = 0;
    int n = a.size();
    vector<int> b(n);
    for (int i=0; i<n; i++) {
      for (auto c : a[i]) {
        int x = c - 'a';
        b[i] |= (1<<x);
      }
    }
    for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        if (b[i]==b[j]) ans++;
      }
    }
    return ans;
  }
};