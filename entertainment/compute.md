# Memory and compute in games

- Strategy is more memory based, whereas tactics are more computation based.
- Strategy requires you to know about the game state.
- High level / symbolic decision relies on caching / abstracting low level decisions.
- Planning in general relies on accessing game states.
- Abstraction themselves are memory. Think of training a policy network. On a specific instance, it only needs computing and branching. However, if this policy always behave similarly, it's because the behavior is remembered by its parameters.
- Good tactics can be achieved by computation, however, for higher level planning, you want an abstract / symbolic representation. Which requires showing how the underlying tactic behave over multiple instances of game states. This must be memory based because it is memorizing over multiple history trajectories, which if computing based, would have to compute over all of them (see the next section).
- Game sense (in 2 player game) is guessing what the opponent is doing, coupled with what you are doing yourself, you have a complete world view. Game sense (in PvE) is just learning how the environment would respond.

## Strategy vs tactics

Some game theorists define strategy as "having complete access to all the game states, and figure out the best possible rewards", and tactics as "having limited access to the game tree, and figure out the best possible rewards", and conclude that tactics are positional inherently, and does not make sense for information available globally.

I disagree. I think strategy / tactics is more like the high / low level decision making I described, where high level guides low level (pushing vs retreat), and low level informs and influences (adjusts) high level decision making.

I don't think strategy is limited to global game state, but "being higher level" is probably a better definition. Maybe both are working with the game tree, where strategy = tree being high level, where each node is multiple steps decided by tactics. Kind of like RL's hierarchical policy.

In a PvP game, you naturally do not have access to your opponent's mind, therefore by definition no information is global or certain. Even in a zero sum game, opponent's computation power is not infinite.

Positional warfare like advance wars still can have strategic play, where players decide where to fight and unit type how to counter opponent.

Global information, like how to spend money in a turn based 4x game, can still be highly tactical (low level), for example optimize spending when dealing with a timing attack (e.g. opponent's threat will materialize in 3 turns, 1st turn let's be maximally greedy so once the threat can be dealt with, you are in better position).

4x games having money making it much more strategic, because money is by definition high level, and can be switched into (any? depending on the game) resources that you want.

Some people think that strategy is about prioritization. Which is true, but that is IMO only a part of strategy. Think of it this way: if the computation power is restrained into only being able to make 1 actions, then it is prioritization indeed.

4x / rts games where you can "out macro" your opponent is more strategic and feels more strategic, because "out macro" means making higher level decisions, such that no matter how good your opponent's micro is, they cannot come back. So again, higher level decisions.

One case where tactics affects strategy is it dictates how good each step can be, if your tactics are better, your strategy are more flexible. E.g. in starcraft, if someone has very good worker micro, they can get away with very greedy strategy, because they can survive with less units in the early game.

### Active vs Reactive

In a 1v1 game, active means focusing on your own game tree (maximizing your own), where reactive aims to minimize opponent's scores.

### Flexible vs Non-Flexible playstyle

Hot paths in game state tree (game script) spread out vs very focused on specific paths.

Reactive playstyles usually pairs well with flexible playstyle.
Active playstyles usually are less flexible.
Simply put, if you can maximize your play, yet having many opportunities, your faction might be OP.
