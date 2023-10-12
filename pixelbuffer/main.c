#include <stdio.h>
#include <stdlib.h>

#define PIXEL_Y 1
#define PIXEL_X 5 
#define PIXEL_SIZE PIXEL_X * PIXEL_Y
typedef struct Pixel{
    unsigned char r, g, b, a
} Pixel;

int main(void){


    Pixel* buffer = calloc(PIXEL_SIZE, sizeof(Pixel));
    Pixel red = {255,0,0,255};
    buffer[1] = red;
    for(int i = 0; i < PIXEL_SIZE; i++){
        printf("Pixel data: %u", buffer[i].r);
        printf("Pixel data: %u", buffer[i].g);
        printf("Pixel data: %u", buffer[i].b);
        printf("Pixel data: %u", buffer[i].a);
    }

    return 0;


}