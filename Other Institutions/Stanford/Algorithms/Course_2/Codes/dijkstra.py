class Graph:
    def __init__(self, graph_file):
        """
        @param graph_file : A file containing the adjacency list

        This creates a graph object with the adjacency list. The preprocessing step is also done here
        """
        self.adjacency_list = dict()
        self.properties = dict()
        F = open(graph_file)
        for line in F:
            line = line.split()
            key = int(line[0])
            line = line[1:]
            self.adjacency_list[key] = line
            self.properties[key] = [1000000, False]

            # The first param is the distance. The second tells whether this has been visited till now
        self.node_count = len(self.properties)
        F.close()

    def extract_min(self):
        min_dist = 1000000
        min_node = None
        for node in self.properties:
            if self.properties[node][1] is False and self.properties[node][0] <= min_dist:
                min_node = node
                min_dist = self.properties[node][0]
            # print(node,self.properties[node][0], self.properties[node][1], min_node)

        self.properties[min_node][1] = True
        self.node_count -= 1
        return min_node

    def relax_all_edges(self, node):
        for vertex in self.adjacency_list[node]:
            vertex = vertex.split(',')
            if int(vertex[0]) not in self.properties:
                self.properties[int(vertex[0])] = [1000000, False]
                # self.node_count += 1
            # print(self.properties[node])
            # print(vertex)
            # print(vertex[0])
            # print(vertex[1])
            if self.properties[node][0] + int(vertex[1]) < self.properties[int(vertex[0])][0]:
                self.properties[int(vertex[0])][0] = self.properties[node][0] + int(vertex[1])

    def dijkstra(self, source_node):
        self.properties[int(source_node)][0] = 0
        # print(self)
        while self.node_count > 0:
            min_node = self.extract_min()
            self.relax_all_edges(min_node)

    def __str__(self):
        ret_str = ""
        for node in self.properties:
            ret_str += str(node) + ":" + str(self.properties[node][0]) + "\n"

        return ret_str


def print_req_vertices(G):
    req_ver = [7, 37, 59, 82, 99, 115, 133, 165, 188, 197]
    ret_str = ""
    for i in req_ver:
        ret_str += str(G.properties[i][0]) + ","

    ret_str = ret_str.strip(',')
    return ret_str


def start(inp_file, source_node=1):
    G = Graph(inp_file)
    # print(G)
    G.dijkstra(source_node)
    # print("After Dijkstra")
    # print(G)
    return print_req_vertices(G)


if __name__ == "__main__":
    import sys

    print(start(sys.argv[1], 1))
