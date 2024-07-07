// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    string getEncryptedString(string s, int k) {
        rotate(begin(s), begin(s) + (k % size(s)), end(s));
        return s;
    }
};

// Time:  O(n)
// Space: O(1)
// string
class Solution2 {
public:
    string getEncryptedString(string s, int k) {
        string result;
        result.reserve(size(s));
        for (int i = 0; i < size(s); ++i) {
            result.push_back(s[(i + k) % size(s)]);
        }
        return result;
    }
};
