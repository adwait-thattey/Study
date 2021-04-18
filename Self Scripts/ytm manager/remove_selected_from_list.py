import json

FULL_FILE = "frozen_shuffled/full_complete_ids__2021-04-14.json"
SELECTED_FILES = ["frozen_shuffled/shuffled_1_200.json", "frozen_shuffled/shuffled_200_400.json"]
CUR_DATE = "2021-04-14"

def remove_selected(full_file, selected_files):
    f = open(full_file, mode="r")
    all_track_ids = set(json.loads(f.read()))
    f.close()

    for i in selected_files:
        f = open(i, mode="r")
        selected_track_ids = list(json.loads(f.read()))
        f.close()
        all_track_ids.difference_update(selected_track_ids)
    
    f = open("frozen_shuffled/filtered_till_" + CUR_DATE + ".json", mode="w" )
    f.write(json.dumps(list(all_track_ids)))
    f.close()


if __name__ == "__main__":
    remove_selected(FULL_FILE, SELECTED_FILES)
