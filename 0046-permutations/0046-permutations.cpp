class Solution {
public:
    vector<vector<int>> permute(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ret;
        do {
            ret.push_back(a);
        } while(next_permutation(a.begin(), a.end()));
        return ret;
    }
};