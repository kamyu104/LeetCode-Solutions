// Time:  O(nlogn)
// Space: O(n)

class BIT {  // Fenwick Tree, 1-indexed
public:
    BIT(int n) : bit_(n) {
        
    }

    void add(int i, int val) {
        for (; i < bit_.size(); i += lower_bit(i)) {
            bit_[i] += val;
        }
    }
    
    int sum(int i) {
        int sum = 0;
        for (; i > 0; i -= lower_bit(i)) {
            sum += bit_[i];
        }
        return sum;
    }

    inline int lower_bit(int i) {
        return i & -i;
    }

private:
    vector<int> bit_;
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        BIT bit(2 * m + 1);
        unordered_map<int, int> lookup;
        for (int i = 1; i <= m; ++i) {
            lookup[i] = m + i;
            bit.add(m + i, 1);
        }
        vector<int> result;
        int curr = m;
        for (const auto& q : queries) {
            auto i = lookup[q]; lookup.erase(q);
            result.emplace_back(bit.sum(i - 1));
            bit.add(i, -1);
            lookup[q] = curr;
            bit.add(curr--, 1);
        }
        return result;
    }
};
