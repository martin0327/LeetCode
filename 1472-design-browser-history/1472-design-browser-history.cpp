class BrowserHistory {
public:
    vector<string> a;
    int idx;
    BrowserHistory(string homepage) {
        a = {homepage};
        idx = 0;
    }
    
    void visit(string url) {
        while (a.size() > idx+1) a.pop_back();
        a.push_back(url);
        idx++;
    }
    
    string back(int steps) {
        int d = min(idx, steps);
        idx -= d;
        return a[idx];
    }
    
    string forward(int steps) {
        int d = min((int)a.size()-1-idx, steps);
        idx += d;
        return a[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */