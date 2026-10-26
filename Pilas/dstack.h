#ifndef _DSTACK
	#define _DSTACK
	typedef char element;
	typedef struct nodeDS{
		element e;
		struct nodeDS *next;
	} NodeDS;
	int is_emptyDS(NodeDS *ds);
	void createDs (NodeDS **ds); 
	void push(NodeDS **ds, element ele);
	element pop(NodeDS **ds);
	void printStack(NodeDS *ds, const char *nombre);
	void suma(char *num1, char *num2);
	void checarExpresion(const char *expresion);
	#include "dstack.c"
#endif

