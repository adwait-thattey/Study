from ytmusicapi import YTMusic
import json

f = open("shuffled_liked.json", mode="r")
track_ids = f.read()
f.close()

tracks = json.loads(track_ids)
print("Taking first 200")

tracks_tbc = tracks[:200]

ytmusic = YTMusic('headers_auth.json')

ytmusic.create_playlist(title="Liked Shuffled 1-200", description="YT Liked Shuffled 1-200", privacy_status='PRIVATE', video_ids=list(tracks_tbc))
