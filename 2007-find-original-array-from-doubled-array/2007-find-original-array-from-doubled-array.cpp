class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        vector<int> ret, ret2;
        map<int,int> mp;
        for (auto &x : a) mp[x]++;
        for (auto &[k,v] : mp) {
            if (v==0) continue;
            if (k==0) {
                if (v&1) return ret2;
                else for (int i=0; i<v/2; i++) ret.push_back(k);
            }
            else if (mp.count(2*k) && mp[2*k] >= v) {
                mp[2*k] -= v;
                for (int i=0; i<v; i++) ret.push_back(k);
            }
            else return ret2;
        }
        return ret;
    }
};  