## What languages are you interested in working on?

I'm only interested in Python, and Modern C++/C/CUDA. [Any performant system comes down to algorithms and engineering](https://stackoverflow.com/a/4911818), and programming languages is just a small part of engineering (e.g. less than architecture design). These are more than enough to cover my use cases (I do not build too much frontend).

Personally, I treat all other languages as domain specific and use them from time to time, but those aren't my focus. **Languages are the same anyways, so they can be picked up easily**.

## What do I use Python and C++ for?

🐍 Python:

Simple and beautiful, it's **my favorite language**. Besides, it's an awesome glue language that exposes lots of C / C++ libraries, especially in machine learning. Really no alternative. My favorite scripting language.

Usage: prototyping, machine learning, scripting, glue language for C++ libraries, not-so-performant solution for quick and easy tools / services

🛠️ Modern C++ (Old C++, C, Cuda):

Complicated but useful. Super fast (bascially the 1x on benchmarks). Preferred when **performance** is needed. Modern C++ is also pleasant to write, except for debugging template errors.

Usage: high performance computing, desktop UI, games, improve Python performance, computing bound CLI tools, performant solution for long running tools / services, any sort of low level stuff

**NOTE** Python and C++ are ubiquitous and don't have a lot of [deficiencies](https://softwareengineering.stackexchange.com/questions/329728/are-design-patterns-frowned-upon). They also don't have very few overalpping use cases.

## Since when do languages of a project matter?

**It doesn't**. [Any performant system comes down to algorithms and engineering](https://stackoverflow.com/a/4911818), and programming languages is just a small part of engineering (e.g. less than architecture design). Users care about the end product, rather than how things are written. Still, some languages are better at certain things than others. For me, I would like the minimum possible to be able to do everything I want to do. This is why I use these.

## Languages I have written in the past, and why I stopped loving them

Java:

Java is my intro to data structures and algorithms, and is a very simple clean language (language itself, not the culture). But, I hate its tooling. Very difficult to get around and very cluncky.

Rust:

I like the language. But the community isn't too likable (lots of cocky but ignorant people). Furthermore, since it will never replace C++ because it has no killer application, while being mostly overlapping in the same domain and style (both are kitchen sink languges), and as there exists very few pure rust libraries, incompatibility with C++ means it could not leverage the existing sea of libraries.

> Programming in rust bogged down to thinkig about language features rather than solving problems.

Would it become big in the future? No, because only people who have learned about C++ would love rust. It won't be a successful language as C++ imo. Also too FP like, not C like, to be popular. Most languages that are popular look like C, also FP has its own issues [(sum types)](./fpoop.md).

Go:

I love the language, but simply have no use for it. It shines in building web backends / goroutines, but is outclassed by python / c++ in other areas, in terms of avaialbility of tools / libraries and features.

JS/TS:

My first PR was actually for TS, and the language is nice. But I don't enjoy doing frontend, and there are better alternatives for backend.

## Successful language

Excellent quote on [reddit](https://www.reddit.com/r/ada/comments/twv7je/comment/i3kqdf4/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button)

> Languages don't fail or succeed based on technical merits. We can lecture all day on the benefits of Ada over what's currently in use, but in the end that barely matters.

> In my experience, the success of a language depends on:

> Momentum. If something is already widely used, it will continue to be used even if something better exists. C continues to be used because it's used everywhere. Far better options have promised to replace it, but absolutely nothing has actually managed to do so to this day, and it's not because we can't figure out a better language.

> Environment. This includes the compiler, debugger, editor, package manager, and most importantly, libraries that are available for use. I won't choose the perfect language of it a different, imperfect language already has that top-grade audio library (especially if I just add one line to my build system to get it).

> Available workforce. Most companies won't choose a language that current or potential employees don't already know. Are schools teaching it? How many applicants have it on their resume? It's far easier to justify using what they already know than take the risk of training the workforce yourself.

> Value match. What I mean is, does the values of the language match what I value in a programming language. There is no single language that works for all needs. Speed, portability, development time, reliability, etc.

> Community. What's the wider community like? Support forums, literature, conferences, code sharing, etc. Some communities are helpful in getting beginners up to speed, others are downright toxic or elitist.

> Availability. This is where licensing, compiler pricing, open source adoption, variety of supported architectures, support by big-name vendors, etc. come in.
