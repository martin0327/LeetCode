class Solution {
public:
    bool sumGame(string s) {
        int n=s.size(), m = n/2;
        int x=0, y=0;
        int c1=0, c2=0;
        for (int i=0; i<n; i++) {
            if (s[i] == '?') {
                if (i<m) c1++;
                else c2++;
            }
            else {
                if (i<m) x += s[i] - '0';
                else y += s[i] - '0';
            }
        }
        if ((c1+c2)%2) return true;

        if (c1 < c2) {
            swap(c1,c2);
            swap(x,y);
        }
        int d = (c1-c2)/2;
        if (x+9*d > y) return true;
        if (x+9*d < y) return true;
        return false;
    }
};