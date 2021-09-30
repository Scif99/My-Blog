
---
layout: post
title:  "Leetcodes to remember"
date:   2021-09-17 09:04:53 +0100
categories: jekyll update
---



**Statistics**

Paradigms:
- Frequentist : probabilities represent long run frequencies of events 
- Bayesian : probabilities represent uncertainties 

**Distributions**

Conditional distributions:

- Suppose we want to predict a variable given some inputs $$x \in X$$ (i.e. we aren't given the parameters). Then we have a conditional distribution
$$D(y \vert f(x;\theta))$$ where $$f$$ estimate the parameters.

- Sigmoid function : transformation for bernoulli outputs
    - Logistic regression is when we use a linear model to estimate a bernoulli parameter!

- Softmax function : transformation for multi-class (categorical) outputs
    - 

**Gaussian distribution**

- In the conditional case, might want to estimate both the mean and variance. Typicalle we assume a fixed variance though.
- Linear regression is just using linear models to fit a gaussian distribution!
