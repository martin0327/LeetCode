using pii = pair<int,int>;
using vp = vector<pii>;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vp d = {{a,0},{b,1},{c,2}};
        vector<int> ans;
        while (true) {
            sort(d.begin(), d.end());
            auto &[cnt,j] = d.back();
            if (cnt == 0) break;
            if (ans.size() >= 2) {
                if (j == ans.back() && j == ans[ans.size()-2]) {
                    auto &[cnt2,j2] = d[1];
                    // cout << cnt2 << " " << j2 << endl;
                    if (cnt2 == 0) break;
                    cnt2--;
                    ans.push_back(j2);
                }
                else {
                    cnt--;
                    ans.push_back(j);
                }
            }
            else {
                cnt--;
                ans.push_back(j);
            }
        }
        string sol;
        for (auto j : ans) sol += 'a' + j;
        return sol;
        
    }
};