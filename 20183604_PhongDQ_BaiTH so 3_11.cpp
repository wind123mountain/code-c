#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define MAX 100
int n, c[MAX][MAX];
int cmin = INT_MAX;
int best = INT_MAX;
int curr = 0;
int mark[MAX]{};
int x[MAX]{};
int **p;//luu danh sach dia diem voi p[i][0] so dia diem cua nguoi i
int r;

void reset(int n){
	for(int i = 1; i <= n; i++){
		x[i] = 0;
		mark[i] = 0;
	}
	cmin = INT_MAX;
	best = INT_MAX;	
	curr = 0;
}

void input(){
    cin>>n>>r;
    for(int i = 1; i<=n; ++i)
        for (int j = 1; j<=n; j++){
            cin>>c[i][j];
            if(c[i][j]>0)
                cmin = min(cmin,c[i][j]);
        }
    p = new int*[r];
	for(int i=0;i<r;i++){
		p[i] = new int[n+1];
		int j = 1;
		do{
			cin>>p[i][j];
			j++;
		}while(getchar() != '\n');
		p[i][0] = j-1;
	}
		 
}

void TRY(int k,int rn, int *rp){
	
    for(int i=2; i< rn; i++){
    	int place = rp[i];
        if(mark[place] == 0 && c[x[k-1]][place] != 0){
           x[k] = place;
           mark[place] = 1;
           curr += c[x[k-1]][x[k]];
             
           if(curr+cmin*(rn-k) > best){
                curr -= c[x[k-1]][x[k]];
                mark[place]=0;
                continue;
           }
           
           if(k == (rn-1) && c[x[k]][rp[rn]] != 0){
                int sum = curr + c[x[k]][rp[rn]];
                best = min(best,sum);
           }else{
                TRY(k+1,rn,rp);
           }
            curr -= c[x[k-1]][x[k]];
            mark[place]=0;
        }
        
    }
}

int main()
{
    cout<<"Ho Va Ten: Dao Quoc Phong\nMSSV: 20183604\n\n";
    cout<<"input:\n";
    input();
    cout<<"output:\n";
    for(int persion = 0; persion<r ;persion++){
    	int rn = p[persion][0];
    	x[1] = p[persion][1];
	    TRY(2,rn,p[persion]);
	    if(best == INT_MAX)
	    	best =0;
	    cout<<best<<"\n";
	    reset(n);
	}
	
    for(int i=0;i<r;i++)
    	delete []p[i];
    delete []p;
    return 0;
}
