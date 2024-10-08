# 42-miniRT
#### A 42 School project
<br>

Goal(s):
- create a simple raytracer in C capable of rendering simple geometric objects, with the help of a basic graphics library.
<br>

Features :
- real time rendering of basic 3D shapes (planes, spheres, cylinders, cones(bonus))
- user inputs handling :
  - move, resize (diameter, height), rotate objects (3 axis)
  - move, rotate camera (3 axis)
  - save scene
  - hiding objects
- basic gui
- multiple light sources (spots)
- colored light sources and ambient lighting
- phong reflection model
<br>

Concept(s) learned :
- formulas of 3d shapes
- 3d vectors manipulation and calculations (rotation, scaling, normalizing, cross and dot products, [Rodrigues' formula](https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula), ...)
- phong model

Resources :
- https://physique.cmaisonneuve.qc.ca/svezina/nyc/note_nyc/NYC_CHAP_6_IMPRIMABLE_4.pdf

---
### Preview:
<br>

![basic-sphere](https://github.com/user-attachments/assets/52a7e301-169a-451a-a504-7bcecb9b3bfe)
![basic-sphere+light](https://github.com/user-attachments/assets/f617a2ab-15d6-419c-9861-7ec890881b7b)
![basic-cylinder](https://github.com/user-attachments/assets/fdce8ad8-8333-4101-a8a0-b5d64be1b58d)
![basic-cone](https://github.com/user-attachments/assets/d77f202d-d0ab-4c5e-a19d-81885e91b9ec)
<br>
basic shapes in the void with a spot. all white.
<br><br><br>

![two-cylinders](https://github.com/user-attachments/assets/b32687c9-34a0-4c61-926e-fd50f41c5f9c)
![pink-room](https://github.com/user-attachments/assets/045b841f-f9b4-4fb4-9846-8d4f54619cff)
![tunnel](https://github.com/user-attachments/assets/7ec01501-5e10-4b75-9be0-1c6625c9d36c)
![planets+gui](https://github.com/user-attachments/assets/f02db7ad-1ac1-48be-a665-8f2af1e5abcb)
<br>
scenes with a few more shapes, different colors. GUI visible in last shot.
<br><br><br>

![shapes-everywhere](https://github.com/user-attachments/assets/999f5976-8115-4774-bbe2-061616099087)
![shapes-everywhere+hidden-objs](https://github.com/user-attachments/assets/82bda834-3d8d-41f4-922b-692c34b819d2)
<br>
shapes everywhere, display of the GUI once again. same scene twice, with a few objs hidden in second shot. ("(H)" indicated next to hidden objs)
<br><br><br>

![shapes-everywhere-RED-amb+light](https://github.com/user-attachments/assets/89053ea9-16bc-4cb4-a787-82d4f7d9efe1)
![shapes-everywhere-GREEN-amb+light](https://github.com/user-attachments/assets/f55f7c82-4214-4346-80db-20b6694d3ec9)
![shapes-everywhere-BLUE-amb+light](https://github.com/user-attachments/assets/0637f437-853e-49ea-8167-2aeeae639576)
<br>
previous scene but this time with a spot and ambient lighting of each color channel.
<br><br><br>

![RGB](https://github.com/user-attachments/assets/36adfe82-a564-4ddb-8e03-b6c9ea2f7384)
<br>
white plane and spheres, 3 spots of each color channel.
<br><br><br>

![castle](https://github.com/user-attachments/assets/ebd46c5b-1364-490d-992f-094a04e53b4c)
![temple](https://github.com/user-attachments/assets/2eff8839-aca7-47e9-90a6-469dbf5358c4)
<br>
a couple of more complicated scenes.
<br>
