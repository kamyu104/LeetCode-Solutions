// Time:  O(n)
// Space: O(n)

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        live_[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        const auto [startStation, startTime] = move(live_[id]); live_.erase(id);
        statistics_[startStation][stationName].first += t - startTime;
        ++statistics_[startStation][stationName].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        const auto& [numer, denom] = statistics_[startStation][endStation];
        return double(numer) / denom; 
    }

private:
    unordered_map<int, pair<string, int>> live_;
    unordered_map<string, unordered_map<string, pair<int, int>>> statistics_;
};
