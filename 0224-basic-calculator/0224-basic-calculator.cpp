using vs = vector<string>;
using pii = pair<int,int>;
using vi = vector<int>;
using vp = vector<pii>;

class Solution {
public:

  bool is_num(string s) {
    int x = s.back() - '0';
    return 0<=x && x<=9;
  }

  bool is_num(char c) {
    int x = c - '0';
    return 0<=x && x<=9;
  }

  int calculate(string s) {
    vs a;
    for (auto c : s) {
      if (c == ' ') continue;
      if (is_num(c)) {
        if (a.empty() || !is_num(a.back())) a.push_back(string(1,c));
        else a.back() += c;
      }
      else a.push_back(string(1,c));
    }

    int n = a.size();
    vp b;
    vp st;

    for (int i=0; i<n; i++) {
      if (a[i] == "(") {
        if (i > 0 && a[i-1] == "-") st.push_back({i+1,1});
        else st.push_back({i+1,0});
      }
      if (a[i] == ")") {
        auto [l,neg] = st.back();
        st.pop_back();
        if (neg) b.push_back({l,i-1});
      }
      if (i > 0 && is_num(a[i]) && a[i-1]=="-") b.push_back({i,i});
    }

    vi sign(n+1);
    for (auto [l,r] : b) {
      sign[l] ^= 1;
      sign[r+1] ^= 1;
    }
    for (int i=1; i<=n; i++) sign[i] ^= sign[i-1];

    int ans = 0;
    for (int i=0; i<n; i++) {
      if (is_num(a[i])) {
        if (sign[i]) ans -= stoi(a[i]);
        else ans += stoi(a[i]);
      }
    }
    return ans;    
  }
};