#include "convolution.h"
#include <stdio.h>
#include <stdlib.h>
void convolve(struct pixel data[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH], struct pixel out[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH], int kernel[KERNEL_HEIGHT][KERNEL_WIDTH], int scalar) {
	int tred=0, tblue=0, tgreen=0;
	int xCenter = KERNEL_WIDTH/2;
	int yCenter = KERNEL_HEIGHT/2;
	
	for (int i = 0; i < INPUT_IMAGE_HEIGHT; i++){
		for (int j = 0; j < INPUT_IMAGE_WIDTH; j++){
			tred = 0;
			tgreen = 0;
			tblue = 0;
			//printf("In: \n");
			for (int k = 0; k < KERNEL_HEIGHT; k++){
				for (int l = 0; l < KERNEL_WIDTH; l++){
					if(i-yCenter+k >-1 && i-yCenter+k < INPUT_IMAGE_HEIGHT && j-xCenter+l >-1 && j-xCenter+l < INPUT_IMAGE_WIDTH){
						tred += data[i-yCenter+k][j-xCenter+l].red*kernel[k][l];
						tgreen += data[i-yCenter+k][j-xCenter+l].green*kernel[k][l];
						tblue += data[i-yCenter+k][j-xCenter+l].blue*kernel[k][l];		
					}
					
					//printf("(%i, %i,%i) ",data[i-yCenter+k][j-xCenter+l].red,data[i-yCenter+k][j-xCenter+l].green,data[i-yCenter+k][j-xCenter+l].blue);
					//printf("(%d, %d,%d) ",data[i-yCenter+k][j-xCenter+l].red*kernel[k][l],data[i-yCenter+k][j-xCenter+l].green*kernel[k][l],data[i-yCenter+k][j-xCenter+l].blue)*kernel[k][l];
				}
				//printf("\n");
			}
			out[i][j].red = (char)abs(tred*scalar) & 0xFF;
			out[i][j].green = (char)abs(tgreen*scalar) & 0xFF;
			out[i][j].blue = (char)abs(tblue*scalar) & 0xFF;
			//printf("Out: (%i,%i,%i)\n",out[i][j].red ,out[i][j].green ,out[i][j].blue );
		}
	}
}
void grayScale(struct pixel data[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH], struct pixel out[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH]){
	int grey = 0;
	for (int i = 0; i < INPUT_IMAGE_HEIGHT; i++){
		for (int j = 0; j < INPUT_IMAGE_WIDTH; j++){
			grey = (data[i][j].red + data[i][j].green + data[i][j].blue)/3;	
			out[i][j].red = grey;
			out[i][j].green = grey;
			out[i][j].blue = grey;
		}
	}

}