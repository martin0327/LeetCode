class Solution {
public:
  string reverseVowels(string s) {
    string t = "aeiouAEIOU";
    set<char> sc;
    for (auto c : t) sc.insert(c);
    int n = s.size();
    vector<char> a;
    vector<int> idx;
    for (int i=0; i<n; i++) {
      if (sc.count(s[i])) {
        idx.push_back(i);
        a.push_back(s[i]);
      }
    }
    reverse(idx.begin(), idx.end());
    for (int i=0; i<idx.size(); i++) {
      s[idx[i]] = a[i];
    }
    return s;
  }
};