import random
from queue import Queue
import os

def generate_maze(m, n):
    maze = [[random.choice([0, 'x']) for j in range(n)] for i in range(m)]
    return maze

def find_path(maze):
    start = (random.randint(0, len(maze)-1), random.randint(0, len(maze[0])-1))
    q = Queue()
    q.put(start)
    visited = set()
    while not q.empty():
        curr = q.get()
        if curr[0] == 0 or curr[0] == len(maze)-1 or curr[1] == 0 or curr[1] == len(maze[0])-1:
            return curr
        if curr in visited:
            continue
        visited.add(curr)
        if maze[curr[0]][curr[1]] == 'x':
            continue
        q.put((curr[0]-1, curr[1]))
        q.put((curr[0]+1, curr[1]))
        q.put((curr[0], curr[1]-1))
        q.put((curr[0], curr[1]+1))
    return None

def solve_maze(m, n):
    while True:
        maze = generate_maze(m, n)
        start = find_path(maze)
        if start is not None:
            break
    return maze, start

def print_maze(maze):
    for row in maze:
        print(row)

def move_character(maze, start):
    pos = start
    steps_left = None
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')
        print_maze(maze)
        print(f'Steps left: {steps_left}')
        if pos[0] == 0 or pos[0] == len(maze)-1 or pos[1] == 0 or pos[1] == len(maze[0])-1:
            print('You have reached the exit!')
            break
        neighbors = []
        if pos[0]-1 >= 0 and maze[pos[0]-1][pos[1]] != 'x':
            neighbors.append((pos[0]-1, pos[1]))
        if pos[0]+1 < len(maze) and maze[pos[0]+1][pos[1]] != 'x':
            neighbors.append((pos[0]+1, pos[1]))
        if pos[1]-1 >= 0 and maze[pos[0]][pos[1]-1] != 'x':
            neighbors.append((pos[0], pos[1]-1))
        if pos[1]+1 < len(maze[0]) and maze[pos[0]][pos[1]+1] != 'x':
            neighbors.append((pos[0], pos[1]+1))
        distances = [abs(nbr_pos[0]-start[0])+abs(nbr_pos[1]-start[1]) for nbr_pos in neighbors]
        min_distance_idx = distances.index(min(distances))
        pos = neighbors[min_distance_idx]
        steps_left = len(neighbors) - 2
        input('Press any key to continue...')

maze, start = solve_maze(5, 5)
move_character(maze, start)
