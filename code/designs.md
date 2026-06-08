## What is coding?

Quoting Wikipedia on [Turing Machine](https://en.wikipedia.org/wiki/Turing_machine):

> The machine operates on an infinite memory tape divided into discrete cells, each of which can hold a single symbol drawn from a finite set of symbols called the alphabet of the machine. It has a "head" that, at any point in the machine's operation, is positioned over one of these cells, and a "state" selected from a finite set of states. At each step of its operation, the head reads the symbol in its cell. Then, based on the symbol and the machine's own present state, the machine writes a symbol into the same cell, and moves the head one step to the left or the right, or halts the computation. The choice of which replacement symbol to write, which direction to move the head, and whether to halt is based on a finite table that specifies what to do for each combination of the current state and the symbol that is read. Like a real computer program, it is possible for a Turing machine to go into an infinite loop which will never halt.

and [Turing Completeness](https://en.wikipedia.org/wiki/Turing_completeness)

> In computability theory, a system of data-manipulation rules (such as a model of computation, a computer's instruction set, a programming language, or a cellular automaton) is said to be Turing-complete or computationally universal if it can be used to simulate any Turing machine.

[Church–Turing thesis](https://en.wikipedia.org/wiki/Church%E2%80%93Turing_thesis) states that **any function that is computable by an algorithm is a [computable function](https://en.wikipedia.org/wiki/Computable_function)**.

[Computational Theory](https://en.wikipedia.org/wiki/Computability_theory) states that:

> A set of natural numbers is said to be a computable set (also called a decidable, recursive, or Turing computable set) if there is a Turing machine that, given a number n, halts with output 1 if n is in the set and halts with output 0 if n is not in the set.

With all these information, one can conclude that anything that is computable must be able to be compiled (transformed) to an algorithm running on a Turing machine, where compiling means transforming between different language / instruction set.

Considering that

> A related concept is that of Turing equivalence – two computers P and Q are called equivalent if P can simulate Q and Q can simulate P. The Church–Turing thesis conjectures that any function whose values can be computed by an algorithm can be computed by a Turing machine, and therefore that if any real-world computer can simulate a Turing machine, it is Turing equivalent to a Turing machine. A universal Turing machine can be used to simulate any Turing machine and by extension the purely computational aspects of any possible real-world computer.

> In computing, a [compiler](https://en.wikipedia.org/wiki/Compiler) is a computer program that translates computer code written in one programming language (the source language) into another language (the target language).

A best translation is always the closest to the original that is the shortest in the new domain, therefore, the best software design is therefore the best transformation from the source (map domain, physics domain etc) to the language understood by the Turing machine (your software), with structures / meanings naturally mimicking the problems in the domains we aim to solve, unless there is a more terse / faster way of computing the same thing.

As an example, let's say if an action `A` can be accomplished with the instructions `I`, and a computer `T` follows the instruction. `T` is flexible in its definition (maybe even humans, if humans are Turing machines)! Provided that the same thing can be accomplished by a computer program `P` running on computer `C`. This means that there must be a translation between `I` and `P`, understood by `T` and `C` respectively. The translation principle still follows (similar in meaning but as terse as possible) in this case, without exception.

## Strategy pattern

Strategy pattern is better than if else because the power lies in easy removal of components, where as binary decision has a boundary engrained in the branching logic. This allows modular components to even have overlaps or null implementations.

## Mental state of reading and designing

Reading vs designing code feels much different.
Reading → just simulating different conditions and think how they interact, possibly compiling and optimizing existing logic.
Designing → Wholistic and breaking down problems

## Rewrites

Rewrite (architecture) is only when business problems change, because architecture is usually derived from business problems and no one uses a harder than necessary architecture.

## Push vs pull

Pulling is when downstream queries upstream in an iterator fashion, pushing is in reverse, when upstream calls callbacks to update downstream (inverted control flow).

Pulling is lazy, but events aren't lazy, so they are usually push based.

Pushing is more memory efficient for fan outs (upstream calls users in a loop).
Pulling model in this case would require memoization (when do you free the output? how many users?). Pushing just use a temporary variable in the loop.

Pulling is more memory efficient for fan ins (downstream request data).
Pushing model in this case would require a buffer to store the results.

Pushing better models stages (because of the fan-in buffer), and pulling better models batches (because you can free the memos).
