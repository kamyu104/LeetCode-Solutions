// Time:  O(1) ~ O(n), n is 10^3
// Space: O(1)

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10);
        for (const auto& d : digits) {
            ++cnt[d];
        }
        vector<int> result, curr;
        backtracking(&curr, &cnt, &result);
        return result;
    }

private:
    void backtracking(vector<int> *curr, vector<int> *cnt, vector<int> *result) {
        static const int k = 3;
        if (size(*curr) == k) {
            result->emplace_back(accumulate(cbegin(*curr), cend(*curr), 0,
                                            [](const auto& total, const auto& x) {
                                                return total * 10 + x;
                                            }));
            return;
        }
        for (int i = 0; i < size(*cnt); ++i) {
            if ((*cnt)[i] == 0 ||
                (empty(*curr) && (i == 0)) ||
                (size(*curr) == k - 1 && i % 2 != 0)) {
                continue;
            }
            --(*cnt)[i];
            curr->emplace_back(i);
            backtracking(curr, cnt, result);
            curr->pop_back();
            ++(*cnt)[i];
        }
    }
};

// Time:  O(n), n is 10^3
// Space: O(1)
class Solution2 {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> cnt;
        for (const auto& d : digits) {
            ++cnt[d];
        }
        vector<int> result;
        for (int i = 1; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; k += 2) {
                    if (cnt[i] > 0 && cnt[j] > (i == j) && cnt[k] > (i == k) + (j == k)) {
                        result.emplace_back(100 * i + 10 * j + k);
                    }
                }
            }
        }
        return result;
    }
};

// Time:  O(1) ~ O(n), n is 10^3
// Space: O(1)
class Solution3 {
private:
    struct Node {
        int digit, cnt, left, right;
        Node(int digit, int cnt, int left, int right) : digit(digit), cnt(cnt), left(left), right(right) {}
    };

public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> cnt;
        for (const auto& d : digits) {
            ++cnt[d];
        }
        vector<pair<int, int>> digit_cnt;
        for (const auto& [d, c] : cnt) {
            digit_cnt.emplace_back(d, c);
        }
        sort(begin(digit_cnt), end(digit_cnt));
        vector<Node> digit_cnt_list;
        int i = 0;
        digit_cnt_list.emplace_back(0, 0, i - 1, i + 1);
        ++i;
        for (const auto& [d, c] : digit_cnt) {
            digit_cnt_list.emplace_back(d, c, i - 1, i + 1);
            ++i;
        }
        vector<int> result, curr;
        backtracking(&curr, &digit_cnt_list, &result);
        return result;
    }

private:
    void backtracking(vector<int> *curr, vector<Node> *digit_cnt_list, vector<int> *result) {
        static const int k = 3;
        if (size(*curr) == k) {
            result->emplace_back(accumulate(cbegin(*curr), cend(*curr), 0,
                                            [](const auto& total, const auto& x) {
                                                return total * 10 + x;
                                            }));
            return;
        }
        for (int i = (*digit_cnt_list)[0].right; i != size(*digit_cnt_list); i = (*digit_cnt_list)[i].right) {
            if ((empty(*curr) && (*digit_cnt_list)[i].digit == 0) ||
                (size(*curr) == k - 1 && (*digit_cnt_list)[i].digit % 2 != 0)) {
                continue;
            }
            --(*digit_cnt_list)[i].cnt;
            curr->emplace_back((*digit_cnt_list)[i].digit);
            if ((*digit_cnt_list)[i].cnt == 0) {
                if ((*digit_cnt_list)[i].left >= 0) {
                    (*digit_cnt_list)[(*digit_cnt_list)[i].left].right = (*digit_cnt_list)[i].right;
                }
                if ((*digit_cnt_list)[i].right < size(*digit_cnt_list)) {
                    (*digit_cnt_list)[(*digit_cnt_list)[i].right].left = (*digit_cnt_list)[i].left;
                }
            }
            backtracking(curr, digit_cnt_list, result);
            curr->pop_back();
            if ((*digit_cnt_list)[i].cnt == 0) {
                if ((*digit_cnt_list)[i].left >= 0) {
                    (*digit_cnt_list)[(*digit_cnt_list)[i].left].right = i;
                }
                if ((*digit_cnt_list)[i].right < size(*digit_cnt_list)) {
                    (*digit_cnt_list)[(*digit_cnt_list)[i].right].left = i;
                }
            }
            ++(*digit_cnt_list)[i].cnt;
        }
    }
};

// Time:  O(1) ~ O(nlogn), n is 10^3
// Space: O(1)
class Solution4 {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> cnt;
        for (const auto& d : digits) {
            ++cnt[d];
        }
        vector<pair<int, int>> digit_cnt;
        for (const auto& [d, c] : cnt) {
            digit_cnt.emplace_back(d, c);
        }
        vector<int> result, curr;
        backtracking(&curr, &digit_cnt, &result);
        sort(begin(result), end(result));
        return result;
    }

private:
    void backtracking(vector<int> *curr, vector<pair<int, int>> *digit_cnt, vector<int> *result) {
        static const int k = 3;
        if (size(*curr) == k) {
            result->emplace_back(accumulate(cbegin(*curr), cend(*curr), 0,
                                            [](const auto& total, const auto& x) {
                                                return total * 10 + x;
                                            }));
            return;
        }
        for (int i = 0; i < size(*digit_cnt); ++i) {
            if ((empty(*curr) && (*digit_cnt)[i].first == 0) ||
                (size(*curr) == k - 1 && (*digit_cnt)[i].first % 2 != 0)) {
                continue;
            }
            --(*digit_cnt)[i].second;
            swap((*digit_cnt)[i], (*digit_cnt).back());
            auto [digit, cnt] = (*digit_cnt).back();
            curr->emplace_back(digit);
            if (cnt == 0) {
                digit_cnt->pop_back();
            }
            backtracking(curr, digit_cnt, result);
            curr->pop_back();
            if (cnt == 0) {
                digit_cnt->emplace_back(digit, cnt);
            }
            swap((*digit_cnt)[i], (*digit_cnt).back());
            ++(*digit_cnt)[i].second;
        }
    }
};
