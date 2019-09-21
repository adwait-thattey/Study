import shared
import utils
import graph
import search
print("Hello World")

if __name__ == "__main__":
    utils.build_graph()
    graph.print_graph(shared.GRAPH_NODES)
    source = "chennai"
    dest = "dispur"

    source_node = shared.GRAPH_NODES[source]
    goal_test = lambda node: node.name == dest

    action_sequence = search.graph_search(shared.GRAPH_NODES, source_node, goal_test, "bfs")


    utils.print_action_sequence(action_sequence)
