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
    string minInteger(string num, int k) {
        unordered_map<int, vector<int>> lookup;
        BIT bit(num.length() + 1);
        for (int i = num.length() - 1; i >= 0; --i) {
            lookup[num[i] - '0'].emplace_back(i + 1);
            bit.add(i + 1, 1);
        }
        string result;
        for (int i = 0; i < num.length(); ++i) {
            for (int d = 0; d <= 9; ++d) {
                if (!lookup[d].empty() && bit.sum(lookup[d].back() - 1) <= k) {
                    k -= bit.sum(lookup[d].back() - 1);
                    bit.add(lookup[d].back(), -1);
                    lookup[d].pop_back();
                    result.push_back('0' + d);
                    break;
                }
            }
        }
        return result;
    }
};
