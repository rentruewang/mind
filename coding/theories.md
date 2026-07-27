# My learning on dependent type theory

**There are Isomorphism between the theories (category and type)**.

Set theory = study of sets, seems to be most generalized and fundamental.
Type theory = set that can be constructed not enumerated
natural language and programming can behave the same, in type theory

category theory = study of some category of functions, like monad.
Type theory = studying how types relate, a lot of programming concepts related to category theory

Which is the best theory? Depends on the use case and context. Theory = natural and simple representation.

## Why dependent type theory in proof assistants?

Dependent type means you can have a type that depends on values.
Normally, you have functions from value -> value, type -> value (constructor), and type -> type (subclassing). Dependent type is the 4th possibility for value -> type.

Dependent types strong enough to represent a lot of symbolic logic, s.t. a lot of provers correspond with DT programming languages. Also if we can infer from those symbolic relations, we can implement proofs. Curry Howard correspondence.

No linear types (use once, good for modeling resource usage mathematically) in dependent types.

## Why runtime checks exists at all

C++ Turing complete templates is almost dependently typed.

Think of it this way: if all computation happens during compile time, then compiler can execute the program without doing anything at runtime. This is essentially what dependent type does, where compiler executes and verify code during compile time.

Perhaps, we only use runtime checks because the compile time types are not expressive enough? E.g. in python, sometimes we `assert value > 0`, just because there is no positive value type, but we need one when running.

## What is dependent type?

You can actually simulate dependent type in python, just your class has to store info in metaclass, or a local class from closure

Runtime checks to compile time checks, possibly with symbols because at compile time we have to work with limited info

### Ada spark / lean

Gnatprove based on induction so if the conditions are not strong enough, it can try to produce counterexample. It requires contracts and loop invariants to be specified. Sometimes the invariants are too difficult to express in program terms, and only basic types.

FV is a superset of halting problem, can be un-decidable in general.
Complex code needs a lot of boilerplate to be verified.

Ada contracts are subset of dependent type (at least serves the same purpose)

Note: Halting problem is solvable for finite state machine because it has finite states. also the strict subset.

FV (Ada spark, lean) is not Turing complete because they all halt.
Cannot implementation things like infinite generator or task runner etc.

From incomplete theorem: no consistent logical system can prove itself. lean cannot prove itself.

### Why can ada spark eliminate runtime errors?

It doesn't mean it can predict all user inputs. Rather, because runtime errors are defined by humans anyways, so we can eliminate them by checking for specific errors.

C has no runtime errors (ada can eliminate with some checks). This is something defined by the runtime, ergo, artificial.
