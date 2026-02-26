# Problem solving

## Scientific method

Problem solving involves the following process:

0. (Simplify) Maybe simplify the problem first. Preserve and isolate the relevant parts. AKA analysis.
1. (Retrieve) Enumerate some instances you know, whether it being concrete or symbolic, or a simplified version of the problem.
2. (Simulate) Do simulation in the head, maybe extrapolate or use extreme cases, assemble solutions from known primitives.
3. (Verify) Check if the solution is working, symbolically or experiments. If not, maybe restart. Compare to things we know.
4. (Aggregate) Find common pattern across different instances, or derive at a result symbolically.
5. (Update) Update hypothesis / world models.

### Problem transformation

Problem transformation applies simplify, retrieval, simulation on **abstract patterns**. E.g. we retrieve induction, hierarchical structure from memory, using it to simulate the original problem, and assemble (inverse transform) into the original problem. We can use it to isolate / focus on the smaller problem, to **simplify** the original problem.

## Categories

Pre-condition: Simplify

Planning: Retrieve, Simulate, Verify (assemble = have target solution, simulate + verify)

Memorize: Aggregate, Update

### Notes

Planning is the essential part.

World models allow planning (provides transition).

You simply cannot do any of which without memory.

Especially since brain is more of a sequence machine, where you identify patterns in sequences, memory is used for retrieval and similarity comparison.

Learning the fundamentals and understand a knowledge -> able to use it in various ways, and plan with it

In editing, action = change, state = outcome. Not really that different from generating (maybe with less middleware).

## Examples for problem solving and planning

- Algorithm exams / inventing an algorithm
  Find similar problem (retrieval)
  Find special case, and then do induction (simplify / assemble / verify)
  Using known problems and the similar problem as a stepping stone, and try to transform the problem (assemble)
  Simulate the running of the algorithm (simulation)
  Analyze the structural property of the problem, e.g. Z-order curve is recursive (simulation / pattern / assemble)
  Break down the problem if needed (simplify)
  Try / assemble different combination (simulation / assemble / aggregate)
  Check if working (verification)

- Debugging
  Doesn't behave as expected, look at relevant items (retrieval)
  Only look at parts changed for a working system (simplify)
  Knowing the cause and effect of different components (retrieval / simulation)
  Isolate the parts of concern (simplify)
  What did I do? (retrieval)
  Revisiting state of mind, to figure out why, hypothesize, and check the result (simulate, verify)
  Deduct from the observation after change (update)
  Have hypothesis of what's wrong (assemble / verify)
  Rollout + deduction + predict + verify from hypothetical scenarios (assemble)
  Plan on changing (rollout) and predict what would be the result of change (simulation)
  If fail, update beliefs and try again (update)

- Editing and refactoring
  Know what each part is doing, gain idea into actual data flow (retrieval)
  Plan a series of change that can be tested along the way (assemble)
  Find equivalent ways of doing things in old and new (assemble)
  Try to make the problem as simple and clean as possible (assemble / aggregate)
  Find min-cut in the new data flow / info exchange for modularity (simulate / assemble)
  Revisit assumptions, and predict how the input could cause change in output (simulate / verify)

- Learning when something clicks
  Compare with past knowledge and experience (retrieval)
  Break down into basic primitives, and reconstruct (aggregate / assemble)
  Simulate and see the cause and effect (simulate)
  Find out isomorphism / difference with current knowledge (retrieval / assemble / aggregate)
  Incorporate new knowledge into old world model (simulation / update)
  How is the knowledge different from what I know? (retrieval / update)
  Ensure consistency and update beliefs (retrieve / update)
  Try using this new knowledge (simulation)
  Use the knowledge in new ways, inspired by specific difference with current concept (assemble)
  Go down a path, doesn't work, check the reference material, try again (retrieval / simulate / verify / update)

- Theory of mind (try to make other person feel some way / do something)
  Think in terms of information they get (retrieval)
  Pretend you are the other person receiving info (simulation)
  Optimize for what you want (simulation)
  Memorize the result (update)
  Finding common pattern and make assumptions (e.g. humor) (aggregate / planning)

- Game planning
  Pretend you are the other opponent (simulation)
  Plan with opponent's play style (retrieval / analyze)

- Deduction
  Find out events / attributes to focus on (simplify)
  Simulate a bunch of plausible scenarios (simulation).
  Validate each scenarios (verify)
  Narrowing of scope after isolating each possibility (simulate / update)
  Perhaps a series of yes / no question on (symbolic) scenario search tree (aggregate / simulate)

## Neurons

I think this is done in neurons in the following way

activate circuits (retrieve): retrieve, assemble, verify
aggregation (hierarchy processing): simplify, aggregate, simulate
update (memory): update
