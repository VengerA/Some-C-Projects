#include<stdio.h>
#include<stdlib.h>




int main (){
    FILE *p;
    char ch;

    p = fopen("sample.dat", "r");

    while((ch = fgetc(p)) != EOF){
        printf("%c", ch);
    }
    fclose(p);
    printf("\n");

    return 0;
}