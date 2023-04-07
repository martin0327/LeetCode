using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& a) {
        vvi ret;
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        while (true) {
            vi b;
            for (auto &[k,v] : mp) {
                if (v-- > 0) b.push_back(k);
            }
            if (b.size()) ret.push_back(b);
            else break;
        }
        return ret;
    }
};