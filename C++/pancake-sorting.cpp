// Time:  O(nlogn)
// Space: O(n)

// bit solution
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        BIT bit(size(arr));
        vector<int> result;
        for (int i = 0; i < size(arr); ++i) {
            int n = bit.query((arr[i] - 1) - 1);
            bit.add(arr[i] - 1, 1);
            if (n == i) {  // already sorted
                continue;
            }
            if (n == 0) {                    // (0..i-1)i
                if (i > 1) {
                    result.emplace_back(i);  // (i-1..0)i
                }
                result.emplace_back(i + 1);  // i(0..i-1)
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

// Time:  O(nlogn)
// Space: O(n)
// merge sort solution
class Solution2 {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> smaller_counts(size(arr));
        vector<pair<int, int>> smaller_idxs;
        for (int i = 0; i < size(arr); ++i) {
            smaller_idxs.emplace_back(arr[i], i);
        }
        smallerMergeSort(&smaller_idxs, 0, size(smaller_idxs) - 1, &smaller_counts);
        vector<int> result;
        for (int i = 0; i < size(smaller_counts); ++i) {
            const auto n = smaller_counts[i];
            if (n == i) {  // already sorted
                continue;
            }
            if (n == 0) {                    // (0..i-1)i
                if (i > 1) {
                    result.emplace_back(i);  // (i-1..0)i
                }
                result.emplace_back(i + 1);  // i(0..i-1)
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
    void smallerMergeSort(vector<pair<int, int>> *idxs, int start, int end, vector<int> *counts) {
        if (end - start <= 0) {  // The number of range [start, end] of which size is less than 2 doesn't need sort.
            return;
        }
        int mid = start + (end - start) / 2;
        smallerMergeSort(idxs, start, mid, counts);
        smallerMergeSort(idxs, mid + 1, end, counts);

        int r = start;
        vector<pair<int, int>> tmp;
        for (int i = mid + 1; i <= end; ++i) {
            // Merge the two sorted arrays into tmp.
            while (r <= mid && (*idxs)[r].first < (*idxs)[i].first) {
                tmp.emplace_back((*idxs)[r++]);
            }
            if (r <= mid) {
                tmp.emplace_back((*idxs)[i]);
            }
            (*counts)[(*idxs)[i].second] += r - start;
        }
        while (r <= mid) {
            tmp.emplace_back((*idxs)[r++]);
        }
        // Copy tmp back to num_idxs.
        copy(tmp.begin(), tmp.end(), idxs->begin() + start);
    }
};

// Time:  O(n^2)
// Space: O(1)
class Solution3 {
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
