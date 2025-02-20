# Time:  O(nlogn)
# Space: O(n)

# sort, line sweep, segment tree
class Solution(object):
    def separateSquares(self, squares):
        """
        :type squares: List[List[int]]
        :rtype: float
        """
        class SegmentTreeRecu(object):
            def __init__(self, sorted_x):
                self.sorted_x = sorted_x
                n = len(sorted_x)-1
                l = 1<<((n-1).bit_length()+1)
                self.tree = [0]*l
                self.cnt = [0]*l
        
            def update(self, ql, qr, v, l, r, i):  # update [ql, qr) by v, interval [l, r) in sorted_x is covered by i
                if ql >= r or qr <= l:
                    return
                if ql <= l and r <= qr:
                    self.cnt[i] += v
                else:
                    m = l+(r-l)//2
                    self.update(ql, qr, v, l, m, 2*i)
                    self.update(ql, qr, v, m, r, 2*i+1)
                if self.cnt[i] > 0:
                    self.tree[i] = self.sorted_x[r]-self.sorted_x[l]
                else:
                    if r-l == 1:
                        self.tree[i] = 0
                    else:
                        self.tree[i] = self.tree[2*i]+self.tree[2*i+1]
    
        events = []
        x_set = set()
        for x, y, l in squares:
            events.append((y, 1, x, x+l))
            events.append((y+l, -1, x, x+l))
            x_set.add(x)
            x_set.add(x+l)
        events.sort(key=lambda e: e[0])
        sorted_x = sorted(x_set) 
        x_to_idx = {x:i for i, x in enumerate(sorted_x)}
        st = SegmentTreeRecu(sorted_x)
        prev = events[0][0]
        intervals = []
        for y, v, x1, x2 in events:
            if y != prev:
                intervals.append([prev, y, st.tree[1]])
                prev = y
            st.update(x_to_idx[x1], x_to_idx[x2], v, 0, len(sorted_x)-1, 1)
        expect = sum((y2-y1)*curr for y1, y2, curr in intervals)/2.0
        total = 0.0
        for y1, y2, curr in intervals:
            if total+(y2-y1)*curr >= expect:
                break
            total += (y2-y1)*curr
        return y1+(expect-total)/curr
