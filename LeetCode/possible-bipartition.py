from typing import List
import itertools

class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        g = [[] for _ in range(n+1)]
        for ai,bi in dislikes:
            g[ai] += [bi]
            g[bi] += [ai]
        colors = [-1 for _ in range(n+1)] # ignore 0
        def color_nbrs(person: int):
            assert(g[person] != -1)
            for nbr in g[person]:
                if colors[nbr] == colors[person]:
                    return False
                else:
                    colors[nbr] = 1-colors[person]
            return True
        def color_all():
            frontier = [x for x in range(1,n+1)]
            visited = set()
            while len(frontier) > 0:
                vst = frontier.pop()
                if vst in visited:
                    continue
                if colors[vst] == -1:
                    colors[vst] = 0
                visited.add(vst)
                yield color_nbrs(vst)
                for nbr in g[vst]:
                    if nbr not in visited:
                        frontier += [nbr]
        for b in color_all():
            if b == False: return False
        return True
