# StarCraft Broodwar and StarCraft 2

Broodwar seems more varied in its play and avaialble strategy at the top level, but why?

Disclaimer: I do not play those games, but watch them extensively.

1. Slower start makes timing window larger -> comeback possible because of larger window, not all about eco
2. Positional play is stronger -> player stays more on the map because (smaller groups of) units can defend themselves -> more skirmishes
3. Mobility worse -> positional play stronger
4. Less clump -> more plays because no balls and splash is weaker and terrain is more important -> scaling worse (also selection limit) -> comeback possible
5. More about throughput than latency -> longevity
6. Harder game -> more varied play style as players play differently (composition etc) -> every game is different
7. No instant death
8. Different maps
9. Map control needed to secure new bases, worker spread mechanic -> bases and spaces are important, not just workers
10. There seems to be more randomness and gambling in broodwar as you cannot be ready for everything. In sc2 you can be ready.

## What technical jargon translate to in terms of game state

Positional = slower units, vs multitask = faster units

2 ways to look at army
1. money and cost efficiency
2. power and money as constraint

To look at positions:
With 2 armies of similar speed and size
Concave (Zerg, surround) = less scalable units, hate terrain
Convex (Terran, death ball, spearhead) = more scalable units, use terrain

I compare games to the ones I have played, and the difference to explore new positions

Strategy vs mechanics
Strategy = hard counters / decision making, higher level, range
Mechanics = do basic things, lower level, sameness

Safe vs corner cutting
How big the threshold is for transitioning between good gamestates

Pre planned strategy vs on the fly
Pre planned deviates you farther (deep planning), and on the fly relies more on quick compute / cache, more middle of the road, but has more flexibility in execution.

Game sense = on the fly deduction and requires you to be fast
