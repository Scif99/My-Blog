---
layout: post
title:  "Policy Gradients"
date:   2021-09-17 09:04:53 +0100
categories: jekyll update
---

Openai works for episodic. Deepmind/S&B also works for continuing using stationary distributions

**Difference between Supervised Learning and Reinforcement Learning for Policy Gradients**

Recall that the policy gradient is given by

$$\nabla_{\theta} J(\pi_{\theta}) =E_{\tau \sim \pi_{\theta}}[{\sum_{t=0}^{T} \nabla_{\theta} \log \pi_{\theta}(a_t |s_t) R(\tau)}]$$

So that a monte carlo estimate is given by 

$$\hat{g} = \frac{1}{|\mathcal{D}|} \sum_{\tau \in \mathcal{D}} \sum_{t=0}^{T} \nabla_{\theta} \log \pi_{\theta}(a_t |s_t) R(\tau)$$

**Comparison to Supervised Learning:**

- Suppose we were given a set of (state,action) pairs, where the actions were optimal for the given state (i.e equivalent to labels in SL).
- Performing SL on this would mean that we are looking to fit a model that outputs a general policy $$\pi_{\theta}(a \vert s) $$
- To do this we would perform MLE: The log likelihood is given by
$$ \sum_{t=0}^{T} \log \pi_{\theta}(a_t |s_t) R(\tau)$$


- From this you might notice that the RL objective is essentially a weighted maximum likelihood objective, where the weights are the rewards!


**Intuition behind baselines**
- Intuitively, policy gradients do the following:"policy gradient makes the good stuff more likely, and the bad stuff less likely"
- Recall that, we can think of the rewards as a weighting that determines whether (and by how much) we increase the probability of choosing certain actions.
- But what if all rewards were positive? In such a case it might seem like we are never decreasing the probability of "bad stuff"
- e.g. if rewards are +1 and 0, then recieving 0 loads will mean parameters aren't updated!

- It might be useful to 'centre' our rewards around some 'average', such that above-average actions have their probs increased, and below-average ones have theirs decreased

- Thus we might be looking for some expression $$b$$ such that our policy gradient estimate can be written as 
$$\hat{g} = \frac{1}{|\mathcal{D}|} \sum_{\tau \in \mathcal{D}} \sum_{t=0}^{T} \nabla_{\theta} \log \pi_{\theta}(a_t |s_t) [R(\tau) - b]$$

- Immediately, we might wonder "what sort of expression might b look like?" More generally we might ask "What kind of function can b be, such that the equation for $$\hat{g}$$ is still valid?"

- It turns out that(*) b can be any function that does not depend on the state! (Expectation will be 0) 

- More formally, subtracting a baseline is unbiased in expectation, but will lower the variance!

**What is a good baseline?**

- We can explicitly derive an optimal baseline, though it is not often used (why?)

- A natural choice might be the value function $$V^{\pi}(s_{t})$$, the expected return from state s onwards

**Introducing a critic**
- Why not also consider the value function when using policy gradient methods?
Critic: Updates action-value functions
Actor: Updates policy weighted by direction from critic

- Note that we will now need another network to estimate V!

**Advantage function**
- Combines notion of critic & baseline!

$$A^{\pi}(s_t,a_t) = Q^{\pi}(s_t,a_t) - V^{\pi}(s_t)$$
The advantage function tells us how good an action is relative to the average. Clearly we would need some other NN to estimate V however.

- How to estimate Advantage?
1. estimate Q, estimate V then subtract V from Q. With this method we would need two NNs for Q and V, and would need to update both Q and V via say TD.

Actually we only need to estimate V!

**the problem of policy gradients, in some sense, reduces to finding good estimates A^π,γ(st,at) of the advantage function Aπ,γ(st,at).**

**Introducing a critic**
- Why not also consider the value function when using policy gradient methods?
Critic: Updates action-value functions
Actor: Updates policy weighted by direction from critic

- Note that we will now need another network to estimate V!
