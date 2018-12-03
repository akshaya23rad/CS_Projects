#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

//Matrix construction using bstree ini()
Matrix matrix_construction(void)
{
    Matrix mtx = bstree_ini();
    return mtx;
}

//If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
unsigned char matrix_isin(Matrix m, Index index1, Index index2)
{
    Data data = bstree_search(m, key_gen(index1,index2));
    if(data!=NULL)
    {
        return 1;
    }
    else 
        return 0;
}

//If location (index1, index2) is defined in Matrix m, then return a pointer to the associated value. Otherwise, return NULL.
Value *matrix_get(Matrix m, Index index1, Index index2)
{
    Data mtx_data = bstree_search(m, key_gen(index1,index2)); 
    if(matrix_isin(m,index1,index2)==1)
    {
        return mtx_data;
    }
    else{
        return NULL;
    }
    
}

//Assign value to Matrix m at location (index1, index2). If that location already has value, then overwrite.
void matrix_set(Matrix m, Index index1, Index index2, Value value)
{

    Data mtx_data = bstree_search(m, key_gen(index1,index2)); 
    if(mtx_data!=NULL)
    {
        data_set(mtx_data,value);
    }
    else
    {
        bstree_insert(m,key_gen(index1,index2),data_gen(value));
        
    }
}

//If location (index1, index2) is defined in Matrix m, then increase the associated value by value. Otherwise, report error.
void matrix_inc(Matrix m, Index index1, Index index2,Value value)
{
    Data mtx_data = bstree_search(m, key_gen(index1,index2));
    if(mtx_data!=NULL)
    {
        data_set(mtx_data,*mtx_data+value);
    }
    else
    {
        printf("error");
    }
}


//Print indices and values in the Matrix m (with bstree traversal()).
void matrix_list(Matrix m)
{
    bstree_traversal(m);
}


//Free allocated space (with bstree free()).
void matrix_destruction(Matrix m)
{
    bstree_free(m);
}
