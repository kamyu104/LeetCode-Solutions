// Time:  O(n + m)
// Space: O(1)

// string, hash table
class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> lookup(26, -1);
        int i = 0;
        for (auto x : key) {
            x -= 'a';
            if (x < 0 || lookup[x] != -1) {
                continue;
            }
            lookup[x] = i++;
        }
        transform(begin(message), end(message), begin(message),
                  [&](const auto& x) {
                      return x != ' ' ? 'a' + lookup[x - 'a'] : ' ';
                  });
        return message;
    }
};
