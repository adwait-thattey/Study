import json

LIKED_TRACKS_JSON = "./liked_tracks_2021_04_14.json"
CUR_DATE = "2021-04-14"

def get_tracks_ids(file_path):
    f = open(file_path, mode="r")
    content = f.read()
    f.close()

    tracks_info = json.loads(content)
    track_ids = [i["videoId"] for i in tracks_info]

    f = open("./frozen_shuffled/full_complete_ids__" + CUR_DATE +  ".json", mode="w")
    f.write(json.dumps(track_ids))
    f.close()


if __name__ == "__main__":
    get_tracks_ids(LIKED_TRACKS_JSON)