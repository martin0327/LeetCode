class Solution {
public:
  bool halvesAreAlike(string s) {
    string t = "aeiouAEIOU";
    set<char> sc(t.begin(), t.end());
    int x=0, y=0;
    int n = s.size();
    for (int i=0; i<n/2; i++) if (sc.count(s[i])) x++;
    for (int i=n/2; i<n; i++) if (sc.count(s[i])) y++;
    return x==y;
  }
};