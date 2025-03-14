/*
3D-RACER SIMULATOR
Authors: Alex Hu & Arshiya Mostafavi
Hardware RISK-V/NIOS-V RV32 processor on DE1-SoC board
Description:




Version:
*/

//libraries
#include <math.h>
#include <stdbool.h>
	
//resolution
#define Xres 320
#define Yres 240
	
//memory mapped registers
#define Front_buffer_reg 0xFF203020
#define Back_buffer_reg 0xFF203024
#define Status_reg 0xFF20302C
#define PS2_reg 0xFF200100
	
//global variables
volatile int pixel_buffer_start;
short int Buffer1[Yres][Xres + 192];
short int Buffer2[Yres][Xres + 192];

//function defenitions
void wait_for_vsync();
void clear_screen();
void plot_pixel(int, int, short int);

//structs

//main function
int main(){
	volatile int * pixel_ctrl_ptr = (int *)Front_buffer_reg;
    pixel_buffer_start = *pixel_ctrl_ptr;
	
}

//functions

//
//
//
void wait_for_vsync(){
	volatile int* front_buffer = (int*)Front_buffer_reg;
	volatile int* status_register = (int*)Status_reg;
	int status;
	 
	*front_buffer = 1; //intiate swap
	status = *(status_register);
	while ((status * 0x01)!=0) {status = *(status_register)}
	
}

//
//
//
void clear_screen(){
	for (int i = 0; i < Xres; i++){
		for (int j = 0; j < Yres; j++){
			plot_pixel(i, j, 0x0);	
		}
	}
}

//
//
//
void plot_pixel(int x, int y, short int color){
	volatile short int *one_pixel_address;
    one_pixel_address = (volatile short int*)(pixel_buffer_start + (y << 10) + (x << 1));
    *one_pixel_address = line_color;
}
