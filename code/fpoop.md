# FP vs OOP

## Style

I think in general imperative programming is much more greedy, maintaining a state in your mind, and keep executing eagerly. Functional programming on the other hand operates on the abstraction of functions. It's lazy in nature and can enable optimization.

Furthermore, FP favors data structures like linked lists and trees, where it's a node / data pattern rather than hashmaps / arrays, where data is grouped together and acting like a unit. This is because immutability makes it s.t. you need to create rather than mutate, making a wholistic data structure like array expensive to change.

## What to abstract and represent

In OOP data is hidden, and functions are exposed (as interface)
In FP, functions are hidden, but data need to be exposed (as interface)
In fp, instructions are implicit (using input dependency to constrain executing order)

In FP, a side effect can be thought of as taking state as input and returning additional updated state.

OOP is about coupling different functions together into a single abstraction

## Visitor pattern

See this amazing [link](https://craftinginterpreters.com/representing-code.html) to see how visitor pattern in OOP simulates FP.

Perhaps typeclasses in FP simulates protocols in OOP?
