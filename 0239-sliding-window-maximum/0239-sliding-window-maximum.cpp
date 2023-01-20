class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& a, int k) {
    map<int,int> mp;
    int n = a.size();
    for (int i=0; i<k; i++) mp[a[i]]++;
    vector<int> ans = {mp.rbegin()->first};
    for (int i=k; i<n; i++) {
      if (--mp[a[i-k]] == 0) mp.erase(a[i-k]);
      mp[a[i]]++;
      ans.push_back(mp.rbegin()->first);
    }
    return ans;
  }
};