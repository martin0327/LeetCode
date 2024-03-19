using vi = vector<int>;
using pii = pair<int,int>;
using vp = vector<pii>;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vi cnt(26);
        for (auto x : tasks) cnt[x-'A']++;
        set<pii> a;
        for (int i=0; i<26; i++) {
            if (cnt[i] > 0) a.insert({-cnt[i],i});
        }
        int cur = 0;
        vi last(26,-100);
        while (a.size()) {
            for (auto [x,i] : a) {
                if (cur > last[i] + n) {
                    last[i] = cur;
                    a.erase({x,i});
                    if (x+1 != 0) a.insert({x+1,i});
                    break;
                }
            }
            cur++;
        }
        return cur;
    }
};