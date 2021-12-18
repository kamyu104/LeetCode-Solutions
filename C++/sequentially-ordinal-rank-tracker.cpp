// Time:  add: O(logn)
//        get: O(logn)
// Space: O(n)

class SORTracker {
public:
    SORTracker() {
        
    }
    void add(string name, int score) {
        auto cit1 = lookup_.emplace(-score, name).first;
        if (cit_ == cend(lookup_) || *cit1 < *cit_) {
            --cit_;
        }
    }
    
    string get() {
        return (cit_++)->second;
    }

private:
    set<pair<int, string>> lookup_;
    set<pair<int, string>>::const_iterator cit_ = cend(lookup_);
};
