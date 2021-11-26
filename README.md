  What is it?
  -----------
  
  This project is an introduction to the beautiful world of Raytracing.
  The goal of this project is to be able to render simple Computer-Generated-Images.
  
  Description 
  -----------
  
  > Project is using external graphics library mniLibX. 
  
  
  * The management of your window must remain smooth: changing to another window, minimizing, etc.
  * Need to handle at least these 3 simple geometric objects: plane, sphere, cylinder.
  * All possible intersections and the inside of the object must be handled correctly.
  * Program must be able to resize the object’s unique properties: 
    diameter for a sphere and the width and height for a cylinder.
  * Program must be able to apply translation and rotation transformation to
    objects, lights and cameras (except for spheres and lights that cannot be rotated).
  * Program must properly handle light management: spot brightness, hard shadows, ambiance lighting (objects are
    never completely in the dark). Need to implement Ambient and diffuse lighting.
  * Program must save rendered image of scene in format .bmp if flag --save is presented
  
  * The program displays the image in a window and respect the following rules:
    + Pressing ESC must close the window and quit the program cleanly.
    + Clicking on the red cross on the window’s frame must close the window and
        quit the program cleanly.
    + Program must take as a first argument a scene description file with the .rt  
      extension.
  * .rt file description must follow rules:
     + Each type of element can be separated by one or more line break(s).
     + Each type of information from an element can be separated by one or more
       space(s).
     + Each type of element can be set in any order in the file.
     + Elements which are defined by a capital letter can only be declared once in
       the scene.
       
       
  Usage 
  -----------
  ```
  make
  ./miniRT |--save| ['file with .rt extension] 
  ```
  
  if flag --save is presented rendered image will be saved in root of the project in .bmp format
  
       
  Examples 
  -----------
  
  
  
