   _____      _               _____      _
  / ____|    | |             / ____|    | |
 | |     ___ | | ___  _ __  | |    _   _| |__   ___
 | |    / _ \| |/ _ \| '__| | |   | | | | '_ \ / _ \
 | |___| (_) | | (_) | |    | |___| |_| | |_) |  __/
  \_____\___/|_|\___/|_|     \_____\__,_|_.__/ \___|

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. How is the cube stored?
2. How is the cube solved?


HOW IS THE CUBE STORED?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
On a standard 3x3 Rubik's cube, there are 6 faces, each one with
9 small faces. Doing the math, we find that there are 54 small faces
on each cube. The faces are stored in an array, a private data value
of the Cube class (cube.h, line 66).

  In order for the program to correctly solve the cube, it is
important that the input cube values are oriented in a certain way.
The following is how the cubeValues[] is allocated:

	+-----------+-----------+---------------------------+
	|	Face	    |	Abbr.	    |	cubeValues[] indexes	    |
	+-----------+-----------+---------------------------+
	|	Front	    |   F	      |			0-8				            |
	|	Right	    |	  R		    |			9-17			            |
	|	Back	    | 	B		    |			18-26			            |
	|	Left	    | 	L		    |			27-35			            |
	|	Top		    | 	U		    |			36-44			            |
	|	Bottom	  |	  D		    |			45-53			            |
	+---------------------------------------------------+

	It is not important how the original cube is oriented. The first
step in solving the cube, in this program, is to call the orient()
function, which turns the cube so that the white side is on top and
the blue side is facing the front.

	The turn functions (F(), B(), I(), etc.) simply manipulate the
cubeValues() to represent the changed faces.


HOW IS THE CUBE SOLVED?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	This program follows the official Rubik's cube solution guide,
found online at http://rubiks.com/solving-guide/3x3.

	+-----------+-----------------------+
	|	Steps	    |	Description			      |
	+-----------+-----------------------+
	|	1		      |	White Cross		       	|
	|	2		      |	White Corners 		    |
	|	3		      | Middle Layer	  	    |
	|	4		      | Yellow Cross		      |
	|	5		      | Yellow Corners	  	  |
	|	6		      |	Last Layer Corners	  |
	|	7		      |	Last Layer Edges	    |
	+-----------+-----------------------+
