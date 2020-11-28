#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int binom2(int n, int k){
    int c = 1;
    int j = n-k;
    for(int i=1;i<=k;i++){
    	j++;
    	c = c*j/i;
	}
   // n_k = n-1_k-1 * n/k
   return c;
}

int main() {
    int m;
    cout<<"Ho Va Ten: Dao Quoc Phong\nMSSV: 20183604\n\n";
    cout<<"input:\n";
    cin >> m;
    cout<<"output:\n";
    cout<<"de quy:\n";
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    cout<<"khu de quy:\n";
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
