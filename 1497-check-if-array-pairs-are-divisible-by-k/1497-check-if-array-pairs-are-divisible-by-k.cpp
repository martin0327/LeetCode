class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        vector<int> cnt(k);
        for (auto x : a) cnt[(x%k+k)%k]++;
        bool ans = (cnt[0]%2==0);
        for (int i=1; i<k-i; i++) {
            ans &= cnt[i] == cnt[k-i];
        }
        return ans;
    }
};