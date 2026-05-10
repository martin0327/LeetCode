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

vector<string> split_str(string s, const char delim = ' ') {
    vector<string> ret;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        ret.push_back(t);
    }
    return ret;
}

using vs = vector<string>;
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& qr) {
        string t;
        for (auto &s : chunks) t += s;
        auto a = split_str(t, ' ');
        vs b;
        for (auto &s : a) {
            int n = s.size();
            dsu uf(n);
            for (int i=1; i<n; i++) {
                if (s[i] == '-') {
                    if (s[i-1] == '-') uf.merge(i,i-1);
                }
                else {
                    if (s[i-1] != '-') uf.merge(i,i-1);
                    else {
                        if (i-2 >= 0 && s[i-2] != '-') {
                            uf.merge(i,i-1);
                        }
                    }
                }
            }
            vs t;
            for (auto &g : uf.groups()) {
                string ss;
                for (auto i : g) ss += s[i];
                if (ss[0] == '-' || ss.back() == '-') continue;
                b.push_back(ss);
            }
        }
        map<string,int> mp;
        for (auto &s : b) {
            mp[s]++;
        }
        int n = qr.size();
        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            if (mp.count(qr[i])) {
                ans[i] = mp[qr[i]];
            }
        }
        return ans;
    }
};