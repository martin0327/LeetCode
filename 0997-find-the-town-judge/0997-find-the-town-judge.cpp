class Solution {
public:
    int findJudge(int n, vector<vector<int>>& a) {
        typedef vector<int> vi;
        typedef vector<vi> vvi;
        
        vvi b(n+1);
        vvi c(n+1);
        for (auto aa : a) {
            int x = aa[0];
            int y = aa[1];
            b[y].push_back(x);
            c[x].push_back(y);
        }        
        vi ans;
        for (int i=1; i<=n; i++) {
            if (b[i].size()==n-1 && c[i].size()==0) {
                ans.push_back(i);
            }
        }
        if (ans.size()==1) return ans[0];
        else return -1;
    }
};