#ifndef CONVOLUTION
#define CONVOLUTION 

#define INPUT_IMAGE_WIDTH 276
#define INPUT_IMAGE_HEIGHT 155
#define KERNEL_WIDTH 3
#define KERNEL_HEIGHT 3
#define DEBUG 0

struct pixel {
	unsigned char red;
	unsigned char green;
	unsigned char blue;	
} pixel_t;

void convolve(struct pixel data[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH], struct pixel out[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH], int kernel[KERNEL_HEIGHT][KERNEL_WIDTH], int scalar);
void grayScale(struct pixel data[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH], struct pixel out[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH]);
extern unsigned char img1[];
struct pixel data[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH];
struct pixel out[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH];
struct pixel out2[INPUT_IMAGE_HEIGHT][INPUT_IMAGE_WIDTH];


#endif 