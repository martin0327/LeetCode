class Solution {
public:
  int countOdds(int lo, int hi) {
    if (lo==hi) return hi&1;
    int ans = 0;
    if (hi&1) {
      ans++;
      hi--;
    }
    if (lo&1) {
      ans++;
      lo++;
    }
    if (hi >= lo) ans += (hi - lo) / 2;
    return ans;
  }
};