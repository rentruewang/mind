# FP vs OOP

## Style

I think in general imperative programming is much more greedy, maintaining a state in your mind, and keep executing eagerly. Functional programming on the other hand operates on the abstraction of functions. It's lazy in nature and can enable optimization.

Furthermore, FP favors data structures like linked lists and trees, where it's a node / data pattern rather than hashmaps / arrays, where data is grouped together and acting like a unit. This is because immutability makes it s.t. you need to create rather than mutate, making a wholistic data structure like array expensive to change.

Oop restrict access to data (encapsulation). Fp restrict mutation / allow easy composition of computation, to quote some random strangers:

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

## Good code in each

I feel like good = simple. Easy to understand, elegant, minimizing information exchange unless absolutely necessary (modular).

Compared to each other

- OOP relaxes:
    Mutation. Sometimes good and simplest OOP code use this, and can mutate global state. (Contexts, command line parser, global variables etc).
    Easy polymorphism. This means objects can be as complicated as possible. This means you can write libraries that capture only high level business logic.

- FP relaxes:
    Places where you can use the functions. This means instead of if-else, you can use function pointers and don't hard code the decision boundary.
    Relation between objects. This means you can use them however you like, each are going to be isolated for the most part.

## Problem with FP (sum types)

I personally feel that immutability aspect of FP is very nice,
but sum types (tagged union)... they make code easy to write but difficult to verify.
Hurts readability.

Let me explain.

Stemming from the fact that FP favors working with smaller data types,
sum types are added (smaller kinds, switching over a few cases).

In languages like Haskell, sum types are very easy to write and very expressive,
making abusing this very easy.
Lots of code does `data rec = a | b | c | ...`.

This has the following downside:

1. Too easy to depend on specific data (kind of leaky).
   Lacking **cohesion** between different members of the sum types is quite common.
   If OOP wants to emulate the same style, polymorphism + visitor pattern is required,
   forcing the items in the "sum types" to behave commonly.
2. Too many code paths (many transformations on **specific** things).
   Now you need to verify the product of input -> output kinds of code paths.
   And since output type might also be defined **adhoc**, they lack clear cohesion.
3. Worse intermediate representation (too low level).
   Due to how flexible the sum type is, a lot of times intermediate representation is defined as sum type.
   _Without a cohesive theme for those types, you need to verify many code paths, rather than one (more abstract) code path_.
4. Coupled with the fact that compared to OOP,
   FP "methods" can be anywhere in the library, possibly in another file,
   making it quite difficult to find.

OOP's methods are part of their contracts (objects are the main cast),
and FP's data types are part of the contracts (functions are the main cast).

This means that usually better OOP design (simpler) has fewer methods,
and better FP design (simpler) has fewer data types.

> This means that compilers are usually FP's killer application.
According to some strangers on stack overflow.

I did take a look at GHC's implementation, but I notice that,
in a lot of the sum types, the data types are one time use (only 1-2 functions operate on them),
and there are more members in the sum types than there are functions,
and then `case` is used in those functions liberally (just if-elses essentially),
which have the problems mentioned above.
This means it might have been clearer written in an OOP fashion.
