class Solution {
public:
  string intToRoman(int x) {
    vector<string> a = {"M??", "CDM", "XLC", "IVX"};
    vector<int> b = {1000,100,10,1};
    string ret;
    for (int i=0; i<4; i++) {
      int q = x / b[i];
      if (q == 9) {
        ret += a[i][0];
        ret += a[i][2];
      }
      else if (q==4) {
        ret += a[i][0];
        ret += a[i][1];
      }
      else{
        if (q/5 > 0) ret += a[i][1];
        for (int j=0; j<q%5; j++) ret += a[i][0];
      }
      x %= b[i];
    }
    return ret;
  }
}; 