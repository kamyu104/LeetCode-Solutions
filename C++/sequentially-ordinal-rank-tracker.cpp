// Time:  add: O(logn)
//        get: O(logn)
// Space: O(n)

class SORTracker {
public:
    SORTracker() {
        
    }
    void add(string name, int score) {
        auto cit1 = s.emplace(-score, name).first;
        if (cit == cend(s) || *cit1 < *cit) {
            --cit;
        }
    }
    
    string get() {
        return (cit++)->second;
    }

private:
    set<pair<int, string>> s;
    set<pair<int, string>>::const_iterator cit = cend(s);
};
