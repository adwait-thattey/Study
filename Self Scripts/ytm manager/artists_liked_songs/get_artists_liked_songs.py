from ytmusicapi import YTMusic
import json

ytmusic = YTMusic('../headers_auth.json')
any_artist_song_id = '9VcDnWMOBtw'

song_details = ytmusic.get_song(any_artist_song_id)

print(song_details)
