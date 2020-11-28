#include<iostream>

using namespace std;

void lich(int d,int n,int k1, int k2, int L1, int *day){
	int l = L1;
	for(int i=0; i<2; i++){
		if(i == 0 && (l >= k1 || d==1) ){
			day[d] = i;
			L1 = 0;
		}
		else if(i == 1 && l < k2){
			day[d] = i;
			L1  = l+1;
		}
		else
			continue;
		if(d==n){
			if(L1 >= k1 || L1 == 0){
				for(int j=1; j<=n; j++)
					cout<<day[j];
				cout<<"\n";	
			}
			continue;
		}else
			lich(d+1,n,k1,k2,L1,day);
	}
		
}

int main() {
	
	cout<<"Ho Va Ten: Dao Quoc Phong\nMSSV: 20183604\n\n";
	cout<<"input:\n";
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	cout<<"output:\n";
	int L1 = 0;//so bit 1 lien tiep cuoi day
	int day[n+1];
	lich(1,n,k1,k2,L1,day);
	return 0;
}

