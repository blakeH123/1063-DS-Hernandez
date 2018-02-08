/*@ProgramName: Program-1
* @Author: Blake Hernandez
* @Description:
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 09 02 2018
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

// Structure to hold an rgb value
struct rgb {
	int r;
	int g;
	int b;
};

/*@FunctionName: flipHorz
* @Description:
*     Loops through a 2D array and swaps the array from left to right,
	  horizontally "flipping" it.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns: void
*/
void flipHorz(rgb** image, int width, int height)
{	int Rtemp, Gtemp, Btemp, k;			// temporary variables for swap that
							// "flips" the array horizontaly
	int halfwidth = width / 2;			// speeds up for loop execution
	for (int i = 0; i < height; i++)
	{	for (int j = 0; j < halfwidth; j++) 	// halfwidth used for swap to end
							// the loop because if we used width,
							// we would get what we started with.
		{	k = width - 1 - j;		// k, used to meet j in the middle
							// for swap.
			Rtemp = image[i][j].r;		// Swap begins
			Gtemp = image[i][j].g;
			Btemp = image[i][j].b;

			image[i][j].r = image[i][k].r;
			image[i][j].g = image[i][k].g;
			image[i][j].b = image[i][k].b;

			image[i][k].r = Rtemp;
			image[i][k].g = Gtemp;
			image[i][k].b = Btemp;		 // Swap ends
		} // end inner for loop
	} // end outer for loop
} // end of flipHorz function

/*@FunctionName: changeColor
* @Description:
*     Loops through a 2D array and swaps it from top to bottom, vertivally
	  "flipping" it.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns: void
*/
void flipVert(rgb** image, int width, int height)
{	int Rtemp, Gtemp, Btemp, k;			// temporary variables for the swap
							// that "flips" the array
	int halfheight = height / 2;			// saves execution time in for loop
							// by not performing same opperation
							// multiple times
	for (int j = 0; j < width; j++)
	{	for (int i = 0; i < halfheight; i++)	// halfheight used for swap to end
							// the loop because if we used width,
							// we would get what we started with.
		{	k = height - 1 - i;		// k, used to meet i in the middle
							// for swap
			Rtemp = image[i][j].r;		// Swap begins
			Gtemp = image[i][j].g;
			Btemp = image[i][j].b;

			image[i][j].r = image[k][j].r;
			image[i][j].g = image[k][j].g;
			image[i][j].b = image[k][j].b;

			image[k][j].r = Rtemp;
			image[k][j].g = Gtemp;
			image[k][j].b = Btemp;		 // Swap ends
		} // end of inner for loop
	} // end of outer for loop
} // end of flipVert function

/*@FunctionName: grayScale
* @Description:
*     Loops through a 2D array and turns every RGB value into its greyscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns: void
*/
void greyScale(rgb** image, int width, int height)
{	int r, g, b, grey;
		for (int i = 0; i<height; i++)
		{	for (int j = 0; j<width; j++)
			{	r = image[i][j].r;
				g = image[i][j].g;
				b = image[i][j].b;

				grey = (r + g + b) / 3;

				image[i][j].r = grey;
				image[i][j].g = grey;
				image[i][j].b = grey;
			} // end of inner for loop
	} // end of outer for loop
} // end of greyScale funtcion


int main() 
{	ifstream ifile;          //Input / output files
	ofstream ofile;
	ifile.open("bot.txt");
	ofile.open("bot2.txt");

	int width;               //width of image
	int height;              //height of image

	rgb **imgArray;         //Pointer var for our 2D array because we         
				//don't know how big the image will be!

	ifile >> width >> height;//Read in width and height from top of input file
				 //We need this so we can make the array the right 
				 //size. After we get these two values, we can
				 //now allocate memory for our 2D array.

	imgArray = new rgb*[height];    //This array points to every row

	for (int i = 0; i<height; i++)
	{	imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	//Read the color data in from our txt file
	for (int i = 0; i < height; i++)
	{	for (int j = 0; j < width; j++)
		{	ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}

	// Print original image
	ofile << "This is th original image." << endl << width << " " << height
		<< endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " "
				<< imgArray[i][j].b << " ";
		}
		ofile << endl;
	}

	// Function call	Horizontal
	flipHorz(imgArray, width, height);

	//  Print Horizontal
	ofile << "This image is horizontally flipped." << endl << width << " "
		<< height << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " "
				<< imgArray[i][j].b << " ";
		}
		ofile << endl;
	}

	// Funtion call		Vertial
	flipVert(imgArray, width, height);

	// print Vertical
	ofile << "This image is vertically flipped." << endl << width << " "
		<< height << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " "
				<< imgArray[i][j].b << " ";
		}
		ofile << endl;
	}

	// Function Call	Greyscale
	greyScale(imgArray, width, height);

	// Print Greyscale
	ofile << "This image is greyscaled." << endl << width << " " << height
		<< endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " "
				<< imgArray[i][j].b << " ";
		}
		ofile << endl;
	}
	return 0;
} // end of main
