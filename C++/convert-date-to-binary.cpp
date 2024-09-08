// Time:  O(1)
// Space: O(1)

// string
class Solution {
public:
    string convertDateToBinary(string date) {
        const auto& bin = [](int x) {
            string result;
            for (; x; x >>= 1) {
                result.push_back(x & 1 ? '1' : '0'); 
            }
            reverse(begin(result), end(result));
            return result;
        };
    
        return bin(stoi(date.substr(0, 4))) + "-" +
               bin(stoi(date.substr(5, 2))) + "-" +
               bin(stoi(date.substr(8, 2)));
    }
};
