#%%

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

#%%

def normalize(vector):
    return vector / np.linalg.norm(vector)

class PlaneEquation:
    def __init__(self, a=None,b=None,c=None,d=None):
        self.a = a
        self.b = b
        self.c = c
        self.d = d

class Face:
    def __init__(self, v1, v2, v3, v4):
        # A face of 4 vertices
        self.vertices = np.array([v1,v2,v3,v4])
        self.normal = None
        self.equation = PlaneEquation()


    def check_coplaner(self):
        c1 = np.cross(self.vertices[0] - self.vertices[1], self.vertices[1] - self.vertices[2])
        c2 = np.cross(self.vertices[1] - self.vertices[2], self.vertices[2] - self.vertices[3])
        c3 = np.cross(self.vertices[2] - self.vertices[3], self.vertices[3] - self.vertices[0])
        c4 = np.cross(self.vertices[3] - self.vertices[0], self.vertices[1] - self.vertices[2])

        cc1 = np.cross(c1,c2)
        cc2 = np.cross(c1,c3)
        cc3 = np.cross(c1,c4)

        if np.linalg.norm(cc1)!=0 :
            raise ValueError(f"Face points not coplanar, vertices = {self.vertices}. Failed for c1, c2. c1={c1} c2={c2}  ")

        if np.linalg.norm(cc2)!=0 :
            raise ValueError(f"Face points not coplanar, vertices = {self.vertices}. Failed for c1, c3. c1={c1} c3={c3}  ")

        if np.linalg.norm(cc3)!=0 :
            raise ValueError(f"Face points not coplanar, vertices = {self.vertices}. Failed for c1, c4. c1={c1} c4={c4}  ")

    def build_normal(self):
        cross = np.cross(self.vertices[1] - self.vertices[0], self.vertices[2] - self.vertices[0])
        self.normal = normalize(cross)

        D = -1*np.dot(self.normal, self.vertices[0])
        self.equation.d  = D

    # def build_equation(self):
    #     vec1 = self.vertices[2] - self.vertices[0]
    #     vec2 = self.vertices[1] - self.vertices[0]
    #
    #     cp = np.cross(vec1, vec2)
    #
    #     a,b,c = cp
    #     d = -1* np.dot(cp,self.vertices[2])
    #
    #     self.equation = np.array([a,b,c,d])

    def process(self):
        self.check_coplaner()
        self.build_normal()
        # self.build_equation()

class SceneObject:
    def __init__(self, name=""):
        self.name = name
        self.vertices = list()
        self.faces = list()

        self.is_finished = False

        self.color_params = {}

    def add_vertex(self, x, y, z):
        self.vertices.append(np.array([x,y,z]))

    def add_face(self, v1,v2,v3,v4):
        # v1,v2,v3,v4 are the index of vertices. Not actual vector
        face = Face(self.vertices[v1], self.vertices[v2], self.vertices[v3], self.vertices[v4])
        face.process()
        self.faces.append(face)


class CameraScreenImage:
    def __init__(self,camera, center, height, width):
        self.camera = camera
        self.center = center
        self.height = height
        self.width = width

        self.screen_vertices = [
            np.array([self.center[0] - self.width//2, self.center[1] - self.height//2, self.center[2]]),
            np.array([self.center[0] - self.width//2, self.center[1] + self.height//2, self.center[2]]),
            np.array([self.center[0] + self.width//2, self.center[1] + self.height//2, self.center[2]]),
            np.array([self.center[0] + self.width//2, self.center[1] - self.height//2, self.center[2]]),
        ]

        self.image = np.zeros((self.height, self.width, 3))


    # def print_image_values(self):
    #     for i in self.image:
    #         for j in self.image[i]:
    #             print(i,j,self.image[i][j])

#%%



# print(image)

#%%

def get_all_faces(objects):
    faces = []
    for o in objects:
        faces.extend(o.faces)

    return faces

def get_intersection_t_if_ray_intersects_face(origin, ray_direction, face:Face):
    fnorm_R_dot = np.dot(ray_direction, face.normal)
    # if dot is 0, plane and ray parallel
    # print("fnorm_dir_dot", fnorm_R_dot)
    if fnorm_R_dot == 0:
        return False,None

    numerator = np.dot(face.normal, origin) + face.equation.d
    # print("numerator", numerator)
    t = numerator / -1*fnorm_R_dot

    return True, t

def right_left_test_for_face(face:Face, point):
    c = np.cross(face.vertices[1] - face.vertices[0], point - face.vertices[0])
    d1 = c[2] > 0

    c = np.cross(face.vertices[2] - face.vertices[1], point - face.vertices[1])
    d2 = c[2] > 0

    c = np.cross(face.vertices[3] - face.vertices[2], point - face.vertices[2])
    d3 = c[2] > 0

    c = np.cross(face.vertices[0] - face.vertices[3], point - face.vertices[3])
    d4 = c[2] > 0

    if d1 == d2 == d3 == d4 :
        return True

    return False

BREAK_POINTS = []
def build_for_each_screen_pixel(camscreen:CameraScreenImage, all_faces):
    for i, y in enumerate(np.linspace(camscreen.screen_vertices[0][1],camscreen.screen_vertices[1][1],camscreen.height)):
        for j, x in enumerate(np.linspace(camscreen.screen_vertices[1][0], camscreen.screen_vertices[2][0], camscreen.width)):
            if (i, j) in BREAK_POINTS:
                pass
            ray_dir = normalize(np.array([x,y,camscreen.center[2]]) - camscreen.camera)
            for face in all_faces:
                Texists,T = get_intersection_t_if_ray_intersects_face(camscreen.camera, ray_dir, face)
                if Texists == True:
                    if T > 0:
                        point = camscreen.camera + T*ray_dir
                        if right_left_test_for_face(face, point):
                            camscreen.image[i,j] = np.clip(np.array([255,255,255]),0,1)

#%%


def driver():
    cam_screen = CameraScreenImage(
        camera = np.array([0,0,-10]),
        center = np.array([0,0,0]),
        height = 20,
        width  = 20
    )

    obj1 = SceneObject("cube1")
    obj1.add_vertex(0,0,5)
    obj1.add_vertex(0,5,5)
    obj1.add_vertex(5,5,5)
    obj1.add_vertex(5,0,5)

    # obj1.add_vertex(0,0,10)
    # obj1.add_vertex(0,5,10)
    # obj1.add_vertex(5,5,10)
    # obj1.add_vertex(5,0,10)

    obj1.add_vertex(1,1,10)
    obj1.add_vertex(1,6,10)
    obj1.add_vertex(6,6,10)
    obj1.add_vertex(6,1,10)


    obj1.add_face(0,1,2,3)
    obj1.add_face(0,1,5,4)
    obj1.add_face(4,5,6,7)
    obj1.add_face(3,2,6,7)
    obj1.add_face(0,4,7,3)
    obj1.add_face(1,5,6,2)


    print("normal", obj1.faces[0].normal)
    print("face 0 D", obj1.faces[0].equation.d)

    # compute ray 1
    # chk = right_left_test_for_face(obj1.faces[0], np.array([0,-1,4.9]))
    # print("right, left test:", chk)

    all_faces = get_all_faces([obj1])
    build_for_each_screen_pixel(cam_screen,all_faces)
    # print(cam_screen.image)

    plt.imsave('image.png', cam_screen.image)
    plt.imshow(cam_screen.image)
    return cam_screen
#%%
BREAK_POINTS.append((19,9))
cs = driver()
#%%
# print(cs.image[19])
#%%

# test plot
def test_plot_3d():
    x, y, z = np.indices((20, 20, 20))

    # draw cuboids in the top left and bottom right corners, and a link between them
    # cube1 = (x < 3) & (y < 3) & (z < 3)
    shape1 = (x >= 10) & (x < 15) & (y >= 10) & (y <= 15) & (z >= 10) & (z < 15)
    # link = abs(x - y) + abs(y - z) + abs(z - x) <= 2

    # combine the objects into a single boolean array
    voxels = shape1 #cube1 | cube2 | link

    # set the colors of each object
    colors = np.empty(voxels.shape, dtype=object)
    # colors[link] = 'red'
    # colors[cube1] = 'blue'
    colors[shape1] = 'green'

    # and plot everything
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    ax.voxels(voxels, facecolors=colors, edgecolor='k')

    plt.show()

