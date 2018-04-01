// from codeforces.com/problemset/problem/20/C
#include <stdio.h>

int A[1001][1001]; 
/* Its giving me segmentation fault, when I am trying to create an array
 * of size 100001  x 100001 
 */
int min_edge_vertex(int vertex,int n) {
	int min = 10000001;
	int edge = -1;
	for ( int i = 1; i <= n; i++) {
		if ( vertex != i && A[vertex][i] < min) {
			min = A[vertex][i];
			edge = i;
		}
	}
	for ( int i = 1; i <= n; i++) {
		if (vertex != i && A[i][vertex] < min) {
			min = A[i][vertex];
			edge = i;
		}
	}
	return edge;
}

int find_path(int vertex_path[], int source_vertex,int destination_vertex) {
	int index = 0;
    int size = destination_vertex - source_vertex + 1;
 	vertex_path[index++] = source_vertex;
	int current_vertex = source_vertex;	
	int vertex_count = 0;

	while ( current_vertex != destination_vertex && vertex_count <= destination_vertex - source_vertex + 1) {
		int next_edge = min_edge_vertex(current_vertex, destination_vertex-source_vertex+1);	
		++vertex_count ;
		if (next_edge == -1) {
			return -1;
		} else {
			vertex_path[index++] = next_edge;
		}
		current_vertex = next_edge;		
	}
	return 1;
}


		
int main(int argc, char * argv ) {
	int n,m,v1,v2,dist;
	int Connected_Vertex_sortest[m+1];
	for(int i = 1 ; i <= m; i++) {
		scanf("%d%d%d",&n,&m,&dist);
		A[n][m] = dist;
	}
	int is_path = find_path(Connected_Vertex_sortest, 1, n);		

	//for(i = 0; i < 10; i ++) 
	//	for ( j = 0; j < 10; j++)
	//		printf("%d ",A[i][j]);
	//
	//printf("hello, world\n");
	return 0;
}
