# %%
from ytmusicapi import YTMusic
ytmusic = YTMusic('headers_auth.json')
all_liked = ytmusic.get_liked_songs(limit=3000)

all_liked_tracks = all_liked.get('tracks')

# %%
import json
all_liked_json = json.dumps(all_liked_tracks)
f = open("liked_tracks.json", mode="w")
f.write(all_liked_json)
f.close()
