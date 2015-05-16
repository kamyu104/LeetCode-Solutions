LeetCode
======== 

Up to date (2015-05-16), there are `195` Algorithms / `12` Database / `4` Shell problems on [LeetCode Online Judge](https://oj.leetcode.com/).
The number of problems is increasing recently.
Here is the classification of all `211` problems.
For extra problems and solutions, you can see my [LintCode](https://github.com/kamyu104/LintCode) repo.
I'll keep updating for full summary and better solutions. Stay tuned for updates.

--- 
Algorithms
====

* [Bit Manipulation](https://github.com/kamyu104/LeetCode#bit-manipulation)
* [Array](https://github.com/kamyu104/LeetCode#array)
* [String](https://github.com/kamyu104/LeetCode#string)
* [Linked List](https://github.com/kamyu104/LeetCode#linked-list)
* [Stack](https://github.com/kamyu104/LeetCode#stack)
* [Heap](https://github.com/kamyu104/LeetCode#heap)
* [Tree](https://github.com/kamyu104/LeetCode#tree)
* [Hash Table](https://github.com/kamyu104/LeetCode#hash-table)
* [Data Structure](https://github.com/kamyu104/LeetCode#data-structure)
* [Math](https://github.com/kamyu104/LeetCode#math)
* [Two Pointer](https://github.com/kamyu104/LeetCode#two-pointer)
* [Sort](https://github.com/kamyu104/LeetCode#sort)
* [Brute Force Search](https://github.com/kamyu104/LeetCode#brute-force-search)
* [Divide and Conquer](https://github.com/kamyu104/LeetCode#divide-and-conquer)
* [Binary Search](https://github.com/kamyu104/LeetCode#binary-search)
* [Breadth-First Search](https://github.com/kamyu104/LeetCode#breadth-first-search)
* [Depth-First Search](https://github.com/kamyu104/LeetCode#depth-first-search)
* [Dynamic Programming](https://github.com/kamyu104/LeetCode#dynamic-programming)
* [Backtracking](https://github.com/kamyu104/LeetCode#backtracking)
* [Greedy](https://github.com/kamyu104/LeetCode#greedy)


Database
===

* [SQL](https://github.com/kamyu104/LeetCode#sql)


Shell
===

* [Shell Script](https://github.com/kamyu104/LeetCode#shell-script)

---

##Bit Manipulation
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
136 | [Single Number](https://oj.leetcode.com/problems/single-number/) | [Python](./Python/single-number.py) | _O(n)_       | _O(1)_          | Medium         ||
137 | [Single Number II](https://oj.leetcode.com/problems/single-number-ii/) | [Python](./Python/single-number-ii.py) | _O(n)_ | _O(1)_          | Medium         ||
190 | [Reverse Bits](https://oj.leetcode.com/problems/reverse-bits/)  | [Python](./Python/reverse-bits.py) | _O(n)_        | _O(1)_          | Easy           ||
191  |[Number of 1 Bits](https://oj.leetcode.com/problems/number-of-1-bits/) | [Python](./Python/number-of-1-bits.py) | _O(m)_ | _O(1)_          | Easy           ||
201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/) | [Python](./Python/bitwise-and-of-numbers-range.py) | _O(1)_ | _O(1)_ | Medium ||

--- 

##Array

  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
15 | [3 Sum](https://oj.leetcode.com/problems/3sum/)         | [Python](./Python/3sum.py)       | _O(n^2)_        | _O(1)_          | Medium         ||
16 | [3 Sum Closest](https://oj.leetcode.com/problems/3sum-closest/) | [Python](./Python/3sum-closest.py)| _O(n^2)_       | _O(1)_          | Medium         ||
26 | [Remove Duplicates from Sorted Array](https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/)| [Python](./Python/remove-duplicates-from-sorted-array.py) | _O(n)_       | _O(1)_         | Easy           ||
27 | [Remove Element](https://oj.leetcode.com/problems/remove-element/) | [Python](./Python/remove-element.py) | _O(n)_      | _O(1)_         | Easy           ||
31 | [Next Permutation](https://oj.leetcode.com/problems/next-permutation/)| [Python](./Python/next-permutation.py) | _O(n)_  | _O(1)_          | Medium         || Tricky
41 | [First Missing Positive](https://oj.leetcode.com/problems/first-missing-positive/)| [Python](./Python/first-missing-positive.py) | _O(n)_ | _O(1)_ | Hard         || Tricky
48 | [Rotate Image](https://oj.leetcode.com/problems/rotate-image/)   | [Python](./Python/rotate-image.py) | _O(n^2)_      | _O(1)_         | Medium         ||
54 | [Spiral Matrix](https://oj.leetcode.com/problems/spiral-matrix/) | [Python](./Python/spiral-matrix.py) | _O(m * n)_    | _O(1)_         | Medium         ||
59 | [Spiral Matrix II](https://oj.leetcode.com/problems/spiral-matrix-ii/) | [Python](./Python/spiral-matrix-ii.py) | _O(m * n)_ | _O(1)_      | Medium         ||
66 | [Plus One](https://oj.leetcode.com/problems/plus-one/)      | [Python](./Python/plus-one.py)   | _O(n)_           | _O(1)_         | Easy           || 
73 | [Set Matrix Zeroes](https://oj.leetcode.com/problems/set-matrix-zeroes/) | [Python](./Python/set-matrix-zeroes.py) | _O(m * n)_ | _O(1)_    | Medium         ||
80 | [Remove Duplicates from Sorted Array II](https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)| [Python](./Python/remove-duplicates-from-sorted-array-ii.py) | _O(n)_       | _O(1)_         | Medium         ||
118 | [Pascal's Triangle](https://oj.leetcode.com/problems/pascals-triangle/)| [Python](./Python/pascals-triangle.py) | _O(n^2)_ | _O(n)_        | Easy           || 
119 | [Pascal's Triangle II](https://oj.leetcode.com/problems/pascals-triangle-ii/)| [Python](./Python/pascals-triangle-ii.py) | _O(n^2)_ | _O(n)_  | Easy           ||
121 | [Best Time to Buy and Sell Stock](https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/)| [Python](./Python/best-time-to-buy-and-sell-stock.py) | _O(n)_ | _O(1)_ | Medium ||
128 | [Longest Consecutive Sequence](https://oj.leetcode.com/problems/longest-consecutive-sequence/)| [Python](./Python/longest-consecutive-sequence.py) | _O(n)_ | _O(n)_ | Hard         || Tricky
157 | [Read N Characters Given Read4](https://oj.leetcode.com/problems/read-n-characters-given-read4/) | [Python](/Python/read-n-characters-given-read4.py) | _O(n)_ | _O(1)_ | Easy           ||
158 | [Read N Characters Given Read4 II - Call multiple times](https://oj.leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/) | [Python](./Python/read-n-characters-given-read4-ii-call-multiple-times.py) | _O(n)_ | _O(1)_ | Hard ||
163 | [Missing Ranges](https://oj.leetcode.com/problems/missing-ranges/)| [Python](./Python/missing-ranges.py) | _O(n)_      | _O(1)_          | Medium         ||
169 | [Majority Element](https://oj.leetcode.com/problems/majority-element/) | [Python](./Python/majority-element.py) | _O(n)_ | _O(1)_          | Easy           |
189 | [Rotate Array](https://oj.leetcode.com/problems/rotate-array/)   | [Python](./Python/rotate-array.py) | _O(n)_        | _O(1)_         | Easy           ||
209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | [Python] (./Python/minimum-size-subarray-sum.py) | _O(n)_ | _O(1)_ |  Medium ||

--- 

##String
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
5| [Longest Palindromic Substring](https://oj.leetcode.com/problems/longest-palindromic-substring/) | [Python](./Python/longest-palindromic-substring.py) | _O(n)_ | _O(n)_ |  Medium || `Manacher's Algorithm`
6| [ZigZag Conversion](https://oj.leetcode.com/problems/zigzag-conversion/) | [Python](./Python/zigzag-conversion.py) | _O(n)_ | _O(1)_        | Easy           ||
8| [String to Integer (atoi)](https://oj.leetcode.com/problems/string-to-integer-atoi/) | [Python](./Python/string-to-integer-atoi.py) | _O(n)_ | _O(1)_ | Easy      ||
14| [Longest Common Prefix](https://oj.leetcode.com/problems/longest-common-prefix/) | [Python](./Python/longest-common-prefix.py) | _O(n1 + n2 + ...)_   | _O(1)_  | Easy           ||
20| [Valid Palindrome](https://oj.leetcode.com/problems/valid-palindrome/) | [Python](./Python/valid-palindrome.py) | _O(n)_  | _O(1)_         | Easy           ||
28| [Implement strStr()](https://oj.leetcode.com/problems/implement-strstr/) | [Python](./Python/implement-strstr.py) | _O(n + m)_   | _O(m)_  | Easy           || `KMP Algorithm`
38| [Count and Say](https://oj.leetcode.com/problems/compare-version-numbers/) | [Python](./Python/compare-version-numbers.py)| _O(n * 2^n)_  | _O(2^n)_        | Easy           ||
43| [Multiply Strings](https://oj.leetcode.com/problems/multiply-strings/) | [Python](./Python/multiply-strings.py) | _O(m * n)_ | _O(m + n)_  | Medium         ||
58| [Length of Last Word](https://oj.leetcode.com/problems/length-of-last-word/) | [Python](./Python/length-of-last-word.py) | _O(n)_   | _O(1)_  | Easy           ||
67| [Add Binary](https://oj.leetcode.com/problems/add-binary/)    | [Python](./Python/add-binary.py) | _O(n)_          | _O(1)_          | Easy           ||
68| [Text Justification](https://oj.leetcode.com/problems/text-justification/) | [Python](./Python/text-justification.py) | _O(n)_ | _O(1)_      | Hard           ||
151| [Reverse Words in a String](https://oj.leetcode.com/problems/reverse-words-in-a-string/) | [Python](./Python/reverse-words-in-a-string.py) | _O(n)_ | _O(n)_ | Medium         ||
161| [One Edit Distance](https://oj.leetcode.com/problems/one-edit-distance/) | [Python](./Python/one-edit-distance.py) | _O(m + n)_ | _O(1)_    | Medium         ||
165| [Compare Version Numbers](https://oj.leetcode.com/problems/count-and-say/) | [Python](./Python/count-and-say.py) | _O(n)_ | _O(1)_ | Easy     ||
186| [Reverse Words in a String II](https://oj.leetcode.com/problems/reverse-words-in-a-string-ii/) | [Python](./Python/reverse-words-in-a-string-ii.py) | _O(n)_ | _O(1)_ | Medium         ||
205| [Isomorphic Strings](https://oj.leetcode.com/problems/isomorphic-strings/) | [Python](./Python/isomorphic-strings.py) | _O(n)_ | _O(1)_       | Easy           ||    

--- 

##Linked List
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
2| [Add Two Numbers](https://oj.leetcode.com/problems/add-two-numbers/) | [Python](./Python/add-two-numbers.py) | _O(n)_   | _O(1)_          | Medium         ||
24| [Swap Nodes in Pairs](https://oj.leetcode.com/problems/swap-nodes-in-pairs/)| [Python](./Python/swap-nodes-in-pairs.py)   | _O(n)_          | _O(1)_          | Medium         ||
25| [Reverse Nodes in k-Group](https://oj.leetcode.com/problems/reverse-nodes-in-k-group/)| [Python](./Python/reverse-nodes-in-k-group.py) | _O(n)_       | _O(1)_         | Hard         ||
61| [Rotate List](https://oj.leetcode.com/problems/rotate-list/)| [Python](./Python/rotate-list.py)   | _O(n)_          | _O(1)_          | Medium         ||  
82| [Remove Duplicates from Sorted List II](https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)| [Python](./Python/remove-duplicates-from-sorted-list-ii.py) | _O(n)_       | _O(1)_         | Medium         ||
83| [Remove Duplicates from Sorted List](https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/)| [Python](./Python/remove-duplicates-from-sorted-list.py) | _O(n)_       | _O(1)_         | Easy           ||
92| [Reverse Linked List II](https://oj.leetcode.com/problems/reverse-linked-list-ii/)| [Python](./Python/reverse-linked-list-ii.py) | _O(n)_       | _O(1)_         | Medium         || 
138| [Copy List with Random Pointer](https://oj.leetcode.com/problems/copy-list-with-random-pointer/) | [Python](./Python/copy-list-with-random-pointer.py) | _O(n)_   | _O(1)_          | Hard         ||
160| [Intersection of Two Linked Lists](https://oj.leetcode.com/problems/intersection-of-two-linked-lists/)| [Python](./Python/intersection-of-two-linked-lists.py) | _O(m + n)_ | _O(1)_         | Easy           ||
203| [Remove Linked List Elements](https://oj.leetcode.com/problems/remove-linked-list-elements/)| [Python](./Python/remove-linked-list-elements.py) | _O(n)_       | _O(1)_         | Easy         || 
206| [Reverse Linked List](https://oj.leetcode.com/problems/reverse-linked-list/)| [Python](./Python/reverse-linked-list.py) | _O(n)_       | _O(1)_         | Easy         || 

--- 

##Stack
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
20| [Valid Parentheses](https://oj.leetcode.com/problems/valid-parentheses/)| [Python](./Python/valid-parentheses.py) | _O(n)_        | _O(n)_          | Easy           ||
32| [Longest Valid Parentheses](https://oj.leetcode.com/problems/longest-valid-parentheses/)| [Python](./Python/longest-valid-parentheses.py) | _O(n)_ | _O(1)_ | Hard   ||
71| [Simplify Path](https://oj.leetcode.com/problems/simplify-path/)| [Python](./Python/simplify-path.py) | _O(n)_        | _O(n)_          | Medium         ||
101| [Symmetric Tree](https://oj.leetcode.com/problems/symmetric-tree/)| [Python](./Python/symmetric-tree.py) | _O(n)_      | _O(h)_          | Easy           ||
150| [Evaluate Reverse Polish Notation](https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/)| [Python](./Python/evaluate-reverse-polish-notation.py)| _O(n)_| _O(n)_| Medium          ||
155| [Min Stack](https://oj.leetcode.com/problems/min-stack/)     | [Python](./Python/min-stack.py)  | _O(n)_          | _O(1)_          | Easy           ||
173| [Binary Search Tree Iterator](https://oj.leetcode.com/problems/binary-search-tree-iterator/) | [Python](./Python/binary-search-tree-iterator.py) | _O(1)_| _O(h)_| Medium ||   

--- 

##Heap
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
23| [Merge k Sorted Lists](https://oj.leetcode.com/problems/merge-k-sorted-lists/) | [Python](./Python/merge-k-sorted-lists.py) | _O(nlogk)_| _O(k)_| Hard          ||

--- 

##Tree
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
94 | [Binary Tree Inorder Traversal](https://oj.leetcode.com/problems/binary-tree-inorder-traversal/)  | [Python](./Python/binary-tree-inorder-traversal.py) | _O(n)_| _O(1)_| Medium           || `Morris Traversal` | 
99 | [Recover Binary Search Tree](https://oj.leetcode.com/problems/recover-binary-search-tree/) | [Python](./Python/recover-binary-search-tree.py) | _O(n)_| _O(1)_| Hard  || `Morris Traversal` 
144 | [Binary Tree Preorder Traversal](https://oj.leetcode.com/problems/binary-tree-preorder-traversal/) | [Python](./Python/binary-tree-preorder-traversal.py) | _O(n)_| _O(1)_| Medium || `Morris Traversal` 
145 | [Binary Tree Postorder Traversal](https://oj.leetcode.com/problems/binary-tree-postorder-traversal/) | [Python](./Python/binary-tree-postorder-traversal.py) | _O(n)_| _O(1)_| Hard  || `Morris Traversal` 
208 | [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) | [Python](./Python/implement-trie-prefix-tree.py) | _O(n)_ | _O(1)_ | Medium || Trie
211 | [Add and Search Word - Data structure design ](https://leetcode.com/problems/add-and-search-word-data-structure-design/) | [C++](./C++/add-and-search-word-data-structure-design.cpp) [Python](./Python/add-and-search-word-data-structure-design.py) | _O(min(n, h))_ | _O(min(n, h))_ | Medium || Trie, DFS

--- 

##Hash Table
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
1| [Two Sum](https://oj.leetcode.com/problems/two-sum/)      | [Python](./Python/two-sum.py)      | _O(n)_         | _O(n)_          | Medium         ||
3| [Longest Substring Without Repeating Characters](https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/) | [Python](./Python/longest-substring-without-repeating-characters.py) | _O(n)_ | _O(1)_ | Medium ||
18| [4 Sum](https://oj.leetcode.com/problems/4sum/)         |[Python](./Python/4sum.py)        | _O(n^2 * p)_    | _O(n^2 * p)_    | Medium         ||
30| [Substring with Concatenation of All Words](https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/) | [Python](./Python/substring-with-concatenation-of-all-words.py) | _O(m * n * k)_ | _O(n * k)_ | Hard          ||
36| [Valid Sudoku](https://oj.leetcode.com/problems/valid-sudoku/) | [Python](./Python/valid-sudoku.py) | _O(n^2)_         | _O(n)_          | Easy           ||
49| [Anagrams](https://oj.leetcode.com/problems/anagrams/)     | [Python](./Python/anagrams.py)   | _O(n)_          | _O(n)_          | Medium         ||
76| [Minimum Window Substring](https://oj.leetcode.com/problems/minimum-window-substring/) | [Python](./Python/minimum-window-substring.py) | _O(n)_ | _O(k)_ | Hard          ||
149| [Max Points on a Line](https://oj.leetcode.com/problems/max-points-on-a-line/) | [Python](./Python/max-points-on-a-line.py) | _O(n^2)_ | _O(n)_ | Hard          ||
159| [Longest Substring with At Most Two Distinct Characters](https://oj.leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)| [Python](./Python/longest-substring-with-at-most-two-distinct-characters.py) | _O(n^2)_ | _O(1)_ | Hard         ||
167| [Two Sum III - Data structure design](https://oj.leetcode.com/problems/two-sum-iii-data-structure-design/) | [Python](./Python/two-sum-iii-data-structure-design.py) | _O(n)_ | _O(n)_ | Easy ||
187| [Repeated DNA Sequences](https://oj.leetcode.com/problems/repeated-dna-sequences/) | [Python](./Python/repeated-dna-sequences.py) | _O(n)_       | _O(n)_          | Medium         ||
202| [Happy Number](https://oj.leetcode.com/problems/happy-number/)      | [Python](./Python/happy-number.py)   | _O(k)_  | _O(k)_          | Easy          ||
204| [Count Primes](https://oj.leetcode.com/problems/count-primes/)  | [Python](./Python/count-primes.py) | _O(n)_        | _O(n)_          | Easy           ||

--- 

##Data Structure
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[LRU Cache]     | [lru-cache.py]  | _O(1)_          | _O(n)_          | Hard         |


[LRU Cache]:https://oj.leetcode.com/problems/lru-cache/
[lru-cache.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/lru-cache.py

--- 

##Math
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Divide Two Integers] | [divide-two-integers.py]    | _O(logn)_       | _O(1)_         | Medium         |
[Excel Sheet Column Title] | [excel-sheet-column-title.py] | _O(logn)_ | _O(1)_ | Easy |
[Excel Sheet Column Number] | [excel-sheet-column-number.py] | _O(n)_ | _O(1)_ | Easy  |
[Factorial Trailing Zeroes] | [factorial-trailing-zeroes.py]  | _O(logn)_ | _O(1)_ | Easy         |
[Fraction to Recurring Decimal] | [fraction-to-recurring-decimal.py]  | _O(logn)_ | _O(1)_ | Medium         |
[Gray Code]     | [gray-code.py]  | _O(2^n)_        | _O(1)_          | Medium         |
[Integer to Roman] | [integer-to-roman.py] | _O(n)_ | _O(1)_          | Medium         |
[Palindrome Number] | [palindrome-number.py] | _O(1)_ | _O(1)_        | Easy           |
[Permutation Sequence] | [permutation-sequence.py] | _O(n^2)_ | _O(n)_  | Medium         | `Cantor Ordering`
[Reverse Integer] | [reverse-integer.py] | _O(logn)_ | _O(1)_         | Easy           |
[Roman to Integer] | [roman-to-integer.py] | _O(n)_ | _O(1)_          | Easy           |
[Valid Number] | [valid-number.py] | _O(n)_         | _O(1)_          | Hard           | `Automata`

[Divide Two Integers]:https://oj.leetcode.com/problems/divide-two-integers/
[divide-two-integers.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/divide-two-integers.py
[Excel Sheet Column Title]:https://oj.leetcode.com/problems/excel-sheet-column-title/
[excel-sheet-column-title.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/excel-sheet-column-title.py
[Excel Sheet Column Number]:https://oj.leetcode.com/problems/excel-sheet-column-number/
[excel-sheet-column-number.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/excel-sheet-column-number.py
[Factorial Trailing Zeroes]:https://oj.leetcode.com/problems/factorial-trailing-zeroes/
[factorial-trailing-zeroes.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/factorial-trailing-zeroes.py
[Fraction to Recurring Decimal]:https://oj.leetcode.com/problems/fraction-to-recurring-decimal/
[fraction-to-recurring-decimal.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/fraction-to-recurring-decimal.py
[Gray Code]:https://oj.leetcode.com/problems/gray-code/
[gray-code.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/gray-code.py
[Integer to Roman]:https://oj.leetcode.com/problems/integer-to-roman/
[integer-to-roman.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/integer-to-roman.py
[Palindrome Number]:https://oj.leetcode.com/problems/palindrome-number/
[palindrome-number.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/palindrome-number.py
[Permutation Sequence]:https://oj.leetcode.com/problems/permutation-sequence/
[permutation-sequence.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/permutation-sequence.py
[Reverse Integer]:https://oj.leetcode.com/problems/reverse-integer/
[reverse-integer.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/reverse-integer.py
[Roman to Integer]:https://oj.leetcode.com/problems/roman-to-integer/
[roman-to-integer.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/roman-to-integer.py
[Valid Number]:https://oj.leetcode.com/problems/valid-number/
[valid-number.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/valid-number.py


--- 

##Sort
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Insert Interval]| [insert-interval.py] | _O(n)_    | _O(1)_          | Hard           |
[Insertion Sort List]|[insertion-sort-list.py] | _O(n^2)_ | _O(1)_    | Medium         |
[Largest Number] | [largest-number.py] | _O(nlogn)_   | _O(1)_        | Medium         |
[Maximum Gap]   | [maximum-gap.py]| _O(n)_          | _O(n)_          | Hard           | Tricky 
[Merge Intervals]| [merge-intervals.py] | _O(nlogn)_  | _O(1)_        | Hard           |
[Merge Sorted Array]| [merge-sorted-array.py] | _O(n)_ | _O(1)_       | Easy           |
[Merge Two Sorted Lists]| [merge-two-sorted-lists.py] | _O(n)_ | _O(1)_ | Easy         |
[Sort Colors]   | [sort-colors.py] | _O(n)_         | _O(1)_          | Medium         |
[Sort List]     | [sort-list.py]  | _O(nlogn)_      | _O(logn)_       | Medium         |

[Insert Interval]:https://oj.leetcode.com/problems/insert-interval/
[insert-interval.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/insert-interval.py
[Insertion Sort List]:https://oj.leetcode.com/problems/insertion-sort-list/
[insertion-sort-list.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/insertion-sort-list.py
[Largest Number]:https://oj.leetcode.com/problems/largest-number/
[largest-number.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/largest-number.py
[Maximum Gap]:https://oj.leetcode.com/problems/maximum-gap/
[maximum-gap.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/maximum-gap.py
[Merge Intervals]:https://oj.leetcode.com/problems/merge-intervals/
[merge-intervals.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/merge-intervals.py
[Merge Sorted Array]:https://oj.leetcode.com/problems/merge-sorted-array/
[merge-sorted-array.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/merge-sorted-array.py
[Merge Two Sorted Lists]:https://oj.leetcode.com/problems/merge-two-sorted-lists/
[merge-two-sorted-lists.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/merge-two-sorted-lists.py
[Sort Colors]:https://oj.leetcode.com/problems/sort-colors/
[sort-colors.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/sort-colors.py
[Sort List]:https://oj.leetcode.com/problems/sort-list/
[sort-list.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/sort-list.py

---

##Two Pointer
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Linked List Cycle]| [linked-list-cycle.py] | _O(n)_ | _O(1)_         | Medium         | 
[Linked List Cycle II]| [linked-list-cycle-ii.py] | _O(n)_ | _O(1)_   | Medium         |
[Partition List]| [partition-list.py] | _O(n)_       | _O(1)_         | Medium         | 
[Remove Nth Node From End of List]| [remove-nth-node-from-end-of-list.py] | _O(n)_       | _O(1)_         | Easy         | 
[Reorder List]| [reorder-list.py] | _O(n)_          |  _O(1)_         | Medium         |  
[Two Sum II - Input array is sorted] | [two-sum-ii-input-array-is-sorted.py] | _O(n)_   | _O(1)_         | Medium         |

[Linked List Cycle]:https://oj.leetcode.com/problems/linked-list-cycle/
[linked-list-cycle.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/linked-list-cycle.py
[Linked List Cycle II]:https://oj.leetcode.com/problems/linked-list-cycle-ii/
[linked-list-cycle-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/linked-list-cycle-ii.py
[Partition List]:https://oj.leetcode.com/problems/partition-list/
[partition-list.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/partition-list.py
[Remove Nth Node From End of List]:https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
[remove-nth-node-from-end-of-list.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/remove-nth-node-from-end-of-list.py
[Reorder List]:https://oj.leetcode.com/problems/reorder-list/
[reorder-list.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/reorder-list.py
[Two Sum II - Input array is sorted]:https://oj.leetcode.com/problems/two-sum-ii-input-array-is-sorted/
[two-sum-ii-input-array-is-sorted.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/two-sum-ii-input-array-is-sorted.py

---

##Brute Force Search
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Letter Combinations of a Phone Number]| [letter-combinations-of-a-phone-number.py] | _O(n * 4^n)_ | _O(n)_ | Medium |
[Permutations]| [permutations.py] | _O(n!)_         | _O(n)_          | Medium         |
[Permutations II]| [permutations-ii.py] | _O(n!)_   | _O(n)_          | Hard           |
[Subsets]       | [subsets.py]    | _O(n * 2^n)_    | _O(1)_          | Medium         |
[Subsets II]    | [subsets-ii.py] | _O(n * 2^n)_    | _O(1)_          | Medium         |

[Letter Combinations of a Phone Number]:https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
[letter-combinations-of-a-phone-number.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/letter-combinations-of-a-phone-number.py
[Permutations]:https://oj.leetcode.com/problems/permutations/
[permutations.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/permutations.py
[Permutations II]:https://oj.leetcode.com/problems/permutations-ii/
[permutations-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/permutations-ii.py
[Subsets]:https://oj.leetcode.com/problems/subsets/
[subsets.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/subsets.py
[Subsets II]:https://oj.leetcode.com/problems/subsets-ii/
[subsets-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/subsets-ii.py

--- 

##Divide and Conquer
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Balanced Binary Tree] | [balanced-binary-tree.py] | _O(n)_| _O(h)_   | Easy           |
[Binary Tree Maximum Path Sum]| [binary-tree-maximum-path-sum.py] | _O(n)_| _O(h)_| Hard  |  
[Binary Tree Upside Down] | [binary-tree-upside-down.py] | _O(n)_ | _O(1)_ | Medium    | 
[Construct Binary Tree from Inorder and Postorder Traversal] | [construct-binary-tree-from-inorder-and-postorder-traversal.py] | _O(n)_        | _O(n)_          | Medium         |
[Construct Binary Tree from Preorder and Inorder Traversal] | [construct-binary-tree-from-preorder-and-inorder-traversal.py] | _O(n)_        | _O(n)_          | Medium   
[Convert Sorted Array to Binary Search Tree] | [convert-sorted-array-to-binary-search-tree.py] | _O(n)_        | _O(logn)_          | Medium         |
[Convert Sorted List to Binary Search Tree] | [convert-sorted-list-to-binary-search-tree.py] | _O(n)_        | _O(logn)_          | Medium         |
[Flatten Binary Tree to Linked List]|[flatten-binary-tree-to-linked-list.py]| _O(n)_        | _O(h)_          | Medium         |
[Maximum Depth of Binary Tree]|[maximum-depth-of-binary-tree.py]| _O(n)_ | _O(h)_ | Easy |
[Minimum Depth of Binary Tree]|[minimum-depth-of-binary-tree.py]| _O(n)_ | _O(h)_ | Easy |
[Populating Next Right Pointers in Each Node]|[populating-next-right-pointers-in-each-node.py]| _O(n)_ | _O(1)_ | Medium |
[Same Tree]      |[same-tree.py]  | _O(n)_          | _O(h)_        | Easy          |
[Sum Root to Leaf Numbers] | [sum-root-to-leaf-numbers.py] | _O(n)_ | _O(h)_ | Medium |
[Unique Binary Search Trees II] | [unique-binary-search-trees-ii.py] | _O(4^n / n^(3/2)_      | _O(4^n / n^(3/2)_         | Medium         |
[Validate Binary Search Tree]|[validate-binary-search-tree.py]| _O(n)_ | _O(1)_ | Medium |

[Balanced Binary Tree]:https://oj.leetcode.com/problems/balanced-binary-tree/
[balanced-binary-tree.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/balanced-binary-tree.py
[Binary Tree Maximum Path Sum]:https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
[binary-tree-maximum-path-sum.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/binary-tree-maximum-path-sum.py
[Binary Tree Upside Down]:https://oj.leetcode.com/problems/binary-tree-upside-down/
[binary-tree-upside-down.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/binary-tree-upside-down.py
[Construct Binary Tree from Inorder and Postorder Traversal]:https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
[construct-binary-tree-from-inorder-and-postorder-traversal.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/construct-binary-tree-from-inorder-and-postorder-traversal.py
[Construct Binary Tree from Preorder and Inorder Traversal]:https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
[construct-binary-tree-from-preorder-and-inorder-traversal.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/construct-binary-tree-from-preorder-and-inorder-traversal.py
[Convert Sorted Array to Binary Search Tree]:https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
[convert-sorted-array-to-binary-search-tree.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/convert-sorted-array-to-binary-search-tree.py
[Convert Sorted List to Binary Search Tree]:https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
[convert-sorted-list-to-binary-search-tree.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/convert-sorted-list-to-binary-search-tree.py
[Flatten Binary Tree to Linked List]:https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
[flatten-binary-tree-to-linked-list.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/flatten-binary-tree-to-linked-list.py
[Maximum Depth of Binary Tree]:https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
[maximum-depth-of-binary-tree.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/maximum-depth-of-binary-tree.py
[Minimum Depth of Binary Tree]:https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
[minimum-depth-of-binary-tree.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/minimum-depth-of-binary-tree.py
[Populating Next Right Pointers in Each Node]:https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
[populating-next-right-pointers-in-each-node.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/populating-next-right-pointers-in-each-node.py
[Same Tree]:https://oj.leetcode.com/problems/same-tree/
[same-tree.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/same-tree.py
[Sum Root to Leaf Numbers]:https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
[sum-root-to-leaf-numbers.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/sum-root-to-leaf-numbers.py
[Unique Binary Search Trees II]:https://oj.leetcode.com/problems/unique-binary-search-trees-ii/
[unique-binary-search-trees-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/unique-binary-search-trees-ii.py
[Validate Binary Search Tree]:https://oj.leetcode.com/problems/validate-binary-search-tree/
[validate-binary-search-tree.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/validate-binary-search-tree.py


--- 

##Binary Search

Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Find Minimum in Rotated Sorted Array]         | [find-minimum-in-rotated-sorted-array.py]       | _O(logn)_        | _O(1)_          | Medium         |
[Find Minimum in Rotated Sorted Array II]      | [find-minimum-in-rotated-sorted-array-ii.py]       | _O(logn)_ ~ _O(n)_        | _O(1)_          | Hard         |
[Find Peak Element] | [find-peak-element.py]        | _O(logn)_       | _O(1)_          | Medium         |
[Median of Two Sorted Arrays] | [median-of-two-sorted-arrays.py] | _O(log(m + n))_ | _O(1)_ | Hard         |
[Pow(x, n)]     | [powx-n.py]     | _O(logn)_       | _O(logn)_       | Medium         |
[Search a 2D Matrix] | [search-a-2d-matrix.py] | _O(logm + logn)_ | _O(1)_ | Medium   |
[Search for a Range] | [search-for-a-range.py] | _O(logn)_ | _O(1)_   | Medium         |
[Search in Rotated Sorted Array] | [search-in-rotated-sorted-array.py] | _O(logn)_ | _O(1)_   | Hard         |
[Search in Rotated Sorted Array II] | [search-in-rotated-sorted-array-ii.py] | _O(logn)_ | _O(1)_   | Medium         |
[Search Insert Position] | [search-insert-position.py] | _O(logn)_ | _O(1)_   | Medium         |
[Sqrt(x)]       | [sqrtx.py]      | _O(logn)_        | _O(1)_         | Medium         |

[Find Minimum in Rotated Sorted Array]:https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
[find-minimum-in-rotated-sorted-array.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/find-minimum-in-rotated-sorted-array.py
[Find Minimum in Rotated Sorted Array II]:https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
[find-minimum-in-rotated-sorted-array-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/find-minimum-in-rotated-sorted-array-ii.py
[Find Peak Element]:https://oj.leetcode.com/problems/find-peak-element/
[find-peak-element.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/find-peak-element.py
[Median of Two Sorted Arrays]:https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
[median-of-two-sorted-arrays.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/median-of-two-sorted-arrays.py
[Pow(x, n)]:https://oj.leetcode.com/problems/powx-n/
[powx-n.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/powx-n.py
[Search a 2D Matrix]:https://oj.leetcode.com/problems/search-a-2d-matrix/
[search-a-2d-matrix.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/search-a-2d-matrix.py
[Search for a Range]:https://oj.leetcode.com/problems/search-for-a-range/
[search-for-a-range.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/search-for-a-range.py
[Search in Rotated Sorted Array]:https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
[search-in-rotated-sorted-array.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/search-in-rotated-sorted-array.py
[Search in Rotated Sorted Array II]:https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
[search-in-rotated-sorted-array-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/search-in-rotated-sorted-array-ii.py
[Search Insert Position]:https://oj.leetcode.com/problems/search-insert-position/
[search-insert-position.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/search-insert-position.py
[Sqrt(x)]:https://oj.leetcode.com/problems/sqrtx/
[sqrtx.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/sqrtx.py

--- 

##Breadth-First Search
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Binary Tree Level Order Traversal]| [binary-tree-level-order-traversal.py] | _O(n)_| _O(n)_| Easy  |  
[Binary Tree Level Order Traversal II]| [binary-tree-level-order-traversal-ii.py] | _O(n)_| _O(n)_| Easy  |
[Binary Tree Zigzag Level Order Traversal]| [binary-tree-zigzag-level-order-traversal.py] | _O(n)_| _O(n)_| Medium  |  
[Clone Graph]| [clone-graph.py]   | _O(n)_          | _O(n)_          | Medium         |
[Course Schedule](https://oj.leetcode.com/problems/course-schedule/)| [course-schedule.py](./Python/course-schedule.py)   | _O(\|V\| + \|E\|)_          | _O(\|E\|)_          | Medium         |
[Course Schedule II](https://oj.leetcode.com/problems/course-schedule-ii/)| [course-schedule-ii.py](./Python/course-schedule-ii.py)   | _O(\|V\| + \|E\|)_          | _O(\|E\|)_          | Medium         |
[Populating Next Right Pointers in Each Node II]|[populating-next-right-pointers-in-each-node-ii.py]| _O(n)_ | _O(1)_ | Hard |
[Surrounded Regions]|[surrounded-regions.py]| _O(m * n)_ | _O(m + n)_ | Medium         |
[Word Ladder]   |[word-ladder.py] | _O(n * d)_      | _O(d)_          | Medium         |

[Binary Tree Level Order Traversal]:https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
[binary-tree-level-order-traversal.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/binary-tree-level-order-traversal.py
[Binary Tree Level Order Traversal II]:https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
[binary-tree-level-order-traversal-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/binary-tree-level-order-traversal-ii.py
[Binary Tree Zigzag Level Order Traversal]:https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
[binary-tree-zigzag-level-order-traversal.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/binary-tree-zigzag-level-order-traversal.py
[Clone Graph]:https://oj.leetcode.com/problems/clone-graph/
[clone-graph.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/clone-graph.py
[Populating Next Right Pointers in Each Node II]:https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
[populating-next-right-pointers-in-each-node-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/populating-next-right-pointers-in-each-node-ii.py
[Surrounded Regions]:https://oj.leetcode.com/problems/surrounded-regions/
[surrounded-regions.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/surrounded-regions.py
[Word Ladder]:https://oj.leetcode.com/problems/word-ladder/
[word-ladder.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/word-ladder.py

--- 

##Depth-First Search
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Binary Tree Right Side View] | [binary-tree-right-side-view.py] | _O(n)_     | _O(h)_ | Medium  |
[Combination Sum]| [combination-sum.py] | _O(n^m)_    | _O(m)_          | Medium         |
[Combination Sum II]| [combination-sum-ii.py]| _O(n! / m!(n-m)!)_| _O(m)_         | Medium         |
[Combinations]  | [combinations.py] | _O(n!)_       | _O(n)_          | Medium         |
[Generate Parentheses]| [generate-parentheses.py]| _O(4^n / n^(3/2))_ | _O(n)_   | Medium         |
[N-Queens]      | [n-queens.py]   | _O(n!)_         | _O(n)_          | Hard           |
[N-Queens-II]   | [n-queens-ii.py] | _O(n!)_        | _O(n)_          | Hard           |
[Number of Islands] | [number-of-islands.py] | _O(m * n)_ | _O(m * n)_| Medium         |
[Palindrome Partitioning] | [palindrome-partitioning.py] | _O(n^2)_ ~ _O(2^n)_ | _O(n^2)_ | Medium |
[Path Sum]      | [path-sum.py]   | _O(n)_          | _O(h)_          | Easy           |
[Path Sum II]   | [path-sum-ii.py] | _O(n)_         | _O(h)_          | Medium         |
[Restore IP Addresses] | [restore-ip-addresses.py] | _O(n^m)_ ~ _O(3^4)_ | _O(n * m)_ ~ _O(3 * 4)_ | Medium         |
[Sudoku Solver] | [sudoku-solver.py] | _O((9!)^9)_  | _O(1)_          | Hard           |
[Word Search] | [word-search.py] | _O(m * n * l)_ | _O(l)_  | Medium         |

[Binary Tree Right Side View]:https://oj.leetcode.com/problems/binary-tree-right-side-view/
[binary-tree-right-side-view.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/binary-tree-right-side-view.py
[Combination Sum]:https://oj.leetcode.com/problems/combination-sum/
[combination-sum.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/combination-sum.py
[Combination Sum II]:https://oj.leetcode.com/problems/combination-sum-ii/
[combination-sum-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/combination-sum-ii.py
[Combinations]:https://oj.leetcode.com/problems/combinations/
[combinations.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/combinations.py
[Generate Parentheses]:https://oj.leetcode.com/problems/generate-parentheses/
[generate-parentheses.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/generate-parentheses.py
[N-Queens]:https://oj.leetcode.com/problems/n-queens/
[n-queens.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/n-queens.py
[N-Queens-II]:https://oj.leetcode.com/problems/n-queens-ii/
[n-queens-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/n-queens-ii.py
[Number of Islands]:https://leetcode.com/problems/number-of-islands/
[number-of-islands.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/number-of-islands.py
[Palindrome Partitioning]:https://oj.leetcode.com/problems/palindrome-partitioning/
[palindrome-partitioning.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/palindrome-partitioning.py
[Path Sum]:https://oj.leetcode.com/problems/path-sum/
[path-sum.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/path-sum.py
[Path Sum II]:https://oj.leetcode.com/problems/path-sum-ii/
[path-sum-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/path-sum-ii.py
[Restore IP Addresses]:https://oj.leetcode.com/problems/restore-ip-addresses/
[restore-ip-addresses.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/restore-ip-addresses.py
[Sudoku Solver]:https://oj.leetcode.com/problems/sudoku-solver/
[sudoku-solver.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/sudoku-solver.py
[Word Search]:https://oj.leetcode.com/problems/word-search/
[word-search.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/word-search.py

--- 

##Dynamic Programming
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Best Time to Buy and Sell Stock III]| [best-time-to-buy-and-sell-stock-iii.py] | _O(n)_ | _O(1)_ | Hard |
[Best Time to Buy and Sell Stock IV]| [best-time-to-buy-and-sell-stock-iv.py] | _O(k * n)_ | _O(k)_ | Hard |
[Climbing Stairs]| [climbing-stairs.py] | _O(n)_    | _O(1)_          | Easy           |
[Decode Ways]   | [decode-ways.py]| _O(n)_          | _O(1)_          | Medium         |
[Distinct Subsequences]|[distinct-subsequences.py]| _O(n^2)_ | _O(n)_ | Hard           |
[Dungeon Game]  | [dungeon-game.py]| _O(m * n)_     | _O(m + n)_      | Hard           |
[Edit Distance]|[edit-distance.py]| _O(m * n)_      | _O(m + n)_      | Hard           |
[House Robber]| [house-robber.py] | _O(n)_          | _O(1)_          | Easy           |
[Interleaving String]|[interleaving-string.py]| _O(m * n)_ | _O(m + n)_ | Hard         |
[Maximal Rectangle]|[maximal-rectangle.py]| _O(n^2)_ | _O(n)_         | Hard           |
[Maximum Product Subarray]|[maximum-product-subarray.py]| _O(n)_ | _O(1)_ | Medium     |
[Maximum Subarray]|[maximum-subarray.py]| _O(n)_     | _O(1)_         | Medium         |
[Minimum Path Sum]|[minimum-path-sum.py]| _O(m * n)_ | _O(m + n)_     | Medium         |
[Palindrome Partitioning II] | [palindrome-partitioning-ii.py] | _O(n^2)_ | _O(n^2)_ | Hard |
[Regular Expression Matching] | [regular-expression-matching.py] | _O(m * n)_ | _O(n)_ | Hard |
[Scramble String] | [scramble-string.py] | _O(n^4)_ | _O(n^3)_        | Hard           |
[Triangle]       | [triangle.py]   | _O(m * n)_      | _O(n)_         | Medium         |
[Unique Binary Search Trees] | [unique-binary-search-trees.py] | _O(n^2)_      | _O(n)_         | Medium         |
[Unique Paths]    | [unique-paths.py]| _O(m * n)_      | _O(m + n)_   | Medium         |
[Unique Paths II] | [unique-paths-ii.py] |  _O(m * n)_ | _O(m + n)_   | Medium         |
[Word Break]     | [word-break.py] |  _O(n^2)_         | _O(n)_       | Medium         |
[Word Break II]  | [word-break-ii.py] |  _O(n^2)_      | _O(n)_       | Hard           |

[Best Time to Buy and Sell Stock III]:https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
[best-time-to-buy-and-sell-stock-iii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/best-time-to-buy-and-sell-stock-iii.py
[Best Time to Buy and Sell Stock IV]:https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
[best-time-to-buy-and-sell-stock-iv.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/best-time-to-buy-and-sell-stock-iv.py
[Climbing Stairs]:https://oj.leetcode.com/problems/climbing-stairs/
[climbing-stairs.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/climbing-stairs.py
[Decode Ways]:https://oj.leetcode.com/problems/decode-ways/
[decode-ways.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/decode-ways.py
[Distinct Subsequences]:https://oj.leetcode.com/problems/distinct-subsequences/
[distinct-subsequences.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/distinct-subsequences.py
[Dungeon Game]:https://oj.leetcode.com/problems/dungeon-game/
[dungeon-game.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/dungeon-game.py
[Edit Distance]:https://oj.leetcode.com/problems/edit-distance/
[edit-distance.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/edit-distance.py
[House Robber]:https://oj.leetcode.com/problems/house-robber/
[house-robber.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/house-robber.py
[Interleaving String]:https://oj.leetcode.com/problems/interleaving-string/
[interleaving-string.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/interleaving-string.py
[Maximal Rectangle]:https://oj.leetcode.com/problems/maximal-rectangle/
[maximal-rectangle.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/maximal-rectangle.py
[Maximum Product Subarray]:https://oj.leetcode.com/problems/maximum-product-subarray/
[maximum-product-subarray.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/maximum-product-subarray.py
[Maximum Subarray]:https://oj.leetcode.com/problems/maximum-subarray/
[maximum-subarray.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/maximum-subarray.py
[Minimum Path Sum]:https://oj.leetcode.com/problems/minimum-path-sum/
[minimum-path-sum.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/minimum-path-sum.py
[Palindrome Partitioning II]:https://oj.leetcode.com/problems/palindrome-partitioning-ii/
[palindrome-partitioning-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/palindrome-partitioning-ii.py
[Regular Expression Matching]:https://oj.leetcode.com/problems/regular-expression-matching/
[regular-expression-matching.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/regular-expression-matching.py
[Scramble String]:https://oj.leetcode.com/problems/scramble-string/
[scramble-string.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/scramble-string.py
[Triangle]:https://oj.leetcode.com/problems/triangle/
[triangle.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/triangle.py
[Unique Binary Search Trees]:https://oj.leetcode.com/problems/unique-binary-search-trees/
[unique-binary-search-trees.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/unique-binary-search-trees.py
[Unique Paths]:https://oj.leetcode.com/problems/unique-paths/
[unique-paths.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/unique-paths.py
[Unique Paths II]:https://oj.leetcode.com/problems/unique-paths-ii/
[unique-paths-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/unique-paths-ii.py
[Word Break]:https://oj.leetcode.com/problems/word-break/
[word-break.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/word-break.py
[Word Break II]:https://oj.leetcode.com/problems/word-break-ii/
[word-break-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/word-break-ii.py

--- 

##Backtracking
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Word Ladder II]   |[word-ladder-ii.py] | _O(n * d)_ | _O(d)_         | Hard         |

[Word Ladder II]:https://oj.leetcode.com/problems/word-ladder-ii/
[word-ladder-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/word-ladder-ii.py

--- 

##Greedy
Problem         |  Solution       |  Time           | Space           | Difficulty     | Notes
--------------- | --------------- | --------------- | --------------- | -------------- | -----
[Best Time to Buy and Sell Stock II]| [best-time-to-buy-and-sell-stock-ii.py] | _O(n)_ | _O(1)_ | Medium |
[Candy]| [candy.py] | _O(n)_ | _O(n)_ | Hard |
[Container With Most Water]| [container-with-most-water.py] | _O(n)_ | _O(1)_ | Medium |
[Gas Station]| [gas-station.py]   | _O(n)_          | _O(1)_          | Medium         |
[Jump Game]     | [jump-game.py]  | _O(n)_          | _O(1)_          | Medium         |
[Jump Game II]  | [jump-game-ii.py] | _O(n)_        | _O(1)_          | Hard           |
[Largest Rectangle in Histogram] | [largest-rectangle-in-histogram.py] | _O(n)_ | _O(n)_ | Hard | Tricky
[Trapping Rain Water] | [trapping-rain-water.py] | _O(n)_ | _O(1)_ | Hard | Tricky
[Wildcard Matching] | [wildcard-matching.py] | _O(m + n)_ | _O(1)_    | Hard           | Tricky

[Best Time to Buy and Sell Stock II]:https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
[best-time-to-buy-and-sell-stock-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/best-time-to-buy-and-sell-stock-ii.py
[Candy]:https://oj.leetcode.com/problems/candy/
[candy.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/candy.py
[Container With Most Water]:https://oj.leetcode.com/problems/container-with-most-water/
[container-with-most-water.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/container-with-most-water.py
[Gas Station]:https://oj.leetcode.com/problems/gas-station/
[gas-station.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/gas-station.py
[Jump Game]:https://oj.leetcode.com/problems/jump-game/
[jump-game.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/jump-game.py
[Jump Game II]:https://oj.leetcode.com/problems/jump-game-ii/
[jump-game-ii.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/jump-game-ii.py
[Largest Rectangle in Histogram]:https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
[largest-rectangle-in-histogram.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/largest-rectangle-in-histogram.py
[Trapping Rain Water]:https://oj.leetcode.com/problems/trapping-rain-water/
[trapping-rain-water.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/trapping-rain-water.py
[Wildcard Matching]:https://oj.leetcode.com/problems/wildcard-matching/
[wildcard-matching.py]:https://github.com/kamyu104/LeetCode/blob/master/Python/wildcard-matching.py

---

##SQL
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
175| [Combine Two Tables](https://oj.leetcode.com/problems/combine-two-tables/) | [MySQL](./MySQL/combine-two-tables.sql) | _O(m + n)_   | _O(m + n)_ | Easy     ||
176| [Second Highest Salary](https://oj.leetcode.com/problems/second-highest-salary/) | [MySQL](./MySQL/second-highest-salary.sql) | _O(n)_ | _O(1)_ | Easy         ||
177| [Nth Highest Salary](https://oj.leetcode.com/problems/nth-highest-salary/) | [MySQL](./MySQL/nth-highest-salary.sql) | _O(n^2)_   | _O(n)_ | Medium         ||
178| [Rank Scores](https://oj.leetcode.com/problems/rank-scores/) | [MySQL](./MySQL/rank-scores.sql) | _O(n^2)_        | _O(n)_          | Medium         ||
180| [Consecutive Numbers](https://oj.leetcode.com/problems/consecutive-numbers/) | [MySQL](./MySQL/consecutive-numbers.sql) | _O(n)_   | _O(n)_ | Medium         ||
181| [Employees Earning More Than Their Managers](https://oj.leetcode.com/problems/employees-earning-more-than-their-managers/) | [MySQL](./MySQL/employees-earning-more-than-their-managers.sql) | _O(n^2)_   | _O(1)_ | Easy     ||
182| [Duplicate Emails](https://oj.leetcode.com/problems/duplicate-emails/) | [MySQL](./MySQL/duplicate-emails.sql) | _O(n^2)_ | _O(n)_       | Easy           ||
183| [Customers Who Never Order](https://oj.leetcode.com/problems/customers-who-never-order/) | [MySQL](./MySQL/customers-who-never-order.sql) | _O(n^2)_ | _O(1)_       | Easy           ||
184| [Department Highest Salary](https://oj.leetcode.com/problems/department-highest-salary/) | [MySQL](./MySQL/department-highest-salary.sql) | _O(n^2)_   | _O(n)_ | Medium         ||
185| [Department Top Three Salaries](https://oj.leetcode.com/problems/department-top-three-salaries/) | [MySQL](./MySQL/department-top-three-salaries.sql) | _O(n^2)_   | _O(n)_ | Hard         ||
196| [Delete Duplicate Emails](https://oj.leetcode.com/problems/delete-duplicate-emails/) | [MySQL](./MySQL/delete-duplicate-emails.sql) | _O(n^2)_ | _O(n)_       | Easy           ||
197| [Rising Temperature](https://oj.leetcode.com/problems/rising-temperature/) | [MySQL](./MySQL/rising-temperature.sql) | _O(n^2)_ | _O(n)_       | Easy           ||

---

##Shell Script
  #  | Problem         |  Solution       |  Time           | Space           | Difficulty    | Tag          | Notes
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
192 | [Word Frequency](https://oj.leetcode.com/problems/word-frequency/) | [Shell](./Shell/word-frequency.sh) | _O(n)_     | _O(k)_          | Medium         ||
193 | [Valid Phone Numbers](https://oj.leetcode.com/problems/valid-phone-numbers/) | [Shell](./Shell/valid-phone-numbers.sh) | _O(n)_ | _O(1)_    | Easy           ||
194 | [Transpose File](https://oj.leetcode.com/problems/transpose-file/) | [Shell](./Shell/transpose-file.sh) | _O(n^2)_   | _O(n^2)_        | Medium         ||
195 | [Tenth Line](https://oj.leetcode.com/problems/tenth-line/) | [Shell](./Shell/tenth-line.sh)    | _O(n)_          | _O(1)_          | Easy           ||
