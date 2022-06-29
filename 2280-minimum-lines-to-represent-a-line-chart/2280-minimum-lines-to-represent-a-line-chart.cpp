class Solution {
public:
    int minimumLines(vector<vector<int>>& a) {
        int n = a.size();
        using pii = pair<int,int>;
        sort(a.begin(), a.end());
        vector<pii> b;
        pii last = {0,0};
        int ans = 0;
        for (int i=0; i<n-1; i++) {
            int x1 = a[i][0];
            int y1 = a[i][1];
            int x2 = a[i+1][0];
            int y2 = a[i+1][1];
            int x = x2-x1;
            int y = y2-y1;
            int g = gcd(x,y);
            x /= g;
            y /= g;
            
            pii z = {x,y};
            if (last != z) {
                ans++;
                last = z;
            }
        }
        
        return ans;
    }
};