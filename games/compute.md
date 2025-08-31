# Memory and compute in games

- Strategy is more memory based, whereas tactics are more computation based.
- Strategy requires you to know about the game state.
- High level / symbolic decision relies on caching / abstracting low level decisions.
- Planning in general relies on accessing game states.
- Abstraction themselves are memory. Think of training a policy network. On a specific instance, it only needs computing and branching. However, if this policy always behave similarly, it's because the behavior is remembered by its parameters.
- Good tactics can be achieved by computation, however, for higher level planning, you want an abstract / symbolic representation. Which requires showing how the underlying tactic behave over multiple instances of game states. This must be memory based because it is memorizing over multiple history trajectories, which if computing based, would have to compute over all of them. (For individual run, doesn't matter if it's tree search or ai, but having
- Game sense (in 2 player game) is guessing what the opponent is doing, coupled with what you are doing yourself, you have a complete world view. Game sense (in PvE) is just learning how the environment would respond.
