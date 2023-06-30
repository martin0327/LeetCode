class Solution {
public:
    
    int n, R, C;
    vector<int> dr = {-1,1,0,0,-1,-1,1,1};
    vector<int> dc = {0,0,-1,1,-1,1,-1,1};
    
    struct dsu {
      public:
        dsu() : _n(0) {}
        dsu(int n) : _n(n), parent_or_size(n, -1) {}

        int merge(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            int x = leader(a), y = leader(b);
            if (x == y) return x;
            if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            return x;
        }

        bool same(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            return leader(a) == leader(b);
        }

        int leader(int a) {
            assert(0 <= a && a < _n);
            if (parent_or_size[a] < 0) return a;
            return parent_or_size[a] = leader(parent_or_size[a]);
        }

        int size(int a) {
            assert(0 <= a && a < _n);
            return -parent_or_size[leader(a)];
        }

        std::vector<std::vector<int>> groups() {
            std::vector<int> leader_buf(_n), group_size(_n);
            for (int i = 0; i < _n; i++) {
                leader_buf[i] = leader(i);
                group_size[leader_buf[i]]++;
            }
            std::vector<std::vector<int>> result(_n);
            for (int i = 0; i < _n; i++) {
                result[i].reserve(group_size[i]);
            }
            for (int i = 0; i < _n; i++) {
                result[leader_buf[i]].push_back(i);
            }
            result.erase(
                std::remove_if(result.begin(), result.end(),
                               [&](const std::vector<int>& v) { return v.empty(); }),
                result.end());
            return result;
        }

      private:
        int _n;
        std::vector<int> parent_or_size;
    };
    
    int rc2idx(int r, int c) {
        return (r-1)*C + c;
    }
    
    pair<int,int> idx2rc(int idx) {
        int r = idx / C + 1;
        int c = idx % C;
        return {r,c};
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        R = row;
        C = col;
        n = R * C;
        // cout << "n: " << n << endl;
        dsu d(n+2);
        set<int> check;
        int cnt = 0;
        for (int j=0; j<cells.size(); j++) {
            int r = cells[j][0];
            int c = cells[j][1];
            int idx = rc2idx(r,c);
            
            for (int i=0; i<8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr == 0 || nr == R+1) continue;
                if (nc == 0) d.merge(0,idx);
                else if (nc == C+1) d.merge(n+1, idx);
                else {
                    if (check.count(rc2idx(nr,nc))) d.merge(rc2idx(nr,nc),idx);
                }           
            }
            check.insert(rc2idx(r,c));
            if (d.same(0,n+1)) {
                return cnt;            
            }
            cnt++;
        }
        
        return 0;
    }
};