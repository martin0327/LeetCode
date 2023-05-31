class UndergroundSystem {
public:
    map<int, pair<string,int>> mp;
    map<pair<string,string>,vector<int>> time;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string from, int t) {
        mp[id] = {from, t};
    }
    
    void checkOut(int id, string to, int t) {
        auto [from,tt] = mp[id];
        time[{from,to}].push_back(t-tt);
    }
    
    double getAverageTime(string from, string to) {
        double ret = 0;
        int cnt = 0;
        for (auto x : time[{from,to}]) {
            cnt++;
            ret += x;
        }
        ret /= cnt;
        return ret;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */