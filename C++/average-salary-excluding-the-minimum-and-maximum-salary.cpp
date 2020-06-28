// Time:  O(n)
// Space: O(1)

// one-pass solution
class Solution {
public:
    double average(vector<int>& salary) {
        int total = 0;
        int mi = numeric_limits<int>::max(), ma = numeric_limits<int>::min();
        for (const auto& s : salary) {
            total += s;
            mi = min(mi, s), ma = max(ma, s);
        }
        return double(total - mi - ma) / (salary.size() - 2);
    }
};

// Time:  O(n)
// Space: O(1)
// one-liner solution
class Solution2 {
public:
    double average(vector<int>& salary) {
        return (accumulate(cbegin(salary), cend(salary), 0.0) - 
                *min_element(cbegin(salary), cend(salary)) -
                *max_element(cbegin(salary), cend(salary)))
               / (salary.size() - 2);
    }
};
