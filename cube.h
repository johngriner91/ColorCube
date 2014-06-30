#include <iostream>
#include <string>

using namespace std;

class Cube{
	public:
		Cube(char array[54]);
		void print();
		char at(int);
		int edgeOf(int);
		void orient();
		void whiteCross();
		void whiteCorners();
		char getFColor();
		char getRColor();
		char getBColor();
		char getLColor();
		char getUColor();
		char getDColor();
		void correctSix(int&);
		void correctEight(int&);
		void printE(string);
		void middle_fallLeft();
		void middle_fallRight();
		void middleLayer();
		void yellowCross();
		void yellowCrossSequence();
		void yellowCorners();
		void lastLayer_cornerSequence();
		void lastLayer_corners();
		void lastLayer_topSequenceClock();
		void lastLayer_topSequenceCounter();
		void lastLayer_topEdges();
	private:
		char cubeValues[54];
		void R();
		void Ri();
		void L();
		void Li();
		void B();
		void Bi();
		void D();
		void Di();
		void F();
		void Fi();
		void U();
		void Ui();
		void TurnCube();
		void RollCube();
		void UpsideDownCube();
};