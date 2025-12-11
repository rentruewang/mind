mental notes = Point of recall
Doesn't need to replay the entire event, just the relevant part leading to the conclusion

Satisficing: tree search into acceptable state (boolean)
Humans go back to the roots of the problem (a more basic world model)

Understand = can use it to plan

Creativity = taking a familiar object and reimagine it

We can do something like guided RL, where we do multi step planning (heavy compute), and then knowledge distil into ML model, so the decision is faster.

New memory means new understanding and different world tree, means new outcome

Humans can do symbolic condition in search, the symoblic part can be substituted with enumeration in memory, during simulation.

Humor is caused by expectation and violation of it.

Parrots and babies have small vocabulary,
but we say that they understand because they can use the vocabularies to plan,
and understand the transitions between different states of minds (world models).


## RL

RL is very robust... up to a certain point. RL on small models are generally super easy to train, but getting exponentially more difficult the bigger the model is, requiring very careful tuning and reward designing. Why?

RL is inspired by how neurons behave, a neuron, limited by physics, can have only a couple thousands connections, which is insane for a single cell! This means at neuron's scale, RL works incredibly well and robust, not requiring tuning.

RL in the field often is responsible for tuning models that have billions of parameters, controlled by 1 single agent. No wonder it doesn't work well / isn't too flexible in what they could do / require massive time and effort to babysit. No optimization algorithm is capable of handling that many parameters (e.g. Bayesian handles maybe hundreds?).

However, people now treats the scaling of RL as an engineering issue, and it is! Theoretically RL can always find the optimal value function, but theories are different than practices. To make matters worse, people are obsessed with end to end training, making it very difficult to reason when one of the components go wrong, and the increased number of parameters make it difficult to scale.

How does the brain solve it? Very simple. It employs a sea of RL agents, each being a neuron. The agents are being controlled in a heirarchical matter, and this is a blueprint that is super scalable, as well as being flexible, where extending this design is easy.

This means that the high level decision making would be simple, as the high level (in hierarchy) agent is small in number of parameters. However, on a high level, an organism is simple. How many degrees of freedom can you say you as a human have? Most of the actions is guided by concepts (a hot path of memory sequence, assembled by [planning](./how.md)). Planning (by itself) doesn't really require a lot of parameters as well, just retrieve and search. Other examples: 90% of an octopus's neurons are in its legs, yet it has very intelligent behavior. An ant hive can also be thought of as intelligent, even though individually ants are rather stupid.
