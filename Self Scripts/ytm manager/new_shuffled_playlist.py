# %%
from ytmusicapi import YTMusic
import json

ytmusic = YTMusic('headers_auth.json')
file = "./frozen_shuffled/shuffled_200_400.json"

# %%
f = open(file)
tracks = json.loads(f.read())
f.close()

# %%

ytmusic.create_playlist(title="Liked Shuffled 201-400", description="All liked shuffled 1 - 200 by ytmusicapi",
                        privacy_status="PRIVATE", video_ids=tracks)
