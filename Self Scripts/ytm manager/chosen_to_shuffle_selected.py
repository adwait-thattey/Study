from ytmusicapi import YTMusic
import json

CHOSEN_SHUFFLED_FILE = "frozen_shuffled/chosen.json"
OUT_FILE = "frozen_shuffled/shuffled_400_600.json"
OUT_LENGTH = 200

f = open(CHOSEN_SHUFFLED_FILE, mode="r")
all_track_ids = list(json.loads(f.read()))
f.close()

out_track_ids = all_track_ids[:OUT_LENGTH]

f = open(OUT_FILE, mode="w")
f.write(json.dumps(out_track_ids))
f.close()

# f = open("shuffled_liked.json", mode="r")
# track_ids = f.read()
# f.close()

# tracks = json.loads(track_ids)
# print("Taking first 200")

# tracks_tbc = tracks[:200]

# ytmusic = YTMusic('headers_auth.json')

# ytmusic.create_playlist(title="Liked Shuffled 1-200", description="YT Liked Shuffled 1-200", privacy_status='PRIVATE', video_ids=list(tracks_tbc))
