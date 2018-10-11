# Time:  O(n)
# Space: O(1)

class Solution(object):
    def ipToCIDR(self, ip, n):
        """
        :type ip: str
        :type n: int
        :rtype: List[str]
        """
        def ipToInt(ip):
            result = 0
            for i in ip.split('.'):
                result = 256 * result + int(i)
            return result

        def intToIP(n):
            return ".".join(str((n >> i) % 256) \
                            for i in (24, 16, 8, 0))

        start = ipToInt(ip)
        result = []
        while n:
            mask = max(33-(start & ~(start-1)).bit_length(), \
                       33-n.bit_length())
            result.append(intToIP(start) + '/' + str(mask))
            start += 1 << (32-mask)
            n -= 1 << (32-mask)
        return result

