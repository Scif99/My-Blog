---
layout: post
title:  "Detecting Cycles in Lists"
date:   2021-09-20 19:04:53 +0100
categories: jekyll update
draft: false
---

I recently did a question which asked "Given the head of a linked list, determine whether it contains a cycle". My initial solution involved manipulating memory directly. In C++, you can solve a question like this simply by the storing pointers in the list. Essentially, if a cycle exists, then at some node in the list, the pointer will point to some address already pointed to. Thus, it suffices to iterate through the list, storing the address of each pointer and checking through all previously stored addresses for a match. 

Of course, this is an $$O(n^2)$$ process and so I knew that it couldn't be optimal. A better way to solve is uses a well known algorithm called Floyd's cycle-detection algorithm, a.k.a the "tortoise and hare" - an algorithm can check for a cycle in linear $$O(n)$$ time and constant $$O(1)$$ space.

**How it Works**

Suppose we have a list which does contain a cycle. The "tortoise and hare" refer to two pointers which iterate through the list at different rates. The tortoise will move along one node at a time, whilst the hare moves along at a faster speed, say two nodes at a time. If we know that a cycle exists, then intuitively the two *should* meet at some point within the cycle: since the hare is moving along at twice the rate, the distance between it and the tortoise increases over time. After some time they will both be moving within the cycle, from which point it only makes sense that the hare will eventually 'catch up' to the tortoise at some point! 

We want to show this a bit more formally. In fact, we can prove that the two will meet if and only if there exists a cycle. The latter is not too hard to see: If they do not meet at some intermediate point in the list, then it must be the case that both reached the end of the list (recall that the last node in a list contains a null pointer). Thus it suffices to show that, if there is a cycle, the two will eventually meet.


It might be helpful to draw a picture of what's going on: 
![Cycle ](https://scif99.github.io/My-Blog/images/Cycle.jpg)


Suppose that the cycle begins $$d$$ nodes from the start (which is unknown to us). Now suppose that the tortoise and hare meet at some point P. Let's also split the cycle into two, so that $$L_1$$ is the distance onwards from $$d$$ to P, and $$L_2$$ is the distance from P to the start of the cycle. We can now write down how far T and H will have moved in total by the time they meet at P. Assuming the cycle is of length $$C = L_1 + L_2$$, we can say that the tortoise has moved a distance of $$d + mC + L_1$$, where $$m$$ is some positive integer. This says that, in order to reach P, the hare will have moved a distance of $$d$$ (in order to reach the cycle), from which it may cycled around *fully* some number of times (they might not meet right away), but eventually will have to move an extra distance $$L_1$$ to get to P. Similarly, we can express the distance the hare has moved as $$d + nC + L_1$$, where $$n$$ is some other positive integer $$>m$$. This is the same as for the tortoise except it will have cycled more times than the tortoise since it is moving along at a faster rate. 

The key point here is that we know how the two distances relate. If the hare is moving at twice the speed of the tortoise, then by the time they meet at P it must have travelled twice the distance. this means we can write

$$d+nC+L_1 = 2(d+mC+L_1)$$

$$d+L_1 = (n-2m)C$$             

Now as long as there is a solution to this, then we know that the two will eventually meet. That is, if there is some values of $$L_1, n, m$$ that satisfy the above equation. You can check that $$n=d$$, $$m=0$$,$$L_1 = dC-d$$ works. The point is that a solution exists, and so they will eventually meet. 

Here is a short program to test whether a cycle exists:

{% highlight C++ %}
bool contains_cycle(ListNode* head){

    // define two pointers for the tortoise (T) and hare (H) respectively
    ListNode* T = head;
    ListNode* H = head;

    while(H){
        T = T->next; // tortoise moves along one at a time
        H = H->next ? H->next->next : H->next; // hare moves two at a time 
        
        if(H==T && T) return true; // doesn't count if they're both null!
    }
    return false; // if the hare is null then the list must terminate
}
{% endhighlight %}

Note that the loop ends when the hare is null, at which point it must have reached the end of the list (and thus there cannot be a cycle). It is enough to only check whether the hare is null, since it will always reach the end of a non-cyclic list before the tortoise.


Now that we have shown cycle does exist, we might like to know *where* the cycle exists, i.e at what position the cycle begins. In other words we want to find d. Luckily we are pretty much done already, though some rearranging might help explain why. All we need is to see that $$L_1 = C - L_2$$, so that 

$$d = (m-2n)C - C + L_2$$

$$d = (m-2n-1)C + L_2$$

$$d = aC +L_2$$
  
where a is some (positive) integer. This last line tells us that the distance from the start up until the start of the cycle is equal to some number of *full* cycles plus $$L_2$$, the distance from P onwards back to $$d$$. This means that when the tortoise has moved $$d$$ steps (at which point it will be where the cycle begins), the hare will have moved $$L_2$$ steps (bringing it to $$d$$) and and then fully cycled around $$a$$ times, meaning the two will meet at $$d$$! 

We can therefore find the value of $$d$$ as follows: Place the tortoise at the start, and the hare at P. Now iterate both at the same speed (one at a time) until they meet. Where they meet will be the point at which the cycle starts, i.e. $$d$$.

The following code does exactly that:

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

**Notes**

- This general idea of maintaining two pointers can be used outside of detecting cycles, for example in finding a duplicate in an array.

- When I said that $$n>m$$ it was clear from the context, though if you notice in $$d+L_1 = (n-2m)C$$ the value of $$n$$ actually needs to be $$> 2m$$ in order for the RHS to be positive. This isn't too har to see anyway: if the tortoise has completed $$m$$ cycles without the two meeting, then the hare must have completed *at least* twice as many in that time, since it is moving at twice the speed! 

- At the start I arbitrarily decided that the hare will move twice as fast as the tortoise. In fact the argument generalises to multiples greater than 2, as long as they start from the same point in the list. The number 2 is just what is typically implemented into code.

 