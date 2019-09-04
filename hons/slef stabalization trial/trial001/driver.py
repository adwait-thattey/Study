import node_thread
import central_daemon

if __name__ == "__main__":
    central_thread = central_daemon.CentralDaemon()
    th1 = node_thread.RunNode("1",34001,0,[
        ("2",34002,2)
    ])

    th1.node.parent = None # root node parent must be none

    th2 = node_thread.RunNode("2", 34002, 2, [
        ("1", 34001, 0)
    ])

    print("Starting central thread")
    central_thread.start()
    th1.start()
    th2.start()

    central_thread.join()
    th1.join()
    th2.join()