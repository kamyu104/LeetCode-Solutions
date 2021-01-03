// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string lastSubstring(string s) {
        int left = 0, right = 1, l = 0;
        while (right + l < size(s)) {
            if (s[left + l] == s[right + l]) {
                ++l;
                continue;
            }
            if (s[left + l] > s[right + l]) {
                right += l + 1;
            } else {
                left = max(right, left + l + 1);
                right = left + 1;
            }
            l = 0;
        }
        return s.substr(left);
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    string lastSubstring(string s) {
        unordered_map<char, vector<size_t>> count;
        for (size_t i = 0; i < s.length(); ++i) {
            count[s[i]].emplace_back(i);
        }

        const auto& max_c = max_element(count.cbegin(), count.cend(),
                                        [](const auto& a, const auto& b) {
                                            return a.first < b.first;
                                        })->first;
        unordered_map<int, int> starts;
        for (const auto& i : count[max_c]) {
            starts[i] = i + 1;
        }
        while (starts.size() > 1) {
            unordered_set<int> lookup;
            unordered_map<char, vector<int>> next_count;
            for (const auto& [start, end] : starts) {
                if (end == s.length())  {  // finished
                    lookup.emplace(start);
                    continue;
                }
                next_count[s[end]].emplace_back(start);			
                if (starts.count(end)) {  // overlapped
                    lookup.emplace(end);
                }
            }
            unordered_map<int, int> next_starts;
            const auto& max_c = max_element(next_count.cbegin(), next_count.cend(),
                                            [](const auto& a, const auto& b) {
                                                return a.first < b.first;
                                            })->first;
            for (const auto& start : next_count[max_c]) {
                if (!lookup.count(start)) {
                    next_starts[start] = starts[start] + 1;
                }
            }
            starts = move(next_starts);
        }
        return s.substr(starts.cbegin()->first);
    }
};
