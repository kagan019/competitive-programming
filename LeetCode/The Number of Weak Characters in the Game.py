from typing import *

class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        def desc_first_asc_sec(k: int):
            return -k[0], k[1]
        descndn = sorted(properties, key=desc_first_asc_sec)
        def weaknesses_itr():
            m = 0
            for x in descndn:
                yield 1 if x[1] < m else 0
                m = max(m,x[1])
        return sum(weaknesses_itr())

properties = [[1,5],[10,4],[4,3]]
print(Solution().numberOfWeakCharacters(properties))