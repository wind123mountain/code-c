#include <iostream>

using namespace std;

int lucas(int n){
    if(n==0) return 2;
    if(n==1) return 1;
    return lucas(n-1) + lucas(n-2);
}

int main()
{
    int n;
    cout<<"Ho Va Ten: Dao Quoc Phong\nMSSV: 20183604\n\n";
    cin>>n;
    cout<<"ket qua:\n"<<lucas(n);
    return 0;
}
