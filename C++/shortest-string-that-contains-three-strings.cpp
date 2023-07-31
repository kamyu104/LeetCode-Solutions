// Time:  O(l^2)
// Space: O(l)

// brute force
class Solution {
public:
    string minimumString(string a, string b, string c) {
        const auto& merge = [](const auto& a, const auto& b) {
            if (b.find(a) != string::npos) {
                return b;
            }
            int l = min(size(a), size(b));
            for (; l >= 0; --l) {
                int i = (size(a) - l), j = 0;
                for (; j < l; ++i, ++j) {
                    if (a[i] != b[j]) {
                        break;
                    }
                }
                if (j == l) {
                    break;
                }
            }
            return a + b.substr(l);
        };
    
        vector<string> result = {
            merge(a, merge(b, c)), merge(a, merge(c, b)),
            merge(b, merge(a, c)), merge(b, merge(c, a)),
            merge(c, merge(a, b)), merge(c, merge(b, a))
        };
        return *min_element(cbegin(result), cend(result), [](const auto& a, const auto& b) {
            return size(a) != size(b) ? size(a) < size(b) : a < b;
        });
    }
};
