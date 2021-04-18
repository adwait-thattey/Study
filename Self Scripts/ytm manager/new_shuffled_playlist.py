# %%
from ytmusicapi import YTMusic
import json

ytmusic = YTMusic('headers_auth.json')
file = "./frozen_shuffled/shuffled_400_600.json"

# %%
f = open(file)
tracks = json.loads(f.read())
f.close()

# %%

ytmusic.create_playlist(title="Liked Shuffled 401-600", description="All liked shuffled 400 - 600 by ytmusicapi",
                        privacy_status="PRIVATE", video_ids=tracks)
