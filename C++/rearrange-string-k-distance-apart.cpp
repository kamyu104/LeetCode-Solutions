// Time:  O(n)
// Space: O(c)

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (!k) {
            return s;
        }
        unordered_map<char, int> cnts;
        for (const auto& c : s) {
            ++cnts[c];
        }
        const int bucket_cnt = max_element(cbegin(cnts), cend(cnts), [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;
        if (!((bucket_cnt - 1) * k + count_if(cbegin(cnts), cend(cnts), [&](const auto& x) { return x.second == bucket_cnt; }) <= size(s))) {
            return "";
        }
        vector<char> partial_sorted_cnts;
        for (const auto& [c, v] : cnts) {
            if (v == bucket_cnt) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        for (const auto& [c, v] : cnts) {
            if (v != bucket_cnt) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        string result(size(s), 0);
        int i = (size(s) - 1) % k;
        for (const auto& c : partial_sorted_cnts) {
            for (int _ = 0; _ < cnts[c]; ++_) {
                result[i] = c;
                i += k;
                if (i >= size(result)) {
                    i = (i - 1) % k;
                }
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(c)
// reference: https://codeforces.com/blog/entry/110184 1774B - Coloring
class Solution2 {
public:
    string rearrangeString(string s, int k) {
        if (!k) {
            return s;
        }
        unordered_map<char, int> cnts;
        for (const auto& c : s) {
            ++cnts[c];
        }
        const int bucket_cnt = (size(s) + k - 1) / k;
        const int mx = max_element(cbegin(cnts), cend(cnts), [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;
        if (!(mx <= bucket_cnt && count_if(cbegin(cnts), cend(cnts), [&](const auto& x) { return x.second == bucket_cnt; }) <= (size(s) - 1) % k + 1)) {
            return "";
        }
        vector<char> partial_sorted_cnts;
        for (const auto& [c, v] : cnts) {
            if (v == bucket_cnt) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        for (const auto& [c, v] : cnts) {
            if (v <= bucket_cnt - 2) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        for (const auto& [c, v] : cnts) {
            if (v == bucket_cnt - 1) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        string result(size(s), 0);
        int i = 0;
        for (const auto& c : partial_sorted_cnts) {
            for (int _ = 0; _ < cnts[c]; ++_) {
                result[i] = c;
                i += k;
                if (i >= size(result)) {
                    i = i % k + 1;
                }
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution3 {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> cnts;
        for (const auto& c : s) {
            ++cnts[c];
        }
        const int bucket_cnt = max_element(cbegin(cnts), cend(cnts), [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;
        vector<char> partial_sorted_cnts;
        for (const auto& [c, v] : cnts) {
            if (v == bucket_cnt) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        for (const auto& [c, v] : cnts) {
            if (v == bucket_cnt - 1) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        for (const auto& [c, v] : cnts) {
            if (v <= bucket_cnt - 2) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        vector<string> buckets(bucket_cnt);
        int i = 0;
        for (const auto& c : partial_sorted_cnts) {
            for (int _ = 0; _ < cnts[c]; ++_) {
                buckets[i].push_back(c);
                i = (i + 1) % max(cnts[c], bucket_cnt - 1);
            }
        }
        string result;
        for (int i = 0; i < size(buckets) - 1; ++i) {
            if (size(buckets[i]) < k) {
                return "";
            } else {
                result += buckets[i];
            }
        }
        result += buckets[bucket_cnt - 1];
        return result;
    }
};

// Time:  O(nlogc), c is the count of unique characters.
// Space: O(c)
class Solution4 {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) {
            return s;
        }

        unordered_map<char, int> cnts;
        for (const auto& c : s) {
            ++cnts[c];
        }

        priority_queue<pair<int, char>> heap;
        for (const auto& kvp : cnts) {
            heap.emplace(kvp.second, kvp.first);
        }

        string result;
        while (!heap.empty()) {
            vector<pair<int, char>> used_cnt_chars;
            int cnt = min(k, static_cast<int>(s.length() - result.length()));
            for (int i = 0; i < cnt; ++i) {
                if (heap.empty()) {
                    return "";
                }
                auto cnt_char = heap.top();
                heap.pop();
                result.push_back(cnt_char.second);
                if (--cnt_char.first > 0) {
                    used_cnt_chars.emplace_back(move(cnt_char));
                }
            }
            for (auto& cnt_char: used_cnt_chars) {
                heap.emplace(move(cnt_char));
            }
        }
        return result;
    }
};
