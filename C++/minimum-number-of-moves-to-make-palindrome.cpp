// Time:  O(nlogn)
// Space: O(n)

// greedy, bit, fenwick tree
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        vector<vector<int>> idxs(26);
        for (int i = 0; i < size(s); ++i) {
            idxs[s[i] - 'a'].emplace_back(i);
        }
        vector<pair<int, int>> pairs;
        vector<int> targets(size(s));
        for (const auto& idx : idxs) {
            for (int i = 0; i < size(idx) / 2; ++i) {
                pairs.emplace_back(idx[i], idx[(size(idx) - 1) - i]);
            }
            if (size(idx) % 2) {
                targets[idx[size(idx) / 2]] = size(s) / 2;
            }
        }
        sort(begin(pairs), end(pairs));
        for (int i = 0; i < size(pairs); ++i) {
            targets[pairs[i].first] = i;
            targets[pairs[i].second] = (size(s) - 1) - i;
        }
        BIT bit(size(s));
        int result = 0;
        for (const auto& i : targets) {
            result += i - bit.query(i - 1);  // move from bit.query(i-1) to i
            bit.add(i, 1);
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
// Space: O(n)
// greedy
class Solution2 {
public:
    int minMovesToMakePalindrome(string s) {
        int result = 0;
        while (!empty(s)) {
            const int i = s.find(s.back());
            if (i == size(s) - 1) {
                result += i / 2;
            } else {
                result += i;
                s.erase(i, 1);
            }
            s.pop_back();
        }
        return result;
    }
};
