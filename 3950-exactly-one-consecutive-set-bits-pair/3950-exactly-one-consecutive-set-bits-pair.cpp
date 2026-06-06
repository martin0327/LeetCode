using vi = vector<int>;
class Solution {
public:
    bool consecutiveSetBits(int n) {
        vi a;
        for (int i=0; i<20; i++) {
            if (n>>i&1) a.push_back(1);
            else a.push_back(0);
        }
        int cnt = 0;
        for (int i=1; i<20; i++) {
            if (a[i] && a[i-1]) cnt++;
        }
        return cnt == 1;
    }
};