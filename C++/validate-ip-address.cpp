// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string validIPAddress(string IP) {
    	if (isValidIPv4(IP)) {
    	    return "IPv4";
    	} else if (isValidIPv6(IP)) {
    	    return "IPv6";
    	}

    	return "Neither";
    }

private:
    bool isValidIPv4Block(const string& block) {
    	int num = 0;
    	if (block.size() > 0 && block.size() <= 3) {
    	    for (int i = 0; i < block.size(); ++i) {
    	        char c = block[i];
    	        if (!isdigit(c) || (i == 0 && c == '0' && block.size() > 1)) {
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

    bool isValidIPv4(const string& ip)
    {
        stringstream ss(ip);
        string block;
        if (ip.substr(0, 4).find('.') != string::npos) {
            for (int i = 0; i < 4; ++i) {
                if (!getline(ss, block, '.') || !isValidIPv4Block(block)) {
                    return false;
                }
            }
            if (ss.eof()) {
                return true;
            }
        }
        return false;
    }

    int numberValidIPv6Block(const string& ip)
    {
        int i;
        stringstream ss(ip);
        string block;
        for (i = 0; i < 8; ++i) {
            if (!getline(ss, block, ':')) {
                return i;
            }
            if (!isValidIPv6Block(block)) {
                return -1;
            }
        }
        if (ss.eof()) {
            return i;
        }
        return -1;
    }

    bool isValidIPv6(const string& ip)
    {
        string ipPrefix;
        string ipSuffix;
        string ipv4;
        int ipPrefixCountBlock;
        int ipSuffixCountBlock;
        int ipv4CountBlockIPv6;
        string::size_type posDoubleColon = ip.find("::");
        string::size_type posIPv4 = ip.rfind(':');

        ipv4 = ip.substr(posIPv4 + 1);
        if (isValidIPv4(ipv4)) {
            ipv4CountBlockIPv6 = 2;
        } else {
            ipv4CountBlockIPv6 = 0;
            posIPv4 = string::npos;
        }

        if (posDoubleColon == string::npos)
            return numberValidIPv6Block(ip.substr(0, posIPv4)) + ipv4CountBlockIPv6 == 8;

        ipPrefix = ip.substr(0, posDoubleColon);
        if (posDoubleColon + 2 < posIPv4)
            ipSuffix = ip.substr(posDoubleColon + 2, posIPv4 - (posDoubleColon + 2));

        ipPrefixCountBlock = numberValidIPv6Block(ipPrefix);
        if (ipPrefixCountBlock < 0)
            return false;

        ipSuffixCountBlock = numberValidIPv6Block(ipSuffix);
        if (ipSuffixCountBlock < 0)
            return false;

        return (ipPrefixCountBlock + ipSuffixCountBlock + ipv4CountBlockIPv6) < 8;
    }
};
