## The more you learn, the more you realize you don't know

This is completely BS. If people learn poorly by memorizing then sure. But if by learning you also extrapolate, no way this is true, considering that humans approach things in a hierarchical manner.

## Why rhetorical questions are annoying

They imply the listener "needs to be reminded", belittling the listener.

Now, it doesn't sound rude if you also bring yourself down ("who doesn't like money" -> shows signs of own weakness), but overall it can be annoying when you are reminding the other people the obvious ("don't you know...?", this is more annoying when you already know).

## Interpreters

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

## Compilers

Control flow graph: Control flow of scopes (each scope can be represented as its own dict).

Sea of nodes: Data nodes and control flow nodes.
From the Turing machine abstraction, of course it's data and control nodes! Data = memory access to stack / heap, control flow = changing the program counter.

Starting here -->
Non optimizing compilers

Maintaining control flow, relaxing within each block -->
Control flow graph

Relax data and control flow (except returns) -->
Sea of nodes
