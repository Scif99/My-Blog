To-ADD
- Probability is *not* confidence
- Hypothesis tests
- Noninformative priors...
- Comparing bayesian vs Frequentist 
(Bayesian for one-offs)
Bayesian still requires us to decide a prior...


**What is inference?**
- Inference is about modelling uncertainty
- There are two paradigms: One is the Bayesian way, the other is the frequentist way



**A Note on MLE**
- Note that the MLE is a point estimate for a parameter.
- Therefore it doesn't provide any information about our uncertainty for this estimmte.
- Frequentist view! we assume param *fixed* and unknown
- In fact the MLE is a special case of a bayesian posterior assuming a uniform prior!
- The MLE (if it exists) will always be a function of 

**Bayesian Inference**
The main idea of bayesianism says that we should represent unknown quantities as random variables!
- In other words, we model uncertainty using R.V.s and the rules of probability

- The method is simple.  
1) We have some prior belief of an unknown  quantity, which we represent as a R.V with a *prior distribution*.

3) We update our beliefs in light of such data, giving rise to a a posterior distribution.

Notes:
- Prior beliefs are subjective! Two people may have completely different priors, and will therefore have different posteriors. However, both will have their beliefs *shifted* in a similar manner in light of the data.
- Bayesianism is *not* just 'using bayes' rule'. It is a way of thinking! But bayes' rule represents *exactly* how a bayesian interprets the unknown 

**Finding the Posterior in Practice**
 1) We start with some probabilistic model for some data
 $$Pr_{X}(x \vert \Theta = \theta)$$
 where $$\theta$$ represents the unknowns
 2) We enfore some prior distribution on the parameters
 $$Pr_{\Theta}(\theta)$$
 3) We apply the Bayes update to find the posterior

**Interpreting the Posterior**
- You could report a point estimate of the posterior (e.g. the mean) or the MAP estimate
- But the advantage of bayesian inference is the idea of uncertainty! When we take a point estimate we've just thrown it all away :(
- A better thing to do is compute a point estimate (such as the mean) and compute a *credible interval* for it, which quantifies the uncertainty associated with the estimate

**Using the posterior**
- How can we make future predictions?

- Using a point estimate for params when making predictions is a *plug-in approximation* (e.g MLE)
- Prone to overfitting... Instead we consider a bayesian approach
- Use law of total probability to integrate out 'nuisance' parameters!
**The Frequentist Approach**
- In the frequentist camp, we do not believe in chance. Instead, we rely on simulation. 
- In other words, we model uncertainty by repeatedly sampling and then measuring the variation across these trials
- Note that in this case, the parameters are not treated as R.VS, but instead fixed, unknown values.

**Confidence Intervals**
- The main method of frequentist inference is to use confidence intervals
- A confidence interval of $$\gamma %$$ means "if we sample a large number of datasets, then $$\gamma %$$ of them will contain $$\theta$$
- To do this, we need to be able to 'simulate the multiverse'
How do we simulate such samples?...

