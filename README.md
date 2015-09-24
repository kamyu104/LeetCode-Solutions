LeetCode
======== 

Up to date (2015-09-24), there are `269` Algorithms / `13` Database / `4` Shell questions on [LeetCode Online Judge](https://leetcode.com/).
The number of questions is increasing recently.
Here is the classification of all `286` questions.
For more questions and solutions, you can see my [LintCode](https://github.com/kamyu104/LintCode) repository.
I'll keep updating for full summary and better solutions. Stay tuned for updates.
(Notes: "📖" means you need to subscribe to [LeetCode premium membership](https://leetcode.com/subscribe/) for the access to premium questions. )

* [Bit Manipulation](https://github.com/kamyu104/LeetCode#bit-manipulation)
* [Array](https://github.com/kamyu104/LeetCode#array)
* [String](https://github.com/kamyu104/LeetCode#string)
* [Linked List](https://github.com/kamyu104/LeetCode#linked-list)
* [Stack](https://github.com/kamyu104/LeetCode#stack)
* [Queue](https://github.com/kamyu104/LeetCode#queue)
* [Heap](https://github.com/kamyu104/LeetCode#heap)
* [Tree](https://github.com/kamyu104/LeetCode#tree)
* [Hash Table](https://github.com/kamyu104/LeetCode#hash-table)
* [Data Structure](https://github.com/kamyu104/LeetCode#data-structure)
* [Math](https://github.com/kamyu104/LeetCode#math)
* [Two Pointers](https://github.com/kamyu104/LeetCode#two-pointers)
* [Sort](https://github.com/kamyu104/LeetCode#sort)
* [Brute Force Search](https://github.com/kamyu104/LeetCode#brute-force-search)
* [Divide and Conquer](https://github.com/kamyu104/LeetCode#divide-and-conquer)
* [Binary Search](https://github.com/kamyu104/LeetCode#binary-search)
* [Binary Search Tree](https://github.com/kamyu104/LeetCode#binary-search-tree)
* [Breadth-First Search](https://github.com/kamyu104/LeetCode#breadth-first-search)
* [Depth-First Search](https://github.com/kamyu104/LeetCode#depth-first-search)
* [Dynamic Programming](https://github.com/kamyu104/LeetCode#dynamic-programming)
* [Backtracking](https://github.com/kamyu104/LeetCode#backtracking)
* [Greedy](https://github.com/kamyu104/LeetCode#greedy)
* [Design](https://github.com/kamyu104/LeetCode#design)


Database
===

* [SQL](https://github.com/kamyu104/LeetCode#sql)


Shell
===

* [Shell Script](https://github.com/kamyu104/LeetCode#shell-script)

---

##Bit Manipulation
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
136 | [Single Number](https://leetcode.com/problems/single-number/) | [Python](./Python/single-number.py) | _O(n)_       | _O(1)_          | Medium         ||
137 | [Single Number II](https://leetcode.com/problems/single-number-ii/) | [Python](./Python/single-number-ii.py) | _O(n)_ | _O(1)_          | Medium         ||
190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits/)  | [Python](./Python/reverse-bits.py) | _O(1)_        | _O(1)_          | Easy           ||
191  |[Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | [Python](./Python/number-of-1-bits.py) | _O(1)_ | _O(1)_          | Easy           ||
201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/) | [C++](./C++/bitwise-and-of-numbers-range.cpp) [Python](./Python/bitwise-and-of-numbers-range.py) | _O(1)_ | _O(1)_ | Medium ||
231 | [Power of Two](https://leetcode.com/problems/power-of-two/) | [C++](./C++/power-of-two.cpp) [Python](./Python/power-of-two.py) | _O(1)_ | _O(1)_ | Easy | LintCode |
260 | [Single Number III](https://leetcode.com/problems/single-number-iii/) | [C++](./C++/single-number-iii.cpp) [Python](./Python/single-number-iii.py) | _O(n)_ | _O(1)_          | Medium         ||
268| [Missing Number](https://leetcode.com/problems/missing-number/) | [C++](./C++/missing-number.cpp) [Python](./Python/missing-number.py)  | _O(n)_ |  _O(1)_ | Medium         | LintCode ||

--- 

##Array

  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
15 | [3 Sum](https://leetcode.com/problems/3sum/)         | [Python](./Python/3sum.py)       | _O(n^2)_        | _O(1)_          | Medium         ||
16 | [3 Sum Closest](https://leetcode.com/problems/3sum-closest/) | [Python](./Python/3sum-closest.py)| _O(n^2)_       | _O(1)_          | Medium         ||
26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)| [Python](./Python/remove-duplicates-from-sorted-array.py) | _O(n)_       | _O(1)_         | Easy           ||
27 | [Remove Element](https://leetcode.com/problems/remove-element/) | [Python](./Python/remove-element.py) | _O(n)_      | _O(1)_         | Easy           ||
31 | [Next Permutation](https://leetcode.com/problems/next-permutation/)| [Python](./Python/next-permutation.py) | _O(n)_  | _O(1)_          | Medium         || Tricky
41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)| [Python](./Python/first-missing-positive.py) | _O(n)_ | _O(1)_ | Hard         || Tricky
48 | [Rotate Image](https://leetcode.com/problems/rotate-image/)   | [Python](./Python/rotate-image.py) | _O(n^2)_      | _O(1)_         | Medium         ||
54 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | [Python](./Python/spiral-matrix.py) | _O(m * n)_    | _O(1)_         | Medium         ||
59 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | [Python](./Python/spiral-matrix-ii.py) | _O(m * n)_ | _O(1)_      | Medium         ||
66 | [Plus One](https://leetcode.com/problems/plus-one/)      | [Python](./Python/plus-one.py)   | _O(n)_           | _O(1)_         | Easy           || 
73 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) | [Python](./Python/set-matrix-zeroes.py) | _O(m * n)_ | _O(1)_    | Medium         ||
80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)| [Python](./Python/remove-duplicates-from-sorted-array-ii.py) | _O(n)_       | _O(1)_         | Medium         ||
118 | [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)| [Python](./Python/pascals-triangle.py) | _O(n^2)_ | _O(n)_        | Easy           || 
119 | [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)| [Python](./Python/pascals-triangle-ii.py) | _O(n^2)_ | _O(n)_  | Easy           ||
121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)| [Python](./Python/best-time-to-buy-and-sell-stock.py) | _O(n)_ | _O(1)_ | Medium ||
128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)| [Python](./Python/longest-consecutive-sequence.py) | _O(n)_ | _O(n)_ | Hard         || Tricky
157 | [Read N Characters Given Read4](https://leetcode.com/problems/read-n-characters-given-read4/) | [Python](./Python/read-n-characters-given-read4.py) | _O(n)_ | _O(1)_ | Easy           |📖|
158 | [Read N Characters Given Read4 II - Call multiple times](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/) | [Python](./Python/read-n-characters-given-read4-ii-call-multiple-times.py) | _O(n)_ | _O(1)_ | Hard |📖|
163 | [Missing Ranges](https://leetcode.com/problems/missing-ranges/)| [Python](./Python/missing-ranges.py) | _O(n)_      | _O(1)_          | Medium         | 📖 |
169 | [Majority Element](https://leetcode.com/problems/majority-element/) | [Python](./Python/majority-element.py) | _O(n)_ | _O(1)_          | Easy           |
189 | [Rotate Array](https://leetcode.com/problems/rotate-array/)   | [Python](./Python/rotate-array.py) | _O(n)_        | _O(1)_         | Easy           ||
209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | [Python] (./Python/minimum-size-subarray-sum.py) | _O(n)_ | _O(1)_ |  Medium | | Binary Search
215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | [C++] (./C++/kth-largest-element-in-an-array.cpp) [Python] (./Python/kth-largest-element-in-an-array.py)| _O(n)_ | _O(1)_ |  Medium | EPI|
228 | [Summary Ranges](https://leetcode.com/problems/summary-ranges/) | [C++] (./C++/summary-ranges.cpp) [Python] (./Python/summary-ranges.py)| _O(n)_ | _O(1)_ | Easy | |
229 | [Majority Element II](https://leetcode.com/problems/majority-element-ii/) | [C++](./C++/majority-element-ii.cpp)  [Python](./Python/majority-element-ii.py) | _O(n)_ | _O(1)_          | Medium           | |
238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | [C++](./C++/product-of-array-except-self.cpp)  [Python](./Python/product-of-array-except-self.py) | _O(n)_ | _O(1)_          | Medium           | LintCode |
240 | [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) | [C++](./C++/search-a-2d-matrix-ii.cpp) [Python](./Python/search-a-2d-matrix-ii.py) | _O(m + n)_ | _O(1)_ | Medium   | EPI, LintCode |
243| [Shortest Word Distance](https://leetcode.com/problems/shortest-word-distance/)     | [C++](./C++/shortest-word-distance.cpp) [Python](./Python/shortest-word-distance.py)  | _O(n)_ |  _O(1)_ | Easy         |📖||
245| [Shortest Word Distance III](https://leetcode.com/problems/shortest-word-distance III/)     | [C++](./C++/shortest-word-distance-iii.cpp) [Python](./Python/shortest-word-distance-iii.py)  | _O(n)_ |  _O(1)_ | Medium         |📖||
251| [Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/) | [C++](./C++/flatten-2d-vector.cpp) [Python](./Python/flatten-2d-vector.py)  | _O(1)_ |  _O(1)_ | Medium         |📖||
277| [Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/) | [C++](./C++/find-the-celebrity.cpp) [Python](./Python/find-the-celebrity.py)  | _O(n)_ |  _O(1)_ | Medium         |📖, EPI ||

--- 

##String
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
5| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | [Python](./Python/longest-palindromic-substring.py) | _O(n)_ | _O(n)_ |  Medium || `Manacher's Algorithm`
6| [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/) | [Python](./Python/zigzag-conversion.py) | _O(n)_ | _O(1)_        | Easy           ||
8| [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) | [Python](./Python/string-to-integer-atoi.py) | _O(n)_ | _O(1)_ | Easy      ||
14| [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | [Python](./Python/longest-common-prefix.py) | _O(n)_   | _O(1)_  | Easy           ||
28| [Implement strStr()](https://leetcode.com/problems/implement-strstr/) | [Python](./Python/implement-strstr.py) | _O(n + m)_   | _O(m)_  | Easy           || `KMP Algorithm`
38| [Count and Say](https://leetcode.com/problems/count-and-say/) | [Python](./Python/count-and-say.py)| _O(n * 2^n)_  | _O(2^n)_        | Easy           ||
43| [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | [Python](./Python/multiply-strings.py) | _O(m * n)_ | _O(m + n)_  | Medium         ||
58| [Length of Last Word](https://leetcode.com/problems/length-of-last-word/) | [Python](./Python/length-of-last-word.py) | _O(n)_   | _O(1)_  | Easy           ||
67| [Add Binary](https://leetcode.com/problems/add-binary/)    | [Python](./Python/add-binary.py) | _O(n)_          | _O(1)_          | Easy           ||
68| [Text Justification](https://leetcode.com/problems/text-justification/) | [Python](./Python/text-justification.py) | _O(n)_ | _O(1)_      | Hard           ||
125| [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | [Python](./Python/valid-palindrome.py) | _O(n)_  | _O(1)_         | Easy           ||
151| [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) | [Python](./Python/reverse-words-in-a-string.py) | _O(n)_ | _O(n)_ | Medium         ||
161| [One Edit Distance](https://leetcode.com/problems/one-edit-distance/) | [Python](./Python/one-edit-distance.py) | _O(m + n)_ | _O(1)_    | Medium         |📖|
165| [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/) | [Python](./Python/compare-version-numbers.py) | _O(n)_ | _O(1)_ | Easy     ||
186| [Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/) | [Python](./Python/reverse-words-in-a-string-ii.py) | _O(n)_ | _O(1)_ | Medium         | 📖 |
205| [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/) | [Python](./Python/isomorphic-strings.py) | _O(n)_ | _O(1)_       | Easy           ||    
214| [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/) | [C++](./C++/shortest-palindrome.cpp) [Python](./Python/shortest-palindrome.py) | _O(n)_ | _O(n)_ |  Hard || `KMP Algorithm` `Manacher's Algorithm`
271| [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/) | [C++](./C++/encode-and-decode-strings.cpp) [Python](./Python/encode-and-decode-strings.py) | _O(n)_ | _O(1)_ | Medium         | 📖 |
273| [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/) | [C++](./C++/integer-to-english-words.cpp)  [Python](./Python/integer-to-english-words.py) | _O(logn)_ | _O(1)_ | Medium         | |

--- 

##Linked List
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
2| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [Python](./Python/add-two-numbers.py) | _O(n)_   | _O(1)_          | Medium         ||
24| [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)| [Python](./Python/swap-nodes-in-pairs.py)   | _O(n)_          | _O(1)_          | Medium         ||
25| [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)| [Python](./Python/reverse-nodes-in-k-group.py) | _O(n)_       | _O(1)_         | Hard         ||
61| [Rotate List](https://leetcode.com/problems/rotate-list/)| [Python](./Python/rotate-list.py)   | _O(n)_          | _O(1)_          | Medium         ||  
82| [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)| [Python](./Python/remove-duplicates-from-sorted-list-ii.py) | _O(n)_       | _O(1)_         | Medium         ||
83| [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)| [Python](./Python/remove-duplicates-from-sorted-list.py) | _O(n)_       | _O(1)_         | Easy           ||
92| [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)| [Python](./Python/reverse-linked-list-ii.py) | _O(n)_       | _O(1)_         | Medium         || 
138| [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) | [Python](./Python/copy-list-with-random-pointer.py) | _O(n)_   | _O(1)_          | Hard         ||
160| [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)| [Python](./Python/intersection-of-two-linked-lists.py) | _O(m + n)_ | _O(1)_         | Easy           ||
203| [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)| [Python](./Python/remove-linked-list-elements.py) | _O(n)_       | _O(1)_         | Easy         || 
206| [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)| [Python](./Python/reverse-linked-list.py) | _O(n)_       | _O(1)_         | Easy         || 
234| [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)| [C++](./C++/palindrome-linked-list.cpp) [Python](./Python/palindrome-linked-list.py) | _O(n)_       | _O(1)_         | Easy         ||
237| [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)| [C++](./C++/delete-node-in-a-linked-list.cpp) [Python](./Python/delete-node-in-a-linked-list.py) | _O(1)_       | _O(1)_         | Easy         | LintCode |
242| [Valid Anagram](https://leetcode.com/problems/valid-anagram/)| [C++](./C++/valid-anagram.cpp) [Python](./Python/valid-anagram.py) | _O(n)_       | _O(1)_         | Easy         | LintCode |

--- 

##Stack
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
20| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)| [Python](./Python/valid-parentheses.py) | _O(n)_        | _O(n)_          | Easy           ||
32| [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)| [Python](./Python/longest-valid-parentheses.py) | _O(n)_ | _O(1)_ | Hard   ||
71| [Simplify Path](https://leetcode.com/problems/simplify-path/)| [Python](./Python/simplify-path.py) | _O(n)_        | _O(n)_          | Medium         ||
101| [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)| [Python](./Python/symmetric-tree.py) | _O(n)_      | _O(h)_          | Easy           ||
150| [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)| [Python](./Python/evaluate-reverse-polish-notation.py)| _O(n)_| _O(n)_| Medium          ||
155| [Min Stack](https://leetcode.com/problems/min-stack/)     | [Python](./Python/min-stack.py)  | _O(n)_          | _O(1)_          | Easy           ||
173| [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | [Python](./Python/binary-search-tree-iterator.py) | _O(1)_| _O(h)_| Medium ||   
224| [Basic Calculator](https://leetcode.com/problems/basic-calculator/) | [C++](./C++/basic-calculator.cpp) [Python](./Python/basic-calculator.py) | _O(n)_| _O(n)_| Medium || 
227| [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) | [C++](./C++/basic-calculator-ii.cpp) [Python](./Python/basic-calculator-ii.py) | _O(n)_| _O(n)_| Medium || 
232| [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) | [C++](./C++/implement-queue-using-stacks.cpp) [Python](./Python/implement-queue-using-stacks.py) | _O(1), amortized_| _O(n)_| Easy | EPI, LintCode | 
255| [Verify Preorder Sequence in Binary Search Tree](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/) | [C++](./C++/verify-preorder-sequence-in-binary-search-tree.cpp) [Python](./Python/verify-preorder-sequence-in-binary-search-tree.py) | _O(n)_| _O(1)_| Medium |📖||
272| [Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii/) | [C++](./C++/closest-binary-search-tree-value-ii.cpp) [Python](./Python/closest-binary-search-tree-value-ii.py) | _O(h + k)_| _O(h)_| Hard |📖||

--- 

##Queue
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
239| [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)| [C++](./C++/sliding-window-maximum.cpp) [Python](./Python/sliding-window-maximum.py) | _O(n)_        | _O(k)_          | Hard           | EPI, LintCode |
281| [Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/)| [C++](./C++/zigzag-iterator.cpp) [Python](./Python/zigzag-iterator.py) | _O(n)_        | _O(k)_          | Medium           |📖||

--- 

##Heap
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
23| [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | [Python](./Python/merge-k-sorted-lists.py) | _O(nlogk)_| _O(k)_| Hard          ||
264| [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | [C++](./C++/ugly-number-ii.cpp)  [Python](./Python/ugly-number-ii.py)  | _O(n)_ | _O(1)_ | Medium         | CTCI, LintCode | BST, Heap |

--- 

##Tree
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
94 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)  | [Python](./Python/binary-tree-inorder-traversal.py) | _O(n)_| _O(1)_| Medium           || `Morris Traversal` | 
99 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/) | [Python](./Python/recover-binary-search-tree.py) | _O(n)_| _O(1)_| Hard  || `Morris Traversal` 
144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | [Python](./Python/binary-tree-preorder-traversal.py) | _O(n)_| _O(1)_| Medium || `Morris Traversal` 
145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | [Python](./Python/binary-tree-postorder-traversal.py) | _O(n)_| _O(1)_| Hard  || `Morris Traversal` 
208 | [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) | [Python](./Python/implement-trie-prefix-tree.py) | _O(n)_ | _O(1)_ | Medium || Trie
211 | [Add and Search Word - Data structure design ](https://leetcode.com/problems/add-and-search-word-data-structure-design/) | [C++](./C++/add-and-search-word-data-structure-design.cpp) [Python](./Python/add-and-search-word-data-structure-design.py) | _O(min(n, h))_ | _O(min(n, h))_ | Medium || Trie, DFS
212| [Word Search II](https://leetcode.com/problems/word-search-ii/) | [C++](./C++/word-search-ii.cpp) [Python](./Python/word-search-ii.py) | _O(m * n * l)_ | _O(l)_  | Hard         | LintCode | Trie, DFS
226| [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | [C++](./C++/invert-binary-tree.cpp) [Python](./Python/invert-binary-tree.py) | _O(n)_ | _O(h)_, _O(w)_ | Easy ||

--- 

##Hash Table
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
1| [Two Sum](https://leetcode.com/problems/two-sum/)      | [Python](./Python/two-sum.py)      | _O(n)_         | _O(n)_          | Medium         ||
3| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [Python](./Python/longest-substring-without-repeating-characters.py) | _O(n)_ | _O(1)_ | Medium ||
18| [4 Sum](https://leetcode.com/problems/4sum/)         |[Python](./Python/4sum.py)        | _O(n^2 * p)_    | _O(n^2 * p)_    | Medium         ||
30| [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) | [Python](./Python/substring-with-concatenation-of-all-words.py) | _O(m * n * k)_ | _O(n * k)_ | Hard          ||
36| [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | [Python](./Python/valid-sudoku.py) | _O(n^2)_         | _O(n)_          | Easy           ||
49| [Anagrams](https://leetcode.com/problems/anagrams/)     | [Python](./Python/anagrams.py)   | _O(n)_          | _O(n)_          | Medium         ||
76| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | [Python](./Python/minimum-window-substring.py) | _O(n)_ | _O(k)_ | Hard          ||
149| [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/) | [Python](./Python/max-points-on-a-line.py) | _O(n^2)_ | _O(n)_ | Hard          ||
159| [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)| [Python](./Python/longest-substring-with-at-most-two-distinct-characters.py) | _O(n^2)_ | _O(1)_ | Hard         |📖|
170| [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/) | [Python](./Python/two-sum-iii-data-structure-design.py) | _O(n)_ | _O(n)_ | Easy | 📖 |
187| [Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/) | [Python](./Python/repeated-dna-sequences.py) | _O(n)_       | _O(n)_          | Medium         ||
202| [Happy Number](https://leetcode.com/problems/happy-number/)      | [Python](./Python/happy-number.py)   | _O(k)_  | _O(k)_          | Easy          ||
204| [Count Primes](https://leetcode.com/problems/count-primes/)  | [Python](./Python/count-primes.py) | _O(n)_        | _O(n)_          | Easy           ||
217| [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)  | [C++](./C++/contains-duplicate.cpp) [Python](./Python/contains-duplicate.py) | _O(n)_        | _O(n)_          | Easy           ||
219| [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)  | [C++](./C++/contains-duplicate-ii.cpp) [Python](./Python/contains-duplicate-ii.py) | _O(n)_        | _O(n)_          | Easy           ||
244| [Shortest Word Distance II](https://leetcode.com/problems/shortest-word-distance-ii/)     | [C++](./C++/shortest-word-distance-ii.cpp) [Python](./Python/shortest-word-distance-ii.py)  | ctor: _O(n)_, lookup: _O(a + b)_ |  _O(n)_ | Medium         |📖||
246| [Strobogrammatic Number](https://leetcode.com/problems/strobogrammatic-number/) | [C++](./C++/strobogrammatic-number.cpp)  [Python](./Python/strobogrammatic-number.py)  | _O(n)_ | _O(1)_ | Easy         |📖||
249| [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/) | [C++](./C++/group-shifted-strings.cpp)  [Python](./Python/group-shifted-strings.py)  | _O(nlogn)_ | _O(n)_ | Easy         |📖||
266| [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation/) | [C++](./C++/palindrome-permutation.cpp) [Python](./Python/palindrome-permutation.py)  | _O(n)_ |  _O(1)_ | Easy         |📖||

--- 

##Data Structure
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
146| [LRU Cache](https://leetcode.com/problems/lru-cache/)     | [Python](./Python/lru-cache.py)  | _O(1)_          | _O(n)_          | Hard         ||
225| [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)     | [C++](./C++/implement-stack-using-queues.cpp) [Python](./Python/implement-stack-using-queues.py)  | Push: _O(n)_, Pop: _O(1)_, Top: _O(1)_ | _O(n)_          | Medium         ||

--- 

##Math
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
7| [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | [Python](./Python/reverse-integer.py) | _O(logn)_ | _O(1)_         | Easy           ||
9| [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | [Python](./Python/palindrome-number.py) | _O(1)_ | _O(1)_        | Easy           ||
12| [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | [Python](./Python/integer-to-roman.py) | _O(n)_ | _O(1)_          | Medium         ||
13| [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | [Python](./Python/roman-to-integer.py) | _O(n)_ | _O(1)_          | Easy           ||
29| [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) | [Python](./Python/divide-two-integers.py)    | _O(logn)_       | _O(1)_         | Medium         ||
60| [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) | [Python](./Python/permutation-sequence.py) | _O(n^2)_ | _O(n)_  | Medium         || `Cantor Ordering`
65| [Valid Number](https://leetcode.com/problems/valid-number/) | [Python](./Python/valid-number.py) | _O(n)_         | _O(1)_          | Hard           || `Automata`
89| [Gray Code](https://leetcode.com/problems/gray-code/)     | [Python](./Python/gray-code.py)  | _O(2^n)_        | _O(1)_          | Medium         ||
166| [Fraction to Recurring Decimal](https://leetcode.com/problems/fraction-to-recurring-decimal/) | [Python](./Python/fraction-to-recurring-decimal.py)  | _O(logn)_ | _O(1)_ | Medium         ||
168| [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/) | [Python](./Python/excel-sheet-column-title.py) | _O(logn)_ | _O(1)_ | Easy ||
171| [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) | [Python](./Python/excel-sheet-column-number.py) | _O(n)_ | _O(1)_ | Easy  ||
172| [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/) | [Python](./Python/factorial-trailing-zeroes.py)  | _O(logn)_ | _O(1)_ | Easy         ||
223| [Rectangle Area](https://leetcode.com/problems/rectangle-area/) | [C++](./C++/rectangle-area.cpp)  [Python](./Python/rectangle-area.py)  | _O(1)_ | _O(1)_ | Easy         ||
233| [Number of Digit One](https://leetcode.com/problems/number-of-digit-one/) | [C++](./C++/number-of-digit-one.cpp)  [Python](./Python/number-of-digit-one.py)  | _O(logn)_ | _O(1)_ | Medium        | CTCI, LintCode|
248| [Strobogrammatic Number III](https://leetcode.com/problems/strobogrammatic-number-iii/) | [C++](./C++/strobogrammatic-number-iii.cpp)  [Python](./Python/strobogrammatic-number-iii.py)  | _O(5^(n/2))_ | _O(n)_ | Hard         |📖||
258| [Add Digits](https://leetcode.com/problems/add-digits/) | [C++](./C++/add-digits.cpp)  [Python](./Python/add-digits.py)  | _O(1)_ | _O(1)_ | Easy         |||
263| [Ugly Number](https://leetcode.com/problems/ugly-number/) | [C++](./C++/ugly-number.cpp)  [Python](./Python/ugly-number.py)  | _O(logn)_ | _O(1)_ | Easy         |||

--- 

##Sort
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
21| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)| [Python](./Python/merge-two-sorted-lists.py) | _O(n)_ | _O(1)_ | Easy         ||
56| [Merge Intervals](https://leetcode.com/problems/merge-intervals/)| [Python](./Python/merge-intervals.py) | _O(nlogn)_  | _O(1)_        | Hard           ||
57| [Insert Interval](https://leetcode.com/problems/insert-interval/)| [Python](./Python/insert-interval.py) | _O(n)_    | _O(1)_          | Hard           ||
75| [Sort Colors](https://leetcode.com/problems/sort-colors/)   | [Python](./Python/sort-colors.py) | _O(n)_         | _O(1)_          | Medium         ||
88| [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)| [Python](./Python/merge-sorted-array.py) | _O(n)_ | _O(1)_       | Easy           ||
147| [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/)|[Python](./Python/insertion-sort-list.py) | _O(n^2)_ | _O(1)_    | Medium         ||
148| [Sort List](https://leetcode.com/problems/sort-list/)     | [Python](./Python/sort-list.py)  | _O(nlogn)_      | _O(logn)_       | Medium         ||
164| [Maximum Gap](https://leetcode.com/problems/maximum-gap/)   | [Python](./Python/maximum-gap.py)| _O(n)_          | _O(n)_          | Hard           || Tricky 
179| [Largest Number](https://leetcode.com/problems/largest-number/) | [Python](./Python/largest-number.py) | _O(nlogn)_   | _O(1)_        | Medium         ||
218| [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) | [C++](./C++/the-skyline-problem.cpp) [Python](./Python/the-skyline-problem.py) | _O(nlogn)_   | _O(n)_        | Hard         || Sort, BST|
252| [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) | [C++](./C++/meeting-rooms.cpp) [Python](./Python/meeting-rooms.py) | _O(nlogn)_   | _O(n)_        | Easy         |📖| |
253| [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | [C++](./C++/meeting-rooms-ii.cpp) [Python](./Python/meeting-rooms-ii.py) | _O(nlogn)_   | _O(n)_        | Medium         |📖| |
274| [H-Index](https://leetcode.com/problems/h-index/) | [C++](./C++/h-index.cpp)  [Python](./Python/h-index.py)  | _O(n)_ | _O(n)_ | Medium         || Counting Sort |
280| [Wiggle Sort](https://leetcode.com/problems/wiggle-sort/) | [C++](./C++/wiggle-sort.cpp) [Python](./Python/wiggle-sort.py) | _O(n)_   | _O(1)_        | Medium         |📖| |

---

##Two Pointers
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
19| [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)| [Python](./Python/remove-nth-node-from-end-of-list.py) | _O(n)_       | _O(1)_         | Easy         || 
86| [Partition List](https://leetcode.com/problems/partition-list/)| [Python](./Python/partition-list.py) | _O(n)_       | _O(1)_         | Medium         || 
141| [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)| [Python](./Python/linked-list-cycle.py) | _O(n)_ | _O(1)_         | Medium         || 
142| [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)| [Python](./Python/linked-list-cycle-ii.py) | _O(n)_ | _O(1)_   | Medium         ||
143| [Reorder List](https://leetcode.com/problems/reorder-list/)| [Python](./Python/reorder-list.py) | _O(n)_          |  _O(1)_         | Medium         ||  
167| [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [Python](./Python/two-sum-ii-input-array-is-sorted.py) | _O(n)_   | _O(1)_         | Medium         | 📖 |
259 | [3Sum Smaller](https://leetcode.com/problems/3sum-smaller/) | [C++](./C++/3sum-smaller.cpp) [Python](./Python/3sum-smaller.py) | _O(n^2)_ | _O(1)_          | Medium         | 📖, LintCode |
283 | [Move Zeros](https://leetcode.com/problems/move-zeros/) | [C++](./C++/move-zeros.cpp) [Python](./Python/move-zeros.py) | _O(n)_ | _O(1)_          | Easy         | |

---

##Brute Force Search
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
17| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)| [Python](./Python/letter-combinations-of-a-phone-number.py) | _O(n * 4^n)_ | _O(n)_ | Medium ||
46| [Permutations](https://leetcode.com/problems/permutations/)| [Python](./Python/permutations.py) | _O(n * n!)_         | _O(n)_          | Medium         ||
47| [Permutations II](https://leetcode.com/problems/permutations-ii/)| [Python](./Python/permutations-ii.py) | _O(n * n!)_   | _O(n)_          | Hard           ||
78| [Subsets](https://leetcode.com/problems/subsets/)       | [Python](./Python/subsets.py)    | _O(n * 2^n)_    | _O(1)_          | Medium         ||
90| [Subsets II](https://leetcode.com/problems/subsets-ii/)    | [Python](./Python/subsets-ii.py) | _O(n * 2^n)_    | _O(1)_          | Medium         ||
267| [Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii/) | [C++](./C++/palindrome-permutation-ii.cpp) [Python](./Python/palindrome-permutation-ii.py)  | _O(n * n!)_ |  _O(n)_ | Medium         |📖||

--- 

##Divide and Conquer
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
95| [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/) | [Python](./Python/unique-binary-search-trees-ii.py) | _O(4^n / n^(3/2)_      | _O(4^n / n^(3/2)_         | Medium         ||
98| [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)|[Python](./Python/validate-binary-search-tree.py)| _O(n)_ | _O(1)_ | Medium ||
100| [Same Tree](https://leetcode.com/problems/same-tree/)      |[Python](./Python/same-tree.py)  | _O(n)_          | _O(h)_        | Easy          ||
104| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)|[Python](./Python/maximum-depth-of-binary-tree.py)| _O(n)_ | _O(h)_ | Easy ||
105| [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [Python](./Python/construct-binary-tree-from-preorder-and-inorder-traversal.py) | _O(n)_        | _O(n)_          | Medium   ||
106| [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | [Python](./Python/construct-binary-tree-from-inorder-and-postorder-traversal.py) | _O(n)_        | _O(n)_          | Medium         ||
108| [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) | [Python](./Python/convert-sorted-array-to-binary-search-tree.py) | _O(n)_        | _O(logn)_          | Medium         ||
109| [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | [Python](./Python/convert-sorted-list-to-binary-search-tree.py) | _O(n)_        | _O(logn)_          | Medium         ||
110| [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | [Python](./Python/balanced-binary-tree.py) | _O(n)_| _O(h)_   | Easy           ||
111| [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)|[Python](./Python/minimum-depth-of-binary-tree.py)| _O(n)_ | _O(h)_ | Easy ||
114| [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)|[Python](./Python/flatten-binary-tree-to-linked-list.py)| _O(n)_        | _O(h)_          | Medium         ||
116| [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)|[Python](./Python/populating-next-right-pointers-in-each-node.py)| _O(n)_ | _O(1)_ | Medium ||
124| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)| [Python](./Python/binary-tree-maximum-path-sum.py) | _O(n)_| _O(h)_| Hard  ||  
129| [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/) | [Python](./Python/sum-root-to-leaf-numbers.py) | _O(n)_ | _O(h)_ | Medium ||
156| [Binary Tree Upside Down](https://leetcode.com/problems/binary-tree-upside-down/) | [Python](./Python/binary-tree-upside-down.py) | _O(n)_ | _O(1)_ | Medium    |📖| 
241| [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/) | [C++](./C++/different-ways-to-add-parentheses.cpp) [Python](./Python/different-ways-to-add-parentheses.py) | _O(n * 4^n / n^(3/2))_ | _O(n * 4^n / n^(3/2))_ | Medium    || 

--- 

##Binary Search
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
4| [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [Python](./Python/median-of-two-sorted-arrays.py) | _O(log(m + n))_ | _O(1)_ | Hard         ||
33| [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [Python](./Python/search-in-rotated-sorted-array.py) | _O(logn)_ | _O(1)_   | Hard         ||
34| [Search for a Range](https://leetcode.com/problems/search-for-a-range/) | [Python](./Python/search-for-a-range.py) | _O(logn)_ | _O(1)_   | Medium         ||
35| [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [Python](./Python/search-insert-position.py) | _O(logn)_ | _O(1)_   | Medium         ||
50| [Pow(x, n)](https://leetcode.com/problems/powx-n/)     | [Python](./Python/powx-n.py)     | _O(logn)_       | _O(logn)_       | Medium         ||
69| [Sqrt(x)](https://leetcode.com/problems/sqrtx/)       | [Python](./Python/sqrtx.py)      | _O(logn)_        | _O(1)_         | Medium         ||
74| [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) | [Python](./Python/search-a-2d-matrix.py) | _O(logm + logn)_ | _O(1)_ | Medium   ||
81| [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) | [Python](./Python/search-in-rotated-sorted-array-ii.py) | _O(logn)_ | _O(1)_   | Medium         ||
153| [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)         | [Python](./Python/find-minimum-in-rotated-sorted-array.py)       | _O(logn)_        | _O(1)_          | Medium         ||
154| [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)      | [Python](./Python/find-minimum-in-rotated-sorted-array-ii.py)       | _O(logn)_ ~ _O(n)_        | _O(1)_          | Hard         ||
162| [Find Peak Element](https://leetcode.com/problems/find-peak-element/) | [Python](./Python/find-peak-element.py)        | _O(logn)_       | _O(1)_          | Medium         ||
222| [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/) | [C++](./C++/count-complete-tree-nodes.cpp) [Python](./Python/count-complete-tree-nodes.py) | _O((logn)^2)_       | _O(1)_          | Medium         ||
275| [H-Index II](https://leetcode.com/problems/h-index-ii/) | [C++](./C++/h-index-ii.cpp)  [Python](./Python/h-index-ii.py)  | _O(logn)_ | _O(1)_ | Medium         || Binary Search |
278| [First Bad Version](https://leetcode.com/problems/first-bad-version/) | [C++](./C++/first-bad-version.cpp)  [Python](./Python/first-bad-version.py)  | _O(logn)_ | _O(1)_ | Easy         | LintCode ||

-- 
##Binary Search Tree
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
220| [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/)  | [C++](./C++/contains-duplicate-iii.cpp) [Python](./Python/contains-duplicate-iii.py) | _O(nlogk)_        | _O(k)_          | medium           ||
230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) | [C++](./C++/kth-smallest-element-in-a-bst.cpp) [Python](./Python/kth-smallest-element-in-a-bst.py) | _O(max(h, k))_ | _O(min(h, k))_ | Medium ||
235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | [C++](./C++/lowest-common-ancestor-of-a-binary-search-tree.cpp) [Python](./Python/lowest-common-ancestor-of-a-binary-search-tree.py) | _O(h)_ | _O(1)_ | Easy | EPI |
270| [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/)| [C++](./C++/closest-binary-search-tree-value.cpp) [Python](./Python/closest-binary-search-tree-value.py)   | _O(h)_          | _O(1)_          | Easy         | 📖 |
285| [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/)| [C++](./C++/inorder-successor-in-bst.cpp) [Python](./Python/inorder-successor-in-bst.py)   | _O(h)_          | _O(1)_          | Medium         | 📖 |

--- 

##Breadth-First Search
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
102| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)| [Python](./Python/binary-tree-level-order-traversal.py)| _O(n)_| _O(n)_| Easy  || 
107| [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)| [Python](./Python/binary-tree-level-order-traversal-ii.py) | _O(n)_| _O(n)_| Easy  ||
103| [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)| [Python](./Python/binary-tree-zigzag-level-order-traversal.py) | _O(n)_| _O(n)_| Medium  ||  
117| [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)|[Python](./Python/populating-next-right-pointers-in-each-node-ii.py)| _O(n)_ | _O(1)_ | Hard ||
127| [Word Ladder](https://leetcode.com/problems/word-ladder/)|[Python](./Python/word-ladder.py) | _O(n * d)_      | _O(d)_          | Medium         ||
130| [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)|[Python](./Python/surrounded-regions.py)| _O(m * n)_ | _O(m + n)_ | Medium         ||
133| [Clone Graph](https://leetcode.com/problems/clone-graph/)| [Python](./Python/clone-graph.py)   | _O(n)_          | _O(n)_          | Medium         ||
207| [Course Schedule](https://leetcode.com/problems/course-schedule/)| [Python](./Python/course-schedule.py)   | _O(\|V\| + \|E\|)_          | _O(\|E\|)_          | Medium         || Topological Sort |
210| [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)| [Python](./Python/course-schedule-ii.py)   | _O(\|V\| + \|E\|)_          | _O(\|E\|)_          | Medium         || Topological Sort |
261| [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)| [C++](./C++/graph-valid-tree.cpp) [Python](./Python/graph-valid-tree.py)   | _O(\|V\| + \|E\|)_          | _O(\|V\|)_          | Medium         | 📖 |
269| [Alien Dictionary](https://leetcode.com/problems/alien-dictionary/) | [C++](./C++/alien-dictionary.cpp)  [Python](./Python/alien-dictionary.py)  | _O(n)_ | _O(1)_ | Hard         |📖| Topological Sort, BFS, DFS |
286| [Walls and Gates](https://leetcode.com/problems/walls-and-gates/)| [C++](./C++/walls-and-gates.cpp) [Python](./Python/walls-and-gates.py)   | _O(m * n)_          | _O(g)_          | Medium         | 📖 |

--- 

##Depth-First Search
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
22| [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)| [Python](./Python/generate-parentheses.py)| _O(4^n / n^(3/2))_ | _O(n)_   | Medium         ||
37| [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) | [Python](./Python/sudoku-solver.py) | _O((9!)^9)_  | _O(1)_          | Hard           ||
39| [Combination Sum](https://leetcode.com/problems/combination-sum/)| [Python](./Python/combination-sum.py) | _O(k * n^k)_    | _O(k)_          | Medium         ||
40| [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)| [Python](./Python/combination-sum-ii.py)| _O(k * C(n, k))_| _O(k)_         | Medium         ||
51| [N-Queens](https://leetcode.com/problems/n-queens/)      | [Python](./Python/n-queens.py)   | _O(n!)_         | _O(n)_          | Hard           ||
52| [N-Queens-II](https://leetcode.com/problems/n-queens-ii/)   | [Python](./Python/n-queens-ii.py) | _O(n!)_        | _O(n)_          | Hard           ||
77| [Combinations](https://leetcode.com/problems/combinations/)  | [Python](./Python/combinations.py) | _O(n!)_       | _O(n)_          | Medium         ||
79| [Word Search](https://leetcode.com/problems/word-search/) | [Python](./Python/word-search.py) | _O(m * n * l)_ | _O(l)_  | Medium         ||
93| [Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/) | [Python](./Python/restore-ip-addresses.py) | _O(n^m)_ ~ _O(3^4)_ | _O(n * m)_ ~ _O(3 * 4)_ | Medium         ||
112| [Path Sum](https://leetcode.com/problems/path-sum/)      | [Python](./Python/path-sum.py)   | _O(n)_          | _O(h)_          | Easy           ||
113| [Path Sum II](https://leetcode.com/problems/path-sum-ii/)   | [Python](./Python/path-sum-ii.py) | _O(n)_         | _O(h)_          | Medium         ||
131| [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) | [Python](./Python/palindrome-partitioning.py) | _O(n^2)_ ~ _O(2^n)_ | _O(n^2)_ | Medium ||
199| [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | [Python](./Python/binary-tree-right-side-view.py) | _O(n)_     | _O(h)_ | Medium  ||
200| [Number of Islands](https://leetcode.com/problems/number-of-islands/) | [Python](./Python/number-of-islands.py) | _O(m * n)_ | _O(m * n)_| Medium         ||
216| [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/)| [C++](./C++/combination-sum-iii.cpp) [Python](./Python/combination-sum-iii.py) | _O(k * C(n, k))_    | _O(k)_          | Medium         ||
236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | [C++](./C++/lowest-common-ancestor-of-a-binary-tree.cpp) [Python](./Python/lowest-common-ancestor-of-a-binary-tree.py) | _O(h)_ | _O(h)_ | Medium | EPI |
247| [Strobogrammatic Number II](https://leetcode.com/problems/strobogrammatic-number-ii/) | [C++](./C++/strobogrammatic-number-ii.cpp)  [Python](./Python/strobogrammatic-number-ii.py)  | _O(n^2 * 5^(n/2))_ | _O(n)_ | Medium         |📖||
250| [Count Univalue Subtrees](https://leetcode.com/problems/count-univalue-subtrees) | [C++](./C++/count-univalue-subtrees.cpp)  [Python](./Python/count-univalue-subtrees.py)  | _O(n)_ | _O(h)_ | Medium         |📖||
254| [Factor Combinations](https://leetcode.com/problems/factor-combinations/) | [C++](./C++/factor-combinations.cpp)  [Python](./Python/factor-combinations.py)  | _O(nlogn)_ | _O(logn)_ | Medium         |📖||
257| [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/) | [C++](./C++/binary-tree-paths.cpp)  [Python](./Python/binary-tree-paths.py)  | _O(n * h)_ | _O(h)_ | Easy         |||
282| [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) | [C++](./C++/expression-add-operators.cpp)  [Python](./Python/expression-add-operators.py)  | _O(4^n)_ | _O(n)_ | Hard         |||

--- 

##Dynamic Programming
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
10| [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) | [Python](./Python/regular-expression-matching.py) | _O(m * n)_ | _O(n)_ | Hard ||
53| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)|[Python](./Python/maximum-subarray.py)| _O(n)_     | _O(1)_         | Medium         ||
62| [Unique Paths](https://leetcode.com/problems/unique-paths/)    | [Python](./Python/unique-paths.py)| _O(m * n)_      | _O(m + n)_   | Medium         ||
63| [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | [Python](./Python/unique-paths-ii.py) |  _O(m * n)_ | _O(m + n)_   | Medium         ||
64| [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)|[Python](./Python/minimum-path-sum.py)| _O(m * n)_ | _O(m + n)_     | Medium         ||
70| [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)| [Python](./Python/climbing-stairs.py) | _O(n)_    | _O(1)_          | Easy           ||
72| [Edit Distance](https://leetcode.com/problems/edit-distance/)|[Python](./Python/edit-distance.py)| _O(m * n)_      | _O(m + n)_      | Hard           ||
85| [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)|[Python](./Python/maximal-rectangle.py)| _O(n^2)_ | _O(n)_         | Hard           ||
87| [Scramble String](https://leetcode.com/problems/scramble-string/) | [Python](./Python/scramble-string.py) | _O(n^4)_ | _O(n^3)_        | Hard           ||
91| [Decode Ways](https://leetcode.com/problems/decode-ways/)   | [Python](./Python/decode-ways.py)| _O(n)_          | _O(1)_          | Medium         ||
96| [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/) | [Python](./Python/unique-binary-search-trees.py) | _O(n^2)_      | _O(n)_         | Medium         ||
97| [Interleaving String](https://leetcode.com/problems/interleaving-string/)|[Python](./Python/interleaving-string.py)| _O(m * n)_ | _O(m + n)_ | Hard         ||
115| [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)|[Python](./Python/distinct-subsequences.py)| _O(n^2)_ | _O(n)_ | Hard           ||
120| [Triangle](https://leetcode.com/problems/triangle/)       | [Python](./Python/triangle.py)   | _O(m * n)_      | _O(n)_         | Medium         ||
123| [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | [Python](./Python/best-time-to-buy-and-sell-stock-iii.py) | _O(n)_ | _O(1)_ | Hard ||
132| [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/) | [Python](./Python/palindrome-partitioning-ii.py) | _O(n^2)_ | _O(n^2)_ | Hard ||
139| [Word Break](https://leetcode.com/problems/word-break/)     | [Python](./Python/word-break.py) |  _O(n^2)_         | _O(n)_       | Medium         ||
140| [Word Break II](https://leetcode.com/problems/word-break-ii/)  | [Python](./Python/word-break-ii.py) |  _O(n^2)_      | _O(n)_       | Hard           ||
152| [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)|[Python](./Python/maximum-product-subarray.py)| _O(n)_ | _O(1)_ | Medium     ||
174| [Dungeon Game](https://leetcode.com/problems/dungeon-game/)  | [Python](./Python/dungeon-game.py)| _O(m * n)_     | _O(m + n)_      | Hard           ||
188| [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)| [Python](./Python/best-time-to-buy-and-sell-stock-iv.py) | _O(k * n)_ | _O(k)_ | Hard ||
198| [House Robber](https://leetcode.com/problems/house-robber/)| [Python](./Python/house-robber.py) | _O(n)_          | _O(1)_          | Easy           ||
213| [House Robber II](https://leetcode.com/problems/house-robber-ii/)| [C++](./C++/house-robber-ii.cpp) [Python](./Python/house-robber-ii.py) | _O(n)_          | _O(1)_          | Medium           ||
221| [Maximal Square](https://leetcode.com/problems/maximal-square/)| [C++](./C++/maximal-square.cpp) [Python](./Python/maximal-square.py) | _O(n^2)_         | _O(n)_          | Medium           | EPI |
256| [Paint House](https://leetcode.com/problems/paint-house/) | [C++](./C++/paint-house.cpp) [Python](./Python/paint-house.py) | _O(n)_| _O(1)_| Medium |📖||
265| [Paint House II](https://leetcode.com/problems/paint-house-ii/) | [C++](./C++/paint-house-ii.cpp) [Python](./Python/paint-house-ii.py) | _O(n * k)_| _O(k)_| Hard |📖||
276| [Paint Fence](https://leetcode.com/problems/paint-fence/) | [C++](./C++/paint-fence.cpp) [Python](./Python/paint-fence.py) | _O(n)_| _O(1)_| Easy |📖||
279| [Perfect Squares](https://leetcode.com/problems/perfect-squares/)| [C++](./C++/perfect-squares.cpp) [Python](./Python/perfect-squares.py) | _O(n * sqrt(n))_         | _O(n)_          | Medium           ||  Hash |

--- 

##Backtracking
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
126| [Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)   |[Python](./Python/word-ladder-ii.py) | _O(n * d)_ | _O(d)_         | Hard         ||

--- 

##Greedy
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
11| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)| [Python](./Python/container-with-most-water.py) | _O(n)_ | _O(1)_ | Medium ||
42| [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | [Python](./Python/trapping-rain-water.py) | _O(n)_ | _O(1)_ | Hard || Tricky
44| [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) | [Python](./Python/wildcard-matching.py) | _O(m + n)_ | _O(1)_    | Hard           || Tricky
45| [Jump Game II](https://leetcode.com/problems/jump-game-ii/)  | [Python](./Python/jump-game-ii.py) | _O(n)_        | _O(1)_          | Hard           ||
55| [Jump Game](https://leetcode.com/problems/jump-game/)     | [Python](./Python/jump-game.py)  | _O(n)_          | _O(1)_          | Medium         ||
84| [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) | [Python](./Python/largest-rectangle-in-histogram.py) | _O(n)_ | _O(n)_ | Hard || Tricky
122| [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)| [Python](./Python/best-time-to-buy-and-sell-stock-ii.py) | _O(n)_ | _O(1)_ | Medium ||
134| [Gas Station](https://leetcode.com/problems/gas-station/)| [Python](./Python/gas-station.py)   | _O(n)_          | _O(1)_          | Medium         ||
135| [Candy](https://leetcode.com/problems/candy/)| [Python](./Python/candy.py) | _O(n)_ | _O(n)_ | Hard ||

---
##Design
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
284| [Peeking Iterator](https://leetcode.com/problems/peeking-iterator/)| [C++](./C++/peeking-iterator.cpp) [Python](./Python/peeking-iterator.py) | _O(1)_ | _O(1)_ | Medium ||

---

##SQL
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
175| [Combine Two Tables](https://leetcode.com/problems/combine-two-tables/) | [MySQL](./MySQL/combine-two-tables.sql) | _O(m + n)_   | _O(m + n)_ | Easy     ||
176| [Second Highest Salary](https://leetcode.com/problems/second-highest-salary/) | [MySQL](./MySQL/second-highest-salary.sql) | _O(n)_ | _O(1)_ | Easy         ||
177| [Nth Highest Salary](https://leetcode.com/problems/nth-highest-salary/) | [MySQL](./MySQL/nth-highest-salary.sql) | _O(n^2)_   | _O(n)_ | Medium         ||
178| [Rank Scores](https://leetcode.com/problems/rank-scores/) | [MySQL](./MySQL/rank-scores.sql) | _O(n^2)_        | _O(n)_          | Medium         ||
180| [Consecutive Numbers](https://leetcode.com/problems/consecutive-numbers/) | [MySQL](./MySQL/consecutive-numbers.sql) | _O(n)_   | _O(n)_ | Medium         ||
181| [Employees Earning More Than Their Managers](https://leetcode.com/problems/employees-earning-more-than-their-managers/) | [MySQL](./MySQL/employees-earning-more-than-their-managers.sql) | _O(n^2)_   | _O(1)_ | Easy     ||
182| [Duplicate Emails](https://leetcode.com/problems/duplicate-emails/) | [MySQL](./MySQL/duplicate-emails.sql) | _O(n^2)_ | _O(n)_       | Easy           ||
183| [Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/) | [MySQL](./MySQL/customers-who-never-order.sql) | _O(n^2)_ | _O(1)_       | Easy           ||
184| [Department Highest Salary](https://leetcode.com/problems/department-highest-salary/) | [MySQL](./MySQL/department-highest-salary.sql) | _O(n^2)_   | _O(n)_ | Medium         ||
185| [Department Top Three Salaries](https://leetcode.com/problems/department-top-three-salaries/) | [MySQL](./MySQL/department-top-three-salaries.sql) | _O(n^2)_   | _O(n)_ | Hard         ||
196| [Delete Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails/) | [MySQL](./MySQL/delete-duplicate-emails.sql) | _O(n^2)_ | _O(n)_       | Easy           ||
197| [Rising Temperature](https://leetcode.com/problems/rising-temperature/) | [MySQL](./MySQL/rising-temperature.sql) | _O(n^2)_ | _O(n)_       | Easy           ||
262| [Trips and Users ](https://leetcode.com/problems/trips-and-users/) | [MySQL](./MySQL/trips-and-users.sql) | _O((t * u) + tlogt)_ | _O(t)_       | Hard           ||

---

##Shell Script
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
192 | [Word Frequency](https://leetcode.com/problems/word-frequency/) | [Shell](./Shell/word-frequency.sh) | _O(n)_     | _O(k)_          | Medium         ||
193 | [Valid Phone Numbers](https://leetcode.com/problems/valid-phone-numbers/) | [Shell](./Shell/valid-phone-numbers.sh) | _O(n)_ | _O(1)_    | Easy           ||
194 | [Transpose File](https://leetcode.com/problems/transpose-file/) | [Shell](./Shell/transpose-file.sh) | _O(n^2)_   | _O(n^2)_        | Medium         ||
195 | [Tenth Line](https://leetcode.com/problems/tenth-line/) | [Shell](./Shell/tenth-line.sh)    | _O(n)_          | _O(1)_          | Easy           ||
