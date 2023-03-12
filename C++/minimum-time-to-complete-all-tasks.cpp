// Time:  O(nlogn + nlogr), r = max(e for _, e in tasks)
// Space: O(r)

// sort, greedy, bit, fenwick tree
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks), [](const auto& x, const auto& y) {
            return x[1] < y[1];
        });
        BIT bit(tasks.back()[1] + 1);
        for (const auto& t : tasks) {
            int s = t[0], e = t[1], d = t[2];
            d -= bit.query(e) - bit.query(s - 1);
            for (int i = e; d > 0; --i) {
                if (bit.query(i) - bit.query(i - 1)) {
                    continue;
                }
                bit.add(i, 1);
                --d;
            }
        }
        return bit.query(tasks.back()[1]);
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
