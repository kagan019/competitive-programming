import itertools
from typing import List

class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        def sortby(k: List[int]):
            return (-k[-1], -k[-2], -k[-3])
        maxheight = [0 for _ in cuboids]
        srtd = sorted([sorted(cuboid) for cuboid in cuboids], key=sortby)
        for i,cub in enumerate(srtd):
            mh = 0
            for j in range(i):
                if all([a <= b for a,b in zip(cub,srtd[j])]):
                    mh = max(mh,maxheight[j])
            maxheight[i] = max(maxheight[i],mh + cub[-1])

        remaxheight


cuboids = [[48,9,2]]
print(Solution().maxHeight(cuboids))

