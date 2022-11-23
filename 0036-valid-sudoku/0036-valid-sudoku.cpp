using vi = vector<int>;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        int n = 9;
        for (int i=0; i<n; i++) {
            vi cnt(10);
            for (int j=0; j<n; j++) {
                if (a[i][j]!='.' && cnt[a[i][j]-'0']++) return false;
            }
        }
        for (int j=0; j<n; j++) {
            vi cnt(10);
            for (int i=0; i<n; i++) {
                if (a[i][j]!='.' && cnt[a[i][j]-'0']++) return false;
            }
        }
        for (int i=0; i<n; i++) {
            vi cnt(10);
            for (int j=0; j<n; j++) {
                int r = 3*(i/3) + j/3;
                int c = 3*(i%3) + j%3;
                if (a[r][c]!='.' && cnt[a[r][c]-'0']++) return false;
            }
        }
        return true;
    }
};