---
layout: post
title:  "Concurrency"
date:   2021-09-22 22:04:53 +0100
categories: jekyll update
---

**The pair-programmer analogy**

- One way to approach concurrency is to have two single-threaded processes, equivalent to having two workers in separate offices
- Another is to have a multiple threads in a single process, equivalent to having the two workers working in the same office

There are +/- for each approach
- If in the same office, they could get distracted. Also easy to forget where refereance manual is

**multiple processes**
the processes communicate via the OS?
+ easier to write safe code, due to protection in operating systems
+ can run processes on separate machines using a network
- communications between processes can be slow
- the overhead in initialising all the processes

**multiple threads**
threads communicate via shared memory   
- shared address space means less bookkeeping for the OS
- must take care when multiple threads access data at the same time

**Why use it?**

- **Separating Concerns**

**performance**
- Task parallelism : performing separate tasks on the same data
- Data parallelism : performing the same tasks on different data

*In C++, using multiple threads isn’t complicated in and of itself; the complexity lies in designing the code so that it behaves as intended*