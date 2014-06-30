#include <fstream>
#include "cube.h"
#include "cube.cc"

int main(){

	char cube[54]; 
	char temp;
	int index = 0;

	ifstream inputFile;
	inputFile.open("cubeStart.txt");		
	inputFile >> temp;
	
	while(inputFile){
		cube[index] = temp;
		index++;
		inputFile >> temp;
	}
	
	Cube puzzle(cube);
	puzzle.orient();	
	puzzle.whiteCross();
	
	cout << "At this point, you should have the \"white cross\" and the "
		<< "correct colors going from the cross to the middle of each side.\n";
		
	puzzle.whiteCorners();
	puzzle.print();
	puzzle.orient();
	puzzle.print();
	puzzle.middleLayer();
	puzzle.print();
	puzzle.yellowCross();
	puzzle.print();
	//puzzle.yellowCorners();
	//puzzle.print();
	//puzzle.lastLayer_corners();
	//puzzle.print();
	//puzzle.lastLayer_topEdges();
	//puzzle.print();
	return 0;
}