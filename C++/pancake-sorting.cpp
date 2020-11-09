// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        BIT bit(size(arr));
        vector<int> result;
        bit.add(arr[0] - 1, 1);
        for (int i = 1; i < size(arr); bit.add(arr[i++] - 1, 1)) {
            int count = bit.query((arr[i] - 1) - 1);
            if (count  >= i) {
                continue;
            }
            if (count == 0) {
                if (i > 1) {
                    result.emplace_back(i);
                }
                result.emplace_back(i + 1);
            } else {
                if (count > 1){
                    result.emplace_back(count);
                }
                result.emplace_back(i);
                result.emplace_back(i + 1);
                result.emplace_back(count + 1);
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
