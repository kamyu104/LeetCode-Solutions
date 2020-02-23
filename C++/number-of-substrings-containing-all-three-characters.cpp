// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int result = 0;
        vector<int> left(3, -1);
        for (int right = 0; right < s.length(); ++right) {
            left[s[right] - 'a'] = right;
            result += *min_element(cbegin(left), cend(left)) + 1;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int numberOfSubstrings(string s) {
        int result = 0, left = 0;
        vector<int> count(3);
        for (int right = 0; right < s.length(); ++right) {
            ++count[s[right] - 'a'];
            while (all_of(cbegin(count), cend(count),
                          [](const auto& x) {
                              return x != 0;
                          })) {
                --count[s[left++] - 'a'];
            }
            result += left;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution3 {
public:
    int numberOfSubstrings(string s) {
        int result = 0, right = 0;
        vector<int> count(3);
        for (int left = 0; left < s.length(); ++left) {
            while (right < s.length() &&
                   !all_of(cbegin(count), cend(count),
                           [](const auto& x) {
                              return x != 0;
                           })) {
                ++count[s[right++] - 'a'];
            }
            if (all_of(cbegin(count), cend(count),
                       [](const auto& x) {
                          return x != 0;
                       })) {
                result += (s.length() - 1) - (right - 1) + 1;
            }
            --count[s[left] - 'a'];
        }
        return result;
    }
};
