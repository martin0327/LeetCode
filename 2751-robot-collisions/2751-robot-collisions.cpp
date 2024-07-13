using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vp = vector<pii>;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        int n = pos.size();
        vp a;
        set<pii> b;
        for (int i=0; i<n; i++) {
            if (dir[i] == 'R') {
                a.push_back({pos[i],i});
            }
            else b.insert({pos[i],i});
        }
        sort(a.rbegin(), a.rend());
        for (auto [x,i] : a) {
            while (true) {
                auto it = b.lower_bound({x,0});
                if (it != b.end()) {
                    auto [y,j] = *it;
                    if (h[i] == h[j]) {
                        h[i] = h[j] = 0;
                        b.erase(it);
                        break;
                    }
                    else if (h[i] > h[j]) {
                        h[i]--;
                        h[j] = 0;
                        b.erase(it);
                    } 
                    else {
                        h[j]--;
                        h[i] = 0;
                        break;
                    }
                }
                else break;
            }
        }
        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (h[i] > 0) ans.push_back(h[i]);
        }
        return ans;
    }
};