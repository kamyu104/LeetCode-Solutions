// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<string> ipToCIDR(string ip, int range) {
        auto start = ipToInt(ip);
        vector<string> result;
        while (range > 0) {
            auto mask = max(33 - bitLength(start & ~(start - 1)),
                            33 - bitLength(range));
            result.emplace_back(intToIP(start) + "/" + to_string(mask));
            start += 1 << (32 - mask);
            range -= 1 << (32 - mask);
        }
        return result;
    }

private:
    uint32_t ipToInt(const string& ip) {
        uint32_t result = 0;
        for (const auto& n : split(ip, '.')) {
            result = 256 * result + stoi(n);
        }
        return result;
    }

    string intToIP(uint32_t n) {
        string ip;
        for (const auto& i : {24, 16, 8, 0}) {
            ip += to_string((n >> i) % 256);
            ip += ".";
        }
        ip.pop_back();
        return ip;
    }
                
    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.emplace_back(token);
        }
        return tokens;
    }
    
    uint32_t bitLength(uint32_t n) {
        uint32_t left = 1, right = 32;
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            if ((1 << mid) > n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
