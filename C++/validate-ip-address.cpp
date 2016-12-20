// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string validIPAddress(string IP) {
    	stringstream ss(IP);
    	string block;
    	if (IP.substr(0, 4).find('.') != string::npos) {
    	    for (int i = 0; i < 4; ++i) {
        		if (!getline(ss, block, '.') || !isValidIPv4Block(block)) {
        	   	    return "Neither";
        		}
    	    }
    	    if (ss.eof()) {
    	        return "IPv4";
    	    }
    	} else if (IP.substr(0, 5).find(':') != string::npos) {
    	    for (int i = 0; i < 8; ++i) {
        		if (!getline(ss, block, ':') || !isValidIPv6Block(block)) {
        		    return "Neither";
        		}
    	    }
    	    if (ss.eof()) {
    	        return "IPv6";
    	    }
    	}
    
    	return "Neither";
    }

private:
    bool isValidIPv4Block(const string& block) {
    	int num = 0;
    	if (block.size() > 0 && block.size() <= 3) {
    	    for (int i = 0; i < block.size(); ++i) {
    	        char c = block[i];
    	        if (!isalnum(c) || (i == 0 && c == '0' && block.size() > 1)) {
    	            return false;
    	        } else {
        		    num *= 10;
        		    num += c - '0';
    	        }
    	    }
    	    return num <= 255;
    	}
    	return false;
    }
    
    bool isValidIPv6Block(const string& block) {
    	if (block.size() > 0 && block.size() <= 4) {
    	    for (int i = 0; i < block.size(); ++i) {
    	        char c = block[i];
    	        if (!isxdigit(c)) {
    	    	    return false;
    	        }
    	    }
    	    return true;
    	}
    	return false;
    }
};
