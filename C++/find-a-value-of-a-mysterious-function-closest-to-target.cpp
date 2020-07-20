// Time:  O(nlogm), m is the max value of arr
// Space: O(logm)

class Solution {
public:
    int closestToTarget(std::vector<int>& arr, int target) {
        static const int LOGM = 20;
        BitCount count(LOGM);
        int result = numeric_limits<int>::max();
        for (int left = 0, right = 0; right < arr.size(); ++right) {
            count += arr[right];
            while (left <= right) {
                const auto& f = count.bitAnd();
                result = min(result, abs(f - target));
                if (f >= target) {
                    break;
                }
                count -= arr[left++];
            }
        }
        return result;
    }

private:
    class BitCount {
    public:
        BitCount(int n)
          : l_(0)
          , n_(n)
          , count_(n) {
            
        }

        int bitAnd() const {
            int num = 0;
            for (int i = 0; i < n_; ++i) {
                if (count_[i] == l_) {
                    num |= 1 << i;
                }
            }
            return num;
        }

        void operator+=(int num) {
            ++l_;
            for (int i = 0; i < n_; ++i) {
                if (num & (1 << i)) {
                    ++count_[i];
                }
            }
        }
        
        void operator-=(int num) {
            --l_;
            for (int i = 0; i < n_; ++i) {
                if (num & (1 << i)) {
                    --count_[i];
                }
            }
        }

    private:
        int l_;
        int n_;
        vector<int> count_;
    };
};

// Time:  O(nlogm), m is the max value of arr
// Space: O(logm)
class Solution2 {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int result = numeric_limits<int>::max();
        unordered_set<int> dp;  // at most O(logm) dp states
        for (const auto& x : arr) {
            unordered_set<int> new_dp = {x};
            for (const auto& f: dp) {
                new_dp.emplace(f & x);
            }
            for (const auto& f : new_dp) {
                result = min(result, abs(f - target));
            }
            dp = move(new_dp);
        }
        return result;
    }
};
