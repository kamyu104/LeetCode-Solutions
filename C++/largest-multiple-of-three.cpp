// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        static const unordered_map<int, vector<vector<int>>> lookup = {
            {0, {}},
            {1, {{1}, {4}, {7}, {2, 2}, {2, 5}, {5, 5}, {2, 8}, {5, 8}, {8, 8}}},
            {2, {{2}, {5}, {8}, {1, 1}, {1, 4}, {4, 4}, {1, 7}, {4, 7}, {7, 7}}}
        };
        unordered_map<int, int> count = counter(digits);
        const auto& total = accumulate(cbegin(digits), cend(digits), 0);
        for (const auto& deletes : lookup.at(total % 3)) {
            if (remove(deletes, &count)) {
                break;
            }
        }
        string result;
        for (int d = 9; d >= 0; --d) {
            result += string(count[d], '0' + d);
        }
        return !result.empty() && result[0] == '0' ? "0" : result;
    }

private:
    bool remove(const vector<int>& deletes, unordered_map<int, int> *count) {
        if (all_of(cbegin(deletes), cend(deletes),
                   [&count, &deletes](const auto& x) {
                       return (*count)[x] >= std::count(cbegin(deletes), cend(deletes), x);
                   })) {
            for (const auto& d : deletes) {
                --(*count)[d];
            }
            return true;
        }
        return false;
    }
    
    unordered_map<int, int> counter(const vector<int> & digits) {
        unordered_map<int, int> result;
        for (const auto& i : digits) {
            ++result[i];
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        unordered_map<int, int> count = counter(digits);
        const auto& total = accumulate(cbegin(digits), cend(digits), 0);
        if (total % 3) {
            bool is_found = false;
            for (int i = 0; i < 10; ++i) {
                vector<int> deletes = {i};
                if (remove(deletes, total, &count)) {
                    is_found = true;
                    break;
                }
            }
            if (!is_found) {
                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j <= i; ++j) {
                        vector<int> deletes = {i, j};
                        if (remove(deletes, total, &count)) {
                            break;
                        }
                    }
                }
            }
        }
        string result;
        for (int d = 9; d >= 0; --d) {
            result += string(count[d], '0' + d);
        }
        return !result.empty() && result[0] == '0' ? "0" : result;
    }

private:
    bool remove(const vector<int>& deletes, int total, unordered_map<int, int> *count) {
        if (accumulate(cbegin(deletes), cend(deletes), 0) % 3 == total % 3 &&
            all_of(cbegin(deletes), cend(deletes),
                   [&count, &deletes](const auto& x) {
                       return (*count)[x] >= std::count(cbegin(deletes), cend(deletes), x);
                   })) {
            for (const auto& d : deletes) {
                --(*count)[d];
            }
            return true;
        }
        return false;
    }
    
    unordered_map<int, int> counter(const vector<int> & digits) {
        unordered_map<int, int> result;
        for (const auto& i : digits) {
            ++result[i];
        }
        return result;
    }
};
