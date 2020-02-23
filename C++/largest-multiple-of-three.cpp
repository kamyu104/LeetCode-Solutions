// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        static const unordered_map<int, vector<vector<int>>> lookup = {
            {0, {}},
            {1, {{1}, {4}, {7}, {2, 2}, {5, 2}, {5, 5}, {8, 2}, {8, 5}, {8, 8}}},
            {2, {{2}, {5}, {8}, {1, 1}, {4, 1}, {4, 4}, {7, 1}, {7, 4}, {7, 7}}}
        };
        unordered_map<int, int> count = counter(digits);
        const auto& r = accumulate(cbegin(digits), cend(digits), 0) % 3;
        for (const auto& deletes : lookup.at(r)) {
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
        const auto& delete_count = counter(deletes);
        if (all_of(cbegin(delete_count), cend(delete_count),
                   [&count](const auto& kvp) {
                       return (*count)[kvp.first] >= kvp.second;
                   })) {
            for (const auto& [k, v] : delete_count) {
                (*count)[k] -= v;
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
        const auto& r = accumulate(cbegin(digits), cend(digits), 0) % 3;
        if (r) {
            bool is_found = false;
            for (int i = 0; i < 10; ++i) {
                vector<int> deletes = {i};
                if (remove(deletes, r, &count)) {
                    is_found = true;
                    break;
                }
            }
            if (!is_found) {
                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j <= i; ++j) {
                        vector<int> deletes = {i, j};
                        if (remove(deletes, r, &count)) {
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
    bool remove(const vector<int>& deletes, int r, unordered_map<int, int> *count) {
        const auto& delete_count = counter(deletes);
        if (accumulate(cbegin(deletes), cend(deletes), 0) % 3 == r &&
            all_of(cbegin(delete_count), cend(delete_count),
                   [&count](const auto& kvp) {
                       return (*count)[kvp.first] >= kvp.second;
                   })) {
            for (const auto& [k, v] : delete_count) {
                (*count)[k] -= v;
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
