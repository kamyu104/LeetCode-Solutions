class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        l=[] # take list
        for i in range (1, n+1) :
            l.append(str(i)) # store all n numbers as string 
        l.sort() # list is sorted to get lexicographical 
        for i in range(n):
            l[i]=int(l[i]) # convert all strings into integers
        return l
