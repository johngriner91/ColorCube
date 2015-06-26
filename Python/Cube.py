##############################################################################
#   Author: John Griner
#   
#   Methods:
#     __init__  : initialize class data
#     F : cube turn - front clockwise
#     R : cube turn - right clockwise
#     B : cube turn - back clockwise
#     L : cube turn - left clockwise
#     U : cube turn - top clockwise
#     D : cube turn - bottom clockwise
#     Fi  : cube turn - front counterclockwise
#     Ri  : cube turn - right counterclockwise
#     Bi  : cube turn - back counterclockwise
#     Li  : cube turn - left counterclockwise
#     Ui  : cube turn - top counterclockwise
#     Di  : cube turn - bottom counterclockwise
#
##############################################################################

class Cube:
    "Class that defines and implements the Cube functionality"
    
    def __init__(self, data):
        self.data = data

    # Turn the front face of the cube clockwise
    def F(self):
        self.data[0], self.data[2] = self.data[2], self.data[0]
        self.data[6], self.data[8] = self.data[8], self.data[6]
        self.data[0], self.data[8] = self.data[8], self.data[0]
        self.data[1], self.data[5] = self.data[5], self.data[1]
        self.data[3], self.data[7] = self.data[7], self.data[3]
        self.data[1], self.data[7] = self.data[7], self.data[1]
        self.data[42], self.data[9] = self.data[9], self.data[42]
        self.data[43], self.data[12] = self.data[12], self.data[43]
        self.data[44], self.data[15] = self.data[15], self.data[44]
        self.data[45], self.data[29] = self.data[29], self.data[45]
        self.data[46], self.data[32] = self.data[32], self.data[46]
        self.data[47], self.data[35] = self.data[35], self.data[47]
        self.data[44], self.data[45] = self.data[45], self.data[44]
        self.data[43], self.data[46] = self.data[46], self.data[43]
        self.data[42], self.data[47] = self.data[47], self.data[42]

    # Turn the front face of the cube counterclockwise
    def Fi(self):
        self.data[2], self.data[0] = self.data[0], self.data[2]
        self.data[8], self.data[6] = self.data[6], self.data[8]
        self.data[2], self.data[6] = self.data[6], self.data[2]
        self.data[5], self.data[1] = self.data[1], self.data[5]
        self.data[7], self.data[3] = self.data[3], self.data[7]
        self.data[3], self.data[5] = self.data[5], self.data[3]
        self.data[42], self.data[9] = self.data[9], self.data[42]
        self.data[43], self.data[12] = self.data[12], self.data[43]
        self.data[44], self.data[15] = self.data[15], self.data[44]
        self.data[45], self.data[29] = self.data[29], self.data[45]
        self.data[46], self.data[32] = self.data[32], self.data[46]
        self.data[47], self.data[35] = self.data[35], self.data[47]
        self.data[9], self.data[35] = self.data[35], self.data[9]
        self.data[12], self.data[32] = self.data[32], self.data[12]
        self.data[15], self.data[29] = self.data[29], self.data[15]

    # Turn the right face of the cube clockwise
    def R(self):
        self.data[9], self.data[11] = self.data[11], self.data[9]
        self.data[15], self.data[17] = self.data[17], self.data[15]
        self.data[9], self.data[17] = self.data[17], self.data[9]
        self.data[10], self.data[14] = self.data[14], self.data[10]
        self.data[12], self.data[16] = self.data[16], self.data[12]
        self.data[10], self.data[16] = self.data[16], self.data[10]
        self.data[44], self.data[18] = self.data[18], self.data[44]
        self.data[41], self.data[21] = self.data[21], self.data[41]
        self.data[38], self.data[24] = self.data[24], self.data[38]
        self.data[47], self.data[2] = self.data[2], self.data[47]
        self.data[50], self.data[5] = self.data[5], self.data[50]
        self.data[53], self.data[8] = self.data[8], self.data[53]
        self.data[47], self.data[38] = self.data[38], self.data[47]
        self.data[50], self.data[41] = self.data[41], self.data[50]
        self.data[53], self.data[44] = self.data[44], self.data[53]

    # Turn the right face of the cube counterclockwise
    def Ri(self):
        self.data[9], self.data[11] = self.data[11], self.data[9]
        self.data[15], self.data[17] = self.data[17], self.data[15]
        self.data[11], self.data[15] = self.data[15], self.data[11]
        self.data[10], self.data[14] = self.data[14], self.data[10]
        self.data[12], self.data[16] = self.data[16], self.data[12]
        self.data[12], self.data[14] = self.data[14], self.data[12]
        self.data[44], self.data[18] = self.data[18], self.data[44]
        self.data[41], self.data[21] = self.data[21], self.data[41]
        self.data[38], self.data[24] = self.data[24], self.data[38]
        self.data[47], self.data[2] = self.data[2], self.data[47]
        self.data[50], self.data[5] = self.data[5], self.data[50]
        self.data[53], self.data[8] = self.data[8], self.data[53]
        self.data[2], self.data[24] = self.data[24], self.data[2]
        self.data[5], self.data[21] = self.data[21], self.data[5]
        self.data[8], self.data[18] = self.data[18], self.data[8]        
        
    # Turn the back face of the cube clockwise
    def B(self):
        self.data[18], self.data[20] = self.data[20], self.data[18]
        self.data[24], self.data[26] = self.data[26], self.data[24]
        self.data[18], self.data[26] = self.data[26], self.data[18]
        self.data[19], self.data[23] = self.data[23], self.data[19]
        self.data[21], self.data[25] = self.data[25], self.data[21]
        self.data[19], self.data[25] = self.data[25], self.data[19]
        self.data[36], self.data[33] = self.data[33], self.data[36]
        self.data[37], self.data[30] = self.data[30], self.data[37]
        self.data[38], self.data[27] = self.data[27], self.data[38]
        self.data[51], self.data[17] = self.data[17], self.data[51]
        self.data[52], self.data[14] = self.data[14], self.data[52]
        self.data[53], self.data[11] = self.data[11], self.data[53]
        self.data[51], self.data[38] = self.data[38], self.data[51]
        self.data[52], self.data[37] = self.data[37], self.data[52]
        self.data[53], self.data[36] = self.data[36], self.data[53]

    # Turn the back face of the cube counterclockwise
    def Bi(self):
        self.data[18], self.data[20] = self.data[20], self.data[18]
        self.data[24], self.data[26] = self.data[26], self.data[24]
        self.data[20], self.data[24] = self.data[24], self.data[20]
        self.data[19], self.data[23] = self.data[23], self.data[19]
        self.data[21], self.data[25] = self.data[25], self.data[21]
        self.data[21], self.data[23] = self.data[23], self.data[21]
        self.data[36], self.data[33] = self.data[33], self.data[36]
        self.data[37], self.data[30] = self.data[30], self.data[37]
        self.data[38], self.data[27] = self.data[27], self.data[38]
        self.data[51], self.data[17] = self.data[17], self.data[51]
        self.data[52], self.data[14] = self.data[14], self.data[52]
        self.data[53], self.data[11] = self.data[11], self.data[53]
        self.data[17], self.data[27] = self.data[27], self.data[17]
        self.data[14], self.data[30] = self.data[30], self.data[14]
        self.data[11], self.data[33] = self.data[33], self.data[11]

    # Turn the left face of the cube clockwise
    def L(self):
        self.data[27], self.data[29] = self.data[29], self.data[27]
        self.data[33], self.data[35] = self.data[35], self.data[33]
        self.data[27], self.data[35] = self.data[35], self.data[27]
        self.data[28], self.data[32] = self.data[32], self.data[28]
        self.data[30], self.data[34] = self.data[34], self.data[30]
        self.data[28], self.data[34] = self.data[34], self.data[28]
        self.data[36], self.data[0] = self.data[0], self.data[36]
        self.data[39], self.data[3] = self.data[3], self.data[39]
        self.data[42], self.data[6] = self.data[6], self.data[42]
        self.data[51], self.data[20] = self.data[20], self.data[51]
        self.data[48], self.data[23] = self.data[23], self.data[48]
        self.data[45], self.data[26] = self.data[26], self.data[45]
        self.data[51], self.data[42] = self.data[42], self.data[51]
        self.data[48], self.data[39] = self.data[39], self.data[48]
        self.data[45], self.data[36] = self.data[36], self.data[45]

    # Turn the left face of the cube counterclockwise
    def Li(self):
        self.data[27], self.data[29] = self.data[29], self.data[27]
        self.data[33], self.data[35] = self.data[35], self.data[33]
        self.data[29], self.data[33] = self.data[33], self.data[29]        
        self.data[28], self.data[32] = self.data[32], self.data[28]
        self.data[30], self.data[34] = self.data[34], self.data[30]
        self.data[32], self.data[30] = self.data[30], self.data[32]
        self.data[36], self.data[0] = self.data[0], self.data[36]
        self.data[39], self.data[3] = self.data[3], self.data[39]
        self.data[42], self.data[6] = self.data[6], self.data[42]
        self.data[51], self.data[20] = self.data[20], self.data[51]
        self.data[48], self.data[23] = self.data[23], self.data[48]
        self.data[45], self.data[26] = self.data[26], self.data[45]
        self.data[6], self.data[20] = self.data[20], self.data[6]
        self.data[3], self.data[23] = self.data[23], self.data[3]
        self.data[0], self.data[26] = self.data[26], self.data[0]

        # Turn the top face of the cube clockwise
    def U(self):
        self.data[36], self.data[38] = self.data[38], self.data[36]
        self.data[42], self.data[44] = self.data[44], self.data[42]
        self.data[36], self.data[44] = self.data[44], self.data[36]
        self.data[37], self.data[41] = self.data[41], self.data[37]
        self.data[39], self.data[43] = self.data[43], self.data[39]
        self.data[37], self.data[43] = self.data[43], self.data[37]
        self.data[18], self.data[9] = self.data[9], self.data[18]
        self.data[19], self.data[10] = self.data[10], self.data[19]
        self.data[20], self.data[11] = self.data[11], self.data[20]
        self.data[0], self.data[27] = self.data[27], self.data[0]
        self.data[1], self.data[28] = self.data[28], self.data[1]
        self.data[2], self.data[29] = self.data[29], self.data[2]
        self.data[20], self.data[2] = self.data[2], self.data[20]
        self.data[19], self.data[1] = self.data[1], self.data[19]
        self.data[18], self.data[0] = self.data[0], self.data[18]

    # Turn the top face of the cube counterclockwise
    def Ui(self):
        self.data[36], self.data[38] = self.data[38], self.data[36]
        self.data[42], self.data[44] = self.data[44], self.data[42]
        self.data[38], self.data[42] = self.data[42], self.data[38]
        self.data[37], self.data[41] = self.data[41], self.data[37]
        self.data[39], self.data[43] = self.data[43], self.data[39]
        self.data[39], self.data[41] = self.data[41], self.data[39]
        self.data[18], self.data[9] = self.data[9], self.data[18]
        self.data[19], self.data[10] = self.data[10], self.data[19]
        self.data[20], self.data[11] = self.data[11], self.data[20]
        self.data[0], self.data[27] = self.data[27], self.data[0]
        self.data[1], self.data[28] = self.data[28], self.data[1]
        self.data[2], self.data[29] = self.data[29], self.data[2]
        self.data[11], self.data[29] = self.data[29], self.data[11]
        self.data[10], self.data[28] = self.data[28], self.data[10]
        self.data[9], self.data[27] = self.data[27], self.data[9]

    # Turn the bottom face of the cube clockwise
    def D(self):
        self.data[45], self.data[47] = self.data[47], self.data[45]
        self.data[51], self.data[53] = self.data[53], self.data[51]
        self.data[45], self.data[53] = self.data[53], self.data[45]
        self.data[46], self.data[50] = self.data[50], self.data[46]
        self.data[48], self.data[52] = self.data[52], self.data[48]
        self.data[46], self.data[52] = self.data[52], self.data[46]
        self.data[24], self.data[33] = self.data[33], self.data[24]
        self.data[25], self.data[34] = self.data[34], self.data[25]
        self.data[26], self.data[35] = self.data[35], self.data[26]
        self.data[6], self.data[15] = self.data[15], self.data[6]
        self.data[7], self.data[16] = self.data[16], self.data[7]
        self.data[8], self.data[17] = self.data[17], self.data[8]
        self.data[24], self.data[6] = self.data[6], self.data[24]
        self.data[25], self.data[7] = self.data[7], self.data[25]
        self.data[26], self.data[8] = self.data[8], self.data[26]

    # Turn the bottom face of the cube counterclockwise
    def Di(self):
        self.data[45], self.data[47] = self.data[47], self.data[45]
        self.data[51], self.data[53] = self.data[53], self.data[51]
        self.data[47], self.data[51] = self.data[51], self.data[47]
        self.data[46], self.data[50] = self.data[50], self.data[46]
        self.data[48], self.data[52] = self.data[52], self.data[48]
        self.data[48], self.data[50] = self.data[50], self.data[48]
        self.data[24], self.data[33] = self.data[33], self.data[24]
        self.data[25], self.data[34] = self.data[34], self.data[25]
        self.data[26], self.data[35] = self.data[35], self.data[26]
        self.data[6], self.data[15] = self.data[15], self.data[6]
        self.data[7], self.data[16] = self.data[16], self.data[7]
        self.data[8], self.data[17] = self.data[17], self.data[8]
        self.data[33], self.data[15] = self.data[15], self.data[33]
        self.data[34], self.data[16] = self.data[16], self.data[34]
        self.data[35], self.data[17] = self.data[17], self.data[35]
  
    # Print out the values of the cube
    def print_val(self):
        print("-----------------------------------------------")
        for x in range(0,18):
            for y in range(0,3):
                print(self.data[ (3*x)+y ], end=" ")
            print()
            if not (x+1)%3:
                print()
        print("-----------------------------------------------")        
        print()
       
    # Make sure there are an even number of colors 
    def check_inputs(self):
        if (self.data.count("b") and self.data.count("o") and 
            self.data.count("g") and self.data.count("r") and
            self.data.count("w") and self.data.count("y") == 9):
            return True
        else:
            return False
    
    # Perform the appropriate steps to solve the cube      
    def solve_cube(self):
        self.orient_cube()
        self.white_side()
        self.middle_layer()
        self.yellow_side()
        self.last_layer()
        
    # Make sure the cube starts in the right position      
    def orient_cube(self):
        if (self.data[4] or self.data[13] or 
            self.data[22] or self.data[31] ) == "b" and self.data[40] == "w":
            if self.data[4] == "b":
              return
            elif self.data[13] == "b":
              self.turn_cube()
            elif self.data[22] == "b":
              self.turn_cube()
              self.turn_cube()
            else:
              self.turn_cube_i()
        elif
            
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

}    
