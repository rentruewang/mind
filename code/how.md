# How humans program

Must have:

Discover of primitives
Using primitives

When being faced a problem, humans:

**Break down a problem**

- Find intermediate representation
- Multiple simulation and pattern finding (even symbolic reason can start with simulation)
- Identify patterns, and solve for the given pattern, then confirm the newly built pattern
- Compare to what is previously known, perform deduction
- “Don’t know how to start” because breaking down requires knowing the intermediate
- Sometimes know the problem well enough to transform them into symbolic representation, then solve a general solution
- Perhaps done by hierarchical wiring in the brain, as well as memory and attention
- Symbolic / abstract analyzing (pattern finding) of stages is performed (finding stages of common behavior), and maybe reordering
- Understanding existing code falls into this

**Assemble solution from known primitives**

- Assemble from primitives already in memory
- Seems to be way harder, and memory is limited
- Therefore, solves simpler issues, but perhaps quicker
- Think about how to use primitives we have, even deliberately and try different combos
- Assemble known solution into another primitive
- Perhaps done by memory activations in the brain responding to familiar inputs, or (open ended) symbolic extrapolation (already know how to solve, vaguely)
- Obvious in hindsight
- Knowing how to improve the design falls into this

**Simulation**

- Humans would simulate between different hot paths to find a solution
- In each path, a problem is broken down and assembled
- Rather than math / programming, natural languages probably capture more how humans think.
- Viterbi algorithm in neural wiring probably
- More of a composing solution thing than breaking things down thing

This is possible because humans mind work in sequential, so bigger events can always be broken down

**Anecdotes**

- Brain is mostly doing scientific method, hypothesis, searching, and testing
- Sometimes you form a symbolic conclusion too (works for any case e.g. induction)
- Obviously scientific method is used for concluding over multiple instances of the same problem, or else it's just memorizing
- Summarize items into abstraction by deduction (sometimes it's documented)
- Compare to known, and fix hypothesis when necessary
- Looks like a state map like turing state does exist when reading a program
- I also do lazy evaluation and only extract info I need
- Predict + surprise
- Probably same as reading novel, having general idea of what’s going on = state
- States exist everywhere. When I'm reasoning about dynamic programs, recursion etc, those are states. Any tasks that has intermediate representation or retrieval (tape or state) requires memory.
- Usage of memory is apparent in redactors and reimplementing, where the contract (external states) are unchanged.
- There are no Singleton problems. If there is one, then you cannot explain, only memorize.
- Face recognition is one such instance of feeling (computation) based abstraction.

**What Turing said**

On Wikipedia:

*"State" in the context of Turing machines should be clarified as to which is being described: the current instruction, or the list of symbols on the tape together with the current instruction, or the list of symbols on the tape together with the current instruction placed to the left of the scanned symbol or to the right of the scanned symbol.*

- "State" in the context of Turing machines should be clarified as to which is being described: the current instruction, or the list of symbols on the tape together with the current instruction, or the list of symbols on the tape together with the current instruction placed to the left of the scanned symbol or to the right of the scanned symbol.

This means that programs correspond to states, and data correspond to the tape. Think of a library, where different code paths (different states) are taken based on different user inputs and data configs (different data on tape).

This means that if human brains are simulatable by Turing machines, which I believe to be the case, then humans also have states in their mind, which correspond to different code paths and abstractions.

Fundamentally, if we know where we are in a program, this must be encoded in states not tape because of halting problem and that tapes have infinite length.

Ideally, you want variables in a function to fit in registers anyways (states rather than tape).

Hopcraft book treats program instruction as part of the tape. However, since the program itself is finite, we can enumerate the combo of instruction and the state that Hopcraft defined and treat it as the new state.

**Biological implications**

Regardless, humans attention can only be at a place at once. The primitives in brain does follow the program's flow, but rather work on individual components based on what state (where we are in the program) we are in, but uses memory to reason about past events. That's why good code just be short and concise.

This must be the case because any half decent programmer can tell you about the flow they wrote, even if badly organized.

Even in the problem solving phase, branching out to different solutions requires states to hold the previous solutions.

Act of abstracting = states. Because abstraction allows a person not to recurse into the underlying implementation details -> dp.

**Abstracting has 2 parts**

1. Abstracting over the implementation underneath
2. Abstracting over the program state

These 2 are the same, where as 2nd is simply folding over the precious state.

In some ways, abstraction is recursion (especially when it refers to itself).

Seems to me that humans are doing the reverse, using memory for 2, and memorizing building blocks to do 1 (implicitly contain previous state as new data structures get created).

Debugging is either fixing s.t. it matches the beliefs or fixing the beliefs themselves. Fix-up behavior is essentially coding in reverse.

Debugging is just verifying over if the precious framework / steps of logics are correct. It can be symbolic, a special test case etc. But it follows the designing framework (states / building blocks).

Memory blocks + world model makes sense. This is why design patterns are so prominent.

Attention = context switches = memory.

State to reason current program state, (designing, debugging), tape for existing knowledge (algorithm, data structure), and simulation depends more on state.

Out of order computation requires storage obviously, or a different way to access storage.

**Another dimension of abstraction**

You practically never get the design on the first try. Rather, you build the first world model (design), and then expanding it when it makes sense. During this refinement phase, different phases or versions can be thought of a module / block in a function, where you know what is changing before and after and how the program changes its behavior.

For example in koila, I do lazy > shapes > GPU > partial eval, and even in bocoel, I change and expand on the design multiple iterations.

During each part of the design, I focus on that part of design, observe the outcome, and treating the rest of the parts as static (testing = validation of hypothesis).

Regardless, I'm just editing the world model to behave differently. This relies on state as well as simulation of world model to accomplish.

The edits correspond to a change in world models, be it an incremental update to expand the world model, or toss it out all together. If you do these changes a lot, you kind of build a world model on the changes themselves as well (this is too abstract and maybe not the case, but possible).

**Ubiquitous of memory**

Every step I take I use memory, or the search space is too big.

When typing, I remember the location of each key.

I compute based on the world model, which is built upon the sequence I memorize.

Therefore, memory is ubiquitous

**Streaming**

- Brain obviously is using streaming because neurons cannot move.
- Brain uses abstractions / context switching a lot based on memory.
- Abstraction is based on memory.
- World models are done in the background via simulation.
- People explain by analogies, which relies on memory. This is why smart people struggle to explain because it's all intuitive pattern matching done by computing (no memory). World models are more about how good your memory is.
- Abstracting is generalization (approximation in ml) and uses state to predict unseen instances.
- Generalization (even generate and test some rules that work across multiple instances) take memory (even if just used to store the instances).
- Humans learn languages by associating examplars with words, and when a word is used in multiple examples, the hierarchical part kicks in to create an abstract concept.
- And then, concepts are formed by sunsetting / intersection and finding common patterns.
- Relations between entities are the ultimate primitives.

**Evidence**

- When people write code, they usually don't review the assumption built upon by what they are changing, but rather add additional changes (causing baggage in the long run).
- To do it completely without memory, humans would have to have a big combinatorial logic gates to compute something that may be computed over multiple cycles of a smaller logic designs (which has states).
- Humans encode / decode in hierarchies and use building blocks.
- Humans do not tend to question what they already know. Hence confirmation bias.
- Internal playgrounds do exist, and is how I personally program.
- World models are built by memorizing. This is why some programs are harder to understand, because they use unnatural constructs or are complex.
- Good translation is closest (unless a terser representation is found), and have constructs naturally mimicking the original (high level) constructs, because it is transformation between world models.
- Humans use different networks / circuits for different tasks. Which makes asynchronous tasks merely an attention task.
- Humana backtrack + context switch / switch over back and forth while planning as opposed to e.g. MCTS look ahead due to attention's limitations of being serial.
- Humans sometimes work the reasoning backwards, still in a symbolic way.

**Conclusion**

Memory is inherent in world models = building blocks. Prediction of world models depend on memory because it's based on past trajectories. Abstraction and generalization is essentially a level above. Scientific methods (closely related to symbolic world models and abstractions) of hypothesizing and pattern matching can depend on abstractions or not, but it depends on past trajectories for sure. This goes for symbolic reasoning (e.g. data structures) as well. Or rather they are just a different system that is retrieved and matched (e.g. this problem has same properties as a stack / dag), but still they rely on memory / own world model as well. Of course, algorithms are processed, and rely on program state changes, even in functional languages (abstraction in blocks vs state).
