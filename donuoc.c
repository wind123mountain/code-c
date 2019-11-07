#include<stdio.h>
#include<conio.h>
#include <stdbool.h>
#define value 2

int V[3];
bool visited[5][8][11];
bool isFound;

void init(){
	isFound = false;
	V[0] = 4;
	V[1] = 7;
	V[2] = 10;
	int i=0, j=0, k=0;
	for(i=0;i<5;i++)
		for(j=0;j<8;j++)
			for(k=0;k<11;k++)
				visited[i][j][k]=false;
	
}

void exe(int v4, int v7, int v10){
	if(v4==value||v7==value){
		isFound = true;
		return;
	} else {
		printf("%d--- %d----%d\n",v4,v7,v10);
            int t4 = v4, t7 = v7, t10 = v10;
            //do nuoc tu 4 sang 7
            if (v7 < V[1] && v4 != 0 && !isFound) {
                visited[v4][v7][v10] = true;
                int temp1 = V[1] - v7;
                int temp2 = v4 - temp1 >= 0 ? v4 - temp1 : 0;
                v7 = v4 - temp1 < 0 ? v4 + v7 : V[1];
                v4 = temp2;
                if (!visited[v4][v7][v10]) {
                    printf("do nuoc binh 4 sang binh 7\n");
                    exe(v4, v7, v10);
                }
            }
            //do nuoc tu 7 sang 4
            v4 = t4;
            v7 = t7;
            v10 = t10;
            if (v4 < V[0] && v7 != 0 && !isFound) {
                visited[v4][v7][v10] = true;
                int temp = V[0] - v4;
                int temp2 = v7 - temp >= 0 ? v7 - temp : 0;
                v4 = v7 - temp < 0 ? v7 + v4 : V[0];
                v7 = temp2;
                if (!visited[v4][v7][v10]) {
                    printf("do nuoc binh 7 sang binh 4\n");
                    exe(v4, v7, v10);
                }
            }
            //do nuoc tu 7 sang 10
            v4 = t4;
            v7 = t7;
            v10 = t10;
            if (v10 < V[2] && v7 != 0 && !isFound) {
                visited[v4][v7][v10] = true;
                int temp = V[2] - v10;
                int temp2 = v7 - temp >= 0 ? v7 - temp : 0;
                v10 = v7 - temp < 0 ? v7 + v10 : V[2];
                v7 = temp2;
                if (!visited[v4][v7][v10]) {
                    printf("do nuoc binh 7 sang binh 10\n");
                    exe(v4, v7, v10);
                }
            }
            //do nuoc tu 10 sang 7
            v4 = t4;
            v7 = t7;
            v10 = t10;

            if (v7 < V[1] && v10 != 0 && !isFound) {
                visited[v4][v7][v10] = true;
                int temp = V[1] - v7;
                int temp2 = v10 - temp >= 0 ? v10 - temp : 0;
                v7 = v10 - temp < 0 ? v10 + v7 : V[1];
                v10 = temp2;
                if (!visited[v4][v7][v10]) {
                    printf("do nuoc binh 10 sang binh 7\n");
                    exe(v4, v7, v10);
                }
            }
            //do nuoc tu 4 sang 10
            v4 = t4;
            v7 = t7;
            v10 = t10;

            if (v10 < V[2] && v4 != 0 && !isFound) {
                visited[v4][v7][v10] = true;
                int temp = V[2] - v10;
                int temp2 = v4 - temp >= 0 ? v4 - temp : 0;
                v10 = v4 - temp < 0 ? v4 + v10 : V[2];
                v4 = temp2;
                if (!visited[v4][v7][v10]) {
                    printf("do nuoc binh 4 sang binh 10\n");
                    exe(v4, v7, v10);
                }
            }
            //do nuoc tu 10 sang 4
            v4 = t4;
            v7 = t7;
            v10 = t10;

            if (v4 < V[0] && v10 != 0 && !isFound) {
                visited[v4][v7][v10] = true;
                int temp = V[0] - v4;
                int temp2 = v10 - temp >= 0 ? v10 - temp : 0;
                v4 = v10 - temp < 0 ? v10 + v4 : V[0];
                v10 = temp2;
                if (!visited[v4][v7][v10]) {
                    printf("do nuoc binh 10 sang binh 4\n");
                    exe(v4, v7, v10);
                }
            }
	}

}

int main(){
	init();
	exe(4, 7, 0);
	if(isFound)
		printf("tim ra ket qua\n");
	else
		printf("khong co ket qua\n");
	return 0;
}
