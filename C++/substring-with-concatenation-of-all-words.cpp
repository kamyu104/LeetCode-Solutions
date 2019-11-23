// Time:  O((m + n) * k), m is the length of the string,
//                        n is the size of the dictionary,
//                        k is the length of each word
// Space: O(n * k)

// Sliding window solution.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        
        vector<int> result;
        const int m = s.length(), n = words.size(), k = words.front().length();
        if (m < n * k) {
            return result;
        }

        unordered_map<string, int> lookup;
        for (const auto& word : words) {
            ++lookup[word];                        // Space: O(n * k)
        }
        for (int i = 0; i < k; ++i) {              // Time:  O(k)
            unordered_map<string, int> tmp;
            for (int j = i, left = i, count = 0; j <= m - k; j += k) {  // Time:  O(m / k)
                const auto& str = s.substr(j, k);  // Time:  O(k)
                if (lookup.count(str)) {
                    ++tmp[str];
                    ++count;
                    while (tmp[str] > lookup[str]) {
                        --tmp[s.substr(left, k)];
                        --count;
                        left += k;
                    }
                    if (count == n) {
                        result.emplace_back(left);
                    }
                } else {
                    tmp.clear();
                    count = 0;
                    left = j + k;
                }
            }
        }
        return result;
    }
};


// Time:  O((m - n * k) * n * k) ~ O(m * n * k), m is the length of the string,
//                                               n is the size of the dictionary,
//                                               k is the length of each word
// Space: O(n * k)
class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const auto word_length = words.front().length();
        const auto cat_length = word_length * words.size();
        vector<int> result;

        if (s.length() < cat_length) {
            return result;
        }

        unordered_map<string, int> wordCount;
        for (const auto & word : words) {
            ++wordCount[word];
        }

        for (auto it = s.begin(); it != prev(s.end(), cat_length - 1); ++it) {
            unordered_map<string, int> unused(wordCount);
            for (auto jt = it; jt != next(it, cat_length); jt += word_length) {
                auto pos = unused.find(string(jt, next(jt, word_length)));
                if (pos == unused.end()) {
                    break;
                }
                if (--pos->second == 0) {
                    unused.erase(pos);
                }
            }
            if (unused.empty()) {
                result.emplace_back(distance(s.begin(), it));
            }
        }
        return result;
    }
};
