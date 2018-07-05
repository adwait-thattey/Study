class Graph :
    def __init__(self,vertices) :
        self.no_of_vertices = vertices
        self.adj_list  = [[]]*vertices
        print(self.adj_list)
        for i in range(vertices) :
            self.adj_list[i] = list()
    
    def add_edge(self , v1 , v2) :
        self.adj_list[v1].append(v2)
        self.adj_list[v2].append(v1)

    def print_graph(self) :
        for i in range(len(self.adj_list)) :
            print(i , end=" : ")
            for j in self.adj_list[i] :
                print(j , end=" ")
            print()

    def BFS(self , node) :
        visited = list() 
        for i in range(self.no_of_vertices) :
            visited.append(False)

        visited[node] = True
        queue = []
        queue.append(node)

        while(queue) :
            cur_node = queue.pop(0)
            print(cur_node, end=" ")

            for j in self.adj_list[cur_node] : 
                if not visited[j] :
                    queue.append(j)
                    visited[j] = True

    
    def DFSUtil(self,node,visited) :
        print(node , end=" ")
        visited[node] = True

        for i in self.adj_list[node] :
            if not visited[i] :
                self.DFSUtil(i,visited)
    
    def DFS(self,node) :
        visited = [False]*len(self.adj_list)
        self.DFSUtil(node,visited)                


if __name__=="__main__" :
    G = Graph(5)
    G.add_edge(1,2)
    G.add_edge(3,4)
    G.add_edge(2,3)
    G.add_edge(1,4)
    G.add_edge(2,4)
    G.print_graph()

    G.BFS(4)
    print()
    G.DFS(4)