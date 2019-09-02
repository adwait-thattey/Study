import random

adjacency_list = dict()

taken_edges = dict()

connected_nodes = list()

def print_graph(adj_list):
    for node in adj_list:
        print(f"{node}: {adjacency_list[node]}")

def make_edge(a,b):
    global taken_edges
    adjacency_list[a].append(b)
    adjacency_list[b].append(a)
    taken_edges[(a,b)] = True

def gen_graph(nodes, edges):
    global adjacency_list
    global taken_edges
    global connected_nodes

    if edges < nodes:
        print("edges can't be less than  nodes")
        return

    adjacency_list = {i:list() for i in range(nodes)}    

    # make connected graph first
    connected_nodes.append(0)
    for i in range(1,nodes):
        # print(connected_nodes)
        node2 = random.choice(connected_nodes)
        while ( (i,node2) in taken_edges ) or ( (node2,i) in taken_edges ):
            node2 = random.choice(connected_nodes)
        # print(f"chose {node2}")
        make_edge(i, node2)
        connected_nodes.append(i)

    edges -= nodes - 1

    while edges > 0:
        node1 = random.randint(0,nodes - 1)
        node2 = random.randint(0,nodes - 1)
        
        while node1 == node2:
            node2 = random.randint(0,nodes - 1)

        if ( (node1,node2) not in taken_edges ) and ( (node2,node1) not in taken_edges ):
            # print(f"chose {node1} {node2}")
            make_edge(node1,node2)
            edges-=1    

    

    return adjacency_list

if __name__=="__main__":
    gen_graph(5,6)
    print("\n\n")