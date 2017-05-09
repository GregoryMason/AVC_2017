#include <stdio.h>
#include "E101.h"

/*Returns the average values of the pixels of 3 rows
 *(one row above, and one row below the passed row int)
 *int row must be between 1 and 238
 */
void getRow(int row){
	int rowsAv[32];
	int pixelTotal = 0; 	//Total value of the pixels from all 3 rows
	int average; 	    	//average value of the three pixels
	int max = 100;
	
	for (int pixel = 0; pixel < 320; pixel += 10) { //Get's every 4th pixel
		pixelTotal = get_pixel(row-1,pixel,3) + get_pixel(row,pixel,3) + get_pixel(row+1,pixel,3);
		average = pixelTotal/3;
		rowsAv[pixelRow] = average;
		if (average > max) max = average;
	}
	
	int threshold = max / 2;
	
	for (int pixel = 0; pixel < 32; pixel++) {
		if (rowsAv[pixel] > threshold) {
			linePlace[pixel] = 1;
		} else {
			linePlace[pixel] = 0;
		}
	}
}

/*Detects where the white line is in relation to the centre of the robot.
 *returns positive integer if line is to the right
 *returns negative integer if line is to the left
 */
double detectLine(){
	//take a picture
	take_picture();
	display_picture(1,0);
	
	getRow(200);
	
	double error = 0;
	int numPixels = 0;
	for (int pixel = 0; pixel < 32; pixel++) {
		if (linePlace[pixel] == 1){
			error += (pixel-16);
			numPixels++;
		}
	}
	if (numPixels > 0) {
		return (error/numPixels);
	}
return 0;}
