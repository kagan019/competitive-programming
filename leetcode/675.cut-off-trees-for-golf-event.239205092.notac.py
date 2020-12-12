class Solution:
    def to_target(self, forest, from_coords, target_value): 
        def canMoveUp(cp, been):
            return \
            cp[1] > 0 and \
            forest[cp[1] - 1][cp[0]] != 0 and \
            (cp[0], cp[1] - 1) not in been
        def canMoveDown(cp, been):
            return \
            cp[1] < len(forest) - 1 and \
            forest[cp[1] + 1][cp[0]] != 0 and \
            (cp[0], cp[1] + 1) not in been
        def canMoveLeft(cp, been):
            return \
            cp[0] > 0 and \
            forest[cp[1]][cp[0] - 1] != 0 and \
            (cp[0] - 1, cp[1]) not in been
        def canMoveRight(cp, been):
            return \
            cp[0] < len(forest[cp[1]]) - 1 and \
            forest[cp[1]][cp[0] + 1] != 0 and \
            (cp[0] + 1, cp[1]) not in been
        
        def move(cp, tc, been):
            if cp == tc:
                return 0
            
            canMove = False
            moves = [] # up, down, left, right
            if canMoveUp(cp, been):
                new_pos = (cp[0], cp[1] - 1)
                attempt = move(new_pos, tc, been | frozenset([new_pos]))
                if attempt >= 0:
                    canMove = True
                    moves += [1 + attempt]
            if canMoveDown(cp, been):
                new_pos = (cp[0], cp[1] + 1)
                attempt = move(new_pos, tc, been | frozenset([new_pos]))
                if attempt >= 0:
                    canMove = True
                    moves += [1 + attempt]
            if canMoveLeft(cp, been):
                new_pos = (cp[0] - 1, cp[1])
                attempt = move(new_pos, tc, been | frozenset([new_pos]))
                if attempt >= 0:
                    canMove = True
                    moves += [1 + attempt]
            if canMoveRight(cp, been):
                new_pos = (cp[0] + 1, cp[1])
                attempt = move(new_pos, tc, been | frozenset([new_pos]))
                if attempt >= 0:
                    canMove = True
                    moves += [1 + attempt]
            
            if not moves:
                return -1
            return min(moves)
        
        cur_pos = (from_coords[0], from_coords[1])
        to_coords = (-1, -1)
        for y, row in enumerate(forest):
            for x, tree in enumerate(row):
                if tree == target_value:
                    to_coords = (x, y)       
        if to_coords[0] < 0 or to_coords[1] < 0:
            return -1 
        
        steps = move(cur_pos, to_coords, frozenset())
        return steps, to_coords
                
        
    def cutOffTree(self, forest: List[List[int]]) -> int:
        tree_heights = []
        for row in forest:
            for height in row:
                if height > 1:
                    tree_heights += [height]
        tree_heights = sorted(tree_heights)
        if tree_heights[0] == forest[0][0]:
            # Can chop right away
            tree_heights = tree_heights[1:]
        
        total_steps = 0
        starting_coords = (0, 0)
        for height in tree_heights:
            steps, starting_coords = self.to_target(forest, starting_coords, height)
            if steps < 0:
                return -1
            total_steps += steps
            
        return total_steps
        
