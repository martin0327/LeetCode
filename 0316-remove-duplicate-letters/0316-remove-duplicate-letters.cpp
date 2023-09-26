using vi = vector<int>;
class Solution {
public:
  string removeDuplicateLetters(string s) {
    int n = s.size();
    vi ridx(26);
    for (int i=0; i<n; i++) {
      ridx[s[i]-'a'] = i;
    }
    vi st;
    vi check(26);
    for (int i=0; i<n; i++) {
      if (check[s[i]-'a']) continue;
      while (st.size()) {
        int j = st.back();
        if (s[i] < s[j] && ridx[s[j]-'a'] > i) {
          st.pop_back();
          check[s[j]-'a'] = 0;
        }
        else break;
      }
      st.push_back(i);
      check[s[i]-'a'] = 1;
      // debug(st);
    }

    string ret;

    for (auto i : st) {
      int x = s[i] - 'a';
      // if (check[x]) continue;
      ret += s[i];
      check[x] = 1;
    }
    return ret;
  }
};