# Time:  put:      O(1)
#        retrieve: O(n + dlogd), n is the size of the total logs
#                              , d is the size of the found logs
# Space: O(n)
    
class LogSystem(object):

    def __init__(self):
        self.__logs = []
        self.__granularity = {'Year': 4, 'Month': 7, 'Day': 10, \
                              'Hour': 13, 'Minute': 16, 'Second': 19}
        

    def put(self, id, timestamp):
        """
        :type id: int
        :type timestamp: str
        :rtype: void
        """
        self.__logs.append((id, timestamp))

        
    def retrieve(self, s, e, gra):
        """
        :type s: str
        :type e: str
        :type gra: str
        :rtype: List[int]
        """
        i = self.__granularity[gra]
        begin = s[:i]
        end = e[:i]
        return sorted(id for id, timestamp in self.__logs \
                      if begin <= timestamp[:i] <= end)


# Your LogSystem object will be instantiated and called as such:
# obj = LogSystem()
# obj.put(id,timestamp)
# param_2 = obj.retrieve(s,e,gra)
