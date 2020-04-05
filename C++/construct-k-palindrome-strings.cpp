// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canConstruct(string s, int k) {
        bitset<26> odd;
        for (const auto& c : s) {
            odd.flip(c - 'a');
        }
        return odd.count() <= k && k <= s.length();
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    bool canConstruct(string s, int k) {
        const auto& count = counter(s);
        const auto& odd = accumulate(cbegin(count), cend(count), 0,
                              [](const auto& a, const auto& b) {
                                  return a + b.second % 2;
                          });
        return odd <= k && k <= s.length();
    }

private:
	unordered_map<int, int> counter(const string& word) {
        unordered_map<int, int> count;
        for (const auto& c : word) {
            ++count[c];
        }
        return count;
    }
};
