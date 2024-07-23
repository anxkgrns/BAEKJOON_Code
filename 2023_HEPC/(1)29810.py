from collections import defaultdict
import sys
sys.setrecursionlimit(999999)
visit_x = 0


def dfs(graph, visited, node, target_node):
    visited[node] = True
    count = 1

    for neighbor in graph[node]:
        if neighbor == target_node:
            global visit_x
            visit_x += 1
        if not visited[neighbor] and neighbor != target_node:
            count += dfs(graph, visited, neighbor, target_node)

    return count





def main():
    n, m = map(int, sys.stdin.readline().split())
    graph = defaultdict(list) # adj = [[] for _ in range(N + 1)]

    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)

    X = int(sys.stdin.readline())
    visited = [False] * (n + 1)

    result = 0

    for node in range(1, n + 1):
        if not visited[node] and node != X:
            global visit_x
            visit_x = 0
            A = dfs(graph, visited, node, X)
            
            if(visit_x == 1):
                A += 1
            result = max(result, A)

    print(result)

if __name__ == "__main__":
    main()

# from collections import defaultdict
# import sys

# def dfs(graph, visited, node, target_node):
#     stack = [node]
#     visited[node] = True
#     count = 1

#     while stack:
#         current_node = stack.pop()

#         for neighbor in graph[current_node]:
#             if neighbor == target_node:
#                 global visit_x
#                 visit_x += 1
#             if not visited[neighbor] and neighbor != target_node:
#                 stack.append(neighbor)
#                 visited[neighbor] = True
#                 count += 1

#     return count

# def main():
#     n, m = map(int, sys.stdin.readline().split())
#     graph = defaultdict(list)

#     for _ in range(m):
#         a, b = map(int, sys.stdin.readline().split())
#         graph[a].append(b)
#         graph[b].append(a)

#     X = int(sys.stdin.readline())
#     visited = [False] * (n + 1)

#     result = 0

#     for node in range(1, n + 1):
#         if not visited[node] and node != X:
#             global visit_x
#             visit_x = 0
#             A = dfs(graph, visited, node, X)
            
#             if visit_x == 1:
#                 A += 1
#             result = max(result, A)

#     print(result)

# if __name__ == "__main__":
#     main()
