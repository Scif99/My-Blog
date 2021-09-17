---
layout: post
title:  "Leetcodes to remember"
date:   2021-09-17 09:04:53 +0100
categories: jekyll update
---

1. Rotating a matrix
2. Min Linked List
3. Detecting cycles in a list


4. sort stack:
Idea:

- Create a 'helper' stack
- This stack will always maintain descending order.
- Therefore, onece the initial stack is empty, we know that the helper must be the original stack
in descending order from the top
- Then we can move all elements over to the original to get ascending order.
-INVARIANT: Helper will always maintain decresing order from the top.

Loop
- Store top of original, tmp
- Move elements from helper back into original until adding tmp to helper maintains invariant
- then push tmp onto helper
- repeat until the original has no elements left
