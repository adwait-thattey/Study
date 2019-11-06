"""
Trying Solution:
See it as a graph, 4 choices at each step, move left, right, top, bottom
Apply heuristics to prune in direction of goal
Search via bfs 
"""

INF = 999999

def apply_heuristics(position_choices, goal):

    def hf(pos):
        xdist = pos[0] - goal[0]
        ydist = pos[1] - goal[1]

        return xdist**2 + ydist**2

    position_choices.sort(key=hf, reverse=True)

    return position_choices

def find_best_path(mat, cur_pos, goal,cur_steps, min_steps, explored, last=-1):
    # if last is 0, last move was row changed, if last is 1, last was in column changed
    # print("at", cur_pos)
    explored.add(cur_pos)
    if (cur_pos[0] < 0) or (cur_pos[0] >= len(mat[0])) or (cur_pos[1] < 0) or (cur_pos[1] >= len(mat)):
        # crossed end of matrix
        # print("out of bounds")
        return INF

    if mat[cur_pos[0]][cur_pos[1]] == "X":
        # reached blocked node
        # print("blocked")
        return INF
    
    
    if (cur_steps >= min_steps):
        # cant get any better than that
        # print("cat get better")
        return cur_steps

    
    if (cur_pos[0] == goal[0] and cur_pos[1] == goal[1]):
        # reached goal
        # print("reached")
        return cur_steps

    # we have 4 choces. Go to (X-1,Y), (X+1,Y), (X,Y-1), (X,Y+1)
    # Put all 4 choices in a queue
    choices_queue = [(cur_pos[0]-1,cur_pos[1]), (cur_pos[0]+1, cur_pos[1]), (cur_pos[0], cur_pos[1]-1), (cur_pos[0], cur_pos[1]+1)]
    
    choices_queue = [x for x in choices_queue if x not in explored]
    # reorgani`ze choices based on heuristics. Most feasible choice should be at end
    choices_queue = apply_heuristics(choices_queue, goal)

    # print("choices",choices_queue)
    # Now try each choice

    while choices_queue:
        choice = choices_queue.pop()

        dir=1
        if choice[0] - cur_pos[0] !=0:
            #changing rows
            dir=0
        
        steps = find_best_path(mat,choice,goal,cur_steps+ int(dir!=last), min_steps, explored, dir)
        min_steps = min(min_steps,steps)

        # print("min", min_steps)
    return min_steps
if __name__ == "__main__":
    N = int(input())
    mat = list()
    for _ in range(N):
        l = input()
        mat.append(l)
    
    startX,startY,endX,endY = [int(i) for i in input().split()]
    start = (startX, startY)
    goal = (endX,endY)

    if(mat[goal[0]][goal[1]] == "X"):
        print("Goal blocked")
        
    else:
        # print(start, goal)
        explored = set()
        min_steps = find_best_path(mat,start,goal,0,INF, explored)
        print(min_steps)

    