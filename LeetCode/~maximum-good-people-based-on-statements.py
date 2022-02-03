# a: b
# a -> b
# !b -> !a

# a: !b
# a -> !b
# b -> !a

# a: b
# b: c
# c: !a
# a -> b -> c -> !a
# !a  works

# a -> b
# b -> c
# |- a -> c
# d -> !c
# |- a -> !d

# a -> !b
# b -> ?
# |- nothing (about a)

# a -> b
# b -> !c
# |- a -> !c
# d -> c
# |- a -> !d





from typing import List

def transitive_closure(adj: List[List[int]]):
    # adj[i] = list of people i thinks is good
    closed = [set() for _ in adj]
    for key,goods in enumerate(adj):
        frontier = [key]
        while len(frontier) > 0:
            gd = frontier.pop()
            closed[key].add(gd)
            frontier += [x for x in adj[gd] if x not in closed[key]]
    for i,s in enumerate(closed):
        s.discard(i) #not hold itself
    return closed

print(transitive_closure([[1,2],[0],[],[1]]))


# transitively look for everyone whos good based on key
# look at everyone who those people say is bad (1st order, nontransitive)
# these are all people key implies is bad
# if any of them are in the good group, we have a contradiction, key is bad

# look for the fewest colors of the u-thinks-v-is-bad nonditectional graph and count the max color