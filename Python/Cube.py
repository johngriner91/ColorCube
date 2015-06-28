##############################################################################
#   Author: John Griner
#   
#   Methods:
#     __init__  : initialize class data
#     Clockwise Turns (F-D) : turn the cube face clockwise
#     Counterclockwise Turns (Fi-Di) : turn the cube face counterclockwise
#
##############################################################################

class Cube:
    "Class that defines and implements the Cube functionality"
    
    # This is the constructor. With the input file, initialize data
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
        
    # Get the color at a specific index
    def at(self, index):
        return self.data[index]
        
    # Return the color of the front side
    def get_F_color(self):
        return self.data[4]
        
    # Return the color of the right side
    def get_R_color(self):
        return self.data[13]
        
    # Return the color of the back side
    def get_B_color(self):
        return self.data[22]
        
    # Return the color of the left side
    def get_L_color(self):
        return self.data[31]
        
    # Return the color of the top side
    def get_U_color(self):
        return self.data[40]
        
    # Return the color of the bottom side
    def get_D_color(self):
        return self.data[49]
        
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
        
    def orient_cube(self):
        print()
            
    def white_side(self):
        self.move_white_piece(1,50)
        print()
        
    def middle_layer(self):
        print()
        
    def yellow_side(self):
        print()
        
    def last_layer(self):
        print()
        
    # Move around the white pieces        
    def move_white_piece(self, start, finish):
        
        # Positions of edge pieces
        edges = {	 1,  3,  5,  7, 10, 12, 14, 16, 
	  				19, 21, 23, 25, 28, 30, 32, 34,
					37, 39, 41, 43, 46, 48, 50, 52 };
		
		# Positions of corner pieces
        corners = {  0,  2,  6,  8,  9, 11, 15, 17,
					18, 20, 24, 26,	27, 29, 33, 35,
					36, 38, 42, 44,	45, 47, 51, 53 };
										
		# Positions of center pieces
        centers = {4, 13, 22, 31, 40, 49}      
                    
        # If start can't go to finish, return early. 
        if start in edges and finish in corners:
            print("Invalid turn. Terminating.")
            return
        if start in corners and finish in edges:
            print("Invalid turn. Terminating.")
            return
        if start in centers or finish in centers:
            print("Invalid turn. Terminating.")
            return
            
        # TODO: There has to be a better Python way to do this loop
        if start in edges:   
            for i,x in enumerate(self.data):
                if i in edges:
                    if x is 'w':
                        index = i
                        break
            
            # Depending on where the piece was found, perform specific turns
            if index == 37:
                oppositeEdge = self.at(19)
                if oppositeEdge == self.get_F_color():
                    self.Bi()
                    self.Bi()
                    self.Di()
                    self.Di()
                    self.F()
                    self.F()
                elif oppositeEdge == self.get_R_color():
                    self.Bi()
                    self.Ui()
                    self.B()
                    self.U()
                elif oppositeEdge == self.get_B_color():
                    pass
                elif oppositeEdge == self.get_L_color():
                    self.B()
                    self.U()
                    self.Bi()
                    self.Ui()
                else:
                    print("whiteCross(): case 37: ERROR")
            elif index == 39:
                oppositeEdge = self.at(28)
                if oppositeEdge == self.getFColor():
                    self.L()
                    self.U()
                    self.Li()
                    self.Ui()
                elif oppositeEdge == self.getRColor():
                    self.Li()
                    self.Li()
                    self.Di()
                    self.Di()
                    self.R()
                    self.R()
                elif oppositeEdge == self.getBColor():
                    self.Li()
                    self.Ui()
                    self.L()
                    self.U()
                elif oppositeEdge == self.getLColor():
                    pass
                else:
                    print("whiteCross(): case 37: ERROR")
            elif index == 41:
                oppositeEdge = self.at(10);
                if oppositeEdge == self.getFColor():
                    self.Ri()
                    self.Ui()
                    self.R()
                    self.U()
                elif oppositeEdge == self.getRColor():
                    pass
                elif oppositeEdge == self.getBColor():
                    self.R()
                    self.U()
                    self.Ri()
                    self.Ui()
                elif oppositeEdge == self.getLColor():
                    self.R()
                    self.R()
                    self.Di()
                    self.Di()
                    self.Li()
                    self.Li()
                else:
                    print("whiteCross(): case 41: ERROR")
            elif index == 43:
                oppositeEdge = self.at(1);
                if oppositeEdge == self.getFColor():
                    pass
                elif oppositeEdge == self.getRColor():
                    self.F()
                    self.U()
                    self.Fi()
                    self.Ui()
                elif oppositeEdge == self.getBColor():
                    self.F()
                    self.F()
                    self.Di()
                    self.Di()
                    self.Bi()
                    self.Bi()
                elif oppositeEdge == self.getLColor():
                    self.Fi()
                    self.Ui()
                    self.F()
                    self.U()
                else:
                    print("whiteCross(): case 43: ERROR")
     
      
        elif start in corners:
            print()