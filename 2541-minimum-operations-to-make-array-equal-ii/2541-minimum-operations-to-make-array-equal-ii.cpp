using ll = long long;

class Solution {
public:
  long long minOperations(vector<int>& a, vector<int>& b, int k) {
    if (k==0) return a==b?0:-1;
    ll n = a.size();
    ll cnt = 0, ans = 0;
    for (int i=0; i<n; i++) {
      if (a[i]%k != b[i]%k) return -1;
      ll x = a[i]/k - b[i]/k;
      cnt += x;
      ans += abs(x);
    }
    if (cnt) return -1;
    else return ans/2;
  }
};