class Solution {
public:
    int numberOfBeams(vector<string>& b) {
        if (b.size()<=1) return 0;
        vector<int> a;
        for (auto row : b) {
            int cnt = 0;
            for (auto c : row) {
                if (c=='1') cnt++;
            }
            if (cnt>0) a.push_back(cnt);
        }
        if (a.size()<=1) return 0;
        int ans = 0;
        for (int i=0; i<a.size()-1; i++) {
            ans += a[i] * a[i+1];
        }
        return ans;
    }
};