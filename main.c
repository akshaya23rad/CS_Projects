#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>

int main() {
    Matrix matrix = matrix_construction();
    char *frst_string;
    char *scnd_string;
    frst_string = (char*) malloc(sizeof(char));
    scnd_string = (char*) malloc(sizeof(char));
    FILE *file_in_op=fopen("in_f1.txt","r");
    
    int read = fscanf( file_in_op,"%s %s ",frst_string,scnd_string);
    while(read!=-1){
        
        if(matrix_isin(matrix,frst_string,scnd_string) == 1){
            matrix_inc(matrix,frst_string,scnd_string,1);
        }else{
            matrix_set(matrix,frst_string,scnd_string,1);
            
        }
        read = fscanf(file_in_op,"%s %s",frst_string, scnd_string);
    }

    printf("%s \t %s \t %s \t \n","String 1","String 2","Occurrence");
    matrix_list(matrix);
    
    fclose(file_in_op);
    return 0;
}

