// Time:  O(nlogn)
// Space: O(n)

// sort, fenwick tree, hash table
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

class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        vector<pair<int, int>> points;
        for (int i = 0; i < size(xCoord); ++i) {
            points.emplace_back(xCoord[i], yCoord[i]);
        }
        sort(begin(points), end(points));
        set<int> sorted_ys;
        for (const auto& [_, y] : points) {
            sorted_ys.emplace(y);
        }
        unordered_map<int, int> y_to_idx;
        for (const auto& y : sorted_ys) {
            y_to_idx[y] = size(y_to_idx);
        }
        BIT bit(size(y_to_idx));
        unordered_map<int, unordered_map<int, pair<int, int>>> lookup;
        int64_t result = -1;
        int prev_x = -1, prev_y = -1;
        for (const auto& [x, y] : points) {
            const int y_idx = y_to_idx[y];
            bit.add(y_idx, +1);
            if (x == prev_x) {
                const int prev_y_idx = y_to_idx[prev_y];
                const int curr = bit.query(y_idx) - bit.query(prev_y_idx - 1);
                const auto [prev, prev_x2] = lookup[prev_y_idx][y_idx];
                if (prev && prev == curr - 2) {
                    result = max(result, static_cast<int64_t>(x - prev_x2) * (y - prev_y));
                }
                lookup[prev_y_idx][y_idx] = pair(curr, x);
            }
            prev_x = x, prev_y = y;
        }
        return result;
    }
};
