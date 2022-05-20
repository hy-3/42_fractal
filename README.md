# Fractal

Create fractal images(Mandelbrot & Julia) with a graphical library(Minilibx).
> A fractal is an abstract mathematical object, like a curve or a surface, which has a similar pattern whatever the scale.

Mandelbrot             |  Julia
:-------------------------:|:-------------------------:
![](https://github.com/hy-3/fractal/blob/master/gif/mandelbrot.gif)  |  ![](https://github.com/hy-3/fractal/blob/master/gif/julia.gif)

## Usage
```
$ make

>> To show Mandelbrot set <<
$ ./fractal mandelbrot

>> To show Julia set <<
$ ./fractal julia 1
$ ./fractal julia 2
$ ./fractal julia 3
(You can choose 1 to 3 for different Julia set
 or You can just change fixed real number and imaginary number in source code)

>> Key & Mouse controle <<
[LEFT, RIGHT, UP and DOWN key]            : Move around in the image
['i' character key or Mouse scroll up]    : Zoom in
['o' character key or Mouse scroll down]  : Zoom out
[ESC key]                                 : Close the window & Finish the program
```
