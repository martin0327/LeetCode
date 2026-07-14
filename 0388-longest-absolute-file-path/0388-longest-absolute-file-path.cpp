vector<string> split_str(const string& s, const string& delim) {
    vector<string> ret;
    size_t start = 0;
    size_t end = s.find(delim);

    while (end != string::npos) {
        ret.push_back(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
    }
    
    ret.push_back(s.substr(start));
    return ret;
}

pair<int,string> f(string &s) {
    int cnt = 0, n = s.size();
    for (int i=0; i<n; i++) {
        if (s.substr(i,1) == "\t") {
            cnt++;
        }
        else break;
    }
    auto t = s.substr(cnt, n-cnt);
    return make_pair(cnt,t);
}

bool is_file(string &s) {
    for (auto &ch : s) {
        if (ch == '.') return true;
    }
    return false;
}

template<typename T> 
void debug(vector<T> a) {
    for (auto x : a) {
        cout << x << " ";
    }   cout << endl;
}

class Solution {
public:
    int lengthLongestPath(string s) {
        auto a = split_str(s, "\n");
        vector<int> b;
        int ans = 0, cur = 0;
        for (auto t : a) {
            auto [x,s] = f(t);
            while (b.size() > x) {
                cur -= b.back();
                b.pop_back();
            }
            b.push_back(s.size());
            cur += b.back();
            int sz = b.size();
            if (is_file(s)) {
                ans = max(ans, cur+sz-1);
            }
        }
        return ans;
    }
};