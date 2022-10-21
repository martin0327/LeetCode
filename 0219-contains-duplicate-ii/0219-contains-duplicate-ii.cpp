class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& a, int k) {
    int n = a.size();
    map<int,int> mp;
    k = min(n, k+1);
    for (int i=0; i<k; i++) if (mp[a[i]]++) return true;
    for (int i=k; i<n; i++) {
      mp[a[i-k]]--;
      if (mp[a[i]]++) return true;
    }
    return false;
  }
};     