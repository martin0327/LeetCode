class Solution {
public:
    int largestInteger(int n, int s) {
        string t;
        while (n--) {
            int d = min(9,s);
            s -= d;
            t += '0' + d;
        }
        if (s > 0) return -1;
        return stoi(t);
    }
};