// Time:  ctor:     O(n)
//        fix:      O(1)
//        unfix:    O(1)
//        flip:     O(1)
//        all:      O(1)
//        one:      O(1)
//        count:    O(1)
//        toString: O(n)
// Space: O(n)

// design
class Bitset {
public:
    Bitset(int size)
      : lookup_(size) {
        
    }
    
    void fix(int idx) {
        if (lookup_[idx] == flip_) {
            lookup_[idx] = !lookup_[idx];
            ++cnt_;
        }
    }
    
    void unfix(int idx) {
         if (lookup_[idx] != flip_) {
            lookup_[idx] = !lookup_[idx];
            --cnt_;
        }
    }
    
    void flip() {
        flip_ = !flip_;
        cnt_ = size(lookup_) - cnt_;
    }
    
    bool all() {
        return cnt_ == size(lookup_);
    }
    
    bool one() {
        return cnt_ >= 1;
    }
    
    int count() {
        return cnt_;
    }
    
    string toString() {
        string result(size(lookup_), '0');
        for (int i = 0; i < size(result); ++i) {
            result[i] = (lookup_[i] != flip_) ? '1' : '0';
        }
        return result;
    }

private:
    vector<bool> lookup_;
    bool flip_ = false;
    int cnt_ = 0;
};
