#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
    int n, M;
    cout<<"Ho Va Ten: Dao Quoc Phong\nMSSV: 20183604\n\n";
    cout<<"input:\n";
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    cout<<"output:\n";
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1));
    while (!s.empty()){
        state &top = s.top();
        if (top.i > n){
            if (sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }
        
        if(top.j == -1){
			x[top.i] = top.j;
			top.j++;
			if(top.i == n){
				sum = 0;
				for(int i =1;i<=n;i++)
					sum += x[i]*m[i];
			}	
			s.push(state(top.i+1,-1));
			continue;
		}
	
		if(top.j == 0){
			x[top.i] = top.j;
			top.j++;
			if(top.i == n){
				sum = 0;
				for(int i =1;i<=n;i++)
					sum += x[i]*m[i];
			}	
			s.push(state(top.i+1,-1));
			continue;
		}
		
		if(top.j == 1){
			x[top.i] = top.j;
			top.j++;
			if(top.i == n){
				sum = 0;
				for(int i =1;i<=n;i++)
					sum += x[i]*m[i];
			}	
			s.push(state(top.i+1,-1));
			continue;
		}
		s.pop();
    }
    cout << -1;

    return 0;
}
