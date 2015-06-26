/*
+---------------------------------------------------------------------------
|
|	Program:	Color Cube
|	File:			cube.h
|	Author: 	John Griner
|
|	Welcome to the Color Cube program.
|	After reading in the colored faces of a rubiks cube, this program
| 	solves the cube and prints out the proper steps so the user will
|		be able to solve it too.
|
|
|	This is the header file. It defines the cube class that will be used to
|   implement the digital rubik's cube.
+---------------------------------------------------------------------------
*/

#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//	The Cube type to implement the virtual Rubiks Cube.
class Cube{
	public:
		//	Constructor, initializes cubeValues[]
		Cube(char array[54]);

		// 	Checks that the input is valid
		int checkInputs();

		//	Prints out the faces of the cube.
		void print();

		//	Print function with error alerts
		void printE(std::string);

		//	Returns the color of the face at index a
		char at(int);

		//	Returns the center color of the front face
		char getFColor();

		//	Returns the center color of the right face
		char getRColor();

		//	Returns the center color of the back face
		char getBColor();

		//	Returns the center color of the left face
		char getLColor();

		//	Returns the center color of the top face
		char getUColor();

		//	Returns the center color of the bottom face
		char getDColor();

		//	Interprets the found solution
		void parseResult();

		//	Edits the solution method
		void optimizeData();

		//	calls the necessary functions to solve the cube
		void solve_cube();

		// The following methods are methods are steps to solve the Rubik's
		//		Cube, as per the Official Rubik's Cube Solution Guide.

		//	positions the cube white up, blue front
		void orient();

		//	solves the 'white cross' step
		int whiteCross();

		//	solves the 'white corners' step
		int whiteCorners();

		//	solves the middle layer
		int middleLayer();

		//	solves the 'yellow cross' step
		int yellowCross();

		//	solves the 'yellow corners' step
		int yellowCorners();

		//	solves the corner pieces of last layer
		int lLayer_corners();

		//	solves the last layer 'edge' pieces
		int lLayer_topEdges();

		// Support function
		//	middle layer solving
		void middle_fallLeft();

		//	middle layer solving
		void middle_fallRight();

		//	turns that solve the 'yellow cross'
		void yellowCrossSequence();

		//	turns for the last layer corners
		void lLayer_cornerSequence();

		//	rotate last layer edge pieces clockwise
		void lLayer_topSequenceClock();

		//	rotate last layer edge pieces counter
		void lLayer_topSequenceCounter();

	private:
		char cubeValues[54];	//	Stores the colors of each square on the cube.

		//	The following methods alter 'cubeValues[]' by "turning" the cube.
		//	Turn the Right face clockwise
		void R();

		//	Turn the Right face counterclockwise
		void Ri();

		//	Turn the Left face clockwise
		void L();

		// 	Turn the Left face counterclockwise
		void Li();

		//	Turn the Back face clockwise
		void B();

		// 	Turn the Back face counterclockwise
		void Bi();

		//	Turn the Bottom face clockwise
		void D();

		// 	Turn the Bottom face counterclockwise
		void Di();

		//	Turn the Front face clockwise
		void F();

		// 	Turn the Front face counterclockwise
		void Fi();

		//	Turn the Top face clockwise
		void U();

		// 	Turn the Top face counterclockwise
		void Ui();

		//	Specialized turns
		//	Turn the whole cube clockwise, top pivot
		void TurnCube();

		//	Turn the whole cube clockwise, front pivot
		void RollCube();

		//	Calls RollCube() twice
		void UpsideDownCube();

		//	The following vector stores the steps to solve the cube. Because
		//		the number of steps varies in length, a vector is used.
		std::vector< std::string > instruction;
};

#endif
