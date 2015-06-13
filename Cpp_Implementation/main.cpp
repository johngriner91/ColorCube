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
|	This is the main file. Because we are currently in development, we are
|   assuming correct input and are doing not checking. This file reads in
|   the colors of a rubik's cube and calls the Cube::solve() function, which
|   will itself call a few functions that will solve the cube.
|
+---------------------------------------------------------------------------
*/
#include "cube.h"
#include "cube.cc"

#include <__debug>

int main(){

	//	Variables
	char cube_faces[54];
	ifstream inputFile;

	// Right now, there isn't any file checking. Because it's in the
	//	beginning stages, I know the input file will be in a correct
	//	format.
	inputFile.open("../input/test_0.txt");

	for(int j = 0; j < 54; j++){
		inputFile >> cube_faces[j];
	}

	inputFile.close();

	//	Create a cube object
	Cube puzzle(cube_faces);

	//	Calle the method that will solve the cube.
	puzzle.solve_cube();

	// End the program
	return 0;
}
