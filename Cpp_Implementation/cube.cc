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

#include <iostream>
#include <iomanip>

// Helpful for debugging and / or logging
#define LOG( message ) logError( __LINE__,__func__, message )

// Functions return pass when things work out well, fail otherwise
const int FAIL = 0;
const int PASS = 1;

using namespace std;

void logError (int lineNumber, string function, const std::string& message)
{
    cout << "line: " << setw(4) << lineNumber << " : ";
		cout << function << ": " <<  message << "\n";
}

// Constructor: instantiates the Cube object with the cubeValues data
Cube::Cube( char array[54] ){
	// Read in the colors of the cube.
	for(int i = 0; i < 54; i++){
		cubeValues[i] = array[i];
	}
}


// This is the method that solves the Cube by calling the appropriate
//		methods in the correct order.
void Cube::solve_cube(){
	this->print();
	this->orient();

	if ( FAIL == this->whiteCross() ){
		printE("Terminating from whiteCross()");
		return;
	}

	if ( FAIL == this->whiteCorners() ){
		printE("Terminating from whiteCorners()");
		return;
	}

	//	At this point, the white side of the cube is complete
	this->orient();
	this->middleLayer();

	//	At this point, the middle layer is complete
	this->yellowCross();
	this->yellowCorners();

	//	At this point, the yellow layer is complete
	this->lLayer_corners();
	this->lLayer_topEdges();

	//	At this point, the cube is completed
	this->print();
	this->optimizeData();

	//	The optimized solution is provided to the user
	this->parseResult();
}


// This method prints out the cube faces in a grid format. Prints in the
// following format.
void Cube::print(){
	cout << "Printing the cubeValues\n-----------------";

	// Print the front facing cube faces
	cout << "\n\nFront\n-------\n";
	for(int i = 0; i < 9; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}

	// Print out the right facing cube faces
	cout << "\n\nRight\n-------\n";
	for(int i = 9; i < 18; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}

	// Print out the back facing cube faces
	cout << "\n\nBack\n-------\n";
	for(int i = 18; i < 27; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}

	// Print out the left facing cube faces
	cout << "\n\nLeft\n-------\n";
	for(int i = 27; i < 36; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}

	// Print out the top facing cube faces
	cout << "\n\nTop\n-------\n";
	for(int i = 36; i < 45; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}

	// Print out the bottom facing cube faces
	cout << "\n\nBottom\n-------\n";
	for(int i = 45; i < 54; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}
	cout << "\n\nCompleted printing\n-----------------\n\n";
}


// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree clockwise rotation of the front-side face.
void Cube::F(){
	char temp = 'x';
	temp = cubeValues[2];
	cubeValues[2] = cubeValues[0];
    cubeValues[0] = cubeValues[6];
    cubeValues[6] = cubeValues[8];
    cubeValues[8] = temp;
    temp = cubeValues[1];
    cubeValues[1] = cubeValues[3];
    cubeValues[3] = cubeValues[7];
    cubeValues[7] = cubeValues[5];
    cubeValues[5] = temp;
    temp = cubeValues[9];
    cubeValues[9] = cubeValues[42];
    cubeValues[42] = cubeValues[35];
    cubeValues[35] = cubeValues[47];
    cubeValues[47] = temp;
    temp = cubeValues[12];
    cubeValues[12] = cubeValues[43];
    cubeValues[43] = cubeValues[32];
    cubeValues[32] = cubeValues[46];
    cubeValues[46] = temp;
    temp = cubeValues[15];
    cubeValues[15] = cubeValues[44];
    cubeValues[44] = cubeValues[29];
    cubeValues[29] = cubeValues[45];
    cubeValues[45] = temp;
    instruction.push_back("F");
		cout << "F\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree counterclockwise rotation of the front-side face.
void Cube::Fi(){
	char temp = 'x';
    temp = cubeValues[0];
    cubeValues[0] = cubeValues[2];
    cubeValues[2] = cubeValues[8];
    cubeValues[8] = cubeValues[6];
    cubeValues[6] = temp;
    temp = cubeValues[1];
    cubeValues[1] = cubeValues[5];
    cubeValues[5] = cubeValues[7];
    cubeValues[7] = cubeValues[3];
    cubeValues[3] = temp;
    temp = cubeValues[42];
    cubeValues[42] = cubeValues[9];
    cubeValues[9] = cubeValues[47];
    cubeValues[47] = cubeValues[35];
    cubeValues[35] = temp;
    temp = cubeValues[43];
    cubeValues[43] = cubeValues[12];
    cubeValues[12] = cubeValues[46];
    cubeValues[46] = cubeValues[32];
    cubeValues[32] = temp;
    temp = cubeValues[44];
    cubeValues[44] = cubeValues[15];
    cubeValues[15] = cubeValues[45];
    cubeValues[45] = cubeValues[29];
    cubeValues[29] = temp;
    instruction.push_back("Fi");
		cout << "Fi\n";
	}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree clockwise rotation of the right-side face.
void Cube::R(){
	char temp = 'x';
	temp = cubeValues[11];
	cubeValues[11] = cubeValues[9];
	cubeValues[9] = cubeValues[15];
	cubeValues[15] = cubeValues[17];
	cubeValues[17] = temp;
	temp = cubeValues[10];
	cubeValues[10] = cubeValues[12];
	cubeValues[12] = cubeValues[16];
	cubeValues[16] = cubeValues[14];
	cubeValues[14] = temp;
	temp = cubeValues[38];
	cubeValues[38] = cubeValues[2];
	cubeValues[2] = cubeValues[47];
	cubeValues[47] = cubeValues[24];
	cubeValues[24] = temp;
	temp = cubeValues[41];
	cubeValues[41] = cubeValues[5];
	cubeValues[5] = cubeValues[50];
	cubeValues[50] = cubeValues[21];
	cubeValues[21] = temp;
	temp = cubeValues[44];
	cubeValues[44] = cubeValues[8];
	cubeValues[8] = cubeValues[53];
	cubeValues[53] = cubeValues[18];
	cubeValues[18] = temp;
  instruction.push_back("R");
	cout << "R\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree counterclockwise rotation of the right-side face.
void Cube::Ri(){
	char temp = 'x';
	temp = cubeValues[9];
	cubeValues[9] = cubeValues[11];
	cubeValues[11] = cubeValues[17];
	cubeValues[17] = cubeValues[15];
	cubeValues[15] = temp;
	temp = cubeValues[12];
	cubeValues[12] = cubeValues[10];
	cubeValues[10] = cubeValues[14];
	cubeValues[14] = cubeValues[16];
	cubeValues[16] = temp;
	temp = cubeValues[2];
	cubeValues[2] = cubeValues[38];
	cubeValues[38] = cubeValues[24];
	cubeValues[24] = cubeValues[47];
	cubeValues[47] = temp;
	temp = cubeValues[5];
	cubeValues[5] = cubeValues[41];
	cubeValues[41] = cubeValues[21];
	cubeValues[21] = cubeValues[50];
	cubeValues[50] = temp;
	temp = cubeValues[8];
	cubeValues[8] = cubeValues[44];
	cubeValues[44] = cubeValues[18];
	cubeValues[18] = cubeValues[53];
	cubeValues[53] = temp;
  instruction.push_back("Ri");
	cout << "Ri\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree clockwise rotation of the left-side face.
void Cube::L(){
	char temp = 'x';
	temp = cubeValues[30];
	cubeValues[30] = cubeValues[34];
	cubeValues[34] = cubeValues[32];
	cubeValues[32] = cubeValues[28];
	cubeValues[28] = temp;
	temp = cubeValues[27];
	cubeValues[27] = cubeValues[33];
	cubeValues[33] = cubeValues[35];
	cubeValues[35] = cubeValues[29];
	cubeValues[29] = temp;
	temp = cubeValues[36];
	cubeValues[36] = cubeValues[26];
	cubeValues[26] = cubeValues[45];
	cubeValues[45] = cubeValues[0];
	cubeValues[0] = temp;
	temp = cubeValues[39];
	cubeValues[39] = cubeValues[23];
	cubeValues[23] = cubeValues[48];
	cubeValues[48] = cubeValues[3];
	cubeValues[3] = temp;
	temp = cubeValues[42];
	cubeValues[42] = cubeValues[20];
	cubeValues[20] = cubeValues[51];
	cubeValues[51] = cubeValues[6];
	cubeValues[6] = temp;
  instruction.push_back("L");
	cout << "L\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree counterclockwise rotation of the left-side face.
void Cube::Li(){
	char temp = 'x';
	temp = cubeValues[34];
	cubeValues[34] = cubeValues[30];
	cubeValues[30] = cubeValues[28];
	cubeValues[28] = cubeValues[32];
	cubeValues[32] = temp;
	temp = cubeValues[33];
	cubeValues[33] = cubeValues[27];
	cubeValues[27] = cubeValues[29];
	cubeValues[29] = cubeValues[35];
	cubeValues[35] = temp;
	temp = cubeValues[26];
	cubeValues[26] = cubeValues[36];
	cubeValues[36] = cubeValues[0];
	cubeValues[0] = cubeValues[45];
	cubeValues[45] = temp;
	temp = cubeValues[23];
	cubeValues[23] = cubeValues[39];
	cubeValues[39] = cubeValues[3];
	cubeValues[3] = cubeValues[48];
	cubeValues[48] = temp;
	temp = cubeValues[20];
	cubeValues[20] = cubeValues[42];
	cubeValues[42] = cubeValues[6];
	cubeValues[6] = cubeValues[51];
	cubeValues[51] = temp;
  instruction.push_back("Li");
	cout << "Li\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree clockwise rotation of the back-side face.
void Cube::B(){
    char temp = 'x';
	temp = cubeValues[18];
	cubeValues[18] = cubeValues[24];
	cubeValues[24] = cubeValues[26];
	cubeValues[26] = cubeValues[20];
	cubeValues[20] = temp;
	temp = cubeValues[19];
	cubeValues[19] = cubeValues[21];
	cubeValues[21] = cubeValues[25];
	cubeValues[25] = cubeValues[23];
	cubeValues[23] = temp;
	temp = cubeValues[33];
	cubeValues[33] = cubeValues[36];
	cubeValues[36] = cubeValues[11];
	cubeValues[11] = cubeValues[53];
	cubeValues[53] = temp;
	temp = cubeValues[30];
	cubeValues[30] = cubeValues[37];
	cubeValues[37] = cubeValues[14];
	cubeValues[14] = cubeValues[52];
	cubeValues[52] = temp;
	temp = cubeValues[27];
	cubeValues[27] = cubeValues[38];
	cubeValues[38] = cubeValues[17];
	cubeValues[17] = cubeValues[51];
	cubeValues[51] = temp;
  instruction.push_back("B");
	cout << "B\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree counterclockwise rotation of the back-side face.
void Cube::Bi(){
	char temp = 'x';
	temp = cubeValues[24];
	cubeValues[24] = cubeValues[18];
	cubeValues[18] = cubeValues[20];
	cubeValues[20] = cubeValues[26];
	cubeValues[26] = temp;
	temp = cubeValues[19];
	cubeValues[19] = cubeValues[23];
	cubeValues[23] = cubeValues[25];
	cubeValues[25] = cubeValues[21];
	cubeValues[21] = temp;
	temp = cubeValues[36];
	cubeValues[36] = cubeValues[33];
	cubeValues[33] = cubeValues[53];
	cubeValues[53] = cubeValues[11];
	cubeValues[11] = temp;
	temp = cubeValues[37];
	cubeValues[37] = cubeValues[30];
	cubeValues[30] = cubeValues[52];
	cubeValues[52] = cubeValues[14];
	cubeValues[14] = temp;
	temp = cubeValues[38];
	cubeValues[38] = cubeValues[27];
	cubeValues[27] = cubeValues[51];
	cubeValues[51] = cubeValues[17];
	cubeValues[17] = temp;
  instruction.push_back("Bi");
	cout << "Bi\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree clockwise rotation of the top-side face.
void Cube::U(){
	char temp = 'x';
	temp = cubeValues[38];
	cubeValues[38] = cubeValues[36];
	cubeValues[36] = cubeValues[42];
	cubeValues[42] = cubeValues[44];
	cubeValues[44] = temp;
	temp = cubeValues[37];
	cubeValues[37] = cubeValues[39];
	cubeValues[39] = cubeValues[43];
	cubeValues[43] = cubeValues[41];
	cubeValues[41] = temp;
	temp = cubeValues[0];
	cubeValues[0] = cubeValues[9];
	cubeValues[9] = cubeValues[18];
	cubeValues[18] = cubeValues[27];
	cubeValues[27] = temp;
	temp = cubeValues[1];
	cubeValues[1] = cubeValues[10];
	cubeValues[10] = cubeValues[19];
	cubeValues[19] = cubeValues[28];
	cubeValues[28] = temp;
	temp = cubeValues[2];
	cubeValues[2] = cubeValues[11];
	cubeValues[11] = cubeValues[20];
	cubeValues[20] = cubeValues[29];
	cubeValues[29] = temp;
  instruction.push_back("U");
	cout << "U\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree counterclockwise rotation of the top-side face.
void Cube::Ui(){
	char temp = 'x';
	temp = cubeValues[36];
	cubeValues[36] = cubeValues[38];
	cubeValues[38] = cubeValues[44];
	cubeValues[44] = cubeValues[42];
	cubeValues[42] = temp;
	temp = cubeValues[39];
	cubeValues[39] = cubeValues[37];
	cubeValues[37] = cubeValues[41];
	cubeValues[41] = cubeValues[43];
	cubeValues[43] = temp;
	temp = cubeValues[9];
	cubeValues[9] = cubeValues[0];
	cubeValues[0] = cubeValues[27];
	cubeValues[27] = cubeValues[18];
	cubeValues[18] = temp;
	temp = cubeValues[10];
	cubeValues[10] = cubeValues[1];
	cubeValues[1] = cubeValues[28];
	cubeValues[28] = cubeValues[19];
	cubeValues[19] = temp;
	temp = cubeValues[11];
	cubeValues[11] = cubeValues[2];
	cubeValues[2] = cubeValues[29];
	cubeValues[29] = cubeValues[20];
	cubeValues[20] = temp;
  instruction.push_back("Ui");
	cout << "Ui\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree clockwise rotation of the bottom-side face.
void Cube::D(){
	char temp = 'x';
	temp = cubeValues[45];
	cubeValues[45] = cubeValues[51];
	cubeValues[51] = cubeValues[53];
	cubeValues[53] = cubeValues[47];
	cubeValues[47] = temp;
	temp = cubeValues[46];
	cubeValues[46] = cubeValues[48];
	cubeValues[48] = cubeValues[52];
	cubeValues[52] = cubeValues[50];
	cubeValues[50] = temp;
	temp = cubeValues[8];
	cubeValues[8] = cubeValues[35];
	cubeValues[35] = cubeValues[26];
	cubeValues[26] = cubeValues[17];
	cubeValues[17] = temp;
	temp = cubeValues[7];
	cubeValues[7] = cubeValues[34];
	cubeValues[34] = cubeValues[25];
	cubeValues[25] = cubeValues[16];
	cubeValues[16] = temp;
	temp = cubeValues[6];
	cubeValues[6] = cubeValues[33];
	cubeValues[33] = cubeValues[24];
	cubeValues[24] = cubeValues[15];
	cubeValues[15] = temp;
  instruction.push_back("D");
	cout << "D\n";
}

// Face turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree counterclockwise rotation of the bottom-side face.
void Cube::Di(){
	char temp = 'x';
	temp = cubeValues[51];
	cubeValues[51] = cubeValues[45];
	cubeValues[45] = cubeValues[47];
	cubeValues[47] = cubeValues[53];
	cubeValues[53] = temp;
	temp = cubeValues[48];
	cubeValues[48] = cubeValues[46];
	cubeValues[46] = cubeValues[50];
	cubeValues[50] = cubeValues[52];
	cubeValues[52] = temp;
	temp = cubeValues[35];
	cubeValues[35] = cubeValues[8];
	cubeValues[8] = cubeValues[17];
	cubeValues[17] = cubeValues[26];
	cubeValues[26] = temp;
	temp = cubeValues[34];
	cubeValues[34] = cubeValues[7];
	cubeValues[7] = cubeValues[16];
	cubeValues[16] = cubeValues[25];
	cubeValues[25] = temp;
	temp = cubeValues[33];
	cubeValues[33] = cubeValues[6];
	cubeValues[6] = cubeValues[15];
	cubeValues[15] = cubeValues[24];
	cubeValues[24] = temp;
  instruction.push_back("Di");
	cout << "Di\n";
}

// Cube turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree clockwise rotation of the whole cube. This method
//		turns the cube keeping the top and bottom face the same.
void Cube::TurnCube(){
	char temp = 'x';
	temp = cubeValues[51];
	cubeValues[51] = cubeValues[45];
	cubeValues[45] = cubeValues[47];
	cubeValues[47] = cubeValues[53];
	cubeValues[53] = temp;
	temp = cubeValues[48];
	cubeValues[48] = cubeValues[46];
	cubeValues[46] = cubeValues[50];
	cubeValues[50] = cubeValues[52];
	cubeValues[52] = temp;
	temp = cubeValues[35];
	cubeValues[35] = cubeValues[8];
	cubeValues[8] = cubeValues[17];
	cubeValues[17] = cubeValues[26];
	cubeValues[26] = temp;
	temp = cubeValues[34];
	cubeValues[34] = cubeValues[7];
	cubeValues[7] = cubeValues[16];
	cubeValues[16] = cubeValues[25];
	cubeValues[25] = temp;
	temp = cubeValues[33];
	cubeValues[33] = cubeValues[6];
	cubeValues[6] = cubeValues[15];
	cubeValues[15] = cubeValues[24];
	cubeValues[24] = temp;
	temp = cubeValues[38];
	cubeValues[38] = cubeValues[36];
	cubeValues[36] = cubeValues[42];
	cubeValues[42] = cubeValues[44];
	cubeValues[44] = temp;
	temp = cubeValues[37];
	cubeValues[37] = cubeValues[39];
	cubeValues[39] = cubeValues[43];
	cubeValues[43] = cubeValues[41];
	cubeValues[41] = temp;
	temp = cubeValues[0];
	cubeValues[0] = cubeValues[9];
	cubeValues[9] = cubeValues[18];
	cubeValues[18] = cubeValues[27];
	cubeValues[27] = temp;
	temp = cubeValues[1];
	cubeValues[1] = cubeValues[10];
	cubeValues[10] = cubeValues[19];
	cubeValues[19] = cubeValues[28];
	cubeValues[28] = temp;
	temp = cubeValues[2];
	cubeValues[2] = cubeValues[11];
	cubeValues[11] = cubeValues[20];
	cubeValues[20] = cubeValues[29];
	cubeValues[29] = temp;
	temp = cubeValues[30];
	cubeValues[30] = cubeValues[3];
	cubeValues[3] = cubeValues[12];
	cubeValues[12] = cubeValues[21];
	cubeValues[21] = temp;
	temp = cubeValues[31];
	cubeValues[31] = cubeValues[4];
	cubeValues[4] = cubeValues[13];
	cubeValues[13] = cubeValues[22];
	cubeValues[22] = temp;
	temp = cubeValues[32];
	cubeValues[32] = cubeValues[5];
	cubeValues[5] = cubeValues[14];
	cubeValues[14] = cubeValues[23];
	cubeValues[23] = temp;
  instruction.push_back("TC");
	cout << "TC\n";
}

// Cube turn method. This method changed the values of the cubeValues array
//		to simulate a 90 degree clockwise rotation of the whole cube. This method
//		turns the cube keeping the front and back face the same.
void Cube::RollCube(){
	char temp = 'x';
	temp = cubeValues[24];
	cubeValues[24] = cubeValues[18];
	cubeValues[18] = cubeValues[20];
	cubeValues[20] = cubeValues[26];
	cubeValues[26] = temp;
	temp = cubeValues[19];
	cubeValues[19] = cubeValues[23];
	cubeValues[23] = cubeValues[25];
	cubeValues[25] = cubeValues[21];
	cubeValues[21] = temp;
	temp = cubeValues[36];
	cubeValues[36] = cubeValues[33];
	cubeValues[33] = cubeValues[53];
	cubeValues[53] = cubeValues[11];
	cubeValues[11] = temp;
	temp = cubeValues[37];
	cubeValues[37] = cubeValues[30];
	cubeValues[30] = cubeValues[52];
	cubeValues[52] = cubeValues[14];
	cubeValues[14] = temp;
	temp = cubeValues[38];
	cubeValues[38] = cubeValues[27];
	cubeValues[27] = cubeValues[51];
	cubeValues[51] = cubeValues[17];
	cubeValues[17] = temp;
	temp = cubeValues[2];
	cubeValues[2] = cubeValues[0];
  cubeValues[0] = cubeValues[6];
  cubeValues[6] = cubeValues[8];
  cubeValues[8] = temp;
  temp = cubeValues[1];
  cubeValues[1] = cubeValues[3];
  cubeValues[3] = cubeValues[7];
  cubeValues[7] = cubeValues[5];
  cubeValues[5] = temp;
  temp = cubeValues[9];
  cubeValues[9] = cubeValues[42];
  cubeValues[42] = cubeValues[35];
  cubeValues[35] = cubeValues[47];
  cubeValues[47] = temp;
  temp = cubeValues[12];
  cubeValues[12] = cubeValues[43];
  cubeValues[43] = cubeValues[32];
  cubeValues[32] = cubeValues[46];
  cubeValues[46] = temp;
  temp = cubeValues[15];
  cubeValues[15] = cubeValues[44];
  cubeValues[44] = cubeValues[29];
  cubeValues[29] = cubeValues[45];
  cubeValues[45] = temp;
	temp = cubeValues[10];
	cubeValues[10] = cubeValues[39];
	cubeValues[39] = cubeValues[34];
	cubeValues[34] = cubeValues[50];
	cubeValues[50] = temp;
	temp = cubeValues[13];
	cubeValues[13] = cubeValues[40];
	cubeValues[40] = cubeValues[31];
	cubeValues[31] = cubeValues[49];
	cubeValues[49] = temp;
	temp = cubeValues[16];
	cubeValues[16] = cubeValues[41];
	cubeValues[41] = cubeValues[28];
	cubeValues[28] = cubeValues[48];
  cubeValues[48] = temp;
  instruction.push_back("RC");
	cout << "RC\n";
}

// Cube turn method. This method changed the values of the cubeValues array
//		to simulate a 180 degree clockwise rotation of the whole cube. This method
//		turns the cube keeping the front and back face the same.
void Cube::UpsideDownCube(){
		RollCube();
		RollCube();
}

//	This method returns the color of the face at an cubeValues index.
char Cube::at(int a){
	return cubeValues[a];
}


//	By orienting the cube, the algorithm to solve the cube can be standardized.
void Cube::orient(){

	//	If the front side is the "white" side, correct so the top is white.
	if(this->at(4)=='w'){
		this->TurnCube();
		this->RollCube();

		//	Turn the cube so that the blue side is facing the front
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}

	//	If the left side is the "white" side, correct so the top is white.
	else if(this->at(13)=='w'){
		this->TurnCube();
		this->TurnCube();
		this->RollCube();

		//	Turn the cube so that the blue side is facing the front
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}

	//	If the back side is the "white" side, correct so the top is white.
	else if(this->at(22)=='w'){
		this->TurnCube();
		this->TurnCube();
		this->TurnCube();
		this->RollCube();

		//	Turn the cube so that the blue side is facing the front
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}

	//	If the left side is the "white" side, correct so the top is white.
	else if(this->at(31)=='w'){
		this->RollCube();

		//	Turn the cube so that the blue side is facing the front
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}

	//	If the top side is the "white" side, move on.
	else if(this->at(40)=='w')

		//	Turn the cube so that the blue side is facing the front
		while(this->at(4) != 'b'){
			this->TurnCube();
		}

	//	If the bottom side is the "white" side, correct so the top is white.
	else if(this->at(49)=='w'){
		this->RollCube();
		this->RollCube();

		//	Turn the cube so that the blue side is facing the front
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}
		// Note that the cube was oriented
    instruction.push_back("OC");
		cout << "The cube has been oriented.\n\n";

}	// End of Cube::orient()

// Think about the white cross step
int Cube::whiteCross(){
  LOG("Beginning function");

  int edges[24] = {	 1,  3,  5,  7, 	// front
										10, 12, 14, 16, 	// right
										19, 21, 23, 25, 	// back
										28, 30, 32, 34,		// left
										37, 39, 41, 43, 	// up
										46, 48, 50, 52	};// down
  int counter = 0;
  int numTurns = 0;
  bool startOver = true;

  // Until we've looked at and approved all the pieces, keep looking
  while (counter != 24){

    // We haven't found a white piece yet
    while(this->at(edges[counter]) != 'w'){
      counter++;
    }

    // Integrate cube turns to "repeat" the position-based algorithm.
		//	This way, case 0 can be used to handle positions 1, 10, 19, and 28
		//	without any code rewrite. We'll simply turn the cube until those
		//	positions "become" case 0.
    if (counter < 16){
      int numToTurn = counter / 4;

      // reset the counter
      counter = counter % 4;

      for(int i = 0; i < numToTurn; i++)
        this->TurnCube();

    } // end if (counter < 16)

    // This switch is the meat and potatos of the function. Depending on
		//	where the white cross pieces are, we need to make specific turns to
		// 	move them into their correct position. This case statements are the
		//	different possible positions of the white pieces.
    switch(counter){
      case 0:{
        char oppositeEdge = this->at(43);
        if(oppositeEdge == this->getFColor()){
          this->Fi();
          this->U();
          this->Li();
          this->Ui();
        }
        else if(oppositeEdge == this->getRColor()){
          this->F();
          this->R();
        }
        else if(oppositeEdge == this->getBColor()){
          this->F();
          this->F();
          this->Di();
          this->Di();
          this->B();
          this->U();
          this->L();
          this->Ui();
        }
        else if(oppositeEdge == this->getLColor()){
          this->Fi();
          this->Li();
        }
        else{
          printE("whiteCross(): case 0: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 1:{
        char oppositeEdge = this->at(32);
        if(oppositeEdge == this->getFColor()){
          this->U();
          this->Li();
          this->Ui();
        }
        else if(oppositeEdge == this->getRColor()){
          this->L();
          this->Di();
          this->Di();
          this->Li();
          this->R();
          this->R();
        }
        else if(oppositeEdge == this->getBColor()){
          this->L();
          this->Di();
          this->Li();
          this->Bi();
          this->Bi();
        }
        else if(oppositeEdge == this->getLColor()){
          this->L();
        }
        else{
          printE("whiteCross(): case 1: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 2:{
        char oppositeEdge = this->at(12);
        if(oppositeEdge == this->getFColor()){
          this->F();
          this->F();
          this->U();
          this->Li();
          this->Ui();
        }
        else if(oppositeEdge == this->getRColor()){
          this->R();
        }
        else if(oppositeEdge == this->getBColor()){
          this->Ri();
          this->D();
          this->R();
          this->Bi();
          this->Bi();
        }
        else if(oppositeEdge == this->getLColor()){
          this->Ri();
          this->Di();
          this->Di();
          this->R();
          this->Li();
          this->Li();
        }
        else{
          printE("whiteCross(): case 2: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 3:{
        char oppositeEdge = this->at(46);
        if(oppositeEdge == this->getFColor()){
          this->F();
          this->U();
          this->Li();
          this->Ui();
        }
        else if(oppositeEdge == this->getRColor()){
          this->D();
          this->R();
          this->U();
          this->F();
          this->Ui();
        }
        else if(oppositeEdge == this->getBColor()){
          this->Di();
          this->Di();
          this->B();
          this->U();
          this->Ri();
          this->Ui();
        }
        else if(oppositeEdge == this->getLColor()){
          this->Di();
          this->L();
          this->U();
          this->Bi();
          this->Ui();
        }
        else{
          printE("whiteCross(): case 3: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 16:{
        char oppositeEdge = this->at(19);
        if(oppositeEdge == this->getFColor()){
          this->Bi();
          this->Bi();
          this->Di();
          this->Di();
          this->F();
          this->F();
        }
        else if(oppositeEdge == this->getRColor()){
          this->Bi();
          this->Ui();
          this->B();
          this->U();
        }
        else if(oppositeEdge == this->getBColor()){
          // This piece is supposed to be white.
          startOver = false;
        }
        else if(oppositeEdge == this->getLColor()){
          this->B();
          this->U();
          this->Bi();
          this->Ui();
        }
        else{
          printE("whiteCross(): case 16: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 17:{
        char oppositeEdge = this->at(29);
        if(oppositeEdge == this->getFColor()){
          this->L();
          this->U();
          this->Li();
          this->Ui();
        }
        else if(oppositeEdge == this->getRColor()){
          this->Li();
          this->Li();
          this->Di();
          this->Di();
          this->R();
          this->R();
        }
        else if(oppositeEdge == this->getBColor()){
          this->Li();
          this->Ui();
          this->L();
          this->U();
        }
        else if(oppositeEdge == this->getLColor()){
          // This piece is supposed to be white.
          startOver = false;
        }
        else{
          printE("whiteCross(): case 17: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 18:{
        char oppositeEdge = this->at(10);
        if(oppositeEdge == this->getFColor()){
          this->Ri();
          this->Ui();
          this->R();
          this->U();
        }
        else if(oppositeEdge == this->getRColor()){
          // This piece is supposed to be white.
          startOver = false;
        }
        else if(oppositeEdge == this->getBColor()){
          this->R();
          this->U();
          this->Ri();
          this->Ui();
        }
        else if(oppositeEdge == this->getLColor()){
          this->R();
          this->R();
          this->Di();
          this->Di();
          this->Li();
          this->Li();
        }
        else{
          printE("whiteCross(): case 18: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 19:{
        char oppositeEdge = this->at(1);
        if(oppositeEdge == this->getFColor()){
          // This piece is supposed to be white.
          startOver = false;
        }
        else if(oppositeEdge == this->getRColor()){
          this->F();
          this->U();
          this->Fi();
          this->Ui();
        }
        else if(oppositeEdge == this->getBColor()){
          this->F();
          this->F();
          this->Di();
          this->Di();
          this->Bi();
          this->Bi();
        }
        else if(oppositeEdge == this->getLColor()){
          this->Fi();
          this->Ui();
          this->F();
          this->U();
        }
        else{
          printE("whiteCross(): case 19: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 20:{
        char oppositeEdge = this->at(7);
        if(oppositeEdge == this->getFColor()){
          this->F();
          this->F();
        }
        else if(oppositeEdge == this->getRColor()){
          this->D();
          this->R();
          this->R();
        }
        else if(oppositeEdge == this->getBColor()){
          this->Di();
          this->Di();
          this->Bi();
          this->Bi();
        }
        else if(oppositeEdge == this->getLColor()){
          this->Di();
          this->Li();
          this->Li();
        }
        else{
          printE("whiteCross(): case 20: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 21:{
        char oppositeEdge = this->at(34);
        if(oppositeEdge == this->getFColor()){
          this->D();
          this->Bi();
          this->Bi();
        }
        else if(oppositeEdge == this->getRColor()){
          this->Di();
          this->Di();
          this->R();
          this->R();
        }
        else if(oppositeEdge == this->getBColor()){
          this->Di();
          this->Bi();
          this->Bi();
        }
        else if(oppositeEdge == this->getLColor()){
          this->Li();
          this->Li();
        }
        else{
          printE("whiteCross(): case 21: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 22:{
        char oppositeEdge = this->at(16);
        if(oppositeEdge == this->getFColor()){
          this->Di();
          this->F();
          this->F();
        }
        else if(oppositeEdge == this->getRColor()){
          this->R();
          this->R();
        }
        else if(oppositeEdge == this->getBColor()){
          this->D();
          this->Bi();
          this->Bi();
        }
        else if(oppositeEdge == this->getLColor()){
          this->Di();
          this->Di();
          this->Li();
          this->Li();
        }
        else{
          printE("whiteCross(): case 22: found no match for opposite edge");
          return 0;
        }
				break;
      }
      case 23:{
        char oppositeEdge = this->at(25);
        if(oppositeEdge == this->getFColor()){
          this->Di();
          this->Di();
          this->F();
          this->F();
        }
        else if(oppositeEdge == this->getRColor()){
          this->Di();
          this->R();
          this->R();
        }
        else if(oppositeEdge == this->getBColor()){
          this->Bi();
          this->Bi();
        }
        else if(oppositeEdge == this->getLColor()){
          this->D();
          this->Li();
          this->Li();
        }
        else{
          printE("whiteCross(): case 23: found no match for opposite edge");
          return 0;
        }
				break;
      }
    } // end switch statement. The piece was handled at this point.


    // Was the piece that was found supposed to be there? If not, start
		// 	search over, because we may have accidentally moved some pieces out
		//	of place. I doubt it, but it's always better to double check.
    if (startOver) {
			std:string msg = "Fixed white piece at " + to_string(edges[counter]);
      LOG(msg);

      counter = 0;

      // reset the flag
      startOver = true;
    }
		else{
			// Move on, this is supposed to be white
			counter++;
		}

    numTurns++;
    if (numTurns > 10){
      printE("Over 10 turns for WhiteCross(). Must debug before moving on");
      return 0;
    }
  }

  // The function will terminate. No errors were found! :)
  LOG("Returning sucessfully\n");
  return PASS;
}

//	Return the index of the center of the front face
char Cube::getFColor(){
	return cubeValues[4];
}

//	Return the index of the center of the right face
char Cube::getRColor(){
	return cubeValues[13];
}

//	Return the index of the center of the back face
char Cube::getBColor(){
	return cubeValues[22];
}

//	Return the index of the center of the left face
char Cube::getLColor(){
	return cubeValues[31];
}

//	Return the index of the center of the top face
char Cube::getUColor(){
	return cubeValues[40];
}

//	Return the index of the center of the bottom face
char Cube::getDColor(){
	return cubeValues[49];
}

void Cube::correctSix(int &counter){
	bool found = false;
	int i = 0;
	while((!found) & (i < 6)){
		if(this->at(45) == this->getFColor()){
			if(this->at(35) == this->getLColor())
				found = true;
		}
		else{
			this->D();
			this->TurnCube();
			i++;
		}
	}
	if(i == 6){
		this->printE("Error @ correctSix(counter)");
	}
	this->D();
	this->L();
	this->Di();
	this->Li();
	counter = 0;
}

void Cube::correctEight(int &counter){
	bool found = false;
	int i = 0;
	while((!found) & (i < 6)){
		if(this->at(47) == this->getFColor()){
			if(this->at(15) == this->getRColor()){
				found = true;
			}
		}
		else{
			this->D();
			this->TurnCube();
		}
	}
	if(i == 6){
		this->printE("Error @ correctEight(counter).\nThe searched piece configuration does not seem to exist.\nPlease check work.");
	}
	this->Di();
	this->Ri();
	this->D();
	this->R();
	counter = 0;
}

int Cube::whiteCorners(){

	this->print();

	int corners[24] ={ 	 0,  2,  6,  8,		// front
		 									 9, 11, 15, 17,		// right
											18, 20, 24, 26,		// back
											27, 29, 33, 35,		// left
											36, 38, 42, 44,		// top
											45, 47, 51, 53 };	// bottom

	int counter = 0;
	while(counter < 24){
		//cout << "counter is " << counter << ".\n";
		if(this->at(corners[counter]) != 'w'){
			counter++;
		}

		// Integrate cube turns to "repeat" the position-based algorithm.
		//	This way, case 0 can be used to handle positions 1, 10, 19, and 28
		//	without any code rewrite. We'll simply turn the cube until those
		//	positions "become" case 0.
    if (counter < 16){
      int numToTurn = counter / 4;

      // reset the counter
      counter = counter % 4;

      for(int i = 0; i < numToTurn; i++)
        this->TurnCube();

    } // end if (counter < 16)

		switch(counter){
			case 0:{
				char oppositeEdge1 = this->at(42);
				char oppositeEdge2 = this->at(29);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 1:{
				char oppositeEdge1 = this->at(44);
				char oppositeEdge2 = this->at(9);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						this->Ri();
						this->D();
						this->R();
						this->Di();
						this->Ri();
						this->D();
						this->R();
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
			}
			case 2:{
				char oppositeEdge1 = this->at(45);
				char oppositeEdge2 = this->at(35);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 3:{
				char oppositeEdge1 = this->at(47);
				char oppositeEdge2 = this->at(15);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 16:{
				char oppositeEdge1 = this->at(20);
				char oppositeEdge2 = this->at(27);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 17:{
				char oppositeEdge1 = this->at(18);
				char oppositeEdge2 = this->at(11);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 18:{
				char oppositeEdge1 = this->at(0);
				char oppositeEdge2 = this->at(30);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 19:{
				char oppositeEdge1 = this->at(2);
				char oppositeEdge2 = this->at(9);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 20:{
				char oppositeEdge1 = this->at(6);
				char oppositeEdge2 = this->at(35);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 21:{
				char oppositeEdge1 = this->at(8);
				char oppositeEdge2 = this->at(15);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 22:{
				char oppositeEdge1 = this->at(26);
				char oppositeEdge2 = this->at(33);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			case 23:{
				char oppositeEdge1 = this->at(24);
				char oppositeEdge2 = this->at(17);

				if ((oppositeEdge1 == this->getFColor() ) ||
						(oppositeEdge2 == this->getFColor() ) ) {
					if(oppositeEdge1 == this->getRColor() ) {
						LOG("Implement oppositeEdge1 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getRColor() ){
						LOG("Implement oppositeEdge2 == this->getRColor()");
						return 0;
					}
					else if (oppositeEdge1 == this->getLColor() ){
						LOG("Implement oppositeEdge1 == this->getLColor()");
						return 0;
					}
					else if (oppositeEdge2 == this->getLColor() ){
						LOG("Implement oppositeEdge2 == this->getLColor()");
						return 0;
					}
					else{
						LOG("Could not find match");
						return 0;
					}
				}
				break;
			}
			default: {
				LOG("Could not find match");
				return 0;
			}
		} // end switch statement

		/*
		if((16 <= counter) & (counter <= 19)){
			if(counter == 16){
				if((this->at(27) == this->getLColor()) &
					(this->at(20) == this->getBColor()))
					counter++;
				else{
					this->Li();
					this->Di();
					this->Di();
					this->L();
					this->correctEight(counter);
				}
			}
			else if(counter == 17){
				if((this->at(11) == this->getRColor()) &
					(this->at(18) == this->getBColor()))
					counter++;
				else{
					this->R();
					this->Di();
					this->Di();
					this->Ri();
					this->correctSix(counter);
				}
			}
			else if(counter == 18){
				if((this->at(0) == this->getFColor()) &
					(this->at(29) == this->getLColor()))
					counter++;
				else{
					this->L();
					this->D();
					this->Li();
					this->Di();
					this->correctSix(counter);
				}
			}
			else if(counter == 19){
				if((this->at(2) == this->getFColor()) &
					(this->at(9) == this->getRColor()))
					counter++;
				else{
					this->Ri();
					this->Di();
					this->R();
					this->D();
					this->correctEight(counter);
				}
			}
		}
		else{
			switch(counter){
				case 0:
					this->Fi();
					this->D();
					this->D();
					this->F();
					this->Di();
					this->Di();
					this->correctSix(counter);
					break;
				case 1:
					this->F();
					this->D();
					this->Fi();
					this->Di();
					this->correctEight(counter);
					break;
				case 2:
					this->correctSix(counter);
					break;
				case 3:
					this->correctEight(counter);
					break;
				case 4:
					this->Ri();
					this->Di();
					this->R();
					this->correctSix(counter);
					break;
				case 5:
					this->R();
					this->Di();
					this->Di();
					this->Ri();
					this->D();
					this->correctEight(counter);
					break;
				case 6:
					this->Di();
					this->correctSix(counter);
					break;
				case 7:
					this->Di();
					this->correctEight(counter);
					break;
				case 8:
					this->Bi();
					this->Di();
					this->B();
					this->Di();
					this->correctSix(counter);
					break;
				case 9:
					this->B();
					this->D();
					this->Bi();
					this->D();
					this->correctEight(counter);
					break;
				case 10:
					this->Di();
					this->Di();
					this->correctSix(counter);
					break;
				case 11:
					this->Di();
					this->Di();
					this->correctEight(counter);
					break;
				case 12:
					this->Li();
					this->D();
					this->D();
					this->L();
					this->Di();
					this->correctSix(counter);
					break;
				case 13:
					this->L();
					this->D();
					this->Li();
					this->correctEight(counter);
					break;
				case 14:
					this->D();
					this->correctSix(counter);
					break;
				case 15:
					this->D();
					this->correctEight(counter);
					break;
				case 20:
					this->Li();
					this->Fi();
					this->D();
					this->D();
					this->F();
					this->L();
					this->Di();
					this->Di();
					this->correctSix(counter);
					break;
				case 21:
					this->R();
					this->F();
					this->D();
					this->D();
					this->Fi();
					this->Ri();
					this->Di();
					this->Di();
					this->correctEight(counter);
					break;
				case 22:
					this->D();
					this->Li();
					this->Fi();
					this->D();
					this->D();
					this->F();
					this->L();
					this->Di();
					this->Di();
					this->correctSix(counter);
					break;
				case 23:
					this->Di();
					this->R();
					this->F();
					this->D();
					this->D();
					this->Fi();
					this->Ri();
					this->D();
					this->D();
					this->correctEight(counter);
					break;
				default:
					cout << "Hit default case in whiteCorners().\n";
					break;
			}
		} */
	}
	instruction.push_back("WhiteCorners");
	return 1;
}

void Cube::middle_fallLeft(){
	this->Ui();
	this->Li();
	this->U();
	this->L();
	this->U();
	this->F();
	this->Ui();
	this->Fi();
}

void Cube::middle_fallRight(){
	this->U();
	this->R();
	this->Ui();
	this->Ri();
	this->Ui();
	this->Fi();
	this->U();
	this->F();
}

void Cube::middleLayer(){
	this->RollCube();
	this->RollCube();
	bool complete = false;
	while(!complete){
		if((this->at(3) == this->getFColor()) & (this->at(5) == this->getFColor()) &
		(this->at(12) == this->getRColor()) & (this->at(14) == this->getRColor()) &
		(this->at(21) == this->getBColor()) & (this->at(23) == this->getBColor()) &
		(this->at(30) == this->getLColor()) & (this->at(32) == this->getLColor())){
			instruction.push_back("Middle");
			complete = true;
		}
		else{
			int situation = -1;
			bool notAlignedZero = false;
			bool notAlignedOne = false;
			bool notAlignedTwo = false;
			bool notAlignedThree = false;
			bool allYellowSides = false;


			if((this->at(1) != 'y') & (this->at(43) != 'y'))
				situation = 0;
			else if((this->at(10) != 'y') & (this->at(41) != 'y'))
				situation = 1;
			else if((this->at(19) != 'y') & (this->at(37) != 'y'))
				situation = 2;
			else if((this->at(28) != 'y') & (this->at(39) != 'y'))
				situation = 3;
			else
				situation = 4;

			switch(situation){
				case 0:
					notAlignedZero = true;
					while(notAlignedZero){
						if(this->at(1) == this->getFColor())
							notAlignedZero = false;
						else{
							this->Ui();
							this->TurnCube();
						}
					}
					if(this->at(43) == this->getRColor())
						this->middle_fallRight();
					else
						this->middle_fallLeft();
					break;
				case 1:
					this->TurnCube();
					notAlignedOne = true;
					while(notAlignedOne){
						if(this->at(1) == this->getFColor())
							notAlignedOne = false;
						else{
							this->Ui();
							this->TurnCube();
						}
					}
					if(this->at(43) == this->getRColor())
						this->middle_fallRight();

					else
						this->middle_fallLeft();
					break;
				case 2:
					this->TurnCube();
					this->TurnCube();
					notAlignedTwo = true;
					while(notAlignedTwo){
						if(this->at(1) == this->getFColor())
							notAlignedTwo = false;
						else{
							this->Ui();
							this->TurnCube();
						}
					}
					if(this->at(43) == this->getRColor())
						this->middle_fallRight();

					else
						this->middle_fallLeft();
					break;
				case 3:
					this->TurnCube();
					this->TurnCube();
					this->TurnCube();
					notAlignedThree = true;
					while(notAlignedThree){
						if(this->at(1) == this->getFColor())
							notAlignedThree = false;
						else{
							this->Ui();
							this->TurnCube();
						}
					}
					if(this->at(43) == this->getRColor())
						this->middle_fallRight();
					else
						this->middle_fallLeft();
					break;
				case 4:
					allYellowSides = false;
					if((this->at(1) == 'y') & (this->at(10) == 'y') &
						(this->at(19) == 'y') & (this->at(28) == 'y'))
							allYellowSides = true;
					if(allYellowSides){
						bool wrongSide = true;
						while(wrongSide){
							if(this->at(43) != this->at(4)){
								this->Ui();
								this->TurnCube();
							}
							else
								wrongSide = false;
						}

						if(this->at(3) != this->at(4)){
							this->TurnCube();
							this->TurnCube();
							this->TurnCube();
							this->U();
							this->middle_fallRight();
						}
						else{
							this->TurnCube();
							this->Ui();
							this->middle_fallLeft();
						}
					}
					else{
						while(this->at(1) == 'y')
							this->U();
						while(this->at(1) != this->at(4)){
							this->Ui();
							this->TurnCube();
						}
						if(this->at(3) != this->at(4))
							this->middle_fallLeft();
						else
							this->middle_fallRight();
					}
					break;
				default:
					this->printE("Hit default case in Middle Layer switch statement");
			}
		}
		}
		}

void Cube::yellowCross(){
	LOG("Beginning function");
	bool completed = false;
	while(!completed){
		if((this->at(37) == 'y') & (this->at(39) == 'y') &
		(this->at(41) == 'y') & (this->at(43) == 'y')){
			completed = true;
			instruction.push_back("YellowCross");
			return;
		}
		else{
			bool onlyCenter = true;
			for(int i = 0; i < 4; i++){
				if((this->at(39) == 'y') & (this->at(41) == 'y')){
					onlyCenter = false;
					this->F();
					this->R();
					this->U();
					this->Ri();
					this->Ui();
					this->Fi();
					break;
				}
				else if((this->at(37) == 'y') & (this->at(39) == 'y')){
					onlyCenter = false;
					this->F();
					this->U();
					this->R();
					this->Ui();
					this->Ri();
					this->Fi();
					break;
				}
				else
					this->U();
			}
			if(onlyCenter){
				this->F();
				this->U();
				this->R();
				this->Ui();
				this->Ri();
				this->Fi();
			}
		}
	}
}

void Cube::yellowCrossSequence(){
	LOG("Beginning Function");
	this->R();
	this->U();
	this->Ri();
	this->U();
	this->R();
	this->U();
	this->U();
	this->Ri();

}

void Cube::yellowCorners(){
	int numCorners = 0;
	while(numCorners != 4){
		numCorners = 0;
		if(this->at(36) == 'y')
			numCorners++;
		if(this->at(38) == 'y')
			numCorners++;
		if(this->at(42) == 'y')
			numCorners++;
		if(this->at(44) == 'y')
			numCorners++;

		if(numCorners == 0){
			while(this->at(29) != 'y')
				this->U();
			this->yellowCrossSequence();
		}
		else if(numCorners == 1){
			while(this->at(42) != 'y')
				this->U();
			this->yellowCrossSequence();
		}
		else if(numCorners == 2){
			while(this->at(0) != 'y')
				this->U();
			this->yellowCrossSequence();
		}
		else{
			instruction.push_back("YellowCorners");
			return;
		}
	}
}

void Cube::lLayer_cornerSequence(){
	if(this->at(0) == this->at(4))
		if(this->at(9) == this->at(13))
			if(this->at(18) == this->at(21))
				if(this->at(27) == this->at(30))
					return;
	this->Ri();
	this->F();
	this->Ri();
	this->B();
	this->B();
	this->R();
	this->Fi();
	this->Ri();
	this->B();
	this->B();
	this->R();
	this->R();
	this->Ui();
}

void Cube::lLayer_corners(){
	int situation = 0;
	if(this->at(0) == this->at(2))
		situation = 0;
	else if(this->at(9) == this->at(11))
		situation = 1;
	else if(this->at(18) == this->at(20))
		situation = 2;
	else if(this->at(27) == this->at(29))
		situation = 3;
	else
		situation = 4;

	if(situation == 0){
		while(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lLayer_cornerSequence();
		instruction.push_back("LLC");
		return;
	}
	else if(situation == 1){
		this->TurnCube();
		while(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lLayer_cornerSequence();
		instruction.push_back("LLC");
		return;
	}
	else if(situation == 2){
		this->TurnCube();
		this->TurnCube();
		while(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lLayer_cornerSequence();
		instruction.push_back("LLC");
		return;
	}
	else if(situation == 3){
		this->TurnCube();
		this->TurnCube();
		this->TurnCube();
		while(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lLayer_cornerSequence();
		instruction.push_back("LLC");
		return;
	}
	else{
		while(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lLayer_cornerSequence();
		this->lLayer_corners();
	}
}

void Cube::lLayer_topSequenceClock(){
	this->F();
	this->F();
	this->U();
	this->L();
	this->Ri();
	this->F();
	this->F();
	this->Li();
	this->R();
	this->U();
	this->F();
	this->F();
}

void Cube::lLayer_topSequenceCounter(){
	this->F();
	this->F();
	this->Ui();
	this->L();
	this->Ri();
	this->F();
	this->F();
	this->Li();
	this->R();
	this->Ui();
	this->F();
	this->F();
}

void Cube::lLayer_topEdges(){
	int i = 0;
	bool completed = false;
	if(this->at(1) == this->at(4))
		if(this->at(10) == this->at(13))
			if(this->at(19) == this->at(21))
				if(this->at(28) == this->at(29))
					return;

	while(!completed){
		i = 0;
		while((this->at(19) != this->getBColor()) & (i < 4)){
			this->TurnCube();
			i++;
		}
		if(i == 4){
			this->lLayer_topSequenceClock();
		}
		else{
			if(this->at(1) == this->getLColor()){
				this->lLayer_topSequenceClock();
				instruction.push_back("DONE");
				completed = true;
			}
			else if(this->at(1) == this->getRColor()){
				this->lLayer_topSequenceCounter();
				instruction.push_back("DONE");
				completed = true;
			}
		}
	}
}

void Cube::optimizeData(){
	for(int i = 0; i < instruction.size(); i++){
		if(instruction[i] == "F"){
			if(instruction[i+1] == "Fi")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "Fi"){
			if(instruction[i+1] == "F")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "R"){
			if(instruction[i+1] == "Ri")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "Ri"){
			if(instruction[i+1] == "R")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "B"){
			if(instruction[i+1] == "Bi")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "Bi"){
			if(instruction[i+1] == "B")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "L"){
			if(instruction[i+1] == "Li")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "Li"){
			if(instruction[i+1] == "L")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "U"){
			if(instruction[i+1] == "Ui")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "Ui"){
			if(instruction[i+1] == "U")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "D"){
			if(instruction[i+1] == "Di")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "Di"){
			if(instruction[i+1] == "D")
				instruction.erase(instruction.begin()+i, instruction.begin()+i+1);
		}
		else if(instruction[i] == "TC"){
			int j = i;
			int k = 1;
			while(instruction[j] == "TC"){
				j++;
				k++;
			}
			if(k == 3){
				instruction[i] = "TCi";
				instruction.erase(instruction.begin()+i+1, instruction.begin()+i+2);
			}
			else if(k >= 4){
				int num = k/4;
				num = num*4;
				instruction.erase(instruction.begin()+i, instruction.begin()+i+num);
			}
		}
	}
}


//	This function reads in the elements of the instruction vector and translates
//		the messages into more human readable messages (for step by step
//		instructions.)
void Cube::parseResult(){
	for(int i = 0; i < instruction.size(); i++){
		if(instruction[i] == "F")
			cout << "Rotate the front face 90° clockwise.\n";
		else if(instruction[i] == "Fi")
			cout << "Rotate the front face 90° counterclockwise.\n";
		else if(instruction[i] == "R")
			cout << "Rotate the right face 90° clockwise.\n";
		else if(instruction[i] == "Ri")
			cout << "Rotate the right face 90° counterclockwise.\n";
		else if(instruction[i] == "B")
			cout << "Rotate the back face 90° clockwise.\n";
		else if(instruction[i] == "Bi")
			cout << "Rotate the back face 90° counterclockwise.\n";
		else if(instruction[i] == "L")
			cout << "Rotate the left face 90° clockwise.\n";
		else if(instruction[i] == "Li")
			cout << "Rotate the left face 90° counterclockwise.\n";
		else if(instruction[i] == "U")
			cout << "Rotate the top face 90° clockwise.\n";
		else if(instruction[i] == "Ui")
			cout << "Rotate the top face 90° counterclockwise.\n";
		else if(instruction[i] == "D")
			cout << "Rotate the bottom face 90° clockwise.\n";
		else if(instruction[i] == "Di")
			cout << "Rotate the bottom face 90° counterclockwise.\n";
		else if(instruction[i] == "OC")
			cout << "Orient the Cube.\nMake sure white is up and blue is front.\n";
		else if(instruction[i] == "TC")
			cout << "Keeping the same top color, turn the whole cube 90° clockwise.\n";
		else if(instruction[i] == "TCi")
			cout << "Keeping the same top color, turn the whole cube 90° counterclockwise.\n";
		else if(instruction[i] == "RC")
			cout << "Keeping the same front color, roll the whole cube 90° clockwise.\n";
		else if(instruction[i] == "WhiteCross")
			cout << "\nWhite Cross should be done.\n\n";
		else if(instruction[i] == "WhiteCorners")
			cout << "\nWhite Corners should be done.\n\n";
		else if(instruction[i] == "Middle")
			cout << "\nMiddle Layer should be done.\n\n";
		else if(instruction[i] == "YellowCross")
			cout << "\nYellow Cross should be done.\n\n";
		else if(instruction[i] == "YellowCorners")
			cout << "\nYellow Corners should be done.\n\n";
		else if(instruction[i] == "LLC")
			cout << "\nLast Layer corners should be done.\n\n";
		else if(instruction[i] == "DONE")
			cout << "\nCongratulations. Should be done.\n\n";
		else
			cout << "\n\nMYSTERY\n" << instruction[i] << "\n\n";
	}

	cout << "Number of Instructions: " << instruction.size() << ".\n";

}


// This method was very good for terminal debugging. Prints out a large
//		display and the 'error message' string parameter.
void Cube::printE(string error_message){
	cout << "\n\n******************************************************\n";
	cout <<  "\tERROR FOUND\t";
	cout << "\n";
	cout << error_message << "\n";
	cout << "\n******************************************************\n\n";
}
