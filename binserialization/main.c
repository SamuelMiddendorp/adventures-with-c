#include <stdio.h>

typedef struct MyStruct{
    int x;
} MyStruct;

int main(void){
    MyStruct x = {20};

    FILE* file_out;
    FILE* file_in;

    fopen_s(&file_out, "foo.bun2d", "wb");

    if (file_out == NULL){
        return 1;
    }

    size_t elemsWritten = fwrite(&x, sizeof(MyStruct), 1, file_out);
    
    fclose(file_out);
    printf("Elements written: %i", elemsWritten);

    fopen_s(&file_in, "foo.bun2d", "rb");

    MyStruct in;

    fread(&in, sizeof(MyStruct), 1, file_in);
    fclose(file_in);
    printf("Value: %i", in.x);
    return 0;
}

