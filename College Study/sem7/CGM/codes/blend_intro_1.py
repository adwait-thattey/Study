import bpy

for obj in bpy.data.objects:
    print(obj.name)
    
print(bpy.data.scenes.keys())

obj = bpy.data.meshes['Cube']

for v in obj.vertices:
    v.co = .5*v.co




