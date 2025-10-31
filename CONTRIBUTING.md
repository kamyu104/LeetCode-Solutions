# Contributing Guide

Thank you for your interest in contributing! This repository is primarily my **personal algorithm learning notebook**, and the solutions here reflect my own problem-solving process. You’re welcome to contribute in specific ways, as outlined below.

---

## 1. New Problem Contributions
- This repo is mainly for my **own solutions** — either ones I came up with myself, or ones I learned from others and re-implemented after fully understanding them.  
- I’m **not accepting new problems or solutions directly written by others**.  
- That said, **PRs for bug fixes or improvements to existing solutions** (e.g., cleaner, more efficient, or easier to understand) are always welcome! 🙏

---

## 2. Supported Languages
- Each solution is implemented in **both Python and C++**, using the same algorithms and data structures, to demonstrate that the solution performs well in two languages with very different characteristics:
  - **C++**: compiled, high-performance, and memory-efficient  
  - **Python**: interpreted, concise, easy to prototype, emphasizing clarity and readability
- This approach helps illustrate that the **algorithm itself is optimal and robust**, independent of language-specific performance.  
- Both languages are widely used in competitive programming, coding interviews, and real-world applications.  
- **Python2** is used for consistency with earlier solutions. Separate **Python3** versions are not provided, as the syntax differences are minor and conversion is straightforward.  
- PRs improving existing solutions in either language are welcome.

---

## 3. Folder Structure and Naming
- Please follow the existing folder structure and naming conventions when submitting PRs — it helps keep the repo organized and consistent.  
- Each solution should be placed according to the current folder structure.  
- Update the solution file with relevant information, including **time and space complexity analysis**.

---

## 4. Coding Style
- Solutions adopt a **competitive programming style** emphasizing **coding patterns**:
  - Names are **short and concise**, using generic algorithm/data structure terms (`dp`, `heap`, `graph`, `node`) while avoiding problem-specific or business terms.  
  - Focus is on **algorithmic techniques and logic**, not problem-specific context.  
  - **Common coding patterns, algorithms, and templates** are clearly separated from problem-specific logic, making it easy to see:
    - **What to modify** for a new problem  
    - **What to reuse** as a template or pattern  
  - This approach keeps code **readable, maintainable, and efficient to implement**, while also being **highly performant and memory-efficient**, helping learners quickly recognize reusable patterns versus problem-specific adjustments.

> [!WARNING]
> This is **not a production-level or FAANG-standard style**. It’s intended for **personal learning and competitive programming practice**. Please keep this in mind if referencing the code for interviews or projects.

---

## 5. Testing & Validation
- Each solution must **pass all test cases on LeetCode** (or the original problem source) to ensure correctness.  
- Writing additional unit tests is **not required**, and is optional for personal verification only.

---

## 6. Acknowledgement
Thanks again for understanding the purpose of this repo! Your support really means a lot! 🙏
