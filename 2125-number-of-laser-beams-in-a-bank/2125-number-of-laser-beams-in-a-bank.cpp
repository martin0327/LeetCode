class Solution {
public:
    int numberOfBeams(vector<string>& b) {
        vector<int> a;
        for (auto row : b) {
            int cnt = 0;
            for (auto c : row) {
                if (c=='1') cnt++;
            }
            if (cnt>0) a.push_back(cnt);
        }
        int ans = 0;
        for (int i=1; i<a.size(); i++) {
            ans += a[i] * a[i-1];
        }
        return ans;
    }
};