using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int,int> mp;
        int idx = 0;
        for (auto flw : flowers) {
            int l = flw[0];
            int r = flw[1];
            mp[l] = 0;
            mp[r] = 0;
        }
        for (auto p : persons) {
            mp[p] = 0;
        }
        for (auto &[k,v] : mp) v = idx++;
        int n = flowers.size();
        for (int i=0; i<n; i++) {
            int &l = flowers[i][0];
            int &r = flowers[i][1];
            l = mp[l];
            r = mp[r];
        }
        for (auto &p : persons) p = mp[p];

        vi a(idx+10);
        for (auto fl : flowers) {
            int l = fl[0];
            int r = fl[1];
            a[l]++;
            a[r+1]--;
        }
        int m = a.size();
        for (int i=1; i<m; i++) {
            a[i] += a[i-1];
        }
        vi res;
        for (auto p : persons) {
            res.push_back(a[p]);
        }
        return res;
    }
};