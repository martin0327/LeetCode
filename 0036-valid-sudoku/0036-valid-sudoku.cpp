using vi = vector<int>;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        int n = 9;
        for (int i=0; i<n; i++) {
            vi c1(10), c2(10), c3(10);
            for (int j=0; j<n; j++) {
                int r = 3*(i/3) + j/3;
                int c = 3*(i%3) + j%3;
                if (a[i][j]!='.' && c1[a[i][j]-'0']++) return false;
                if (a[j][i]!='.' && c2[a[j][i]-'0']++) return false;
                if (a[r][c]!='.' && c3[a[r][c]-'0']++) return false;
            }
        }
        return true;
    }
};