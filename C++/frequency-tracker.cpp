// Time:  ctor:         O(1)
//        add:          O(1)
//        deleteOne:    O(1)
//        hasFrequency: O(1)
// Space: O(min(n, r))

// freq table
class FrequencyTracker {
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if (--freq_[cnt_[number]] == 0) {
            freq_.erase(cnt_[number]);
        };
        ++freq_[++cnt_[number]];
    }
    
    void deleteOne(int number) {
        if (!cnt_.count(number)) {
            return;
        }
        if (--freq_[cnt_[number]] == 0) {
            freq_.erase(cnt_[number]);
        }
        ++freq_[--cnt_[number]];
        if (cnt_[number] == 0) {
            cnt_.erase(number);
        }
    }
    
    bool hasFrequency(int frequency) {
        return freq_.count(frequency);
    }

private:
    unordered_map<int, int> cnt_;
    unordered_map<int, int> freq_;
};
