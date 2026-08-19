# StarCraft Broodwar and StarCraft 2

Broodwar seems more varied in its play and available strategy at the top level, but why?

Disclaimer: I do not play those games, but watch them extensively.

1.  Slower start makes timing window larger -> comeback possible because of larger window, not all about eco
2.  Positional play is stronger -> player stays more on the map because (smaller groups of) units can defend themselves -> more skirmishes
3.  Mobility worse -> positional play stronger
4.  Less clump -> more plays because no balls and splash is weaker and terrain is more important -> scaling worse (also selection limit) -> comeback possible
5.  More about throughput than latency -> longevity
6.  Harder game -> more varied play style as players play differently (composition etc) -> every game is different
7.  No instant death
8.  Different maps
9.  Map control needed to secure new bases, worker spread mechanic -> bases and spaces are important, not just workers
10. There seems to be more randomness and gambling in broodwar as you cannot be ready for everything. In sc2 you can be ready.
11. Units are more general purpose, which means composition choices are realtively free compared to sc2.

## What technical jargon translate to in terms of game state

Positional = slower units, vs multitask = faster units

2 ways to look at army

1. money and cost efficiency
2. power and money as constraint

To look at positions:
With 2 armies of similar speed and size
Concave (Zerg, surround) = less scalable units, hate terrain
Convex (Terran, death ball, spearhead) = more scalable units, use terrain
Also, cheap, numerous = fast, because even if expensive units are fast, they can't defend anywhere at once.

I compare games to the ones I have played, and the difference to explore new positions

Strategy vs mechanics
Strategy = hard counters / decision making, higher level, range
Mechanics = do basic things, lower level, sameness

Safe vs corner cutting
How big the threshold is for transitioning between good game states

Race for pushing vs race for defending in meta

You only push (try to interfere with opponent's states) when you get outscaled doing single player. E.g. In BW, T in TvZ, P in PvT until carriers. T in both matchups in SC2.

Pre planned strategy vs on the fly
Pre planned deviates you farther (deep planning), and on the fly relies more on quick compute / cache, more middle of the road, but has more flexibility in execution.

Game sense = on the fly deduction and requires you to be fast

Good planner = good at planning in game states, this is not equal to players with big range, who play with more varied game states but may be less precise.

TvT is most positional because both sides try to produce a middle of the road army that deals with many situations, because T tech switches slow.
