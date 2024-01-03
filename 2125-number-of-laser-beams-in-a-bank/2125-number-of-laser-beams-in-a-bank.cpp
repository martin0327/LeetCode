class Solution {
public:
    int numberOfBeams(vector<string>& b) {
        vector<int> a;
        auto f = [&](char c){return c=='1';};
        for (auto t : b) {
            int cnt = count_if(t.begin(), t.end(), f);
            if (cnt>0) a.push_back(cnt);
        }
        int ans = 0;
        for (int i=1; i<a.size(); i++) {
            ans += a[i] * a[i-1];
        }
        return ans;
    }
};