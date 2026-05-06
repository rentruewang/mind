# LLM

### Note

LLM is really good at enhancing existing workflows, making them more user friendly.

My criticisms below are more against people thinking that it can "move fast and break things" while in reality it is more like "break nothing, make it better", which tbh makes it hard for startup to build businesses around, as "it" is way too diverse.

## Current use

Llm is used as a blackbox.
Declarative approach on llm (give answers and find prompts).
Very good at natural language and personalization.

## What it does great

Solves the "framgentation" of AI (you have a unified interface to solutions to text / image etc).

Natural langauge is very flexible (its interface), _but neither reliable nor precise_.

## Why not going to be successful

1. Use in B2C?

Not really useful or entertaining on its on. Search is good, summarization is good, but those predates LLM.

Students might want to pay, but they are the ones with the least money.

In B2C, users don't care about specifics, so LLM is quite good in use cases like drawing, plotting, writing emails, but these activities don't make money.

Right now the cost of running vs paying is 10x (for $200 plan, compute spends $2000+). Most people aren't willing to pay that.

1. Use in B2B?

Not reproducible enough, which is not compatible with businesses, by definition, reproducible processes. Good at experimenting / prototypes does not mean good at engineering / production.

Unreliable.

3. No technical moat

Prompt tuning has a low skill ceiling. Everything you can do I can do too, and vice versa. So you cannot capture value as once value is found, it's spread out.

1 man unicorn is not possible, precisly because if everyone can do it, it lacks scarcity, and is thus worthless.

Low skill level, cannot build too much that the model itself cannot.

4. No path forward

A most common thing to hear is "In 5 years llm would....", but no one actually has a path as to how that would be achieved.

5. For coding / intelligent work??

Llm = maximum likelihood estimation, no creativity / innovation can happen because of how it's trained. Good for writing a demo online that the LLM has seen thousands of times on GitHub on, but no in business. Business needs innovation. LLM use in production? No, use library instead (not new). Good for ad hoc e.g. plotting tho, or for students lazy to write HW, but those don't generate value. Even if llm good for prototype, no money in that.

Not good at maintaining and editing. Good for one time use. Either way, requires heavy human in the loop.
At this time, common patterns in code are all in libraries, which you can trust.

LLM also are bad at generating something new, not just because of lack of optimization, but also it hasn't trained (by definition) on unseen ideas.

Since software is a winner take all industry (especially open source), rebuilding the wheel doesn't really make sense, or create value.

6. Unreliable (fundamental problem of LLM)

**Being unreliable is its fundamental problem**. This means you cannot trust its result, even if it has 90% accuracy, you do not know which part goes wrong, which means it requires human in the loop.

Human in the loop means **no automation**. It also means LLM doesn't save time on valuable thing, but boilerplate and mundane things. Which is important, but at this stage most of them are solved.

Usage of LLM are basically patches to its fundamental problem (unreliable), and is exponentially more expensive.

7. Benchmarks

How, then, are they so good at benchmarks? They cheated. Training testing set leak. As it's at best going to be an average 50% human, it simply doesn't solve problems that are PhD level like so many LLM provider claims.

8. Saving cost

Save time in (inefficient) process, not creating value.

9. No creativity

*I believe creativity comes from planning and optimization*. LLM is maximum likelihood estimation so it doesn't create, but follows a well worn path (may follow it well).

10. Understanding and usage

If you understand, you can use it (part of plan) to achieve your goals. LLM has shallow understanding, not deep, and cannot use it at will / flexible according to a goal.

Therefore, in coding, it doesn't really use patterns well, but rather it repeats patterns (like fizz buzz enterprise), without considering whether or not it is the right call.
Even if it generates lots of comments, it's not simple enough because it likes to repeat itself and doesn't really make use of abstractions (why would it? it has such good memory!)

11. Bad at collaboration and specification

Natural langauge is not accurate. Everyone uses their own dialect, each differing a little. Therefore, it doesn't scale across individuals, teams even less (like when a novel is continued by another author, it doesn't feel the same).

It also doesn't really do what you want it to do. Think of it this way: since LLM is a funciton, the complexity of what it solves only mirrors your command; to do something exactly how you want, you would need to have so many instructions (maybe even more than code), or else LLM is going to follow whatever is in the training data (maybe some terrible random OSS code). Only as accurate as you describe it to be.

12. Wide problem surface, not deep

Since LLM is pitched like AGI, it suffers the same problems as AGI in monetization: it doesn't solve 1 problem 10 times as well, but rather improve **every** problem by a tiny margin. It is difficult to monetize this kind of stuff, as the **value** created is not strong enough (humans are satisficing so may not notice).

13. Anecdotes

> Unfortunately the reality of LLM-based contributions has been mostly negative for us, from an increase in background noise due to worthless drive-by PRs full of hallucinations (that wouldn’t even compile, let alone pass CI), to insane 10 thousand line long first time PRs. In-between we also received plenty of PRs that looked fine on the surface, some of which explicitly claimed to not have made use of LLMs, but where follow-up discussions immediately made it clear that the author was sneakily consulting an LLM and regurgitating its mistake-filled replies to us.

## Unicorn where?

Simple exercise, where are the unicorns? SV unicorns become a unicorn on average in 3 years.
As of moment of writing, no unicorn created with prompts exists (companies that rely on being LLM platform are not themselves reliant on prompt tuning, and companies just using LLM as autocompletion API I wouldn't count as well, specifically copilot as codex predates GPT 3.5).

1. Perhaps because if everyone can do it, no one can do it? (Money is measure of scarcity).

2. Or maybe because, it doesn't do anything new, but rather copy existing libraries well (which doesn't make money, as you pay for novel solutions).

## Potential avenue

Since human in the loop is necessary, maybe tooling like CAD can be good? Other than that I can't think of anything else. Even CAD is stretching it.

## Why other ML algorithms like table missing values filling is more valuable.

LLM predicts texts.

Texts are used for communication, do not on its own guide your other money generation system (e.g. stock trading, logistics etc).
Predicting numbers is more valuable at that.
Texts are more for human reading. Therefore, fundamentally, LLM isn't really positioned to be valuable in business context. But can wow people (what gpt did in 2022).

Maybe you can convert text to numbers to make it valuable. However, for regression tasks, there are simpler and cheaper models. For complicated tasks, texts are a bad form to convert to numbers, as:

1. Rough value surface: the text meaning can change too much with little change in tokens.

2. Ambiguity: Text cannot be interpreted reliably.

3. Reproducibilty: LLM itself cannot be easily predicted. E.g. on documents, you need to run to see if it works on a specific type of docs (like a sorting algorithm that needs to be run and verified with human eyes to see if it works, would be less useful).

## Frontend vs Backend

Good frontend (API) = simple -> easy to copy

Good backend (platform) = powerful -> difficult to copy

Spark / OS ties frontend to backend so they are difficult to copy.
SQL frontend too uniform so they have lots of alternative implementations.

LLM frontend: just text.
LLM backend: just model.
No wonder it's so easy to copy!

## Not AGI!

In 1960s, when people started doing AI, they do planning / games / tree search / symbolic computation, which resulted in today's computers. They are goal oriented.

Today, deep learning (including LLM) captures more of an animal intelligence. Impressive yes, but there is a gap between reasoning and animal intelligence.

Precisly this is the reason reasoning models won't work, it's like asking a dog to learn calculus by memorizing!

Familiar = can use to plan.

LLM cannot plan, therefore they cannot understand.

## Black box

A system with objective function is controllable (control the goal, goal oriented).
It itself does not need to be a white box for it to work flawless, as the goal converges / collapses the behavior of the system.

Creativity is a byproduct of optimization (randomization is the most surprising, but we don't call it creative. It needs to be good to be creative, which is an optimization problem).

Usually, smaller models do not need tuning for the most part, and are very stable. Big models would.

These are the reasons LLMs are very difficult to control, and a better alternative might be simple to achieve.
