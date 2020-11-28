#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAX 100
int n, c[MAX][MAX];
int cmin = INT_MAX;
int best = INT_MAX;
int curr = 0;
int mark[MAX];
int x[MAX];

void input(){
    cin>>n;
    for(int i = 1; i<=n; ++i)
        for (int j = 1; j<=n; j++){
            cin>>c[i][j];
            if(c[i][j]>0)
                cmin = min(cmin,c[i][j]);
        }
}

void TRY(int k){
    for(int i=2; i<=n; i++){
        if(mark[i] == 0 && c[x[k-1]][i] != 0){
           x[k] = i;
           mark[i] = 1;
           curr += c[x[k-1]][x[k]];
           
           
           if(curr+cmin*(n-k+1)>best){
                curr -= c[x[k-1]][x[k]];
                mark[i]=0;
                continue;
           }
           if(k==n){
                int sum = curr + c[x[k]][x[1]];
                best = min(best,sum);

           }else{
                TRY(k+1);
           }
            curr -= c[x[k-1]][x[k]];
            mark[i]=0;
        }
    }
}

int main()
{
    cout<<"Ho Va Ten: Dao Quoc Phong\nMSSV: 20183604\n\n";
    cout<<"input:\n";
    input();
    x[1] = 1;
    TRY(2);
    cout<<"output:\n"<<best;
    return 0;
}
