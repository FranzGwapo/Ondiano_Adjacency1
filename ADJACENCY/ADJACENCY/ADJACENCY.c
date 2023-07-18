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

//void initDict(List *list, int num){
//	int i;
//	list[num].value.arr = malloc(sizeof(Vertex)*MAX);
//
//	for(i=0;i<MAX;++i){
//		strcpy(list[num].value.arr[i].city, "NULL");
//	}
//	list[num].value.count = 0;
//	list[num].value.max = MAX;
//	list[num].value.status = 3;
//
//}

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
		else if(list[num].value.status<=3){
			list[num].value.status = 2;
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
		for(i=0;i<MAX;++i){
			if(strcmp(list[vertexhash].value.arr[i].city, "NULL")==0){
				strcpy(list[vertexhash].value.arr[i].city, edge);
				list[vertexhash].value.status = 3;
				list[vertexhash].value.count++;
				break;
			}
			else{
				
			}
		}
		for(i=0;i<MAX;++i){
			if(strcmp(list[edgehash].value.arr[i].city, "NULL")==0){
				strcpy(list[edgehash].value.arr[i].city, vertex);
				list[edgehash].value.status = 3;
				list[edgehash].value.count++;
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

bool deleteEdge(List *list, int index, String edge){
	int i, j;
	bool state;
	int echar = edge[0];
	int ehash = Hash(echar);
	for(i=0;i<MAX;++i){
		j=i;
		if(strcmp(list[index].value.arr[i].city, edge)==0){
			do{

				strcpy(list[index].value.arr[j].city, list[index].value.arr[j+1].city);
				j++;
			}
			while(strcmp(list[index].value.arr[j].city, "NULL")!=0);

			list[index].value.count = list[index].value.count-1 ;
			state = true;
		}
	}
	return false;
}

bool deleteVertex(List *list, String vertex){
	int i, j;
	int vchar = vertex[0];
	int vhash = Hash(vchar);
	
	while(strcmp(list[vhash].key, vertex)!=0){
		vchar = vertex[0];
		vhash = Hash(vhash+1)%SIZE;
	}
	if(strcmp(list[vhash].key, vertex)==0){
		strcpy(list[vhash].key, "DELETED");
		for(i=0;i<MAX;++i){
			strcpy(list[vhash].value.arr[i].city, "NULL");
		}
		list[vhash].value.count = 0;
		list[vhash].value.max = MAX;
		list[vhash].value.status = 1;
		
		for(j=0;j<SIZE;++j){
			if(list[j].value.status!=4 && list[j].value.status != 1){
				deleteEdge(list, j, vertex);
			}
		}
		return true;
	}
	else{
		return false;
	}
}

void displayList(List *list){
	int i,j;
	for(i=0;i<26;++i){
		if(list[i].value.status!=1 && list[i].value.status!=4){
			printf("Vertex: %s Edges: ", list[i].key);
			for(j=0;j<list[i].value.count;++j){
				if(list[i].value.count!=0 && strcmp(list[i].value.arr[j].city, "NULL")!=0){
					printf("%s, ", list[i].value.arr[j].city);
				}
			}
			printf("\n");	
		}
		
	}
}
