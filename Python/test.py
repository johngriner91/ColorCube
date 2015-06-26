from Cube import Cube

#Variables
data =[]

#Here is a comment. This will do nothing to the program.
with open("input.txt") as textFile:
    for line in textFile:
        for face in line.split():
            data.append(face)

cube = Cube(data)
if cube.check_inputs():
  cube.solve_cube()
  cube.print_val()