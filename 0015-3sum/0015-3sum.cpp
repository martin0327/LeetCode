template <typename T>
using uset = unordered_set<T>;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using ti3 = tuple<int,int,int>;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        set<int> s;
        set<ti3> ans;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int t = a[i] + a[j];
                if (s.count(t)) {
                    ans.insert({-t, a[i], a[j]});
                }
            }
            s.insert(-a[i]);
        }
        vvi ret;
        for (auto [x,y,z] : ans) ret.push_back({x,y,z});        
        return ret;
    }
};