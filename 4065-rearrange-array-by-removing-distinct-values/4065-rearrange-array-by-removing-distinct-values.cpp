const int sz = 101;
int cnt[sz];
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        memset(cnt,0,sizeof(cnt));
        for (auto x : a) cnt[x]++;
        vector<int> ans;
        while (true) {
            bool done = true;
            for (int i=0; i<sz; i++) {
                if (cnt[i] > 0) {
                    ans.push_back(i);
                    cnt[i]--;
                    done = false;
                }
            }
            if (done) break;
        }
        return ans;
    }
};