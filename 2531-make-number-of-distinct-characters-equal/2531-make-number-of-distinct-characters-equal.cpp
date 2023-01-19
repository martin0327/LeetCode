using vi = vector<int>;
class Solution {
public:
  bool isItPossible(string s, string t) {
    vi a(26), b(26);
    for (auto c : s) a[c-'a']++;
    for (auto c : t) b[c-'a']++;
    
    for (int i=0; i<26; i++) {
      for (int j=0; j<26; j++) {
        if (a[i]==0) continue;
        if (b[j]==0) continue;
        vi c = a;
        vi d = b;
        c[i]--; d[j]--;
        c[j]++; d[i]++;
        
        int c1 = 0, c2 = 0;
        for (int k=0; k<26; k++) if (c[k]) c1++;
        for (int k=0; k<26; k++) if (d[k]) c2++;
        if (c1==c2) return true;
      }
    }
    return false;
  }
};