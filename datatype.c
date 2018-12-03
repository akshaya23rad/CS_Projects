#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

//Duplicate string pointed to by str with dynamic memory allocation
char *string_dup(char *str)
{
    int size = strlen(str) + 1;
    char *dupl_icate = malloc(size);
    if(dupl_icate)
    {
        strcpy(dupl_icate, str);
    }
    return dupl_icate;
}


//Generate a key with dynamic memory allocation.
Key key_gen(char *skey_1, char *skey_2)
{
    Key k_e_y;
    k_e_y = (Key) malloc(sizeof(Key_struct));
    k_e_y->skey1 = string_dup(skey_1);
    k_e_y->skey2 = string_dup (skey_2);
    return k_e_y;
}

//comapre keys
int key_comp(Key key1, Key key2)
{
    //create variables for two keys 
    int v_Key1 = strcmp(key1-> skey1, key2 -> skey1);
    int v_Key2 = strcmp(key1-> skey2, key2 -> skey2);
    //checkes if comparison of first key is the same 
    if (v_Key1==0){
        if (v_Key2<0)
            return -1;
	//checks in value of second key is the same 
        else if (v_Key2==0)
            return 0;
        else
            return 1;
    }else{
        return v_Key1;
    }
    
}

//prints key
void key_print(Key key)
{
    printf("%s \t\t %s \t\t", key->skey1, key->skey2);
    
}

//frees key memory
void key_free(Key key)
{
    free(key->skey1);
    free(key->skey2);
}

//Generate a data with dynamic memory allocation.
Data data_gen (int idata)
{
    Data data_p;
    data_p = (Data) malloc (sizeof(int));
    *data_p = idata;
    return data_p;
}

//Assign data with idata.
void data_set(Data data, int idata)
{
    *data=idata;
}

//Print a data.
void data_print(Data data)
{
    printf("%d \n", *data);
}

//Free memory allocated for data.
void data_free(Data data)
{
    free(data);
}

