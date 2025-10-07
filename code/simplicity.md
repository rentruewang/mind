## Simplicity and architecture

Good code is simple. Simple means easy to read, understand, maintain, and less things to do at runtime.

## SOLID is simplicity

Let's look at SOLID principle.

S, I: Do less things -> simplicity.


L: substiution principle, this has nothing to do with simplicity, but rather the contract of template / generics.

O, D: Abstraction allows for extensibility. **Abstraction, as opposed to using implementation details, is about minimizing the amount of information used.** Therefore, more abstract code is more simple (at least more terse, so simpler in terms of information representation).

## Design patterns

Some amazing way of looking at it: language **is** a pattern. `for` loop is a pattern. We only talk about patterns because we have to implement it by hand, because it's not provided by the language. Visitor pattern being replaced by `match` statement is a good example.

### Dependency injection vs strategy pattern

Dependency injection injects data, whereas strategy pattern injects functions.

For a dynamic language like `Python`, where methods can be dyanmically defined and overwritten, strategy pattern seems to be a special case of dependency injection.
