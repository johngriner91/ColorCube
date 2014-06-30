#include <iostream>
using namespace std;

Cube::Cube(char array[54]){
	for(int i = 0; i < 54; i++)
		cubeValues[i] = array[i];
}

void Cube::printE(string a){
	cout << "\n\n******************************************************\n";
	cout <<     "			ERROR FOUND			   ";
	cout << "\n";
	cout << a << "\n";
	cout << "\n******************************************************\n\n";
}

void Cube::print(){
	cout << "Printing the cubeValues\n-----------------";
	cout << "\n\nFront\n-------\n";
	for(int i = 0; i < 9; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}
	cout << "\n\nRight\n-------\n";
	for(int i = 9; i < 18; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}
	cout << "\n\nBack\n-------\n";
	for(int i = 18; i < 27; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}
	cout << "\n\nLeft\n-------\n";
	for(int i = 27; i < 36; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}
	cout << "\n\nTop\n-------\n";
	for(int i = 36; i < 45; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}
	cout << "\n\nBottom\n-------\n";
	for(int i = 45; i < 54; i++){
		if((i+1)%3 == 0)
			cout << cubeValues[i] << endl;
		else
			cout << cubeValues[i] << " ";
	}
}
	
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
    cout << "Perform F()\n";
}

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
    cout << "Perform Fi()\n";
}

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
    cout << "Perform R()\n";
}

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
    cout << "Perform Ri()\n";
}

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
    cout << "Perform L()\n";
}

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
    cout << "Perform Li()\n";
}

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
    cout << "Perform B()\n";
}

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
    cout << "Perform Bi()\n";
}

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
    cout << "Perform U()\n";
}

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
    cout << "Perform Ui()\n";
}

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
    cout << "Perform D()\n";
}

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
    cout << "Perform Di()\n";
}

void Cube::TurnCube(){
	cout << "Turning the Cube!!!\n";
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
}

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
    cout << "Rolling the Cube.\n";
}

void Cube::UpsideDownCube(){
	cout << "\nUpside Down Cube!!!\n";
	for(int i = 0; i < 2; i++){
		RollCube();
    }
}

char Cube::at(int a){
	return cubeValues[a];
}

int Cube::edgeOf(int a){
	switch(a){
		case 1:
			return 43; 
			break;
		case 3:
			return 32; 
			break;			
		case 5:
			return 12; 
			break;
		case 7:
			return 46; 
			break;			
		case 10:
			return 41; 
			break;
		case 12:
			return 5; 
			break;			
		case 14:
			return 21; 
			break;
		case 16:
			return 50; 
			break;			
		case 19:
			return 37; 
			break;
		case 21:
			return 14; 
			break;			
		case 23:
			return 30; 
			break;
		case 25:
			return 52; 
			break;	
		case 28:
			return 39; 
			break;
		case 30:
			return 23; 
			break;			
		case 32:
			return 3; 
			break;
		case 34:
			return 48; 
			break;			
		case 37:
			return 19; 
			break;
		case 39:
			return 28; 
			break;			
		case 41:
			return 10; 
			break;
		case 43:
			return 1; 
			break;			
		case 46:
			return 7; 
			break;
		case 48:
			return 34; 
			break;			
		case 50:
			return 16; 
			break;
		case 52:
			return 25; 
			break;		
		default:
			return -1;
			break;		
	}
}

void Cube::orient(){
	if(this->at(4)=='w'){
		this->TurnCube();
		this->RollCube();
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}
	else if(this->at(13)=='w'){
		this->TurnCube();
		this->TurnCube();
		this->RollCube();
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}
	else if(this->at(22)=='w'){
		this->TurnCube();
		this->TurnCube();
		this->TurnCube();
		this->RollCube();
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}
	else if(this->at(31)=='w'){
		this->RollCube();
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}
	else if(this->at(40)=='w')
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	
	else if(this->at(49)=='w'){
		this->RollCube();
		this->RollCube();
		while(this->at(4) != 'b'){
			this->TurnCube();
		}
	}					
	
	cout << "Please make sure that the top side is white and the " << 
		"front side is blue.\n";
}

void Cube::whiteCross(){
	
	int edges[24] = {1, 3, 5, 7,
					10, 12, 14, 16, 
					19, 21, 23, 25, 
					28, 30, 32, 34, 
					37, 39, 41, 43, 
					46, 48, 50, 52};
					
	if(	(this->at(37)=='w')||(this->at(39)=='w')|| (this->at(41)=='w')||
		(this->at(43)=='w')){
		if(this->at(37)=='w'){
			char temp = this->at(19);
			if(this->at(22) != temp){
				if(this->at(13) == temp)
					this->U();
				else if(this->at(31) == temp)
					this->Ui();
				else if(this->at(4) == temp){
					this->U();
					this->U();
				}
			}
		}
		else if(this->at(39)=='w'){
			char temp = this->at(28);
			if(this->at(31) != temp){
				if(this->at(22) == temp)
					this->U();
				else if(this->at(4) == temp)
					this->Ui();
				else if(this->at(13) == temp){
					this->U();
					this->U();
				}
			}
		}
		else if(this->at(41)=='w'){
			char temp = this->at(10);
			if(this->at(13) != temp){
				if(this->at(4) == temp)
					this->U();
				else if(this->at(22) == temp)
					this->Ui();
				else if(this->at(31) == temp){
					this->U();
					this->U();
				}
			}
		}
		else if(this->at(43)=='w'){
			char temp = this->at(2);
			if(this->at(4) != temp){
				if(this->at(31) == temp)
					this->U();
				else if(this->at(13) == temp)
					this->Ui();
				else if(this->at(22) == temp){
					this->U();
					this->U();
				}
			}
		}
	}

	int cross_index = 0;	
	while(cross_index < 24){
		if(this->at(edges[cross_index]) != 'w'){
			cross_index++;
		}
		else{
			bool topOne = false;
			switch(cross_index){
				case 0:
					this->F();
					this->F();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;
				case 1:
					this->Fi();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;			
				case 2:
					this->F();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;
				case 3:
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;			
				case 4:
					this->TurnCube();
					this->F();
					this->F();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;
				case 5:
					this->TurnCube();
					this->Fi();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;			
				case 6:
					this->TurnCube();
					this->F();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;
				case 7:
					this->TurnCube();		
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;			
				case 8:
					this->TurnCube();		
					this->TurnCube();		
					this->F();
					this->F();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;
				case 9:
					this->TurnCube();		
					this->TurnCube();		
					this->Fi();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;			
				case 10:
					this->TurnCube();		
					this->TurnCube();		
					this->F();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;
				case 11:
					this->TurnCube();				
					this->TurnCube();		
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;	
				case 12:
					this->TurnCube();		
					this->TurnCube();		
					this->TurnCube();		
					this->F();
					this->F();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;
				case 13:
					this->TurnCube();		
					this->TurnCube();		
					this->TurnCube();		
					this->Fi();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;			
				case 14:
					this->TurnCube();		
					this->TurnCube();		
					this->TurnCube();		
					this->F();
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;
				case 15:
					this->TurnCube();		
					this->TurnCube();		
					this->TurnCube();		
					while(this->at(4) != (this->at(this->edgeOf(7)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->U();
					this->Li();
					this->Ui();
					break;			
				case 16:
					if(this->at(19) == this->at(22)){
						cross_index++;
						topOne = true;
					}				
					else{		
						this->TurnCube();		
						this->TurnCube();	
						this->F();
						this->F();
						while(this->at(4) != (this->at(this->edgeOf(46)))){
							this->D();
							this->TurnCube();
						}
						this->F();
						this->F();					
					}
					break;
				case 17:
					if(this->at(28) == this->at(31)){
						cross_index++;
						topOne = true;
					}
					else{
						this->TurnCube();		
						this->TurnCube();		
						this->TurnCube();		
						this->F();
						this->F();
						while(this->at(4) != (this->at(this->edgeOf(46)))){
							this->D();
							this->TurnCube();
						}
						this->F();
						this->F();				
					}
					break;
				case 18:
					if(this->at(10) == this->at(13)){
						cross_index++;
						topOne = true;
					}
					else{
						this->TurnCube();		
						this->F();
						this->F();
						while(this->at(4) != (this->at(this->edgeOf(46)))){
							this->D();
							this->TurnCube();
						}
						this->F();
						this->F();	
					}
					break;	
				case 19:
					if(this->at(1) == this->at(4)){
						cross_index++;
						topOne = true;
					}
					else{
						this->F();
						this->F();
						while(this->at(4) != (this->at(this->edgeOf(46)))){
							this->D();
							this->TurnCube();
						}
						this->F();
						this->F();				
					}
					break;			
				case 20:
					while(this->at(4) != (this->at(this->edgeOf(46)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->F();				 
					break;
				case 21:
					this->TurnCube();		
					this->TurnCube();		
					this->TurnCube();		
					while(this->at(4) != (this->at(this->edgeOf(46)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->F();	
					break;			
				case 22:
					this->TurnCube();		
					while(this->at(4) != (this->at(this->edgeOf(46)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->F();	
					break;
				case 23:
					this->TurnCube();		
					this->TurnCube();		
					while(this->at(4) != (this->at(this->edgeOf(46)))){
						this->D();
						this->TurnCube();
					}
					this->F();
					this->F();	
					break;		
				default:
					cout << "ERROR!!!";
					break;	
			} // end switch statement
			if(!topOne)
				cross_index = 0;
		} 
	}
}

char Cube::getFColor(){
	return cubeValues[4];
}

char Cube::getRColor(){
	return cubeValues[13];
}

char Cube::getBColor(){
	return cubeValues[22];
}

char Cube::getLColor(){
	return cubeValues[31];
}

char Cube::getUColor(){
	return cubeValues[40];
}

char Cube::getDColor(){
	return cubeValues[49];
}

void Cube::correctSix(int &cornerIndex){
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
		}
	}
	if(i == 6){
		this->printE("Error @ correctSix(cornerIndex).\nThe searched piece configuration does not seem to exist.\nPlease check work.");
	}
	this->D();
	this->L();
	this->Di();
	this->Li();
	cornerIndex = 0;
}

void Cube::correctEight(int &cornerIndex){
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
		this->printE("Error @ correctSix(cornerIndex).\nThe searched piece configuration does not seem to exist.\nPlease check work.");
	}
	this->Di();
	this->Ri();
	this->D();
	this->R();
	cornerIndex = 0;
}

void Cube::whiteCorners(){
	int corner[24] ={ 	0,  2,  6,  8,
		 				9, 11, 15, 17,
						18, 20, 24, 26,
						27, 29, 33, 35,
						36, 38, 42, 44,
						45, 47, 51, 53 };

	int cornerIndex = 0; 
	while(cornerIndex < 24){
		cout << "CornerIndex is " << cornerIndex << ".\n";
		if(this->at(corner[cornerIndex]) != 'w')
			cornerIndex++;
		else if((16 <= cornerIndex) & (cornerIndex <= 19)){
			if(cornerIndex == 16){
				if((this->at(27) == this->getLColor()) & 
					(this->at(20) == this->getBColor()))
					cornerIndex++;
				else{
					this->Li();
					this->Di();
					this->Di();
					this->L();
					this->correctEight(cornerIndex);
				}
			}
			else if(cornerIndex == 17){
				if((this->at(11) == this->getRColor()) &
					(this->at(18) == this->getBColor()))
					cornerIndex++;
				else{
					this->R();
					this->Di();
					this->Di();
					this->Ri();
					this->correctSix(cornerIndex);					
				}
			}
			else if(cornerIndex == 18){
				if((this->at(0) == this->getFColor()) & 
					(this->at(29) == this->getLColor()))
					cornerIndex++;
				else{
					this->L();
					this->D();	
					this->Li();
					this->D();
					this->correctSix(cornerIndex);
				}
			}
			else if(cornerIndex == 19){
				if((this->at(2) == this->getFColor()) & 
					(this->at(9) == this->getRColor()))
					cornerIndex++;
				else{
					this->Ri();
					this->Di();	
					this->R();
					this->D();
					this->correctEight(cornerIndex);
				}
			}
		}
		else{
			cout << "Corner Index is  = " << cornerIndex << ".\n";
					switch(cornerIndex){
				case 0:
					this->Fi();
					this->D();
					this->D();
					this->F();
					this->Di();
					this->Di();
					this->correctSix(cornerIndex);
					break;
				case 1:
					this->F();
					this->D();
					this->Fi();
					this->Di();
					this->correctEight(cornerIndex);
					break;
				case 2:
					this->correctSix(cornerIndex);
					break;	
				case 3:
					this->correctEight(cornerIndex);
					break;
				case 4:
					this->Ri();
					this->Di();
					this->R();
					this->correctSix(cornerIndex);
					break;
				case 5:
					this->L();
					this->Di();
					this->Di();
					this->Li();
					this->D();
					this->correctEight(cornerIndex);
					break;
				case 6:
					this->Di();
					this->correctSix(cornerIndex);
					break;	
				case 7:
					this->Di();
					this->correctEight(cornerIndex);
					break;	
				case 8:
					this->Bi();
					this->Di();
					this->B();
					this->Di();
					this->correctSix(cornerIndex);
					break;
				case 9:
					this->B();
					this->D();
					this->Bi();
					this->D();
					this->correctEight(cornerIndex);
					break;
				case 10:
					this->Di();
					this->Di();
					this->correctSix(cornerIndex);
					break;
				case 11:
					this->Di();
					this->Di();
					this->correctEight(cornerIndex);
					break;
				case 12:
					this->Li();
					this->D();
					this->D();
					this->L();
					this->Di();
					this->correctSix(cornerIndex);
					break;
				case 13:
					this->L();
					this->D();
					this->Li();
					this->correctEight(cornerIndex);
					break;
				case 14:
					this->D();
					this->correctSix(cornerIndex);
					break;
				case 15:
					this->D();
					this->correctEight(cornerIndex);
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
					this->correctSix(cornerIndex);
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
					this->correctEight(cornerIndex);
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
					this->correctSix(cornerIndex);
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
					this->correctEight(cornerIndex);
					break;
				default:
					cout << "Hit default case in whiteCorners().\n";
					break;
			}
		}
	}
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
	cout << "\n\nNow, the white side should be facing down ";
	cout << "and the yellow side should be facing up.\n\n";
	bool complete = false;
	while(!complete){
		if((this->at(3) == this->getFColor()) & (this->at(5) == this->getFColor()) & 
		(this->at(12) == this->getRColor()) & (this->at(14) == this->getRColor()) & 
		(this->at(21) == this->getBColor()) & (this->at(23) == this->getBColor()) & 
		(this->at(30) == this->getLColor()) & (this->at(32) == this->getLColor())) 
			complete = true;
		else{
			bool allyellow = true;
			if(this->at(1) != 'y'){
				allyellow=false;
				bool wrongSide = true;
				while(wrongSide){
					if(this->at(1) == this->getFColor())
						wrongSide= false;
					else{
						this->Ui();
						this->TurnCube();
					}
				}
				if(this->at(43) == this->getRColor()){
					this->middle_fallRight();
				}
				else{
					this->middle_fallLeft();
				}
			}
			else if(this->at(10) != 'y'){
				this->TurnCube();
				allyellow=false;
				bool rightSide = false;
				while(!rightSide){
					if(this->at(1) == this->getFColor())
						rightSide = true;
					else{
						this->Ui();
						this->TurnCube();
					}
				}
				if(this->at(43) == this->getRColor()){
					this->middle_fallRight();
				}
				else{
					this->middle_fallLeft();
				}
			}
			else if(this->at(19) != 'y'){
				this->TurnCube();
				this->TurnCube();
				allyellow=false;
				bool rightSide = false;
				while(!rightSide){
					if(this->at(1) == this->getFColor())
						rightSide = true;
					else{
						this->Ui();
						this->TurnCube();
					}
				}
				if(this->at(43) == this->getRColor()){
					this->middle_fallRight();
				}
				else{
					this->middle_fallLeft();
				}
			}
			else if(this->at(28) != 'y'){
				this->TurnCube();
				this->TurnCube();
				this->TurnCube();
				allyellow=false;
				bool rightSide = false;
				while(!rightSide){
					if(this->at(1) == this->getFColor())
						rightSide = true;
					else{
						this->Ui();
						this->TurnCube();
					}
				}
				if(this->at(43) == this->getRColor()){
					this->middle_fallRight();
				}
				else{
					this->middle_fallLeft();
				}
			}
			if(allyellow){
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
					this->F();
					this->middle_fallRight();
				}
				else{
					this->TurnCube();
					this->Fi();
					this->middle_fallLeft();
				}
			}
		}
	}
	cout << "Middle Layer is done.\n";
}

void Cube::yellowCross(){
	bool completed = false;
	while(!completed){
		if((this->at(37) == 'y') & (this->at(39) == 'y') & 
		(this->at(41) == 'y') & (this->at(43) == 'y')){
						cout << "\n\n*********All done with Yellow Cross();*************\n\n";
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
	} // end while loop
}	

void Cube::yellowCrossSequence(){
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
			cout << "numCorners == " << numCorners << ".\n";
			cout << "All done. with Yellow Corners!!!\n\n\n";
			return;
		}
	}
}

void Cube::lastLayer_cornerSequence(){
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

void Cube::lastLayer_corners(){
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
		if(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lastLayer_cornerSequence();
		return;
	}
	else if(situation == 1){
		this->TurnCube();
		if(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lastLayer_cornerSequence();
		return;	
	}
	else if(situation == 2){
		this->TurnCube();
		this->TurnCube();
		if(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lastLayer_cornerSequence();
		return;		
	}
	else if(situation == 3){
		this->TurnCube();
		this->TurnCube();
		this->TurnCube();
		if(this->at(0) != this->at(4)){
			this->Ui();
			this->TurnCube();
		}
		this->TurnCube();
		this->TurnCube();
		this->lastLayer_cornerSequence();
		return;		
	}
	else{
		this->printE("This are the droids you're looking for");
	}	
	cout << "\n\n*********** Last Layer Corners ******************\n\n";
}

void Cube::lastLayer_topSequenceClock(){
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

void Cube::lastLayer_topSequenceCounter(){
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

void Cube::lastLayer_topEdges(){
	int i = 0;
	bool completed = false;
	while(!completed){
		i = 0;
		while((this->at(19) != this->getBColor()) & (i < 4)){
			this->TurnCube();
			i++;
		}
		if(i == 4){
			this->lastLayer_topSequenceClock();	
		}
		else{
			if(this->at(1) == this->getLColor()){
				this->lastLayer_topSequenceClock();	
				completed = true;
			}
			else{
				this->lastLayer_topSequenceCounter();
				completed = true;
			}
		}	
	}
	cout << "\n\nCongrats. You should be done.\n\n";
}