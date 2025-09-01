# My lerning on dependent type theory

**There are Isomorphism between the theories (category and type)**.

Set theory = study of sets, seems to be most generalized and fundamental.
Type theory = set that can be constructed not enumerated
natural language and programming can behave the same, in type theory

category theory = study of some category of functions, like monad.
Type theory = studying how types relate, a lot of programming concepts related to category theory

Which is the best theory? Depends on the use case and context. Theory = natural and simple representation.

## Why dependent type theory in proof assistants?

Dependent type means you can have a type that depends on values.
Normally, you have functions from value -> value, type -> value (constructor), and type -> type (subclassing). Dependent type is the 4th possiblity for value -> type.

Dependent types strong enough to represent a lot of symbolic logic, s.t. a lot of provers correspond with DT programming languages. Also if we can infer from those symbolic relations, we can implement proofs. Curry Howard correspondence.

No linear types (use once, good for modeling resource usage mathematically) in dependent types.

C++ Turing complete templates is almost dependently typed.

Think of it this way: if all computation happens during compile time, then compiler can execute the program without doing anything at runtime. This is essentially what dependent type does, where compiler executes and verify code during compile time.
