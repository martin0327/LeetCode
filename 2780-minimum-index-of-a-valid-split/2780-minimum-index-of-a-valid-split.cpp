class Solution {
public:
    int minimumIndex(vector<int>& a) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        int mx = -1, cnt = 0;
        for (auto [k,v] : mp) {
            if (v > cnt) {
                cnt = v;
                mx = k;
            }
        }
        int n = a.size();
        vector<int> pre(n+1);
        for (int i=0; i<n; i++) {
            pre[i+1] = pre[i] + (a[i]==mx);
        }
        for (int i=1; i<n; i++) {
            if (2*pre[i]>i && 2*(pre[n]-pre[i]) > (n-i)) return i-1;
        }
        return -1;
    }
};