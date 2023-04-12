class Solution {
public:
    vector<long long> distance(vector<int>& a) {
        using ll = long long;
        int n = a.size();
        vector<ll> ans(n);
        map<ll,vector<ll>> mp;
        for (int i=0; i<n; i++) {
            mp[a[i]].push_back(i);
        }
        for (auto &[k,v] : mp) {
            int sz = v.size();
            v.insert(v.begin(),0);
            vector<ll> pre(sz+2), suf(sz+2);
            for (int i=1; i<=sz; i++) pre[i] = pre[i-1] + v[i];
            for (int i=sz; i>=1; i--) suf[i] = suf[i+1] + v[i];
            for (int i=1; i<=sz; i++) {
                ans[v[i]] += (i-1)*v[i] - pre[i-1];
                ans[v[i]] += suf[i+1] - (sz-i) * v[i];
            }
        }
        return ans;
    }
};