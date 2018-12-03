mymatrix: main.c datatype.c datatype.h bstree.c bstree.h matrix.h matrix.c
	gcc -o mymatrix main.c datatype.c datatype.h bstree.c bstree.h matrix.h matrix.c -I.

clean:
	rm -f mymatrix*.o core mymatrix

