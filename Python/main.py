##############################################################################
#   Author: John Griner
#   File Name: main.py
#   Version: python 3.4
##############################################################################
#!/usr/bin/python

# Grab the cube implementation from the Cube.py file
from Cube import Cube

# Variables
data = []
instruction = []
inputFile = "../input/input_9.txt"

# Open up the input file and read in the cube values
with open(inputFile) as textFile:
    for line in textFile:
        for face in line.split():
            # Add the values to the cube data
            data.append(face)

# Create a cube object from the input data
cube = Cube(data, instruction)

# Move on to solve and print the cube ... if the input was valid
if cube.check_inputs():
    # Input was determined to be valid
    cube.solve_cube()
    cube.print_val()
    cube.print_turns()
else:
    # Input was determined to be invalid
    print("Input was determined to be invalid")