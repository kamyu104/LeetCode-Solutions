// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string rearrangeString(string str, int k) {
        int cnts [26] = {0};
        for (int i = 0;  i < str.length(); ++i) {
            ++cnts[str[i] - 'a'];
        }
        vector<pair<int, char>> sorted_cnts;
        for (int i = 0; i < 26; ++i) {
            sorted_cnts.emplace_back(cnts[i], i + 'a');
        }
        sort(sorted_cnts.begin(), sorted_cnts.end(), greater<pair<int, int>>());

        string blocks[sorted_cnts.cbegin()->first];
        int i = 0;
        for (auto it = sorted_cnts.cbegin(); it != sorted_cnts.cend(); ++it) {
            for (int cnt = 0; cnt < it->first; ++cnt) {
                blocks[i].push_back(it->second);
                i = (i + 1) % max(it->first, sorted_cnts.cbegin()->first - 1);
            }
        }

        string result;
        for (int i = 0; i < sorted_cnts.cbegin()->first - 1; ++i) {
            if (blocks[i].size() < k) {
                return "";
            } else {
                result += blocks[i];
            }
        }
        result += blocks[sorted_cnts.cbegin()->first - 1];
        return result;
    }
};

// Time:  O(nlogc), c is the count of unique characters.
// Space: O(c)
class Solution2 {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) {
            return str;
        }

        unordered_map<char, int> cnts;
        for (const auto& c : str) {
            ++cnts[c];
        }

        priority_queue<pair<int, char>> heap;
        for (const auto& kvp : cnts) {
            heap.emplace(kvp.second, kvp.first);
        }

        string result;
        while (!heap.empty()) {
            vector<pair<int, char>> used_cnt_chars;
            int cnt = min(k, static_cast<int>(str.length() - result.length()));
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
