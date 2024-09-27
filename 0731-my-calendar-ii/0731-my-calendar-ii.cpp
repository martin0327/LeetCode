class MyCalendarTwo {
    set<pair<int, int>> map1;
    set<pair<int, int>> map2;
    
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        auto it2 = map2.lower_bound(pair<int, int>(start, start));
        if(it2 != map2.end() && it2->second < end)
            return false;
        
        auto it = map1.lower_bound(pair<int, int>(start, start));
        while(it != map1.end())
        {
            int s = it->second;
            int e = it->first;

            if(end < s)
            {
                break;
            }else if(end == s) 
            {
                it = map1.erase(it);
                end = e;
            }else
            {
                map2.insert(pair<int, int>(min(e, end), max(s, start)));
                start = min(s, start);
                end = max(e, end);
                it = map1.erase(it);
                
            }
        }
        map1.insert(pair<int, int>(end, start));
        return true;
    }
};
