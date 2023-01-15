// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> cnts;
        for (const auto& c : s) {
            ++cnts[c];
        }
        vector<char> sorted_cnts;
        for (const auto& [c, v] : cnts) {
            sorted_cnts.emplace_back(c);
        }
        sort(begin(sorted_cnts), end(sorted_cnts), [&](const auto& a, const auto& b) {
            return cnts[a] > cnts[b];
        });
        const int bucket_cnt = cnts[sorted_cnts[0]];
        vector<string> buckets(bucket_cnt);
        int i = 0;
        for (const auto& c : sorted_cnts) {
            for (int _ = 0; _ < cnts[c]; ++_) {
                
                buckets[i].push_back(c);
                i = (i + 1) % max(cnts[c], bucket_cnt - 1);
                assert(i < size(buckets));
            }
        }
        string result;
        for (int i = 0; i < size(buckets) - 1; ++i) {
            if (buckets[i].length() < k) {
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
class Solution3 {
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
