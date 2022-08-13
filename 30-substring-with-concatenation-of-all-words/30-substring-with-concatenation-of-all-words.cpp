class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int n = s.size();
    int m = words[0].size();
    int wsz = words.size();
    map<string, int> mp;
    int idx = 0;
    for (auto x : words) mp[x] = 0;
    for (auto &[k,v] : mp) v = idx++;
    int sz = idx;
    vector<int> ori_cnt(sz+1);
    for (auto x : words) {
      ori_cnt[mp[x]]++;
    }
    unordered_map<string, int> ump;
    for (auto &[k,v] : mp) ump[k] = v;
    // debug(ump);
    // debug(ori_cnt);

    vector<int> ans;

    for (int i=0; i<m; i++) {
      vector<int> b;
      for (int j=i; j<n; j+=m) {
        string t = s.substr(j,m);
        if (ump.count(t)) b.push_back(ump[t]);
        else b.push_back(sz);
      }
      // debug(b);
      vector<int> cnt(sz+1);
      if (b.size() < wsz) continue;
      for (int j=0; j<wsz; j++) {
        cnt[b[j]]++;
      }
      if (cnt==ori_cnt) {
        ans.push_back(i);
      }
      // debug(cnt);
      for (int j=wsz; j<b.size(); j++) {
        cnt[b[j-wsz]]--;
        cnt[b[j]]++;
        // debug(cnt);
        if (cnt==ori_cnt) {
          ans.push_back(i+m*(j-(wsz-1)));
        }
      }
    }
    return ans;

  }
};