#include <stdio.h>
#include <stdlib.h>
#include "ADJACENCY.h"

#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	List arr[26];
	initList(arr);
	bool state;
	int i, j;
	
	state = addVertex(arr, "Tokyo");
	state = addVertex(arr, "Taiwan");
	state = addVertex(arr, "Chile");
	state = addVertex(arr, "Cebu");
	state = addVertex(arr, "Cthullu");
	state = addVertex(arr, "Manila");
	state = addVertex(arr, "Mandaue");
	state = addVertex(arr, "Marinduque");

	for(i=0;i<26;++i){
		printf("Vertex: %s\n", arr[i].key);
	}


	state = addEdge(arr, "Tokyo", "Manila");
	state = addEdge(arr, "Cebu", "Tokyo");
	state = addEdge(arr, "Cebu", "Cthullu");
	state = addEdge(arr, "Tokyo", "Cthullu");
	state = addEdge(arr, "Mandaue", "Cebu");
	state = addEdge(arr, "Chile", "Cthullu");
	state = addEdge(arr, "Marinduque", "Chile");
	state = addEdge(arr, "Tokyo", "Marinduque");

	
	
	printf("WITH EDGES \n\n");
	displayList(arr);
	
	//DeleteEdge is in DeleteVertex Function
	deleteVertex(arr, "Tokyo");
	deleteVertex(arr, "Cebu");
	printf("\nDELETED VERTEX(Tokyo and Cebu) \n\n");
	displayList(arr);
	return 0;
}
