import node_thread
import central_daemon
import gen_graph
import constants
import random
import graph

NODE_THREADS = {}
adj_list = None

def define_threads_from_graph(central_thread):
    for key in adj_list:
        thr = node_thread.RunNode(
            node_id=key,
            level= random.randint(1,constants.TOTAL_NODES),
            central_daemon = central_thread
        )

        NODE_THREADS[key] = thr

def set_neighbours(node_thr):
    neighbour_nodes = [NODE_THREADS[nid].node for nid in adj_list[node_thr.node.id]]
    node_thr.add_neighbours(neighbour_nodes)

def print_node_and_parents_levels():
    print("\nPrinting node and parents")
    for thr in NODE_THREADS.values():
        print("[DRIVER]:", repr(thr.node), repr(thr.node.parent), thr.node.level)
    print("\n")

def compile_messages(central_thread):
    message_count = [0]*central_thread.current_round
    # for thr in NODE_THREADS.values():
    #     if thr.node.message_list[0] <= 1:
    #         thr.node.message_list.pop(0)
    #     else:
    #         thr.node.message_list[0] -= 1
    #         thr.node.message_list[1] += thr.node.message_list[0]
    #         thr.node.message_list.pop(0)

    # for turn in central_thread.node_privilege_tracker:
    #     if turn:
    #         message_count.append(1)
    #         message_count[-1] += NODE_THREADS[turn].node.message_list.pop(0)
    #     else:
    #         message_count.append(0)

    for thr in NODE_THREADS.values():
        for key in thr.node.message_dict:
            message_count[key] += thr.node.message_dict[key]

    for key in central_thread.message_dict:
            message_count[key] += central_thread.message_dict[key] 

    return message_count    

if __name__ == "__main__":
    # global adj_list

    adj_list = gen_graph.gen_graph(constants.TOTAL_NODES, constants.TOTAL_EDGES)
    # adj_list = graph.al
    # adj_list = gen_graph.gen_full_connected_graph(constants.TOTAL_NODES)
    gen_graph.print_graph(adj_list)

    central_thread = central_daemon.CentralDaemon()
    
    define_threads_from_graph(central_thread)

    NODE_THREADS[0].node.level = 0

    for thr in NODE_THREADS.values():
        set_neighbours(thr)


    for thr in NODE_THREADS.values():
        thr.set_random_parent()

    NODE_THREADS[0].set_parent(None)

    print_node_and_parents_levels()

    print("Starting central thread")
    central_thread.start()



    for thr in NODE_THREADS.values():
        thr.start()

    central_thread.join()

    print_node_and_parents_levels()

    for thr in NODE_THREADS.values():
        thr.keep_running = False

    for thr in NODE_THREADS.values():
        thr.join()

    # for thr in NODE_THREADS.values():
    #     print(thr.node.message_list)

    print(compile_messages(central_thread))    