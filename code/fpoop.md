# FP vs OOP

## Style

I think in general imperative programming is much more greedy, maintaining a state in your mind, and keep executing eagerly. Functional programming on the other hand operates on the abstraction of functions. It's lazy in nature and can enable optimization.

Furthermore, FP favors data structures like linked lists and trees, where it's a node / data pattern rather than hashmaps / arrays, where data is grouped together and acting like a unit. This is because immutability makes it s.t. you need to create rather than mutate, making a wholistic data structure like array expensive to change.

Oop restrict access to data (encapsulation). Fp restrict mutation, to quote some random strangers:

> Oop makes core understandable by encapsulating moving parts, and fp makes code understandable by minimizing moving parts. Moving parts = mutating states.

Now this is not to say that FP has no side effects, things like: time, space, energy are inherent to all programs, but FP aims to abstract it away.

## What to abstract and represent

In OOP data is hidden, and functions are exposed (as interface)
In FP, functions are hidden, but data need to be exposed (as interface)
In fp, instructions are implicit (using input dependency to constrain executing order)

In FP, a side effect can be thought of as taking state as input and returning additional updated state.

OOP is about coupling different functions together into a single abstraction

## Visitor pattern

See this amazing [link](https://craftinginterpreters.com/representing-code.html) to see how visitor pattern in OOP simulates FP.

Perhaps typeclasses in FP simulates protocols in OOP?


## What each is good at

Since purest FP doesn't have the notion of time,
it has no side effects and mutation,
so it favors creation,
which makes big data structures difficult,
so it favors small data structures,
so it doesn't work well with adding new things,
because each implementation is simple in nature.

Since OOP is just normal programming,
it goes into the other direction,
and had to do encapsulation and access control to keep development sane.

> FP is good at adding new transformation at a fixed set of things,
> OOP is good at adding new thing for a fixed set of transformations.
