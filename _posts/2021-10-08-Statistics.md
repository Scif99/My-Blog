---
layout: post
title:  "Intro to Bayesian ML"
date:   2021-10-01 17:00:53 +0100
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


**Empirical distribution**
- The empirircal distribution is an estimate of the cdf that generates the training points (Formally, it is an unbiased estimator of the true distribution function)
- Can think of it as an estimate of the data generating process!
- 

**Regularization**
- Purely minimising ER is prone to overfitting! especially if the model has loads of parameters.
- So we might want to add a penalty to our NLL/ER to compensate.

$$ \lambda C(\theta)$$

- Turns out regularization is equivalent to maximising the log posterior! (MAP)

e.g. weight decay is regularization with a gaussian prior

**Validation Sets**
- One question is, how do we choose a suitable $$ \lambda$$?
- If we choose a very small one, we are essentially just minimising ER
If we choose a very large one, we will end up close to our prior (Recall regularized loss = prior + ER)

**Cross-Validation**

**Bayesian Stats**   
- Instead of computing point estimate for parameters, we use a probability distribution to model our uncertainty
- Once we have found found our posterior over parameters, we can predict future observations                  

**Intro to Bayesian ML**

goal: How can we predict future observations with a bayesian approach?

- In the conditional(supervised) case, the posterior over parameters is $$P(\vec{\theta} \vert \mathcal{D})$$
where $$\mathcal{D}$$ is the set of labelled training data $$\{(\vec{x_{n}},\vec{y_{n}})\}$$

- With this, we can calculate the *posterior predictive* to predict future observations:

$$p(\vec{y} \vert \vec{x},\mathcal{D}) = \int p(\vec{y} \vert \vec{x},\vec{\theta}) \dot{} p(\vec{\theta} \vert \mathcal{D}) \,d\vec{\theta} $$

- Note that the integral is just the law of total probability! Using this allows us to marginalise out $$\vec{\theta}$$ (so that there is no dependence on the LHS)
- Intuituvely, we are essentially accounting for all possibilities over $$\{theta}$$ , i.e accounting for our uncertainty in theta

- One immediate problem is that this integral might be very hard to compute! So typically we need to use some form of approximation

**The plug-in approximation**
- One approximation is to use a point estimate for our posterior $$\delta(\vec{\theta} - \hat{\theta})$$
- Thus, assuming a delta distribution for our posterior, we can simplify the predictive posterior as follows:

$$p(\vec{y} \vert \vec{x},\mathcal{D}) = \int p(\vec{y} \vert \vec{x},\vec{\theta}) \dot{} p(\vec{\theta} \vert \mathcal{D}) \,d\vec{\theta} $$

$$\approx \int p(\vec{y} \vert \vec{x},\vec{\theta}) \dot{} \delta(\vec{\theta} - \hat{\theta}) \,d\vec{\theta}$$

$$ = p(\vec{y} \vert \vec{x},\hat{\theta})$$

- Notice that reduces to the standard approach of fitting a model with a point estimate, then making predictions
- We can use MLE as a point estimate!
- Could also use MAP estimate
**MLE Estimation as a special case of Bayesian Inference**
- MLE = plugin-approximation with MLE as point estimate?

**Examples**

**Why is the Bayesian Approach important**
- By capturing uncertainties in our parameters, we can capture the uncertainty in our future predictions

**What are the problems with the Bayesian Approach**
- As mentioned before, the bayesian approach comes at the cost of tough integrals.
-  Calculating posteriors with high dimensional inputs and many parameters can be computationally challenging

**Approximations**
- Grid approx
- Laplace approx
- Variational inference
- MCMC approx : simplest method -> draw samples from posterior, then take empirical mean



