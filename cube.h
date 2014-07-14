/*
+---------------------------------------------------------------------------
|
|	Program:	Color Cube
|	File:			cube.h
|	Author: 	John Griner
|
+---------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

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
		void solve_cube();		//	calls the necessary functions to solve the cube
		void orient();				// 	positions cube white side up, blue side front
		void whiteCross();		//	solves the 'white cross' step
		void whiteCorners();	//	solves the 'white corners' step
		void correctSix(int&);//	solves the white corner from position six
		void correctEight(int&);//	solves the white corner from position eight
		void printE(string);	//	print function with error alerts
		void middle_fallLeft();	//	middle layer solving
		void middle_fallRight();//	middle layer solving
		void middleLayer();		//	solves the middle layer, calls fallRight/fallLeft
		void yellowCross();		//	solves the 'yellow cross' step
		void yellowCrossSequence();	//	turns that solve the 'yellow cross'
		void yellowCorners();	//	solves the 'yellow corners' step
		void lastLayer_cornerSequence();	//	turns for the last layer corners
		void lastLayer_corners();	//	solves the 'last layer corners'
		void lastLayer_topSequenceClock();//	turns to rotate last layer clockwise
		void lastLayer_topSequenceCounter();//	turns to rotate last layer counter
		void lastLayer_topEdges();//	solves the last layer 'edge' pieces
		void parseResult();	//	interprets the found solution
		void removeRedundancy();	//	edits the solution method

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
		vector<string> instruction;
};
