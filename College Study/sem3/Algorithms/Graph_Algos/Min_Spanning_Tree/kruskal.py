from Graph import Graph

union_array = dict()


def get_rep(vertex):
    if union_array[vertex] == vertex:
        return vertex
    else:
        return get_rep(union_array[vertex])    

def check_cycle(v1, v2):
    global union_array

    rep_v1 = get_rep(v1)
    rep_v2 = get_rep(v2)

    if rep_v1 == rep_v2:
        return True

    union_array[rep_v2] = rep_v1
    return False

def get_min_span(G):
    if not isinstance(G, Graph):
        raise ValueError("Incoming Arg must be an instance of Graph Object")

    global union_array    
    
    for v in sorted(list(G.adj_list.keys())):
        union_array[v] = v

    edges = list()
    for v in G.adj_list:
        for e in G.adj_list[v]:
            edges.append((v, e[0], e[1]))

    edges.sort(key = lambda x: x[2])

    min_span_tree = Graph()
    for e in edges:
        if not check_cycle(e[0], e[1]):
            min_span_tree.add_edge(e[0], e[1], e[2])


    return min_span_tree            



