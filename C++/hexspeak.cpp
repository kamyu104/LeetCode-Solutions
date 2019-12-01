// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string toHexspeak(string num) {
        unordered_map<int, char> lookup = {{0, 'O'}, {1,'I'}};
        for (int i = 0; i < 6; ++i) {
            lookup[10 + i] = 'A' + i;
        }
        string result;
        uint64_t n = stoul(num), r = 0;
        while (n) {
            r = n % 16;
            n /= 16;
            if (!lookup.count(r)) {
                return "ERROR";
            }
            result.push_back(lookup[r]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    string toHexspeak(string num) {
        stringstream ss;
        ss << hex << uppercase  << stoul(num);
        string result(ss.str());
        for (auto i = 0; i < result.length(); ++i) {
            if ('2' <= result[i] && result[i] <= '9') {
                return "ERROR";
            }
            if (result[i] == '0') {
                result[i] = 'O';
            }
            if (result[i] == '1') {
                result[i] = 'I';
            }
        }
        return result;
    }
};
