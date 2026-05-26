const int sz = 5001;
bool vis[sz];
class Solution {
public:
    bool circularArrayLoop(vector<int>& a) {
        int n = a.size();
        for (int i=0; i<n; i++) {
            memset(vis,0,sizeof(vis));
            int cnt = 0, x = i;
            int dir = 0;
            while (!vis[x]) {
                vis[x] = 1;
                if (a[x] > 0) dir |= 1;
                else dir |= 2;
                x = (x+a[x])%n;
                x = (x+n)%n;
                cnt++;
            }
            
            if (cnt > 1 && x == i && dir != 3) return true;
        }
        return false;
    }
};