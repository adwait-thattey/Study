import shared
import utils
import graph
import search
print("Hello World")

if __name__ == "__main__":
    utils.build_graph()
    graph.print_graph(shared.GRAPH_NODES)

    utils.build_heuristics('bangalore')
    utils.print_heuristics()

    source = "jaipur"
    dest = "bangalore"

    if source not in shared.GRAPH_NODES:
        print("Source not found")
        exit()

    source_node = shared.GRAPH_NODES[source]
    goal_test = lambda node: node.name == dest

    action_sequence = search.graph_search(shared.GRAPH_NODES, source_node, goal_test, "astar")
    if not action_sequence:
        print("No path found")
    else:
        utils.print_action_sequence(action_sequence)
