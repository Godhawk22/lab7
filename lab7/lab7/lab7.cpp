#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#include <locale.h>

int** createG(int** G, int sizeG) {
	G = (int**)malloc(sizeG * sizeof(int*));
	for (int i = 0; i < sizeG; i++) {
		G[i] = (int*)malloc(sizeG * sizeof(int));
		for (int j = 0; j < sizeG; j++) {
			G[i][j] = 0;
		}
	}
	for (int i = 0; i < sizeG; i++) {
		for (int j = i + 1; j < sizeG; j++) {
			if (rand() % 2) {
				G[i][j] = 1;
				G[j][i] = 1;
			}
		}
	}
	return G;
}

void printG(int** G, int sizeG) {
	for (int i = 0; i < sizeG; i++) {
		for (int j = 0; j < sizeG; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
}

void DFS(int** G, int sizeG, int v, int* vis) {
	vis[v] = 1;
	printf("%d ", v + 1);
	for (int i = 0; i < sizeG; i++) {
		if (G[v][i] == 1 && vis[i] == 0) {
			DFS(G, sizeG, i, vis);
		}
	}
}

//void DFS(int** G, int N, int* vis, int v) {
//	int* stack = (int*)malloc(N * sizeof(int));
//	int top = -1;
//
//	stack[++top] = v;
//
//	while (top != -1) {
//		int vec = stack[top--];
//		if (vis[vec] == 0) {
//			vis[vec] = 1;
//			printf("%d ", vec + 1);
//		}
//		for (int i = N - 1; i >= 0; i--) {
//			if (G[vec][i] == 1 && vis[i] == 0) {
//				stack[++top] = i;
//			}
//		}
//	}
//}

int main(void)
{
	setlocale(LC_ALL, "");
	int** G = NULL;
	int sizeG = 10;
	int v = 0;

	printf("Введите количество вершин графа 1: ");
	scanf("%d", &sizeG);
	G = createG(G, sizeG);
	printG(G, sizeG);

	printf("Введите номер вершины для старта: ");
	scanf("%d", &v);

	int* vis = (int*)malloc(sizeG * sizeof(int));
	for (int i = 0; i < sizeG; i++) {
		vis[i] = 0;
	}

	printf("Последовательность посещения вершин функцией DFS: \n");
	DFS(G, sizeG, v, vis);

	return 0;
}