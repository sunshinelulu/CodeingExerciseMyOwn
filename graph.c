#include<stdio.h>
#include<limits.h>
#include<time.h>
#define Row 6
#define Col 6
#define False 0
#define True 1
extern void printArray(int v[], int n);
typedef struct{
	int arcs[Row][Col];
	int vexnum;
	int arcnum;
}MGraph;
typedef int Path;
typedef int MinDist;
void holdScreen(){
	getchar();
}
void readInfo(){
	FILE * fp;
	fp = fopen("D:/eclipse workspace/C/graph.txt", "r");
	printf("open start\n");
	if(fp != NULL){
		int start,end, weight;
		while(fscanf(fp, "%d %d %d", &start, &end, &weight) >= 3)
			printf("%d %d %d \n", start, end, weight);

	}else{
		printf("file open failed\n");
	}
	printf("open end\n");
	fclose(fp);
}
void setGraph(MGraph* G){
	int u,v;
	//inital the graph arcs.
	for(u= 0; u< Row; u++){
		for(v= 0; v< Row; v++){
			G->arcs[u][v] = INT_MAX;
		}
	}
	G->arcnum = 0;
	G->vexnum = Row;
	//read data from file;
	FILE * fp;
	fp = fopen("D:/eclipse workspace/C/graph.txt", "r");
	printf("open start\n");
	if(fp != NULL){
		int start,end, weight;
		while(fscanf(fp, "%d %d %d", &start, &end, &weight) >= 3){
			G->arcs[start][end] = weight;
			G->arcnum +=1;
		}
	}else{
		printf("file open failed\n");
	}
	printf("open end\n");
	fclose(fp);
}

void Dijkstra(MGraph G, int v0, MinDist *D, Path *P){
	int S[Row];
	int v;
	int i;
	for(v= 0; v<G.vexnum; v++){
		S[v]=False;
		D[v]=G.arcs[v0][v];
	}
	for(v= 0; v<G.vexnum; v++){
		if(D[v] < INT_MAX)
			P[v] = v0;
	}
	D[v0]=0;S[v0]=True;P[v0]=v0;
	for(i = 1; i < G.vexnum; ++i){
		int min = INT_MAX;
		int minV;
		for(v = 0; v < G.vexnum; v++){
			if(S[v] == False){
				if(D[v] < min){
					minV = v;
					min = D[v];
				}
			}
		}
		S[minV] = True;
		//update distance
		for(v = 0; v < G.vexnum; v++){
			if(S[v] == False &&  G.arcs[minV][v] < INT_MAX && min+G.arcs[minV][v] < D[v]){
					D[v] = min+G.arcs[minV][v];
					P[v] = minV;
			}
		}
	}
}

int main()
{
	MGraph G;
	setGraph(&G);
	int v0=0;
	MinDist D[Row];
	Path P[Row];
	Dijkstra(G, v0, D, P);
	printArray(D, sizeof(D)/sizeof(int));
	printArray(P, sizeof(P)/sizeof(int));

	return 0;
}
