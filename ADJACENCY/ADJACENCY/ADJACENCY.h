#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST
#include <stdbool.h>
#define MAX 5
#define SIZE 26

typedef char String[10];

typedef struct{
	String city;
}Vertex, *VertexPtr;

typedef struct{
	VertexPtr arr;
	int status; //1-DELETED 2-SYNONYM 3-FULL 4-EMPTY
	int count;
	int max;
}Dictionary;

typedef struct{
	String key;
	Dictionary value;
}List;

void initList(List *list);
void initDict(List *list, int num);
int Hash(int firstchar);
bool addVertex(List *list, String key);
bool addEdge(List *list,String vertex, String edge);

#endif
//first letter of your word
//count
//array
//max
