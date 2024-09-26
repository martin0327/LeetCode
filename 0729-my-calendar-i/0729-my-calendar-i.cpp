class MyCalendar {
public:
    using pii = pair<int,int>;
    set<pii> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool ret = true;
        auto it = s.upper_bound({start,start});
        if (it != s.end()) {
            auto [l,r] = *it;
            if (l < end) ret = false;
        }
        if (it != s.begin()) {
            it--;
            auto [l,r] = *it;
            if (r > start) ret = false;
        }
        if (ret) s.insert({start,end});
        return ret;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */