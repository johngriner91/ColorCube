#include <fstream>
#include "cube.h"
#include "cube.cc"

int main(){

	char cube[54]; 
	char temp;
	int index = 0;

	ifstream inputFile;
	ofstream outFile;
	string out = "output.txt";
	inputFile.open("cubeStart.txt");
	for(int i = 0; i < 1; i++){
		for(int j = 0; j < 54; j++){
			inputFile >> temp;
			cube[j] = temp;
		}
		cout << "\nCube #: " << i+1 << ".\n";
		for(int k = 0; k < 54; k++){
			cout << cube[k] << " ";
		}
		Cube puzzle(cube, out);
		puzzle.orient();	
		puzzle.whiteCross();
		puzzle.whiteCorners();
		puzzle.orient();
		puzzle.middleLayer();
		puzzle.yellowCross();
		puzzle.yellowCorners();
		puzzle.lastLayer_corners();
		puzzle.lastLayer_topEdges();
		cout << "Printing out cube number " << i+1 << ".\n";
		puzzle.print();
		puzzle.parseResult();
	}
	inputFile.close();
	return 0;
}