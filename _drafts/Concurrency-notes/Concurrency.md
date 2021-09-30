---
layout: post
title:  "Concurrency"
date:   2021-09-22 22:04:53 +0100
categories: jekyll update
---


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

typically, more tasks are running than there are hardware threads, so task switching still often applies

**Why use it?**

- **Separating Concerns**

**performance**
- Task parallelism : performing separate tasks on the same data
- Data parallelism : performing the same tasks on different data

**Why not to use it?**
- Coding with concurrency is harder to understand
- Performance increase might not be worth the cost

*In C++, using multiple threads isn’t complicated in and of itself; the complexity lies in designing the code so that it behaves as intended*

**Launching a Thread**

- Threads can be constructed in a number of ways (lambdas ets...), but will generally take a type with an () overload as an argument.

- Once a thread object is constructed, you must decide whether you want to wait for it to finish (using join() ), or whether you want to leave it to run on its own (using detach()).

- If you don't decide before the thread object is destroyed,the program will terminate!

- With detach(), you can usually call it immediately after construction.
However with join() you must be careful (See below).

**Thread management**
- Remember when you were learning about raw pointers and the delete keyword? With threads, there are similar issues you must be careful about.

- One situation to keep in mind is that where you have a thread which might access data that has been destroyed before the thread is finished. (see p19 for ex.) 

- One solution to problems like this is to force the calling thread to wait for the other to finish, using join(). The act of calling join() also cleans up any storage associated with the thread. 

- However, as discussed above, you must be careful when using join.
In particular, you need to consider *where* to place the call to join(). 
This is because the call may be skipped if an exception is thrown before calling join()!

SOLUTION- use RAII! (and be careful with copies!)

**Running threads in the background**

- Calling detach() allows a thread to run in the background. From this point, it’s no longer possible to wait for that thread to complete

- An example of when detached threads would be used is word documents, where a separate thread is run for each open document, using the same code but different data