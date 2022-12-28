using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        map<int,int> mp;
        int n = a.size();
        set<ll> s;
        set<vi> ans;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    ll x = (ll) a[i] + a[j] + a[k];
                    if (s.count(t-x)) {
                        int y = t-x;
                        ans.insert({y, a[i], a[j], a[k]});
                    }
                }
            }
            s.insert(a[i]);
        }
        vector<vector<int>> ret;
        for (auto x : ans) ret.push_back(x);
        return ret;
    }
};