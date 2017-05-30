#include <stdio.h>

struct reg {
    int num;                                            //Data structure
    char str[255];
    float numf;
};


int main(int argc, char **argv) {

    struct reg p;                                       //The connection data structure
    FILE *fp;

    fp = fopen(argv[1], "rb\n");                        //Open file

    if (fp == NULL) {
        printf("Can't open file\n");
        return 0;
    }

    while (fread(&p , sizeof(struct reg),1, fp))        //Reading data from a file
        printf("%d %s %f\n", p.num, p.str, p.numf);     //Output data from a file

    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    rewind(fp);
    printf("Size in bytes : %d\n", fileSize);           //Output file size

    fclose(fp);
    return 1;
}