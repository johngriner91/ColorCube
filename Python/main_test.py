##############################################################################
#   Author: John Griner
#   File Name: main_test.py
#   Version: python 3.4
#
#   This is pretty much just a unit test. By running this file, I can run
#       through all the test files and quickly tell if something is
#       broken.
#
##############################################################################
#!/usr/bin/python

# Used to get all files from the input file directory
import glob


# Grab the cube implementation from the Cube.py file
from Cube import Cube

# Variables
inputFiles = glob.glob("../input/*.txt")
line_decoration = "*" * 75
description1 ="Color Cube: Python Implementation Unit Test. Reading input files"
description2 ="from the following directory: ../input/*.txt. "
numTest = 0
numPass = 0

print()
print(line_decoration)
print(" " * 4, description1)
print(" " * 4, description2)
print()
print(" " * 4, "INPUT FILES", " " * 25, "PASS / FAIL")
print(" " * 4, "------------------------", " " * 12, "-----------")

# Open up the input file and read in the cube values
for file in inputFiles:
    numTest = numTest + 1
    data = []
    instruction = []
    print(" " * 4, '{:25s}'.format(file), " " * 15, end="")
    with open(file) as textFile:
        for line in textFile:
            for face in line.split():
                # Add the values to the cube data
                data.append(face)

    # Create a cube object from the input data
    cube = Cube(data, instruction)

    # Move on to solve and print the cube ... if the input was valid
    if cube.check_inputs():
        # Input was determined to be valid
        returnValue = cube.solve_cube()
        if returnValue == 1:
            print("PASS")
            numPass = numPass + 1

        elif returnValue == 2:
            print("FAIL - can't solve white side")

        elif returnValue == 3:
            print("FAIL - can't solve middle layer")

        elif returnValue == 4:
            # This file is supposed to fail. So, if it catches it, PASS
            if file == "../input/input_bad_1.txt":
                print("PASS")
                numPass = numPass + 1

            # This file is supposed to fail. So, if it catches it, PASS
            elif file == "../input/input_bad_2.txt":
                print("PASS")
                numPass = numPass + 1

            # This file is supposed to fail. So, if it catches it, PASS
            elif file == "../input/input_bad_4.txt":
                print("PASS")
                numPass = numPass + 1
            else:
                print("FAIL - can't solve yellow side")

        elif returnValue == 5:
            # This file is supposed to fail. So, if it catches it, PASS
            if file == "../input/input_bad_3.txt":
                print("PASS")
                numPass = numPass + 1

            else:
                print("FAIL - can't solve last layer")

        else:
            print("FAIL - could not solve")
    else:
        # Input was determined to be invalid
        print("FAIL - bad input")

print()
print(" " * 4, "FILES TESTED: ", numTest)
print(" " * 4, "TESTS PASSED: ", format((numPass*100 / numTest), '.2f'), "%")
print()
print(line_decoration)
print()
