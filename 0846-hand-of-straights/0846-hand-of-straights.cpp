class Solution {
public:
    bool isNStraightHand(vector<int>& a, int sz) {
        int n = a.size();
        if (n % sz != 0) return false;
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        while (mp.size()) {
            int x = mp.begin()->first;
            for (int i=x; i<x+sz; i++) {
                if (mp.count(i)) {
                    if (--mp[i] == 0) mp.erase(i);
                }
                else return false;
            }
        }
        return true;
    }
};