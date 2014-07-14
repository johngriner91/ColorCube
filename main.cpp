/*
+---------------------------------------------------------------------------
|
|	Program:	Color Cube
|	File:			main.cpp
|	Author: 	John Griner
|
|	Welcome to the Color Cube program.
|	After reading in the colored faces of a rubiks cube, this program
| 	solves the cube and prints out the proper steps so the user will
|		be able to solve it too.
|
|
|	How it works. 
|
+---------------------------------------------------------------------------
*/

#include <fstream>
#include "cube.h"
#include "cube.cc"

int main(){

	//	Variables
	char cube[54];					//	array to store the cube colors
	ifstream inputFile;			//	input file that holds the faces

	inputFile.open("cubeStart.txt");

	// Right now, there isn't any file checking. Because it's in the
	//	beginning stages, I know the input file will be in a correct
	//	format.
	for(int j = 0; j < 54; j++){
		inputFile >> cube[j];
	}

	//	The program is done reading the input file. We will go ahead
	//		and close the file.
	inputFile.close();

	//	Create a cube object
	Cube puzzle(cube);

	//	Calle the method that will solve the cube.
	puzzle.solve_cube();

	// End the program
	return 0;
}
