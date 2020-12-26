import json
import random
import copy

def print_shuffle_chars(original, shuffled):
    o_pos_dict = {original[k]:k for k in range(len(original))}
    s_pos_dict = {shuffled[k]:k for k in range(len(shuffled))}

    elem_displacement = {i:abs(o_pos_dict[i]-s_pos_dict[i]) for i in original}

    key_list = original.copy()
    neighbour_deviation = {original[k]: abs(s_pos_dict[original[k-1]] - s_pos_dict[original[k]]) + abs(s_pos_dict[original[k+1]] - s_pos_dict[original[k]]) - 2 for k in range(1, len(key_list)-1) }
    
    # print every 200 avgs
    print("Deviation averages")

    ct=0
    avg=0
    for k in key_list:
        avg+=elem_displacement[k]
        ct+=1
        if ct >=200:
            ct=0
            avg/=200
            avg = f"{int(avg*100/len(original))}%"
            print(avg, end=" ")

            avg=0

    print("\n total Deviation average ", (sum(elem_displacement.values())/len(original))*100/len(original))

    print("\n\nNeighbour averages")

    ct=0
    avg=0
    for k in key_list[1:-2]:
        avg+=neighbour_deviation[k]
        ct+=1
        if ct >=200:
            ct=0
            avg/=200
            avg/=2
            avg = f"{int(avg*100/len(original))}%"
            print(avg, end=" ")

            avg=0
    print("\n total neighbour average ", (sum(neighbour_deviation.values())/(len(original)-2))*100/(2*len(original)))



f = open("liked_tracks.json", mode="r")
j = f.read()
f.close()

original_liked_tracks = json.loads(j)
original_liked_tracks = [o["videoId"] for o in original_liked_tracks]


shuffled_lists = list()
for i in range(10):
    print(f"Shuffled List {i}\n")
    sl = copy.deepcopy(original_liked_tracks)
    random.shuffle(sl)
    print_shuffle_chars(original_liked_tracks, sl)

    shuffled_lists.append(sl)

    print('\n')
    
chosen = int(input("Which list do you want"))

chosen_list = shuffled_lists[chosen]

chosen_json = json.dumps(chosen_list)

f = open("frozen_shuffled/chosen.json", mode="w")
f.write(chosen_json)
f.close()
