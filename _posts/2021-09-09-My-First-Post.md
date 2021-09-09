---
layout: post
title:  "Detecting Cycles in Lists"
date:   2021-09-09 19:04:53 +0100
categories: jekyll update
---

Welcome to my first post

I recently did a question which asked "Given the head of a linked list, determine whether it contains a cycle". My initial solution was pretty inefficient, but was simple to understand. 

I typically solve interview questions like this in C++, in which a pointer is a built-in data type. This question in particular was solveable by directly manipulating the pointers in the list. Essentially, if a cycle exists, then at some node in the list, the pointer will point to some address already pointed to. Thus, it suffices to iterate through the list, storing the addresses of each node pointer, then checking through all the stored addresses for a match. Of course, this is an O(n^2) proccess and so I knew that it couldn't be optimal, though it does potentially highlight a use for being able to directly manipulate memory.

Anyway, my suspicions were confirmed when I saw that the runtime for my solution was in the bottom 5% of all C++ solutions. I knew then that there must be some well-known algorithm to solve this, and so I had a look. What I was looking for is called Floyd's cycle-finding algorithm, a.k.a the "tortoise and hare algorithm" - an algorithm can check for a cycle in linear time and constant space.  ...

**The Explanation**

Suppose we have a list which does contain a cycle. The "tortoise and hare" refer to two pointers which iterate through the list at different rates. Although they both start at the head of the list, the tortoise will move along one node at a time, whilst the hare moves along two at a time. Immediately we can intuitively argue that the two will meet at some point within the cycle: since the hare is moving along at twice the rate, the distance between it and the tortoise will be increasing over time. Assuming that a cycle does exist, then they will eventually both be moving within the cycle. At this point, it should be obvious that the hare will eventually 'catch up' to the tortoise at some point! 


It is helpful to draw a picture of what's going on: 
**picture** 



*Note the cyclic part must be smaller than the full list!*

Suppose that the cycle begins d nodes from the start (which is unknown to us). Now suppose that the tortoise and hare meet at some point P. Let's also split the cycle into two, so that L_1 is the distance from d to P, and L_2 is the distance from P to the start of the cycle. . We can now write down how far T and H will have moved overall by the time they meet at P. Assuming the cycle is of length C, we can say that the tortoise has moved a distance of d + mC + L_1, where m is some integer. This says that, in order to reach P, the hare will have moved a distance of d (in order to reach the cycle), from which it may cycled around *fully* some number of times (they might not meet right away), but eventually will have to move an extra distance L_1 to get to P. Similarly, we can express the distance the hare has moved as d + nC + L_1, where n is some integer (>2n) **prove**. This is the same as for the tortoise except it will have cycled more times than the tortoise since it is moving along at a faster rate. 

The key point here is that we know how the two distances relate. If the hare is moving at twice the speed of the tortoise, then by the time they meet at P it must have travelled twice the distance. And so we have

    d+nC+L_1 = 2 * (d+mC+L_1)
    d+L_1 = (n-2m) * C                

If a solution to this exists, then they really do meet...

Here is a short program to test whether a cycle exists:

{% highlight C++ %}
bool contains_cycle(ListNode* head){

    // define two pointers for the tortoise (T) and hare (H) respectively
    ListNode* T = head;
    ListNode* H = head;

    while(H){
        T = T->next; // tortoise moves along one at a time
        H = H->next ? H->next->next : H->next; // hare moves two at a time 
        
        if(H==T) return true; // (it might be useful to also store where they meet)
    }
    return false; // if the hare is null then the list must terminate
}
{% endhighlight %}

Note that the loop ends when the hare is null, at which point it must have reached the end of the list (and thus there cannot be a cycle). 

*It is enough to only check whether the hare is null, since it will always reach the end of a non-cyclic list before the tortoise.


Now that we have shown cycle does exist, we might like to know *where* the cycle exists, i.e at what position the cycle begins. So basically we want to find d. Firstly we can rewrite the equation (*)

    d+L_1 = kC  
    d = kC - L_1
    
where k is some integer.  **picture**

Now note that L_1 = C - L_2, so that 

    d = (m-2n) * C - C + L_2
    d = (m-2n-1) * C + L_2
    d = aC +L_2   
  
  for some integer a
    
This last line tells us that the distance from the start up until the start of the cycle, d, is equal to some number of *full* cycles plus L_2, the distance from P onwards back to d. Therefore, we can find the value of d as follows: Place the tortoise at the start, and the hare at P. Now iterate both at the same speed (one at a time) until they meet. Where they meet will be the point at which the cycle starts.

An explanation for the above: When the tortoise reaches the start of the cycle, it will have moved d steps. From the above equation, the hare will have moved a cycles plus an extra L_2. Since it has started at P, this means it will meet the tortoise at because moving along L_2 from P will lead it back to d! 

We can now implement a program to find the start node of a cycle, assuming we have the meeting point P:

{% highlight C++ %}
ListNode* cycle_start(ListNode* head, ListNode* P){

    ListNode* T = head; // place the tortoise back at the start
    ListNode* H = P; // place the hare at P

    while(H!=T){
        T = T->next;
        H = H->next; 
    }
    return H; // the point where they meet is the start of the cycle
{% endhighlight %}


**Does the speed need to be twice for the hare?
