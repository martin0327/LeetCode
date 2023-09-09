class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.push_back({1});
        for (int i=0; i<numRows-1; i++) {
            vector<int> cur = {1};
            vector<int> &pre = ret.back();
            for (int i=0; i<pre.size()-1; i++) {
                cur.push_back(pre[i]+pre[i+1]);
            }
            cur.push_back(1);
            ret.push_back(cur);
        }
        return ret;
    }
};