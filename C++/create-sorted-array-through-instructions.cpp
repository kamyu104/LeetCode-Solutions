// Time:  O(nlogm)
// Space: O(m)

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        static const int MOD = 1e9 + 7;
        BIT bit(*max_element(cbegin(instructions), cend(instructions)));
        int result = 0;
        for (int i = 0; i < size(instructions); ++i) {
            const auto inst = instructions[i] - 1;
            auto cost = min(bit.query(inst - 1), i - bit.query(inst));
            if (MOD - result <= cost) {
                cost -= MOD;
            }
            result += cost;
            bit.add(inst, 1);
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
// in fact, we could use a raw array instead of vector to avoid TLE
class Solution_TLE {
public:
    int createSortedArray(vector<int>& instructions) {
        static const int MOD = 1e9 + 7;
        vector<int> smaller_counts(size(instructions)), larger_counts(size(instructions));
        vector<pair<int, int>> smaller_idxs, larger_idxs;
        for (int i = 0; i < size(instructions); ++i) {
            smaller_idxs.emplace_back(instructions[i], i);
            larger_idxs.emplace_back(instructions[i], i);
        }
        smallerMergeSort(&smaller_idxs, 0, size(smaller_idxs) - 1, &smaller_counts);
        largerMergeSort(&larger_idxs, 0, size(larger_idxs) - 1, &larger_counts);
        int result = 0;
        for (int i = 0; i < size(instructions); ++i) {
            auto cost = min(smaller_counts[i], larger_counts[i]);
            if (MOD - result <= cost) {
                cost -= MOD;
            }
            result += cost;
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
            tmp.emplace_back((*idxs)[i]);
            (*counts)[(*idxs)[i].second] += r - start;
        }
        while (r <= mid) {
            tmp.emplace_back((*idxs)[r++]);
        }
        // Copy tmp back to num_idxs.
        copy(tmp.begin(), tmp.end(), idxs->begin() + start);
    }
    
    void largerMergeSort(vector<pair<int, int>> *idxs, int start, int end, vector<int> *counts) {
        if (end - start <= 0) {  // The number of range [start, end] of which size is less than 2 doesn't need sort.
            return;
        }
        int mid = start + (end - start) / 2;
        largerMergeSort(idxs, start, mid, counts);
        largerMergeSort(idxs, mid + 1, end, counts);

        int r = start;
        vector<pair<int, int>> tmp;
        for (int i = mid + 1; i <= end; ++i) {
            // Merge the two sorted arrays into tmp.
            while (r <= mid && (*idxs)[r].first <= (*idxs)[i].first) {
                tmp.emplace_back((*idxs)[r++]);
            }
            if (r <= mid) {
                tmp.emplace_back((*idxs)[i]);
            }
            (*counts)[(*idxs)[i].second] += mid - r + 1;
        }
        while (r <= mid) {
            tmp.emplace_back((*idxs)[r++]);
        }
        // Copy tmp back to num_idxs.
        copy(tmp.begin(), tmp.end(), idxs->begin() + start);
    }
};
