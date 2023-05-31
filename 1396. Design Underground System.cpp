class UndergroundSystem {
	map<int,pair<int,string>>f;
	map<pair<string,string>,vector<int>>s;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        f[id]= {t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        s[{f[id].second,stationName}].push_back(t-f[id].first);
    }
    
    double getAverageTime(string startStation, string endStation) {
		double res=0;
        auto& v= s[{startStation,endStation}];
		for(auto& it : v) res+=it;
		return (double) res/v.size() ;        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
