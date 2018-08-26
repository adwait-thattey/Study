#####
# Declaring Global Variables
vertex_dict = dict()
cur_leader_node = None
opened_file_lines = None
t_counter = 0 #counter for f(n) values i.e time values to vertices in 1st pass
v_counter = 0 #counter for counting no of nodes in an SCC
SCC_set = list() #Set containing number of vertices in each SCC
#
#####

def convert_to_reverse_adjacency_list(inp_file):
    F = open(inp_file)
    max_vertex = 0
    adj_file = open("adj" + str(inp_file), mode="w")
    counter = 0
    point_list = list()
    for line in F:
        line = line.split()
        if int(line[0]) > max_vertex : max_vertex = int(line[0])
        if int(line[1]) > max_vertex : max_vertex = int(line[1]) 

        if int(line[1]) > counter:
            line_tbr = str(counter) + " "
            for i in point_list:
                line_tbr+= i + " "
            adj_file.write(line_tbr + "\n")
            
            point_list = list()

            counter = int(line[1])

        point_list.append(line[0])

    line_tbr = str(counter) + " "
    for i in point_list:
        line_tbr+= i + " "
    adj_file.write(line_tbr + "\n")
            
    point_list = list()

    counter = int(line[1])    

    adj_file.write("max_is " + str(max_vertex) + "\n" )
    adj_file.close()
    F.close()


def convert_to_adjacency_list(inp_file):
    F = open(inp_file)
    max_vertex = 0
    adj_file = open("adj" + str(inp_file), mode="w")
    counter = 0
    point_list = list()
    for line in F:
        line = line.split()
        if int(line[0]) > max_vertex : max_vertex = int(line[0])
        if int(line[1]) > max_vertex : max_vertex = int(line[1]) 

        if int(line[0]) > counter:
            line_tbr = str(counter) + " "
            for i in point_list:
                line_tbr+= i + " "
            adj_file.write(line_tbr + "\n")
            
            point_list = list()

            counter = int(line[0])

        point_list.append(line[1])

    line_tbr = str(counter) + " "
    for i in point_list:
        line_tbr+= i + " "
    adj_file.write(line_tbr + "\n")
            
    point_list = list()

    counter = int(line[0])    

    adj_file.write("max_is " + str(max_vertex) + "\n" )
    adj_file.close()
    F.close()

def DFS1stpass(node_i):
    # print(node_i, end="-")
    global vertex_dict, t_counter
    # print(opened_file_lines)
    vertex_dict[node_i][0] = True # mark i explored
    index = 0
    # print(opened_file_lines)
    # print(index)
    while index < len(opened_file_lines) and opened_file_lines[index].split()[0] != str(node_i): 
        # print(index)
        index+=1

    if index < len(opened_file_lines):
        for v2 in opened_file_lines[index].split()[1:]:
            if vertex_dict[int(v2)][0] is False:
                DFS1stpass(int(v2))

    t_counter+=1
    vertex_dict[node_i][2] = t_counter
    # print()            

def pass1():
    for line in opened_file_lines: 
        line = line.split()
        if vertex_dict[int(line[0])][0] is False:
            # print(line[0])
            DFS1stpass(int(line[0]))

def DFS2ndPass(node_i):
    # print(node_i, end="-")
    global vertex_dict, v_counter
    # print(opened_file_lines)
    vertex_dict[node_i][1] = True # mark i explored
    vertex_dict[node_i][3] = cur_leader_node
    index = 0

    while index < len(opened_file_lines) and opened_file_lines[index].split()[0] != str(node_i): 
        # print(index)
        index+=1

    if index < len(opened_file_lines):
        for v2 in opened_file_lines[index].split()[1:]:
            if vertex_dict[int(v2)][1] is False:
                DFS2ndPass(int(v2))

    v_counter+=1
    # vertex_dict[node_i][2] = t_counter
    # print()  

def pass2():
    list_of_vertex_sorted = sorted(list(vertex_dict.keys()), key=lambda x:vertex_dict[x][2], reverse=True)
    # print(list_of_vertex_sorted)
    global v_counter, SCC_set

    # SCC_set = list()
    for vertex in list_of_vertex_sorted: 
        
        if vertex_dict[vertex][1] is False:
            # print(line[0])
            v_counter = 0
            DFS2ndPass(vertex)
            SCC_set.append(v_counter)



def print_dict(D) :
    for key,value in D.items() : 
        print(key, value)

if __name__=="__main__":
    import sys
    sys.setrecursionlimit(5000)
    import subprocess
    if len(sys.argv) > 2 and sys.argv[2] == 'adj' :
        adj_file = sys.argv[1]
        adj_file_rev = sys.argv[1] + "rev"

    else:
        convert_to_adjacency_list(sys.argv[1])
        
        try:
            F = open("rev" + sys.argv[1])
            F.close()
        except FileNotFoundError:
            F_original = open(sys.argv[1])
            lines = F_original.readlines()
            lines.sort(key=lambda x:x.split()[1])
            F_original.close()

            Frev = open("rev" + sys.argv[1], mode="w",encoding="utf-8")
            for line in lines:
                x = Frev.write(line)
            Frev.close()    

        convert_to_reverse_adjacency_list("rev" + sys.argv[1])
        adj_file = "adj" + str(sys.argv[1])
        adj_file_rev = "adjrev" + str(sys.argv[1])

        
    #Get Max vertex
    F = open(adj_file_rev)
    
    opened_file_lines = F.readlines()[1:]
    F.close()
    #Skipped first line as it contains 0
    # assign_global_opend_file_lines
    # proc = subprocess.Popen(['tail', '-n', '1', str(adj_file)], stdout=subprocess.PIPE)
    last_line = opened_file_lines[-1]
    max_number = int(last_line.split()[1])
    opened_file_lines.pop()
    # print(opened_file_lines)
    for i in range(1, max_number+1):
        vertex_dict[i] = [False,False,0, None]
        #First represents whether vartex has been passed in 1st pass. 
        #2nd represents whether vertex is passed in 2nd pass
        # 3rd int represents time taken i.e. f(n)
        # 4th int represents leader of i
    # print_dict(vertex_dict)
    pass1()
    # print_dict(vertex_dict)
    
    F = open(adj_file)
    opened_file_lines = F.readlines()[1:]
    opened_file_lines.pop()
    F.close()

    pass2()
    SCC_set.sort(reverse=True)
    
    if len(SCC_set) < 5:
        print(SCC_set[0],end="")
        for i in SCC_set[1:]:
            print("," + str(i),end="")
        rem = 5 - len(SCC_set)
        for i in range(rem):
            print("," + str(0),end="")    

    else:
        print(SCC_set[0],end="")
        for i in SCC_set[1:5]:
            print("," + str(i),end="")
    # print(SCC_set)