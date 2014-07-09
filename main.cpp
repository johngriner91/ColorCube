#include <fstream>
#include "cube.h"
#include "cube.cc"

int main(){

	char cube[54]; 
	char temp;
	int index = 0;

	ifstream inputFile;
	inputFile.open("cubeStart.txt");
	for(int i = 0; i < 1; i++){
		for(int j = 0; j < 54; j++){
			inputFile >> temp;
			cube[j] = temp;
		}
		cout << "\nCube #" << i+1 << ".\n";
		Cube puzzle(cube);
		puzzle.orient();	
		puzzle.whiteCross();
		puzzle.whiteCorners();
		puzzle.orient();
		puzzle.middleLayer();
		puzzle.yellowCross();
		puzzle.yellowCorners();
		puzzle.lastLayer_corners();
		puzzle.lastLayer_topEdges();
		puzzle.print();
		puzzle.removeRedundancy();
		cout << "\n\nInstructions\n---------------------\n";
		puzzle.parseResult();
	}
	inputFile.close();
	return 0;
}