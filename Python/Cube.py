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
    def __init__(self, data, instruction):
        self.data = data
        self.instruction = instruction
        
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
  
    def TurnCube(self):
        self.U()
        self.Di()
        self.data[3], self.data[30] = self.data[30], self.data[3]
        self.data[4], self.data[31] = self.data[31], self.data[4]
        self.data[5], self.data[32] = self.data[32], self.data[5]
        self.data[21], self.data[12] = self.data[12], self.data[21]
        self.data[22], self.data[13] = self.data[13], self.data[22]
        self.data[23], self.data[14] = self.data[14], self.data[23]
        self.data[3], self.data[21] = self.data[21], self.data[3]
        self.data[4], self.data[22] = self.data[22], self.data[4]
        self.data[5], self.data[23] = self.data[23], self.data[5]
 
    def RollCube(self):
        self.F()
        self.Bi()
        self.data[39], self.data[10] = self.data[10], self.data[39]
        self.data[40], self.data[13] = self.data[13], self.data[40]
        self.data[41], self.data[16] = self.data[16], self.data[41]
        self.data[48], self.data[28] = self.data[28], self.data[48]
        self.data[49], self.data[31] = self.data[31], self.data[49]
        self.data[50], self.data[34] = self.data[34], self.data[50]
        self.data[39], self.data[50] = self.data[50], self.data[39]
        self.data[40], self.data[49] = self.data[49], self.data[40]
        self.data[41], self.data[48] = self.data[48], self.data[41]
        
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
        self.orient_cube()  # Completed - ported from C++
        self.white_side()   # Completed - ported from C++
        self.middle_layer()
        self.yellow_side()
        self.last_layer()   # Completed - ported from C++

    # Start the cube solving in the same position to ease algorithm
    def orient_cube(self):
        # If the front side is the "white" side, correct so the top is white.
        if self.at(4)=='w':
            self.TurnCube()
            self.RollCube()

            # Turn the cube so that the blue side is facing the front
            while self.at(4) != 'b':
                self.TurnCube()

        # If the left side is the "white" side, correct so the top is white.
        elif self.at(13)=='w':
            self.TurnCube()
            self.TurnCube()
            self.RollCube()

            # Turn the cube so that the blue side is facing the front
            while self.at(4) != 'b':
                self.TurnCube()
		
        # If the back side is the "white" side, correct so the top is white.
        elif self.at(22)=='w':
            self.TurnCube()
            self.TurnCube()
            self.TurnCube()
            self.RollCube()

            # Turn the cube so that the blue side is facing the front
            while self.at(4) != 'b':
                self.TurnCube()

        # If the left side is the "white" side, correct so the top is white.
        elif self.at(31)=='w':
            self.RollCube()

            # Turn the cube so that the blue side is facing the front
            while self.at(4) != 'b':
                self.TurnCube()
		
        # If the top side is the "white" side, move on.
        elif self.at(40)=='w':
	    
            # Turn the cube so that the blue side is facing the front
            while self.at(4) != 'b':
                self.TurnCube()

        # If the bottom side is the "white" side, correct so the top is white.
        elif self.at(49)=='w':
            self.RollCube()
            self.RollCube()

            # Turn the cube so that the blue side is facing the front
            while self.at(4) != 'b':
                self.TurnCube()

        # Note that the cube was oriented
        self.instruction.append("OC");
        
    def white_side(self):
        self.white_edges()
        self.white_corners()
        print()
        
    def middle_layer(self):
        self.middleLayer()
        
    def yellow_side(self):
        print()
        
    def last_layer(self):
        # Functions that complete the last laster
        self.last_layer_corners()
        self.last_layer_edges()
        
    def white_edges(self):
        edges = [1,  3,  5,  7, 10, 12, 14, 16, 19, 21, 23, 25, 28, 30, 
                32, 34, 37, 39, 41, 43, 46, 48, 50, 52]
        counter = 0
        numTurns = 0
        startOver = True

        # Until we've looked at and approved all the pieces, keep looking
        while counter < 24:
            # We haven't found a white piece yet
            while self.at(edges[counter]) != 'w':
                counter = counter+1
                if counter >= 24:
                    return 1
      
            # "Repeat" the position-based algorithm. This way, case 0 can be
            #   used to handle positions 1, 10, 19, and 28 without any code
            #   rewrite. We'll simply turn the cube until those positions
            # "become" case 0.
            if counter < 16:
                numToTurn = counter / 4
                # reset the counter
                counter = counter % 4

                for i in range(0..numToTurn):
                    self.TurnCube()

            # This if/elif is the meat and potatos of the function. Depending on
		    #   where the white cross pieces are, we need to make specific 
		    #   turns to move them into their correct position. This case
		    #   statements are the different possible positions of the white 
		    #   pieces.
            if counter == 0:
                oppositeEdge = self.at(43)
                if oppositeEdge == self.get_F_color():
                    self.Fi()
                    self.U()
                    self.Li()
                    self.Ui()
                elif oppositeEdge == self.get_R_color():
                    self.F()
                    self.R()
                elif oppositeEdge == self.get_B_color():
                    self.F()
                    self.F()
                    self.Di()
                    self.Di()
                    self.B()
                    self.U()
                    self.L()
                    self.Ui()
                elif oppositeEdge == self.get_L_color():
                    self.Fi()
                    self.Li()
                else:
                    print("whiteCross(): case 0: bad edge")
                    return 0
            elif counter == 1:
                oppositeEdge = self.at(32)
                if oppositeEdge == self.get_F_color():
                    self.U()
                    self.Li()
                    self.Ui()
                elif oppositeEdge == self.get_R_color():
                    self.L()
                    self.Di()
                    self.Di()
                    self.Li()
                    self.R()
                    self.R()
                elif oppositeEdge == self.get_B_color():
                    self.L()
                    self.Di()
                    self.Li()
                    self.Bi()
                    self.Bi()
                elif oppositeEdge == self.get_L_color():
                    self.L()
                else:
                    print("whiteCross(): case 1: edge error")
                    return 0
            elif counter == 2:
                oppositeEdge = self.at(12)
                if oppositeEdge == self.get_F_color():
                    self.F()
                    self.F()
                    self.U()
                    self.Li()
                    self.Ui()
                elif oppositeEdge == self.get_R_color():
                    self.R()
                elif oppositeEdge == self.get_B_color():
                    self.Ri()
                    self.D()
                    self.R()
                    self.Bi()
                    self.Bi()
                elif oppositeEdge == self.get_L_color():
                    self.Ri()
                    self.Di()
                    self.Di()
                    self.R()
                    self.Li()
                    self.Li()
                else:
                    print("whiteCross(): case 2: edge error")
                    return 0
            elif counter == 3:
                oppositeEdge = self.at(46)
                if oppositeEdge == self.get_F_color():
                    self.F()
                    self.U()
                    self.Li()
                    self.Ui()
                elif oppositeEdge == self.get_R_color():
                    self.D()
                    self.R()
                    self.U()
                    self.Fi()
                    self.Ui()
                elif oppositeEdge == self.get_B_color():
                    self.Di()
                    self.Di()
                    self.B()
                    self.U()
                    self.Ri()
                    self.Ui()
                elif oppositeEdge == self.get_L_color():
                    self.Di()
                    self.L()
                    self.U()
                    self.Bi()
                    self.Ui()
                else:
                    printE("whiteCross(): case 3: edge error")
                    return 0
            elif counter == 16:
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
                    # This piece is supposed to be white.
                    startOver = False
                elif oppositeEdge == self.get_L_color():
                    self.B()
                    self.U()
                    self.Bi()
                    self.Ui()
                else:
                    print("whiteCross(): case 16: edge error")
                    return 0
            elif counter == 17:
                oppositeEdge = self.at(28)
                if oppositeEdge == self.get_F_color():
                    self.L()
                    self.U()
                    self.Li()
                    self.Ui()
                elif oppositeEdge == self.get_R_color():
                    self.Li()
                    self.Li()
                    self.Di()
                    self.Di()
                    self.R()
                    self.R()
                elif oppositeEdge == self.get_B_color():
                    self.Li()
                    self.Ui()
                    self.L()
                    self.U()
                elif oppositeEdge == self.get_L_color():
                    # This piece is supposed to be white.
                    startOver = False
                else:
                    print("whiteCross(): case 17: edge error")
                    return 0
            elif counter == 18:
                oppositeEdge = self.at(10)
                if oppositeEdge == self.get_F_color():
                    self.Ri()
                    self.Ui()
                    self.R()
                    self.U()
                elif oppositeEdge == self.get_R_color():
                    # This piece is supposed to be white.
                    startOver = False
                elif oppositeEdge == self.get_B_color():
                    self.R()
                    self.U()
                    self.Ri()
                    self.Ui()
                elif oppositeEdge == self.get_L_color():
                    self.R()
                    self.R()
                    self.Di()
                    self.Di()
                    self.Li()
                    self.Li()
                else:
                    print("whiteCross(): case 18: edge error")
                    return 0
            elif counter == 19:
                oppositeEdge = self.at(1)
                if oppositeEdge == self.get_F_color():
                    # This piece is supposed to be white.
                    startOver = False
                elif oppositeEdge == self.get_R_color():
                    self.F()
                    self.U()
                    self.Fi()
                    self.Ui()
                elif oppositeEdge == self.get_B_color():
                    self.F()
                    self.F()
                    self.Di()
                    self.Di()
                    self.Bi()
                    self.Bi()
                elif oppositeEdge == self.get_L_color():
                    self.Fi()
                    self.Ui()
                    self.F()
                    self.U()
                else:
                    print("whiteCross(): case 19: edge error")
                    return 0
            elif counter == 20:
                oppositeEdge = self.at(7)
                if oppositeEdge == self.get_F_color():
                    self.F()
                    self.F()
                elif oppositeEdge == self.get_R_color():
                    self.D()
                    self.R()
                    self.R()
                elif oppositeEdge == self.get_B_color():
                    self.Di()
                    self.Di()
                    self.Bi()
                    self.Bi()
                elif oppositeEdge == self.get_L_color():
                    self.Di()
                    self.Li()
                    self.Li()
                else:
                    print("whiteCross(): case 20: edge error")
                    return 0
            if counter == 21:
                oppositeEdge = self.at(34)
                if oppositeEdge == self.get_F_color():
                    self.D()
                    self.Bi()
                    self.Bi()
                elif oppositeEdge == self.get_R_color():
                    self.Di()
                    self.Di()
                    self.R()
                    self.R()
                elif oppositeEdge == self.get_B_color():
                    self.Di()
                    self.Bi()
                    self.Bi()
                elif oppositeEdge == self.get_L_color():
                    self.Li()
                    self.Li()
                else:
                    print("whiteCross(): case 21: edge error")
                    return 0
            if counter == 22:
                oppositeEdge = self.at(16)
                if oppositeEdge == self.get_F_color():
                    self.Di()
                    self.F()
                    self.F()
                elif oppositeEdge == self.get_R_color():
                    self.R()
                    self.R()
                elif oppositeEdge == self.get_B_color():
                    self.D()
                    self.Bi()
                    self.Bi()
                elif oppositeEdge == self.get_L_color():
                    self.Di()
                    self.Di()
                    self.Li()
                    self.Li()
                else:
                    print("whiteCross(): case 22: edge error")
                    return 0
            elif counter == 23:
                oppositeEdge = self.at(25)
                if oppositeEdge == self.get_F_color():
                    self.Di()
                    self.Di()
                    self.F()
                    self.F()
                elif oppositeEdge == self.get_R_color():
                    self.Di()
                    self.R()
                    self.R()
                elif oppositeEdge == self.get_B_color():
                    self.Bi()
                    self.Bi()
                elif oppositeEdge == self.get_L_color():
                    self.D()
                    self.Li()
                    self.Li()
                else:
                    print("whiteCross(): case 23: edge error")
                    return 0


            # Was the piece that was found supposed to be there? If not, start
	    	# 	search over, because we may have accidentally moved some pieces
	    	#   out of place. I doubt it, but it's always better to double
	    	#   check.

            if startOver:
                counter = 0
                # reset the flag
                startOver = True
            else:
                # Move on, this is supposed to be white
                counter = counter + 1

            numTurns = numTurns+1;
            if numTurns > 20:
                print("Over 10 turns for WhiteCross(). Need to debug")
                return 0
        
    def white_corners(self):
        corners = [0,  2,  6,  8, 9, 11, 15, 17, 18, 20, 24, 26,
	              27, 29, 33, 35, 36, 38, 42, 44, 45, 47, 51, 53]

        counter = 0
        numTurns = 0
        startOver = True

        # Until we've looked at and approved all the pieces, keep looking
        while counter < 24:

            # We haven't found a white piece yet
            while self.at(corners[counter]) != 'w':
                counter = counter + 1
                if counter >= 24:
                    return 1

            # Integrate cube turns to "repeat" the position-based algorithm.
            #	This way, case 0 can be used to handle positions 0, 9, 18, and 27
            #	without any code rewrite. We'll simply turn the cube until those
            #	positions "become" case 0.

            if counter < 16:
                numTurns = counter / 4

                # reset the counter
                counter = counter % 4

            for i in range(0, numTurns):
                self.TurnCube()

            if counter == 0:
                oppositeEdge1 = self.at(42)
                oppositeEdge2 = self.at(29)
                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.Fi()
                    self.Di()
                    self.F()
                    self.F()
                    self.Di()
                    self.Di()
                    self.Fi()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.Fi()
                    self.Di()
                    self.R()
                    self.Di()
                    self.Ri()
                    self.F()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and 
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.Fi()
                    self.B()
                    self.Di()
                    self.Bi()
                    self.F()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.L()
                    self.Di()
                    self.Li()
                    self.D()
                    self.L()
                    self.Di()
                    self.Li()
            elif counter == 1:
                oppositeEdge1 = self.at(44)
                oppositeEdge2 = self.at(9)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.Ri()
                    self.D()
                    self.R()
                    self.Di()
                    self.Ri()
                    self.D()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.F()
                    self.Bi()
                    self.D()
                    self.Fi()
                    self.B()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.F()
                    self.D()
                    self.Fi()
                    self.Li()
                    self.D()
                    self.L()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.F()
                    self.Di()
                    self.Di()
                    self.Fi()
                    self.Fi()
                    self.D()
                    self.F()
            elif counter == 2:
                oppositeEdge1 = self.at(45)
                oppositeEdge2 = self.at(35)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.D()
                    self.Ri()
                    self.Di()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.Di()
                    self.R()
                    self.Di()
                    self.Ri()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.B()
                    self.Di()
                    self.Bi()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and 
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.D()
                    self.L()
                    self.Di()
                    self.Li()
            elif counter == 3:
                oppositeEdge1 = self.at(47)
                oppositeEdge2 = self.at(15)

                if ((oppositeEdge1 == self.get_F_color() or 
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.Di()
                    self.Ri()
                    self.D()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.Bi()
                    self.D()
                    self.B()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.Li()
                    self.Di()
                    self.Di()
                    self.L()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.Di()
                    self.L()
                    self.D()
                    self.Li()
            elif counter == 16:
                oppositeEdge1 = self.at(20)
                oppositeEdge2 = self.at(27)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.Li()
                    self.Di()
                    self.L()
                    self.Di()
                    self.Di()
                    self.Ri()
                    self.D()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.Li()
                    self.Di()
                    self.L()
                    self.Di()
                    self.Bi()
                    self.D()
                    self.B()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    startOver = False;
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.B()
                    self.D()
                    self.Bi()
                    self.D()
                    self.L()
                    self.Di()
                    self.Li()
            elif counter == 17:
                oppositeEdge1 = self.at(18)
                oppositeEdge2 = self.at(11)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.R()
                    self.Di()
                    self.Ri()
                    self.Di()
                    self.Di()
                    self.Ri()
                    self.D()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    startOver = False;
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color() ) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.Bi()
                    self.Di()
                    self.B()
                    self.Li()
                    self.Di()
                    self.Di()
                    self.L()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color() ) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.R()
                    self.D()
                    self.Ri()
                    self.D()
                    self.D()
                    self.L()
                    self.Di()
                    self.Li()
            elif counter == 18:
                oppositeEdge1 = self.at(0)
                oppositeEdge2 = self.at(29)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color() ) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.L()
                    self.D()
                    self.Li()
                    self.Ri()
                    self.Di()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.L()
                    self.R()
                    self.Di()
                    self.Di()
                    self.Li()
                    self.Ri()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and 
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.L()
                    self.D()
                    self.Li()
                    self.B()
                    self.Di()
                    self.Di()
                    self.Bi()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                            startOver = False
            elif counter == 19:
                oppositeEdge1 = self.at(2)
                oppositeEdge2 = self.at(9)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    startOver = False
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.Ri()
                    self.Di()
                    self.R()
                    self.Bi()
                    self.Di()
                    self.Di()
                    self.B()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.Ri()
                    self.Li()
                    self.Di()
                    self.Di()
                    self.L()
                    self.R()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.Ri()
                    self.Di()
                    self.R()
                    self.L()
                    self.D()
                    self.Li()
            elif counter == 20:
                oppositeEdge1 = self.at(6)
                oppositeEdge2 = self.at(35)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.D()
                    self.F()
                    self.Di()
                    self.Fi()
                    self.D()
                    self.Ri()
                    self.D()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.Di()
                    self.Di()
                    self.Bi()
                    self.D()
                    self.B()
                    self.Di()
                    self.R()
                    self.Di()
                    self.Ri()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.Li()
                    self.D()
                    self.L()
                    self.B()
                    self.Di()
                    self.Di()
                    self.Bi()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.Fi()
                    self.D()
                    self.F()
                    self.L()
                    self.Di()
                    self.Di()
                    self.Li()
            elif counter == 21:
                oppositeEdge1 = self.at(8)
                oppositeEdge2 = self.at(15)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.F()
                    self.Di()
                    self.Fi()
                    self.Ri()
                    self.Di()
                    self.Di()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.D()
                    self.Bi()
                    self.Di()
                    self.Di()
                    self.B()
                    self.D()
                    self.Bi()
                    self.Di()
                    self.B()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.Di()
                    self.B()
                    self.Di()
                    self.Bi()
                    self.Li()
                    self.Di()
                    self.L()
                    self.Di()
                    self.Di()
                    self.B()
                    self.Di()
                    self.Bi()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.Di()
                    self.Fi()
                    self.D()
                    self.F()
                    self.L()
                    self.Di()
                    self.Di()
                    self.Li()
            elif counter == 22:
                oppositeEdge1 = self.at(26)
                oppositeEdge2 = self.at(33)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.Di()
                    self.Di()
                    self.Ri()
                    self.Di()
                    self.Di()
                    self.R()
                    self.D()
                    self.Ri()
                    self.Di()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.Di()
                    self.R()
                    self.Di()
                    self.Ri()
                    self.D()
                    self.Bi()
                    self.D()
                    self.B()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.Li()
                    self.D()
                    self.L()
                    self.B()
                    self.Di()
                    self.Di()
                    self.Bi()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.D()
                    self.L()
                    self.Di()
                    self.L()
                    self.Fi()
                    self.Di()
                    self.Di()
                    self.F()
            elif counter == 23:
                oppositeEdge1 = self.at(24)
                oppositeEdge2 = self.at(17)

                if ((oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color()) and
                        (oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color())):
                    self.Di()
                    self.F()
                    self.Di()
                    self.Di()
                    self.Fi()
                    self.Di()
                    self.Di()
                    self.Ri()
                    self.D()
                    self.R()
                elif ((oppositeEdge1 == self.get_R_color() or
                        oppositeEdge2 == self.get_R_color()) and
                        (oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color())):
                    self.R()
                    self.Di()
                    self.Ri()
                    self.Bi()
                    self.Di()
                    self.Di()
                    self.B()
                elif ((oppositeEdge1 == self.get_B_color() or
                        oppositeEdge2 == self.get_B_color()) and
                        (oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color())):
                    self.D()
                    self.Li()
                    self.D()
                    self.L()
                    self.B()
                    self.D()
                    self.D()
                    self.Bi()
                elif ((oppositeEdge1 == self.get_L_color() or
                        oppositeEdge2 == self.get_L_color()) and
                        (oppositeEdge1 == self.get_F_color() or
                        oppositeEdge2 == self.get_F_color())):
                    self.Di()
                    self.Di()
                    self.L()
                    self.Di()
                    self.Li()
                    self.Fi()
                    self.Di()
                    self.Di()
                    self.F()
            else:
                return 0

            if startOver:
                counter = 0
            else:
                counter = counter + 1

            # Reset flag
            startOver = True;

            # Make sure we're not spiraling into a black hole of death
            numTurns = numTurns+1
            if numTurns > 20:
                print("Reached 20 moves. Must debug before moving on")
                return 0
    
            return 1
    
    # Sequence used in fixing middle layer
    def middle_fallLeft(self):
        this->Ui()
	    this->Li()
	    this->U()
	    this->L()
	    this->U()
	    this->F()
	    this->Ui()
	    this->Fi()

    # Sequence used in fixing middle layer
    def middle_fallRight(self):
        this->U()
        this->R()
        this->Ui()
        this->Ri()
        this->Ui()
        this->Fi()
        this->U()
        this->F()

    # Make turns to fix middle layer
    def middleLayer():
        complete = False

        # Turn the white side down, as per Rubik's solution
	    this->RollCube()
	    this->RollCube()

	    while not complete:
            # If the middle layer is completed,
		    if this->at(3) == this->getFColor() and
                    this->at(5) == this->getFColor() and
                    this->at(12) == this->getRColor() and
                    this->at(14) == this->getRColor() and
                    this->at(21) == this->getBColor() and
                    this->at(23) == this->getBColor() and
                    this->at(30) == this->getLColor() and
                    this->at(32) == this->getLColor():
                instruction.append("Middle")
                complete = True
            else:
                situation = -1;
                notAlignedZero = False
                notAlignedOne = False
                notAlignedTwo = False
                notAlignedThree = False
                allYellowSides = False

######################
YOU ARE HERE. START PORTING HERE TOMORROW
######################


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
    
    # Make turns used in last_layer_corners()
    def last_layer_cornerSequence(self):
	    if self.at(0) == self.at(4):
		    if self.at(9) == self.at(13):
			    if self.at(18) == self.at(21):
				    if self.at(27) == self.at(30):
					    return
	    # If you make it here, then you need to do this sequence
	    self.Ri()
	    self.F()
	    self.Ri()
	    self.B()
	    self.B()
	    self.R()
	    self.Fi()
	    self.Ri()
	    self.B()
	    self.B()
	    self.R()
	    self.R()
	    self.Ui()

    # Make turns to fix the last layer corners
    def last_layer_corners(self):
        if self.at(0) == self.at(2):
            situation = 0
        elif self.at(9) == self.at(11):
            situation = 1
        elif self.at(18) == self.at(20):
            situation = 2
        elif self.at(27) == self.at(29):
            situation = 3
        else:
            situation = 4

        # Depending on the situation, make the appropriate turns
        if situation == 0:
            while self.at(0) != self.at(4):
                self.Ui()
                self.TurnCube()
            self.TurnCube()
            self.TurnCube()
            self.last_layer_cornerSequence()
            self.instruction.append("LLC")
            return 1
        elif situation == 1:
            self.TurnCube()
            while self.at(0) != self.at(4):
                self.Ui()
                self.TurnCube()
            self.TurnCube()
            self.TurnCube()
            self.last_layer_cornerSequence()
            self.instruction.append("LLC")
            return 1
        elif situation == 2:
            self.TurnCube()
            self.TurnCube()
            while self.at(0) != self.at(4):
                self.Ui()
                self.TurnCube()
            self.TurnCube()
            self.TurnCube()
            self.last_layer_cornerSequence()
            self.instruction.append("LLC")
            return 1
        elif situation == 3:
            self.TurnCube()
            self.TurnCube()
            self.TurnCube()
            while self.at(0) != self.at(4):
                self.Ui()
                self.TurnCube()
            self.TurnCube()
            self.TurnCube()
            self.lLayer_cornerSequence()
            self.instruction.append("LLC")
            return 1
        elif situation == 4:
            while self.at(0) != self.at(4):
                self.Ui()
                self.TurnCube()
            self.TurnCube()
            self.TurnCube()
            self.lLayer_cornerSequence()
            self.lLayer_corners()
            return 1
        else:
            return 0

    # Make clockwise turns used in last layer
    def last_layer_topSequenceClock():
        self.F()
        self.F()
        self.U()
        self.L()
        self.Ri()
        self.F()
        self.F()
        self.Li()
        self.R()
        self.U()
        self.F()
        self.F()

    # Make counter clockwise turns used in lasy layer
    def last_layer_topSequenceCounter():
        self.F()
        self.F()
        self.Ui()
        self.L()
        self.Ri()
        self.F()
        self.F()
        self.Li()
        self.R()
        self.Ui()
        self.F()
        self.F()

    # Make turns to fix the last layer center edges
    def last_layer_edges(self):
        completed = 0;

        # Check to see if the last layer center edges are set
        if self.at(1) == self.at(4):
            if self.at(10) == self.at(13):
                if self.at(19) == self.at(21):
                    if self.at(28) == self.at(29):
                        return 1

        # Not completed, make the appropriate turns
        while not completed:
            i = 0
            
            # Make sure the back edge is the solid side
            while (self.at(19) != self.get_B_color()) & (i < 4):
                self.TurnCube()
                i = i+1
            if i == 4:
                self.last_layer_topSequenceClock()
            else:
                if self.at(1) == self.get_L_color():
                    self.lLayer_topSequenceClock()
                    self.instruction.append("DONE")
                    completed = True
                    return 1
                elif self.at(1) == self.get_R_color():
                    self.last_layer_topSequenceCounter()
                    self.instruction.append("DONE")
                    completed = True
                    return 1
        return 0
