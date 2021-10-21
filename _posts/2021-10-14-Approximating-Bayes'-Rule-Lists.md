---
layout: post
title:  "Approximating Bayes' Rule"
date:   2021-10-01 17:00:53 +0100
categories: jekyll update
---



**Monte Carlo Approximation**

The general idea behind Monte-Carlo approximation is that we can approximate things via repeated random sampling

In particular, we can use it to approximate probabilities.
As a simple example, consider the following problem:

Suppose  $$ X \sim  N(0,1).$$ What is $$P(X>5)?$$
{% highlight Python %}

x = np.random.normal(loc=1,scale=3,size=1000) # generate 1000 samples from a normal distribution with mean 3, std 3

in = (x>5) # vector of booleans
np.mean(in) # numpy casts the booleans into 0/1s
{% endhighlight %}

- All we have done in the above is find the empirical fraction of samples that lie in our desired range.


**Using Monte-Carlo Estimation to Approximate an Expectation**

Recall the definition of expectation for a R.V $$X$$ and 
function $$h$$:

The Monte-Carlo Approximation allows us to approximate this by simply sampling from the distribution of $$X$$ - that is, we don't need to *know* the distribution of x, we just need to be able to sample from it.

$$E[h(X)] \approx  \frac_{n}^{1} \sum_{i=1}^{n} h(x_{i})$$

where $$ x_{i} is sampled from X $$


*Special case where h is an indicator...



**Bayes' Rule**
...


Now we use out Monte-Carlo idea to approximate conditional likelihoods using bayes' rule!

$$
P(X|Y) = \frac{P(Y)} |X) P(X)}{P(Y)}
$$

**Why might we want to approximate this?**
- Typically the denominator of the RHS is a difficult integral, and is sometimes impossible to calculate algebraically
- We might not know the prior distribution explicitly.


**Approximation**

1) Generate samples from X
2) Compute weights and rescale to one
3) Use Monte Carlo Approximation for the posterior



**The Proof**





**What about for multiple unknowns?**

**Underflow?**
- we might have lots and lots of points, to the point where
probabilities are affected by floating point precision



**Approximating an integral using Monte-Carlo Estimation**
Here's one way you can approximate the integral of some non-negative function $$f(x)$$

$$\int_{a}^{b}f(x)dx$$

- Draw a box that contains f throughout the whole range
- Sample points (x,y) at random in this box
- Calculate $$A*p$$ where $$A$$ is the total area of the box, and $$p$$ is the number of points that lie under the curve

Proof:

Consider a box of height h, width b-a, such as below
*image...*

Recall that the monte Carlo Approximation is 

$$ \E(h(X)) \approx \frac{1}{n} \sum_{i=1}^{n} h(x_{i})$$

Let X be uniform in [a,b]
Let Y be uniform in [0,h]
So that our samples are $$(x_{1},y_{1}),...,(x_{n},y_{n})$$

