class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        vector<int> b;
        for (auto [k,v] : mp) {
            b.push_back(v);
        }
        sort(b.begin(), b.end());
        int ans = mp.size();
        for (auto cnt : b) {
            if (k >= cnt) k -= cnt;
            else break;
            ans--;
        }
        return ans;
    }
};