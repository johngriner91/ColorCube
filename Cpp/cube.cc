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

// Used to cleanly print log messages
void logError (int lineNumber, string function, const std::string& message){
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

  if ( FAIL == this->checkInputs() ){
    printE("Terminating from checkInput()");
    return;
  }

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

  if ( FAIL == this->middleLayer() ){
		printE("Terminating from middleLayer()");
		return;
	}

  //	At this point, the middle layer is complete
  if ( FAIL == this->yellowCross() ){
		printE("Terminating from yellowCross()");
		return;
	}

  //	At this point, the middle layer is complete
  if ( FAIL == this->yellowCorners() ){
		printE("Terminating from yellowCorners()");
		return;
	}

	//	At this point, the yellow layer is complete

  if ( FAIL == this->lLayer_corners() ){
    printE("Terminating from lLayer_corners()");
    return;
  }

  if ( FAIL == this->lLayer_topEdges() ){
    printE("Terminating from lLayer_corners()");
    return;
  }

	//	At this point, the cube is completed
  LOG("At this point, the cube is completed");

	this->print();
	this->optimizeData();

	//	The optimized solution is provided to the user
	//this->parseResult();
}

// Make sure that you didn't type anything in wrong
int Cube::checkInputs(){
	// Read in the colors of the cube.
	LOG("Checking Inputs");
  int checkBlue = 0;
  int checkOrange = 0;
  int checkGreen = 0;
  int checkRed = 0;
  int checkWhite = 0;
  int checkYellow = 0;

  char color;

  for(int i = 0; i < 54; i++){
    color = this->at(i);
    if(color == 'b')
      checkBlue++;
    else if(color == 'o')
      checkOrange++;
    else if(color == 'g')
      checkGreen++;
    else if(color == 'r')
      checkRed++;
    else if(color == 'w')
      checkWhite++;
    else if(color == 'y')
      checkYellow++;
    else{
      LOG("Found an unknown color");
      return FAIL;
    }
  }

  if( (checkBlue == 9) &&
      (checkOrange == 9) &&
      (checkGreen == 9) &&
      (checkRed == 9) &&
      (checkWhite == 9) &&
      (checkYellow == 9) ) {
        LOG("Input is valid");
        return PASS;
      }
      else{
        LOG("Invalid number of colors");
        return FAIL;
      }

}

// This method prints out the cube faces in a grid format. Prints in the
// following format.
void Cube::print(){
	cout << "\n\nPrinting the cubeValues\n-----------------";

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
  cout << endl << endl;
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
		LOG("The cube has been oriented.");

}	// End of Cube::orient()

// Make turns to fix the white cross
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
  while (counter < 24){

    // We haven't found a white piece yet
    while(this->at(edges[counter]) != 'w'){
      counter++;

      if(counter >= 24){
        LOG("Reached the end");
        return PASS;
      }
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
          this->Fi();
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
        char oppositeEdge = this->at(28);
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

    std:string msg = "Fixed white piece at " + to_string(edges[counter]);
    LOG(msg);

    if (startOver) {
      counter = 0;

      // reset the flag
      startOver = true;
    }
		else{
			// Move on, this is supposed to be white
			counter++;
		}

    numTurns++;
    if (numTurns > 20){
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

// Make turns to fix the white corners
int Cube::whiteCorners(){

	LOG("Beginning function");

	int corners[24] ={ 	 0,  2,  6,  8,		// front
		 									 9, 11, 15, 17,		// right
											18, 20, 24, 26,		// back
											27, 29, 33, 35,		// left
											36, 38, 42, 44,		// top
											45, 47, 51, 53 };	// bottom

	int counter = 0;
  int numTurns = 0;
  bool startOver = true;

  // Until we've looked at and approved all the pieces, keep looking
  while (counter < 24){

    // We haven't found a white piece yet
    while(this->at(corners[counter]) != 'w'){
      counter++;

      if(counter >= 24){
        LOG("Reached the end");
        return PASS;
      }
    }

    std::string msg2 = "Found white at position "+to_string(corners[counter]);
    LOG(msg2);

		// Integrate cube turns to "repeat" the position-based algorithm.
		//	This way, case 0 can be used to handle positions 0, 9, 18, and 27
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
				if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->Fi();
                   this->Di();
                   this->F();
                   this->F();
                   this->Di();
                   this->Di();
                   this->Fi();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->Fi();
                   this->Di();
                   this->R();
                   this->Di();
                   this->Ri();
                   this->F();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->Fi();
                   this->B();
                   this->Di();
                   this->Bi();
                   this->F();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->L();
                   this->Di();
                   this->Li();
                   this->D();
                   this->L();
                   this->Di();
                   this->Li();
        }
        LOG("Fixed white corner in case 0");
        break;
      }
			case 1:{
				char oppositeEdge1 = this->at(44);
				char oppositeEdge2 = this->at(9);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->Ri();
                   this->D();
                   this->R();
                   this->Di();
                   this->Ri();
                   this->D();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->F();
                   this->Bi();
                   this->D();
                   this->Fi();
                   this->B();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->F();
                   this->D();
                   this->Fi();
                   this->Li();
                   this->D();
                   this->L();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->F();
                   this->Di();
                   this->Di();
                   this->Fi();
                   this->Fi();
                   this->D();
                   this->F();
        }
        LOG("Fixed white corner in case 1");
        break;
      }
			case 2:{
				char oppositeEdge1 = this->at(45);
				char oppositeEdge2 = this->at(35);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->D();
                   this->Ri();
                   this->Di();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->Di();
                   this->R();
                   this->Di();
                   this->Ri();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->B();
                   this->Di();
                   this->Bi();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->D();
                   this->L();
                   this->Di();
                   this->Li();
        }
        LOG("Fixed white corner in case 2");
        break;
      }
			case 3:{
				char oppositeEdge1 = this->at(47);
				char oppositeEdge2 = this->at(15);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->Di();
                   this->Ri();
                   this->D();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->Bi();
                   this->D();
                   this->B();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->Li();
                   this->Di();
                   this->Di();
                   this->L();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->Di();
                   this->L();
                   this->D();
                   this->Li();
        }
        LOG("Fixed white corner in case 3");
        break;
      }
			case 16:{
				char oppositeEdge1 = this->at(20);
				char oppositeEdge2 = this->at(27);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->Li();
                   this->Di();
                   this->L();
                   this->Di();
                   this->Di();
                   this->Ri();
                   this->D();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->Li();
                   this->Di();
                   this->L();
                   this->Di();
                   this->Bi();
                   this->D();
                   this->B();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){

          // This one is supposed to be white, and the colors match
          LOG("CASE 16: Supposed to be white");
          startOver = false;
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->B();
                   this->D();
                   this->Bi();
                   this->D();
                   this->L();
                   this->Di();
                   this->Li();
        }
        LOG("Fixed white corner in case 16");
        break;
      }
			case 17:{
				char oppositeEdge1 = this->at(18);
				char oppositeEdge2 = this->at(11);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->R();
                   this->Di();
                   this->Ri();
                   this->Di();
                   this->Di();
                   this->Ri();
                   this->D();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){

          // This one is supposed to be white, and the colors match
          LOG("CASE 17: Supposed to be white");
          startOver = false;
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->Bi();
                   this->Di();
                   this->B();
                   this->Li();
                   this->Di();
                   this->Di();
                   this->L();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->R();
                   this->D();
                   this->Ri();
                   this->D();
                   this->D();
                   this->L();
                   this->Di();
                   this->Li();
        }
        LOG("Fixed white corner in case 17");
        break;
      }
			case 18:{
				char oppositeEdge1 = this->at(0);
				char oppositeEdge2 = this->at(29);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->L();
                   this->D();
                   this->Li();
                   this->Ri();
                   this->Di();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->L();
                   this->R();
                   this->Di();
                   this->Di();
                   this->Li();
                   this->Ri();

        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->L();
                   this->D();
                   this->Li();
                   this->B();
                   this->Di();
                   this->Di();
                   this->Bi();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){

          // This one is supposed to be white, and the colors match
          LOG("CASE 18: Supposed to be white");
          startOver = false;
        }
        LOG("Fixed white corner in case 18");
        break;
      }
			case 19:{
				char oppositeEdge1 = this->at(2);
				char oppositeEdge2 = this->at(9);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){

          // This one is supposed to be white, and the colors match
          LOG("CASE 19: Supposed to be white");
          startOver = false;
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->Ri();
                   this->Di();
                   this->R();
                   this->Bi();
                   this->Di();
                   this->Di();
                   this->B();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->Ri();
                   this->Li();
                   this->Di();
                   this->Di();
                   this->L();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->Ri();
                   this->Di();
                   this->R();
                   this->L();
                   this->D();
                   this->Li();
        }
        LOG("Fixed white corner in case 19");
        break;
      }
			case 20:{
				char oppositeEdge1 = this->at(6);
				char oppositeEdge2 = this->at(35);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->D();
                   this->F();
                   this->Di();
                   this->Fi();
                   this->D();
                   this->Ri();
                   this->D();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->Di();
                   this->Di();
                   this->Bi();
                   this->D();
                   this->B();
                   this->Di();
                   this->R();
                   this->Di();
                   this->Ri();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->Li();
                   this->D();
                   this->L();
                   this->B();
                   this->Di();
                   this->Di();
                   this->Bi();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->Fi();
                   this->D();
                   this->F();
                   this->L();
                   this->Di();
                   this->Di();
                   this->Li();
        }
        LOG("Fixed white corner in case 20");
        break;
      }
			case 21:{
				char oppositeEdge1 = this->at(8);
				char oppositeEdge2 = this->at(15);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->F();
                   this->Di();
                   this->Fi();
                   this->Ri();
                   this->Di();
                   this->Di();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->D();
                   this->Bi();
                   this->Di();
                   this->Di();
                   this->B();
                   this->D();
                   this->Bi();
                   this->Di();
                   this->B();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->Di();
                   this->B();
                   this->Di();
                   this->Bi();
                   this->Li();
                   this->Di();
                   this->L();
                   this->Di();
                   this->Di();
                   this->B();
                   this->Di();
                   this->Bi();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->Di();
                   this->Fi();
                   this->D();
                   this->F();
                   this->L();
                   this->Di();
                   this->Di();
                   this->Li();
        }
        LOG("Fixed white corner in case 21");
        break;
      }
			case 22:{
				char oppositeEdge1 = this->at(26);
				char oppositeEdge2 = this->at(33);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->Di();
                   this->Di();
                   this->Ri();
                   this->Di();
                   this->Di();
                   this->R();
                   this->D();
                   this->Ri();
                   this->Di();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->Di();
                   this->R();
                   this->Di();
                   this->Ri();
                   this->D();
                   this->Bi();
                   this->D();
                   this->B();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->Li();
                   this->D();
                   this->L();
                   this->B();
                   this->Di();
                   this->Di();
                   this->Bi();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->D();
                   this->L();
                   this->Di();
                   this->L();
                   this->Fi();
                   this->Di();
                   this->Di();
                   this->F();
        }
        LOG("Fixed white corner in case 22");
        break;
      }
			case 23:{
				char oppositeEdge1 = this->at(24);
				char oppositeEdge2 = this->at(17);

        if      (((oppositeEdge1 == this->getFColor() ) ||
						     (oppositeEdge2 == this->getFColor() )) &&
                 ((oppositeEdge1 == this->getRColor() ) ||
                 (oppositeEdge2 == this->getRColor() ))){
                   this->Di();
                   this->F();
                   this->Di();
                   this->Di();
                   this->Fi();
                   this->Di();
                   this->Di();
                   this->Ri();
                   this->D();
                   this->R();
        }
        else if (((oppositeEdge1 == this->getRColor() ) ||
						     (oppositeEdge2 == this->getRColor() )) &&
                 ((oppositeEdge1 == this->getBColor() ) ||
                 (oppositeEdge2 == this->getBColor() ))){
                   this->R();
                   this->Di();
                   this->Ri();
                   this->Bi();
                   this->Di();
                   this->Di();
                   this->B();
        }
        else if (((oppositeEdge1 == this->getBColor() ) ||
						     (oppositeEdge2 == this->getBColor() )) &&
                 ((oppositeEdge1 == this->getLColor() ) ||
                 (oppositeEdge2 == this->getLColor() ))){
                   this->D();
                   this->Li();
                   this->D();
                   this->L();
                   this->B();
                   this->D();
                   this->D();
                   this->Bi();
        }
        else if (((oppositeEdge1 == this->getLColor() ) ||
						     (oppositeEdge2 == this->getLColor() )) &&
                 ((oppositeEdge1 == this->getFColor() ) ||
                 (oppositeEdge2 == this->getFColor() ))){
                   this->Di();
                   this->Di();
                   this->L();
                   this->Di();
                   this->Li();
                   this->Fi();
                   this->Di();
                   this->Di();
                   this->F();
        }
        LOG("Fixed white corner in case 23");
        break;
      }
			default: {
				LOG("Default case statement : Could not find match");
				return FAIL;
			}
		} // end switch statement

    if (startOver){
      // Could have accidentally messed up previously analyzed corner. Recheck
      counter = 0;
    }
    else{
      counter++;

      // Reset flag
      startOver = true;
    }

    // Make sure we're not spiraling into a black hole of death
    numTurns++;
    if (numTurns > 20){
      LOG("Reached 20 moves. Must debug before moving on");
      return FAIL;
    }
	}
	LOG("Returning sucessfully");
	return PASS;
}

// Sequence used in fixing middle layer
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

// Sequence used in fixing middle layer
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

// Make turns to fix middle layer
int Cube::middleLayer(){

  LOG("Beginning function");

  bool complete = false;

  // Turn the white side down, as per Rubik's solution
	this->RollCube();
	this->RollCube();

	while( !complete ){
    // If the middle layer is completed,
		if( (this->at(3) == this->getFColor()) &
        (this->at(5) == this->getFColor()) &
		    (this->at(12) == this->getRColor()) &
        (this->at(14) == this->getRColor()) &
		    (this->at(21) == this->getBColor()) &
        (this->at(23) == this->getBColor()) &
		    (this->at(30) == this->getLColor()) &
        (this->at(32) == this->getLColor()) ){

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

      // In order to fix the middle layer, we need to see which piece needs to
      //  fall down to the sides.
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

      // Situations 0-3 mean that a side was found that didn't have a
      //  yellow piece on the "fall down" side. Situation 4 is the situation
      //  that all the pieces had a yellow face.

      // Based on the situation,
      std::string msg = "Situation " + to_string(situation) + " determined";
      LOG(msg);

      // Depending on the situation, make the appropriate turns
			switch(situation){
				case 0:{
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
        }
				case 1:{
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
        }
				case 2:{
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
        }
				case 3:{
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
        }

        // SPECIAL CASE: Each side had yellow
				case 4:{
					allYellowSides = false;
					if((this->at(1) == 'y') & (this->at(10) == 'y') &
						(this->at(19) == 'y') & (this->at(28) == 'y'))
							allYellowSides = true;

          // All sides are yellow
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
          // Not all sides are yellow
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
        }
				default:
					this->printE("Hit default case in Middle Layer switch statement");
			}
		}
	}

  LOG("Returning sucessfully");
  return PASS;
}

// Make turns to fix the yellow cross
int Cube::yellowCross(){
	LOG("Beginning function");
	bool completed = false;

	while(!completed){
    // At this point, the yellow cross is completed
		if( (this->at(37) == 'y') &
        (this->at(39) == 'y') &
		    (this->at(41) == 'y') &
        (this->at(43) == 'y') ){

			instruction.push_back("YellowCross");
      LOG("Returning Sucessfully from completed point");
      return PASS;
		}

    // Need to keep going
		else{
			bool onlyCenter = true;

      LOG("Fixing the yellow cross pieces");

			for(int i = 0; i < 4; i++){

        // Specific sequence for the yellow "Line"
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
        // Specific sequence for the yellow "U"
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
      //  Only the center piece is yellow, specific sequence
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
  LOG("Did not return from expected place. Debug");
  return FAIL;
}

// Make turns used in yellow cross
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
  LOG("Returning Sucessfully");
}

// Make turns to fix the yellow corners
int Cube::yellowCorners(){

  LOG("Beginning Function");

  int numCorners = 0;

  while(numCorners != 4){

    numCorners = 0;

    // Determine how many corners are set
		if(this->at(36) == 'y')
			numCorners++;
		if(this->at(38) == 'y')
			numCorners++;
		if(this->at(42) == 'y')
			numCorners++;
		if(this->at(44) == 'y')
			numCorners++;

    // What to do?.....
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
    // Otherwise, we are assuming things worked out fine
		else{
			instruction.push_back("YellowCorners");
      LOG("Returning Successfully");
			return PASS;
		}
	}

  LOG("Exiting function from unexpected point");
  return FAIL;
}

// Make turns used in lLayer_corners()
void Cube::lLayer_cornerSequence(){
	if(this->at(0) == this->at(4))
		if(this->at(9) == this->at(13))
			if(this->at(18) == this->at(21))
				if(this->at(27) == this->at(30)){
					return;
        }
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

// Make turns to fix the last layer corners
int Cube::lLayer_corners(){
  LOG("Beginning function");

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

  std::string msg = "Situation is " + to_string(situation);
  LOG(msg);

  // Depending on the situation, make the appropriate turns
	if(situation == 0){
		while(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lLayer_cornerSequence();
		instruction.push_back("LLC");
    LOG("Returning successfully");
		return PASS;
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
    LOG("Returning successfully");
		return PASS;
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
    LOG("Returning successfully");
		return PASS;
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
    LOG("Returning successfully");
		return PASS;
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
    LOG("Returning successfully");
		return PASS;
	}
  LOG("Exiting function from unexpected place");
  return FAIL;
}

// Make turns used in last layer
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

// Make turns used in lasy layer
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

// Make turns to fix the last layer center edges
int Cube::lLayer_topEdges(){
	int i = 0;

	bool completed = false;

  // Check to see if the last layer center edges are set
  if(this->at(1) == this->at(4))
		if(this->at(10) == this->at(13))
			if(this->at(19) == this->at(21))
				if(this->at(28) == this->at(29)){
					LOG("Returning successfully");
          return PASS;
        }

  // Not completed, make the appropriate turns
	while(!completed){
		i = 0;

    // Make sure the back edge is the solid side
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
        LOG("Returning successfully");
        return PASS;
			}
			else if(this->at(1) == this->getRColor()){
				this->lLayer_topSequenceCounter();
				instruction.push_back("DONE");
				completed = true;
        LOG("Returning successfully");
        return PASS;
			}
		}
	}
  LOG("Exiting function from unexpected place");
  return FAIL;
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
