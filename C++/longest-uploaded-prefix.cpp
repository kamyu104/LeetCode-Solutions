// Time:  ctor:    O(1)
//        upload:  O(1), amortized
//        longest: O(1)
// Space: O(n)

// hash table
class LUPrefix {
public:
    LUPrefix(int n) {
        
    }
    
    void upload(int video) {
        lookup_.emplace(video - 1);
        while (lookup_.count(curr_)) {
            lookup_.erase(curr_++);
        }
    }
    
    int longest() {
        return curr_;
    }

private:
    unordered_set<int> lookup_;
    int curr_ = 0;
};
