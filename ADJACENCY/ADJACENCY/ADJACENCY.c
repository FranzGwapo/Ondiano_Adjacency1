#include "ADJACENCY.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initList(List *list){
	int i, j;
	for(i=0;i<26;++i){
		strcpy(list[i].key, "EMPTY") ;
//		list[i].value.arr = malloc(sizeof(Vertex)*MAX);
//		list[i].value.count = 0;
//		list[i].value.max = MAX;
		list[i].value.arr = malloc(sizeof(Vertex)*MAX);
	
		for(j=0;j<MAX;++j){
			strcpy(list[i].value.arr[j].city, "NULL");
		}
		list[i].value.count = 0;
		list[i].value.max = MAX;
		list[i].value.status = 4;	
	}


}

void initDict(List *list, int num){
	int i;
	list[num].value.arr = malloc(sizeof(Vertex)*MAX);

	for(i=0;i<MAX;++i){
		strcpy(list[num].value.arr[i].city, "NULL");
	}
	list[num].value.count = 0;
	list[num].value.max = MAX;
	list[num].value.status = 3;

}


int Hash(int firstchar){
	return firstchar%SIZE;
}

bool addVertex(List *list, String key){
	int num, firstchar = key[0];
	num = Hash(firstchar);
	
	while(strcmp(list[num].key, key)!=0){

		if(strcmp(list[num].key, "EMPTY")!=0 || list[num].key == "DELETED"){
			num = Hash(++firstchar)%SIZE;
		}

		else{
			if(strcmp(list[num].key, "EMPTY")==0){
				strcpy(list[num].key, key);
				list[num].value.status = 3;
				return true;
			}
		}
	}
	return false;

}

bool addEdge(List *list,String vertex, String edge){
	int i;
	bool vstate = true, estate = true; //VertexState and EdgeState
	int vertexchar = vertex[0];
	int edgechar = edge[0];
	int vertexhash = Hash(vertexchar);
	int edgehash = Hash(edgechar);
	int checkhash;

	while(strcmp(list[vertexhash].key, vertex)!=0 && list[vertexhash].value.status<4){
		vertexhash = (vertexhash+1)%SIZE;
		if(strcmp(list[vertexhash].key, vertex)==0){
			vstate = true;
			break;
		}
		vstate = false;
	}
	
	if(strcmp(list[vertexhash].key, vertex)==0){
		vstate = true;
	}

	while(strcmp(list[edgehash].key, edge)!=0 && list[edgehash].value.status<4){
		edgehash = (edgehash+1)%SIZE;
		if(strcmp(list[edgehash].key, edge)==0){
			estate = true;
			break;
		}
		estate = false;

	}
	if(strcmp(list[vertexhash].key, vertex)==0){
		estate = true;
	}

	
	if(vstate && estate){
//		printf("Vertex index: %d\n", vertexhash);
		for(i=0;i<MAX;++i){
			if(strcmp(list[vertexhash].value.arr[i].city, "NULL")==0){
				strcpy(list[vertexhash].value.arr[i].city, edge);
				list[vertexhash].value.status = 3;
				list[vertexhash].value.count++;
				printf("count: %d\n", list[vertexhash].value.count);
				break;
			}
			else{
				
			}
		}
//		printf("Edge index: %d\n", edgehash);
		for(i=0;i<MAX;++i){
			if(strcmp(list[edgehash].value.arr[i].city, "NULL")==0){
				strcpy(list[edgehash].value.arr[i].city, vertex);
				list[edgehash].value.status = 3;
				list[edgehash].value.count++;
				printf("count: %d\n", list[edgehash].value.count);
				break;
			}
			else{
				
			}
		}
		return true;
	}
	else{
		return false;
	}

	
	return true;
}
