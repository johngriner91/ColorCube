/*
Program: Color Cube - color_cube.java
Summary: The java implementation of the Color Cube program:


*/

public class HelloWorld
{
	public static void main() {
		//	Variables
		char cube[54];					//	array to store the cube colors
		ifstream inputFile;			//	input file that holds the faces

		inputFile.open("color_cube_input.txt");

		// Right now, there isn't any file checking. Because it's in the
		//	beginning stages, I know the input file will be in a correct
		//	format.
		for(int j = 0; j < 54; j++){
			inputFile >> cube[j];
		}

		//	The program is done reading the input file. We will go ahead
		//		and close the file.
		inputFile.close();

		//	Create a cube object
		//Cube puzzle(cube);

		//	Calle the method that will solve the cube.
		//puzzle.solve_cube();

		for(int i = 0; i < cube.length(); i++){
			System.out.print(cube[i] + "\n");
		}


		// End the program
		return 0;
	}
}
