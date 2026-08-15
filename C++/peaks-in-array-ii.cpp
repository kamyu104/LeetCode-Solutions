// Time:  O(nlogn + qlogn)
// Space: O(n)

// fenwick tree
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

    int kth_element(int k) const {
        int total = 0;
        int pos = 0;
        for (int i = floor_log2_x(size(bit_) - 1); i >= 0; --i) {
            if (pos + (1 << i) < size(bit_) && !(total + bit_[pos + (1 << i)] >= k)) {
                total += bit_[pos + (1 << i)];
                pos += (1 << i);
            }
        }
        return (pos + 1) - 1;
    }

private:
    int lower_bit(int i) const {
        return i & -i;
    }

    int floor_log2_x(int x) const {
        return bit_width(static_cast<uint32_t>(x)) - 1;
    };

    vector<int> bit_;
};

class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        const auto& count = [](long long x) {
            return x * (x - 1) / 2;
        };

        BIT bit(size(nums));
        BIT bit2(size(nums));
        vector<int> lookup(size(nums));
        const auto& update = [&](int i) {
            if (!(0 < i && i < size(nums) - 1)) {
                return;
            }
            const int x = (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) ? 1 : 0;
            if (lookup[i] == x) {
                return;
            }
            const auto& d = x - lookup[i];
            lookup[i] = x;
            bit.add(i, d);
            const int j = bit.kth_element(bit.query(i - 1));
            if (j >= 0) {
                bit2.add(j, d * count(i - j));
            }
            const int k = bit.kth_element(bit.query(i) + 1);
            if (k < size(nums)) {
                bit2.add(i, d * count(k - i));
            }
            if (j >= 0 && k < size(nums)) {
                bit2.add(j, -d * count(k - j));
            }
        };

        int prev = -1;
        for (int i = 1; i + 1 < size(nums); ++i) {
            if (!(nums[i - 1] < nums[i] && nums[i] > nums[i + 1])) {
                continue;
            }
            lookup[i] = 1;
            bit.add(i, 1);
            if (prev >= 0) {
                bit2.add(prev, count(i - prev));
            }
            prev = i;
        }
        vector<long long> result;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                const auto& l = q[1], &r = q[2];
                const auto& base = bit.query(l);
                const auto& cnt = bit.query(r - 1) - base;
                if (cnt == 0) {
                    result.emplace_back(0);
                    continue;
                }
                const auto& left = bit.kth_element(base + 1);
                const auto& right = bit.kth_element(base + cnt);
                result.emplace_back(count(r - l) - (count(left - l) + (bit2.query(right - 1) - bit2.query(left - 1)) + count(r - right)));
            } else {
                nums[q[1]] = q[2];
                for (int i = q[1] - 1; i <= q[1] + 1; ++i) {
                    update(i);
                }
            }
        }
        return result;
    }
};
