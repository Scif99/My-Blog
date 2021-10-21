
To-Do
- Monte-Carlo as distribution approx...
- Bad to use random subbset for validation set?
(see vid 9)
- Mean of a dataset = expectation over empirical dist!


**Motivation**
How good a fit can we find to a dataset?
- We could try to 'sketch' over a dataset and find a RV with this curve as a pdf. Clearly this isn't a good idea
- A better way is to consider the ECDF of the dataset, and try to find an RV whos CDF is 'close' to the ECDF 

key point: *A good fit for a dataset is equivalent to saying that the CDF of the predictive distribution looks close to the ECDF*






**Empirical distribution**
- A dataset *is* a distribution
- When you compute statistics for a dataset, you are really computing statistics for its empirical distribution

**The Empirical Distribution as a Model**
- The empirical distribution is a *perfect* fit for a dataset, but is a *bad* model, as it cannot generalise!
(being able to generalise is part of the goal of ML!)
- The goal of USL is to train a NN (via MLE), such that we can synthesise novel data
- Using a validation set allows us to test our ability to generalise, and to prevent overfitting
"getting good log likelihood on validation data (USL) is equivalent to getting accurate predictions on validation data (SL)"

**The main point**
- If we think probabilisticaly, we have a clean way to think about model evaluation, that works in both the supervised and unsupervised case
- This idea is the idea of validation/holdout sets

**So Why is the Empirical Distribution so Important?**
- We evaluate models using holdout data...
- We do this assuming the holdout set is a good sample of the true data generating distribution
- In other words, we are approximating the whole world of unseen data with a sample
- i.e we are using the empirical distribution!!!

