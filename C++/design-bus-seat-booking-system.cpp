// Time:  ctor:         O(1)
//        toggle:       O(1)
//        getTotalTime: O(1)
//        getMinTime:   O(1)
// Space: O(n)

// hash table
class BusBooking {
public:
    BusBooking(int n) {
        
    }
    
    void toggle(string seat) {
        if (lookup_.count(seat)) {
            total_ -= lookup_[seat];
            lookup_.erase(seat);
            return;
        }
        lookup_[seat] = (seat[0] == 'A' && lookup_.count(string(1, 'B') + seat.substr(1))) || (seat[0] == 'D' && lookup_.count(string(1, 'C') + seat.substr(1))) ? 3 : 1;
        total_ += lookup_[seat];
    }
    
    int getTotalTime() {
        return total_;
    }
    
    int getMinTime() {
        return size(lookup_);
    }

private:
    int total_ = 0;
    unordered_map<string, int> lookup_;
};

// Time:  ctor:         O(n)
//        toggle:       O(1)
//        getTotalTime: O(1)
//        getMinTime:   O(1)
// Space: O(n)
// hash table
class BusBooking2 {
public:
    BusBooking2(int n) : lookup_(4, vector<int>(n)) {
        
    }
    
    void toggle(string seat) {
        const auto& i = seat[0] - 'A', &j = stoi(seat.substr(1)) - 1;
        if (lookup_[i][j]) {
            --cnt_;
            total_ -= lookup_[i][j];
            lookup_[i][j] = 0;
            return;
        }
        lookup_[i][j] = (i == 0 && lookup_[i + 1][j]) || (i == 3 && lookup_[i - 1][j]) ? 3 : 1;
        total_ += lookup_[i][j];
        ++cnt_;
    }
    
    int getTotalTime() {
        return total_;
    }
    
    int getMinTime() {
        return cnt_;
    }

private:
    int cnt_ = 0;
    int total_ = 0;
    vector<vector<int>> lookup_;
};
