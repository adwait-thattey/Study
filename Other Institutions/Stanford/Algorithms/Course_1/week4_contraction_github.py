from random import randint
class KargerMinCutter:
    def __init__(self, graph_file):
        self._graph = {}
        self._total_edges = 0
        with open(graph_file) as file:
            for index, line in enumerate(file):
                numbers = [int(number) for number in line.split()]
                self._graph[numbers[0]] = numbers[1:]
                self._total_edges += len(numbers[1:])
	

    def find_min_cut(self):
        min_cut = 0
        while len(self._graph) > 2:
            v1, v2 = self._pick_random_edge()
            self._total_edges -= len(self._graph[v1])
            self._total_edges -= len(self._graph[v2])
            self._graph[v1].extend(self._graph[v2])
            for vertex in self._graph[v2]:
                self._graph[vertex].remove(v2)
                self._graph[vertex].append(v1)
            self._graph[v1] = list(filter(lambda v: v != v1, self._graph[v1]))
            self._total_edges += len(self._graph[v1])
            self._graph.pop(v2)
        for edges in self._graph.values():
            min_cut = len(edges)
        return min_cut

    def _pick_random_edge(self):
        rand_edge = randint(0, self._total_edges - 1)
        for vertex, vertex_edges in self._graph.items():
            if len(vertex_edges) <= rand_edge:
                rand_edge -= len(vertex_edges)
            else:
                from_vertex = vertex
                to_vertex = vertex_edges[rand_edge]
                return from_vertex, to_vertex

def start(in_file):
    K = KargerMinCutter(in_file)
    line_count = 0
    F = open(in_file)
    for l in F:
        line_count+=1
    from math import log
    # line_count = K._total_edges
    total_count = line_count*line_count*log(line_count,2)
    F.close()
    
    cur_min =  K.find_min_cut()
    while total_count > 0:
        total_count-=1
        K = KargerMinCutter(in_file)
        cur = K.find_min_cut()
        print(total_count,cur)
        if cur < cur_min:
            cur_min = cur
    # total_count = K._total_edges
    return cur_min


if __name__=="__main__":
    print(start('kargerMinCut.txt'))
