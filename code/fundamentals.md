# Computation fundamentals

## Data and compute

There are 2 main components in computing, data (measured by space complexity) and compute (measured by time complexity).

I theorize that
Data = entities, storage, intrinsically exists
Compute = mutation on data

Data is more fundamental than computation, because computation are performed on data (data = symbol, compute = instruction in Turning machine), and therefore is a derivative by nature.

## Relation to Turing machine

Think of the possible types of data as Markov, then a library / app is just moving on a path on this Markov state / graph. This state is exactly a Turing machine’s state as I can ask TM to simulate a function for me.

Even transmitting a packet counts as computation, because it's changing state (location) of a piece of data.

## How do abstractions come into play?

- I think it's just types of data and the type of compute (abstract, reasoned with invariance) that can be performed on them. Considering that every function is data -> compute -> data, abstraction in terms of breaking down functions are just composing data into intermediate representation, and abstract interfaces are shared traits of different data + specialized compute for each kind of data.
- Abstractions are just using computation to transform underlying data into the same mathematical model. Compiler optimizing this away = 0 cost. Some data structures might happen to have a better complexity but those are implementation details.

## Modularity and abstraction

To produce maximally modular code, the component itself is kept small (more specific, more use in places), and the contract options large / interface less demanding (more abstract, accepts more items). This gets reflected in function signature (see covariance and contravariance of input / output).

## How modeling works

Hardware program: you find a set of physical constructs with mathematical property, like adder, and work from there.
Same with using software to program: Writing code = using code to mimic the mathematical property of something, isolate the part we care about, from sensors etc.

OS abstracts from hardware and lets you only do (pure) software.

System design: architecture that may rely on entities you don't control (hardware / DB etc) vs software architecture: you control everything.

System design requires mapping real world requirement to code (interface level), and software design requires cleanness and simplicity, depends on what the available interface are ofc, minimizing mincut of information flow.
