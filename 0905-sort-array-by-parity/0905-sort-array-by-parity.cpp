class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        vector<int> ret;
        for (auto x : a) if (!(x&1)) ret.push_back(x);
        for (auto x : a) if (x&1) ret.push_back(x);
        return ret;        
    }
};