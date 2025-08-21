
When I was in RL / ML, I mostly didn't care about code quality.

When I was still doing eda -> I optimized for fanciness and speed

Started caring about simplicity / readability in 2021 -> Huffman and brief

Simplicity and readability being increasingly important after koila, in which I designed quite hard and so does all following projects. (You don't pay for what you don't use, the simpler the better, in maintainence and performance)

I was obsessed with abstraction principles after I read clean architecture somewhere in 2023, and decided micro architecture is the way to go. (No data leaked principle)

At 2024-2025, I adopted the simplity doctrine, and tolerate no code duplication.
At this time, I optimize for simplicity, not just in writing code, but also in the compiled instructions / machine code (no extra computation).
Writing the bocoel project gave me a lot of real world application to my knowledge on architecture (depending on abstraction, which evolves into strategy pattern, which at the time I didn't make an explicit connection but is obvious I figured this type of idea out retrospectively)

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
