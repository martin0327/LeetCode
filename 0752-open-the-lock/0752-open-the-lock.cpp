class Solution {
public:
    int sz = 10;
    int vis[10][10][10][10];
    int blk[10][10][10][10];
    const int inf = 1e9;
    using vi = vector<int>;
    
    int openLock(vector<string>& de, string tg) {
        for (int i=0; i<sz; i++) {
            for (int j=0; j<sz; j++) {
                for (int k=0; k<sz; k++) {
                    for (int l=0; l<sz; l++) {
                        vis[i][j][k][l] = inf;
                        blk[i][j][k][l] = 0;
                    }
                }
            }
        }
        for (auto s : de) {
            if (s == "0000") return -1;
            int i = s[0]-'0';
            int j = s[1]-'0';
            int k = s[2]-'0';
            int l = s[3]-'0';
            blk[i][j][k][l] = 1;
        }
        using ti4 = tuple<int,int,int,int>;
        ti4 src = {0,0,0,0};
        vector<ti4> dx;
        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                for (int k=-1; k<=1; k++) {
                    for (int l=-1; l<=1; l++) {
                        vi t = {i,j,k,l};
                        int cnt = 0;
                        for (auto x : t) if (x == 0) cnt++;
                        if (cnt==3) dx.push_back({i,j,k,l});
                    }
                }
            }
        }
        // for (auto [i,j,k,l] : dx) {
        //     cout << i <<j<<k<<l<<endl;
        // }
        queue<ti4> q;
        vis[0][0][0][0] = 0;
        q.push({0,0,0,0});
        while (q.size()) {
            auto [i,j,k,l] = q.front();
            q.pop();
            for (auto [di,dj,dk,dl] : dx) {
                vi t = {i+di,j+dj,k+dk,l+dl};
                for (auto &x : t) x = (x+sz)%sz;
                int ni = t[0], nj = t[1], nk = t[2], nl = t[3];
                if (vis[ni][nj][nk][nl] == inf && !blk[ni][nj][nk][nl]) {
                    vis[ni][nj][nk][nl] = vis[i][j][k][l]+1;
                    q.push({ni,nj,nk,nl});
                }
            }
        }
        int ti = tg[0] - '0';
        int tj = tg[1] - '0';
        int tk = tg[2] - '0';
        int tl = tg[3] - '0';
        int ans = vis[ti][tj][tk][tl];
        if (ans == inf) ans = -1;
        return ans;
    }
};