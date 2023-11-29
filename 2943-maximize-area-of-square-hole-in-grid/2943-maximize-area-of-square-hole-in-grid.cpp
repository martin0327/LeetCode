class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& a, vector<int>& b) {
        auto f = [&] (vector<int> &a) {
            sort(a.begin(), a.end());
            int cnt = 1, ret = 1;
            for (int i=1; i<a.size(); i++) {
                if (a[i]-a[i-1]==1) cnt++;
                else cnt = 1;
                ret = max(ret, cnt);
            }
            return ret;
        };
        
        int s = min(f(a),f(b))+1;
        return s*s;
    }
};