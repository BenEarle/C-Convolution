#include <stdio.h>
#include <stdlib.h>
#include "convolution.h"

int main() {
	FILE *fptr;
	char filename[100], c; 
	int EDGE_DETECT_KERNEL1[KERNEL_HEIGHT][KERNEL_WIDTH] = {
		{-1, -1, -1},
		{-1,  8, -1},
		{-1, -1, -1}
	};
	int EDGE_DETECT_KERNEL2[KERNEL_HEIGHT][KERNEL_WIDTH] = {
		{0,  -1,  0},
		{-1,  4, -1},
		{0,  -1,  0}
	};
	int EDGE_DETECT_KERNEL3[KERNEL_HEIGHT][KERNEL_WIDTH] = {
		{0,  1,  0},
		{1, -4,  1},
		{0,  1,  0}
	};
	int EDGE_DETECT_KERNEL4[KERNEL_HEIGHT][KERNEL_WIDTH] = {
		{1,  0,  -1},
		{0,  0,  0},
		{-1, 0,  1}
	};
	double BLUR_KERNEL[KERNEL_HEIGHT][KERNEL_WIDTH] = {
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1}
	};
	// unsigned char img[] = rgb;

#if 0
	printf("Enter the filename to open \n"); 
	scanf("%s", filename); 
	// Open file 
	fptr = fopen(filename, "r"); 
	if (fptr == NULL) 
	{ 
		printf("Cannot open file \n"); 
		exit(0); 
	} 

	// Read contents from file 
	c = fgetc(fptr); 
	for(int i = 0; i < sizeof(data); i++)
	{ 
		if(i%3 == 0)
			data[(i/3)%INPUT_IMAGE_WIDTH][(i/3)/INPUT_IMAGE_WIDTH].red = fgetc(fptr);
		else if (i%3 == 1)
			data[(i/3)%INPUT_IMAGE_WIDTH][(i/3)/INPUT_IMAGE_WIDTH].green = fgetc(fptr);
		else 
			data[(i/3)%INPUT_IMAGE_WIDTH][(i/3)/INPUT_IMAGE_WIDTH].blue = fgetc(fptr);
	} 

	fclose(fptr); 
#endif
	//Unpack the image an populate the RGB array
	for(int i = 0; i < (INPUT_IMAGE_WIDTH * INPUT_IMAGE_HEIGHT * 4); i+=4) { 
		data[(i/4)/(INPUT_IMAGE_WIDTH)][(i/4)%(INPUT_IMAGE_WIDTH)].red = img1[i+2];
		data[(i/4)/(INPUT_IMAGE_WIDTH)][(i/4)%(INPUT_IMAGE_WIDTH)].green = img1[i+1];
		data[(i/4)/(INPUT_IMAGE_WIDTH)][(i/4)%(INPUT_IMAGE_WIDTH)].blue = img1[i];		
		#if DEBUG
			printf( "[%i][%i] = (%i,%i,%i,%i)\n",(i/4)%(INPUT_IMAGE_WIDTH), (i/4)/(INPUT_IMAGE_WIDTH), rgb[i+2],rgb[i+1],rgb[i],rgb[i+3]); 
		#endif
	}
	// for (int k = 0; k < KERNEL_HEIGHT; k++){
	// 	for (int l = 0; l < KERNEL_WIDTH; l++){
	// 		printf("%d, ", EDGE_DETECT_KERNEL[k][l]);
	// 	}
	// 	printf("\n");	
	// }
	grayScale( data, out);
	convolve( out, out2, EDGE_DETECT_KERNEL1,1);

	char x[] = "img1.rgb";
	// Open file 
	fptr = fopen(x, "w"); 
	if (fptr == NULL) 
	{ 
		printf("Cannot open file \n"); 
		exit(0); 
	} 

	fwrite(out2, sizeof(char), sizeof(data),fptr);
	return 0; 
}