# Interpreters

Interpreters are a very robust abstraction, pretty much everything can be modelled as an interpreter. Why?

Instruction + state of machine -> interpreter -> emission

matches the RL

observation / state -> RL agent -> action (reward)

which we know that brains run on.

We can think of the interpreter emission doing 2 things.

1. Update the state of machine.
2. Set the PC to the next instruction.

So it can be treated as a special case of action.

Reward is not modelled.

RL scores how good an instruction sequence is, and can be used to compare 2 trajectories.

Point is, RL can be modelled with interpreter architecture,
and brain is a very powerful general purpose computer.

# Compilers

Control flow graph: Control flow of scopes (each scope can be represented as its own dict).

Sea of nodes: Data nodes and control flow nodes.
From the Turing machine abstraction, of course it's data and control nodes! Data = memory access to stack / heap, control flow = changing the program counter.

Starting here -->
Non optimizing compilers

Maintaining control flow, relaxing within each block -->
Control flow graph

Relax data and control flow (except returns) -->
Sea of nodes

Actually: for a single assignment language (perhaps functional), abstract syntax tree nodes + control flow dependencies = sea of nodes (pending further optimization).

Because control flow graph = sea of (block) nodes,
this means that control flow graph is a representation on the unoptimized IR.
If you already have the nodes, might as well apply sea of nodes;
also sea of nodes require some code motion algorithm to reconstruct the original function, which is not convenient.

AST: In an imperative language, later nodes (the nodes more "right" in the AST) _can_ have implicit data dependencies on the nodes on previous nodes (more "left" in the AST). This corresponds to the fact that data depdencies are DAG by nature.
