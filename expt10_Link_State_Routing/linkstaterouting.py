def link_state_routing(n, d):
    for s in range(n):
        I, D, P = [0]*n, [float('inf')]*n, [[] for _ in range(n)]
        D[s] = 0
        for _ in range(n):
            i, D[i] = min(((i, D[i]) for i in range(n) if not I[i]), key=lambda x: x[1])
            I[i] = 1
            for k in range(n):
                if d[i][k] and not I[k] and D[k] > D[i] + d[i][k]:
                    D[k] = D[i] + d[i][k]
                    P[k] = P[i] + [i+1]
        for i in range(n):
            if i != s:
                path_via = " via " + " to ".join(map(str, P[i] + [i+1])) if P[i] else ""
                print(f"SHORTEST PATH IS : ({s+1},{i+1}){path_via}--{D[i]}")

nodes = int(input("ENTER THE NUMBER OF HOSTS IN THE GRAPH\n"))
distance_matrix = [[int(input(f"ENTER THE DISTANCE BETWEEN ({i+1},{j+1}): ")) if i != j else 0 for j in range(nodes)] for i in range(nodes)]
link_state_routing(nodes, distance_matrix)
