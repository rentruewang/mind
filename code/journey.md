## By category

### Pre 2019

When I was in RL / ML, I mostly didn't care about code quality.

### 2020-2021

When I was still doing eda -> I optimized for fanciness and speed

Started caring about readability in 2021 -> Huffman and brief.

### Open source in 2021

Simplicity and readability being increasingly important after koila, in which I designed quite hard and so does all following projects. (You don't pay for what you don't use, the simpler the better, in maintainance and performance)
Functions start being as short as possible (not yet as abstract and DRY as possible).
Being readable and short implicit constraints on simplicity.

### 2022-2023

I was obsessed with abstraction principles after I read clean architecture somewhere in 2023, and decided micro architecture is the way to go. (No data leaked principle)

### 2024

I adopted the simplicity doctrine, and tolerate no code duplication.
At this time, I optimize for simplicity, not just in writing code, but also in the compiled instructions / machine code (no extra computation).
Writing the bocoel project gave me a lot of real world application to my knowledge on architecture (depending on abstraction, which evolves into strategy pattern, which at the time I didn't make an explicit connection but is obvious I figured this type of idea out retrospectively)

### 2025

Work also makes me prioritize and work with a deadline. Makes me minimize work as well. Working with a much more "dirty" real world app. For example, in `bocoel`, I made everything an interface because I can. In work there wasn't such time.

Also I never was able to spend time on coding for this long, which made my made some good progress about programming principles.

Maybe I focus too much on simplicity and terseness, not necessarily approachability and maintainability (perhaps too abstract).

### 2026

Practicality: New mindset. _Write now, design later_. Uses github's squash and merge (coding with less focus on perfection, can always squash later). Happy to merge less than perfect changes, so long as it keeps the progress flowing (personal project ofc, in work there are external pressure). I realized that focusing endlessly on perfection is just not going to cut it, with my limited time and many goals to hit.

I think this is a pushback from previous years where I was very stressed out designing perfect plans when writing new code. No more (still do it to some extent but try not to).

Tho, my skills have improved, and I write with decent modularity and elegance in my designs by default, making the refactors down the road a little easier and managable.

[Trying to be the stoneager](https://www.reddit.com/r/rustjerk/comments/wey6dy/im_in_this_photo_and_i_dont_like_it/), moving from overthiking, elegant elitist and simplistic, modular boilater.

## Platform type code I read

2019/08: CPython. Specifically around types.
2024/04: [Crafting interpreters](https://craftinginterpreters.com/).
2025/08: FP (Haskell / GHC) and FV (ADA / Lean), Type / set / category theory.

Honorable mention: Spark / Postgres / Clickhouse somewhere in 2025.

Reading these platform type source code has dramatically improved my ability to design code, as those are pretty abstract, has good code quality themselves, and employ a lot of data structures / algorithms / tricks to be robust. Especially crafting interpreters made my coding skills improve by a lot.

## Previous projects' processes

### Koila

**thought process**

- Batch size ~ memory use
- TF don't get OOM because static graph -> full info, decide batch size

**impl process**

- Create static from dynamic -> lazy eval can track graph
- Shapes are important, then device / batch info
- Partial info depends on device and shape

### Bocoel

**thought process**

- Select with Bayesian
- Bayesian only work with vectors
- Convert into embeddings

**impl process**

- Index + corpus
- Bayesian optim
- Adaptors (starting from functions)
- Exam / Manager API
- Compared to koila, bocoel is way more modular in its implementation process, and less organic, in the sense that koila evolves naturally, and bocoel is designed and stayed static
