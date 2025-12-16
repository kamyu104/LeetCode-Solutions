// Time:  O((n + q) * logn)
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

private:
    inline int lower_bit(int i) const {
        return i & -i;
    }
    
    vector<int> bit_;
};

class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        BIT bit(size(s) - 1);
        for (int i = 0; i + 1 < size(s); ++i) {
            if (s[i] == s[i + 1]) {
                bit.add(i, 1);
            }
        }
        vector<int> result;
        for (const auto& q : queries) {
            if (size(q) == 3) {
                result.emplace_back(bit.query(q[2] - 1) - bit.query(q[1] - 1));
                continue;
            }
            const auto& i = q[1];
            s[i] = (s[i] == 'A') ? 'B' : 'A';
            if (i - 1 >= 0) {
                bit.add(i - 1, (s[i - 1] == s[i]) ? 1 : -1);
            }
            if (i + 1 < size(s)) {
                bit.add(i, (s[i] == s[i + 1]) ? 1 : -1);
            }
        }
        return result;
    }
};
