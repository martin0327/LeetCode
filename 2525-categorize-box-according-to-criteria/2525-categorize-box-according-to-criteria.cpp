using ll = long long;
class Solution {
public:
  string categorizeBox(int l, int w, int h, int mass) {
    int x = 1e4;
    int y = 1e9;
    ll prod = 1;
    prod *= l;
    prod *= w;
    prod *= h;
    bool b1 = l >= x || w >= x || h >= x || prod >= y;
    bool b2 = mass >= 100;
    if (b1 && b2) return "Both";
    else if (!b1 && !b2) return "Neither";
    else if (b1) return "Bulky";
    else return "Heavy";
  }
};