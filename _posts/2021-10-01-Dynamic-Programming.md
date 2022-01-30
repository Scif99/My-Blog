---
layout: post
title:  "Dynamic Programming"
date:   2022-01-01 17:00:53 +0100
categories: jekyll update
draft: true
---

**What *really* is dynamic programming**

- Those in the programming field may have heard of dynamic programming in standard Data Structures & algorithms course.

- The goal of this post is to connect the two.

**Basic Control Theory**

I will try to not make this as theory-based as possible, though I thought it was fair to briefly go over where dynamic prtogramming came from!.

- Control theory revolves around the evolution of dynamical systems!
- Sequential decision making

Naively, one can think of control theory as the theory of 'optimisation over time'. In particular, the optimisation is over a set of *controls* $$u_t$$, and the subscript t represents the time step we are at. For example, if you wanted to balance a vertical pole that stands on top of a cartpole for as long as possible, your controls might be the directions you can 'push' the cart, in order to keep the pole upright. (For more on this example, see my next post...)

**The principle of optimality**
 
 The principle of optimality states that:

*"For any point along an optimal trajectory, the remaining trajectory is optimal for the same problem initiated from that point*
 
 This might seem like a trivial statement. For example, consider the shortest path problem (for a weighted graph), where A is the source, and B is the goal. All that this principle says is that the shortest path from A to B is equivalent to the shortest path from A to C, where C is any intermediate point, followed by the shortest path form C to B.

 However, the main point is that optimisation over time can be thought of as optimisation in stages. In the shortest paths example, this means that the full  shortest path from A to B can be broken down into the shortest path from A to C plus the shortest path from C to B, which can be further broken down into A->D + D->C +C->B.

 Now, keeping this in mind, I'm going to argue that Dynamic Programming (DP) is simply a smart way to break up a problem!

 **The Bellman Equation**

 Let's present the principle of optimality as an equation. 

 First Let's define some important terms:

1. How can we represent the system in question?

    Let's model the *state* of our system at time tvia a state variable $$x_t$$, that evolves via

    $$x_{t+1}  = a(x_{t},u_{t},t)$$

    Where $$a$$ is some function. 

2. What are we trying to minimise?

    Suppose that our goal is to minimize a cost function $$C$$. Assume that the cost is separable, such that

    $$C = \sum_{t=0}^{h-1}{a(x_{t},u_{t},t)}   + C(x_{h}$$
    
    where the second term on the RHS is just the terminal cost. In our shortest paths example, these costs might correspond to the weights of the edges between vertices, such that minimising this sum is indeed equal to the shortest distance.

3. Bellman's equation

    Bellman's equation relates the subproblems in a recursive manner. In particular, if we define the minimum 'cost-to-go' as

    $$F(x,t) = inf C_t$$
    where the inf is over $$u_{t},u_{t+1}...u_{h}$$
    
    then the principle of optimality says that:

    $$F(x,t) = \inf_{u}[c(x,u,t) + F(c(x,u,t),t+1)]$$
    for $$t<h$$ , with terminal condition $$F(x,h)=C(x_h)$$

What does this tell us?

- This equation is just the principle of optimality in an equation!
- This equatiion is an optimisation!
- In particular, the optimisation is over short-term and long-term gain!
- This equation is recursive in nature
- In this equation, we are assuming that we are acting optimally from time t!

**Relationship between the bellman equation and "memoization"/bottom u**

Notice that the direction of recursion is reversed to what we normally see. That is, $$F(x,t)$$ is a expressed in terms of the *next* timestep, and not the previous one. Therefore, we must be careful about how we solve it.

In a standard recurrence relation, you typically calculate the base cases, then recurse from there. Maybe we could do the same here. The only difference is that the 'starting' case is actually the end!.

- Typically in a math course, you might use a transformation to 'reverse' the recursion, namely defining the 'time-to-go' $$s = h-t$$

- The bellman equation naturally expresses a DP problem in terms of 'suffixes'!


**The programming interpretation**
- Hopefully you now have a better idea of what DP is, rather than just 'recursion + memoization'

 - In programming the term 'over time' doesn't really make sense...

- In programming, DP allows us to solve problems in polynomial time, where it might have been exponential otherwise!

- The DP equation guarantees a topological ordering (once we have the Bellman Eq, we can just iterate over the 'timesteps') so that we only need to solve each subproblem once!

- This is because we can cache subproblems, meaning we don't need to solve them again!

- Typically in a programming question, there is no notion og 'state evolution'. Instead you might be given a sequence of numbers/strings in e.g. an aray 

- You can therefore of the 'state evolution' as simply a new input to the function. (I like to think from right to left, might be confusing...) 
    - In the MIT lectures, this is equivalent to the idea of suffixes/prefixes


- The 'bottom up' method is just the bellman equation! (plus cacheing)

- Note that sometimes the DP equation will not directly provide the answer...

**The algorithm**
- Define the problem (controls, 'evolution')
- Write down the DP Equation
- Write down base case(s)
- For each 'timesteps'
    - Solve DP equation
    - Store answer in cache
- Solve original problem


**Worked example - The bowling alley**

Suppose you are at a bowling alley, and there is a special alley with some peculiar rules...

- The alley contains n pins.
- You have an unlimited number of 'throws'
- The pins are places in a way such that you can hit at most 2 pins (by aiming in between them)
- Each pin has a number on it, representing the score you gain when hitting it. Each number can be +ve or -ve, and the pins aren't sorted by number in any way.

Your goal is to find the maximum score achievable.


**Setting up a solution**

- Assume the input is an array P, where element i corresponds to the score of the ith pin.
- The 'evolution' can be though as 'observing' the next pin in the line (moving right to left)
- the controls are as follows:
    - We can choose to hit the most recently observed pin
    - We can choose to hit between the most recent pin and the previous one
    - We can choose to not throw, i.e wait to observe the next pin

- Solutions often start with "assuming we are following an optimal trajectory..." When coding, we don't need to sya this, because we *will* be following an optimal trajectory.

- The base cases are simple:
    - For the first pin we see, we should hit it if it's  scored >0, else we leave it
    - For the second pin we see, we have a few more choices...

- In general the DP equation is then:

$$B(i) = \max(B(i+1),P[i] + B(i+1), P[i]*P[i+1] + B(i+2))$$


    - The P terms are the same as the c term in the original DP equation. The B terms are the same as the F terms.

- Now we just iterate over all 'timesteps' (i.e over the size of the input arry), storing our result in a cache.


Here is the code (python (3)):

{% highlight Python %}

def Bowling(pins: list) -> int:
    cache = {}
    ans = 0
    n = len(pins)
    for i in reversed(range(n)):

        if i == n-1:
            ans = max(pins[i],0)

        if i== n-2:
            ans = max(cache[i+1],pins[i] + cache[i+1], pins[i+1]*pins[i])

        else:
            ans = max(cache[i+1],pins[i] + cache[i+1], pins[i+1]*pins[i] + cache[i+2])
        
    return cache[0]

{% endhighlight %}