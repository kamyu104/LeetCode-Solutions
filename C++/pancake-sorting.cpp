// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        BIT bit(size(arr));
        vector<int> result;
        for (int i = 0; i < size(arr); ++i) {
            int n = bit.query((arr[i] - 1) - 1);
            bit.add(arr[i] - 1, 1);
            if (n == i) {
                continue;
            }
            if (n == 0) {                    // (0..n-1)i
                if (i > 1) {
                    result.emplace_back(i);  // (n-1..0)i
                }
                result.emplace_back(i + 1);  // i(0..n-1)
            } else {                         // (0..n-1)n(n+1..i-1)i
                if (n > 1) {
                    result.emplace_back(n);  // (n-1..0)n(n+1..i-1)i
                }
                result.emplace_back(i);      // (i-1..n+1)n(0..n-1)i
                result.emplace_back(i + 1);  // i(n-1..0)n(n+1..i-1)
                result.emplace_back(n + 1);  // (0..n-1)in(n+1..i-1)
            }
        }
        return result;
    }

private:
    class BIT {
    public:
        BIT(int n) : bit_(n + 1) {  // 0-indexed
        }
        
        void add(int i, int val) {
            ++i;
            for (; i < size(bit_); i += lower_bit(i)) {
                bit_[i] += val;
            }
        }

        int query(int i) const {
            ++i;
            int total = 0;
            for (; i > 0; i -= lower_bit(i)) {
                total += bit_[i];
            }
            return total;
        }
    
    private:
        int lower_bit(int i) const {
            return i & -i;
        }
        
        vector<int> bit_;
    };
};

// Time:  O(n^2)
// Space: O(1)
class Solution2 {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        for (int n = A.size(); n > 0; --n) {
            int i;
            for (i = 0; A[i] != n; ++i);
            reverse(A.begin(), A.begin() + i + 1);
            result.emplace_back(i + 1);
            reverse(A.begin(), A.begin() + n);
            result.emplace_back(n);
        }
        return result;
    }
};
