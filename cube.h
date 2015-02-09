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
		Cube(char array[54]);	//	Constructor, initializes cubeValues[]
		void print();					//	Prints out the faces of the cube.
		char at(int);					//	Returns the color of the face at index a
		char getFColor();			//	Returns the center color of the front face
		char getRColor();			//	Returns the center color of the right face
		char getBColor();			//	Returns the center color of the back face
		char getLColor();			//	Returns the center color of the left face
		char getUColor();			//	Returns the center color of the top face
		char getDColor();			//	Returns the center color of the bottom face
		int edgeOf(int);			// 	Returns color of the opposite edge of index a
		void parseResult();		//	interprets the found solution
		void optimizeData();	//	edits the solution method

		void solve_cube();		//	calls the necessary functions to solve the cube

		// The following methods are methods are steps to solve the Rubik's
		//		Cube, as per the Official Rubik's Cube Solution Guide.

		void orient();                   //	positions the cube white up, blue front
		void whiteCross();   	         	 //	solves the 'white cross' step
		void whiteCorners();	           //	solves the 'white corners' step
		
		//  Eventually, the following two methods will be replaced
		void correctSix(int&);		       //	solves the white corner from position 6
		void correctEight(int&);		     //	solves the white corner from position 8
		
		void printE(std::string);        //	print function with error alerts
		void middle_fallLeft();	         //	middle layer solving
		void middle_fallRight();		     //	middle layer solving
		void middleLayer();		           //	solves the middle layer
		void yellowCross();		           //	solves the 'yellow cross' step
		void yellowCrossSequence();		   //	turns that solve the 'yellow cross'
		void yellowCorners();		         //	solves the 'yellow corners' step
		void lLayer_cornerSequence();		 //	turns for the last layer corners
		void lLayer_corners();	 	       //	solves the corner pieces of last layer
		void lLayer_topSequenceClock();	 //	rotate last layer edge pieces clockwise
		void lLayer_topSequenceCounter();//	rotate last layer edge pieces counter
		void lLayer_topEdges();		       //	solves the last layer 'edge' pieces

	private:
		char cubeValues[54];	//	Stores the colors of each square on the cube.

		//	The following methods alter 'cubeValues[]' by "turning" the cube.
		void R();							//	Turn the Right face clockwise
		void Ri();						//	Turn the Right face counterclockwise
		void L();							//	Turn the Left face clockwise
		void Li();						// 	Turn the Left face counterclockwise
		void B();							//	Turn the Back face clockwise
		void Bi();						// 	Turn the Back face counterclockwise
		void D();							//	Turn the Bottom face clockwise
		void Di();						// 	Turn the Bottom face counterclockwise
		void F();							//	Turn the Front face clockwise
		void Fi();						// 	Turn the Front face counterclockwise
		void U();							//	Turn the Top face clockwise
		void Ui();						// 	Turn the Top face counterclockwise

		//	The following methods are specialized turnes.
		void TurnCube();			//	Turn the whole cube clockwise, top pivot
		void RollCube();			//	Turn the whole cube clockwise, front pivot
		void UpsideDownCube();//	Calls RollCube() twice

		//	The following vector stores the steps to solve the cube. Because
		//		the number of steps varies in length, a vector is used.
		std::vector< std::string > instruction;
};

#endif