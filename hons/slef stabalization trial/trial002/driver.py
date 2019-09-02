import node_thread
import central_daemon
import gen_graph
import constants

NODE_THREADS = {}
adj_list = None

def define_threads_from_graph(central_thread):
    for key in adj_list:
        thr = node_thread.RunNode(
            node_id=key,
            level=constants.TOTAL_NODES,
            central_daemon = central_thread
        )

        NODE_THREADS[key] = thr

def set_neighbours(node_thr):
    neighbour_nodes = [NODE_THREADS[nid].node for nid in adj_list[node_thr.node.id]]
    node_thr.add_neighbours(neighbour_nodes)

def print_node_and_parents():
    print("\nPrinting node and parents")
    for thr in NODE_THREADS.values():
        print("[DRIVER]:", repr(thr.node), repr(thr.node.parent))
    print("\n")


if __name__ == "__main__":
    # global adj_list

    adj_list = gen_graph.gen_graph(constants.TOTAL_NODES, constants.TOTAL_EDGES)

    gen_graph.print_graph(adj_list)

    central_thread = central_daemon.CentralDaemon()
    
    define_threads_from_graph(central_thread)

    NODE_THREADS[0].node.level = 0

    for thr in NODE_THREADS.values():
        set_neighbours(thr)


    for thr in NODE_THREADS.values():
        thr.set_random_parent()

    NODE_THREADS[0].set_parent(None)

    print_node_and_parents()

    print("Starting central thread")
    central_thread.start()



    for thr in NODE_THREADS.values():
        thr.start()

    central_thread.join()

    print_node_and_parents()

    for thr in NODE_THREADS.values():
        thr.keep_running = False

    for thr in NODE_THREADS.values():
        thr.join()