class Solution {
public:
  bool halvesAreAlike(string s) {
    string t = "aeiouAEIOU";
    set<char> sc(t.begin(), t.end());
    int x=0, y=0;
    int n = s.size();
    for (int i=0; i<n/2; i++) x += sc.count(s[i]);
    for (int i=n/2; i<n; i++) y += sc.count(s[i]);
    return x==y;
  }
};  