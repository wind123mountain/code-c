#include<stdio.h>
#include<stdlib.h>
int b[100][3], max[3],j,n=0,cs[100];
void doi( int x,int y, int z, int i )
{
	if ((b[i][x]+b[i][y])<=max[y])
 {
    b[j+1][y]=b[i][x]+b[i][y];
    b[j+1][x]=0;
 }
 else 
 {
	b[j+1][x]=b[i][x]+b[i][y]-max[y];
	b[j+1][y]=max[y];
 }
    b[j+1][z]=b[i][z];
}
 
int ktlap(int j)
{
	int k;
 for(k=0;k<=j;k++)
  if ((b[j+1][1]==b[k][1])&&(b[j+1][2]==b[k][2]))
   return 0;   
   return 1;
}

int s(int x, int y, int z, int i)
{
	if ((b[i][x]!=0)&&(b[i][y]<max[y]))
 {
  doi(x,y,z,i);
 if( b[j+1][1]==2 ||  b[j+1][2]==2)
   {
   cs[n++]=j+1;
   //printf("%d  ; %d   ; %d  ,i=%d , j=%d \n",b[j+1][0],b[j+1][1],b[j+1][2],i,j);
   return 1;
   }
 if (ktlap(j)==0)
   	   	return 0;
 else
    {  
	    if (i<j) n=i;
		//printf("%d  ; %d   ; %d  ,i=%d , j=%d \n",b[j+1][0],b[j+1][1],b[j+1][2],i,j);
  	    j=j+1;   
  	    i=j;
  	    cs[n++]=j;
        if(tao(i)==1) return 1;  	
	}  
 }
 return 0;
}

 int tao(int i)
{
	if (s(2,0,1,i)==1) return 1;
	if (s(0,1,2,i)==1) return 1;
	if (s(0,2,1,i)==1) return 1;  
    if (s(1,0,2,i)==1) return 1;
	if (s(1,2,0,i)==1) return 1;	
	if (s(2,1,0,i)==1) return 1;
 return 0;
}

int main()
{
	int i=0;
	j=0;
	b[0][0]=0;b[0][1]=7;b[0][2]=4;
	max[0]=10;max[1]=7;max[2]=4;
	int a;
	a=tao(0);	
	printf("%3d  ; %3d   ; %3d   \n",b[0][0],b[0][1],b[0][2]);
	for (i=0;i<n;i++)
	  printf("%3d  ; %3d   ; %3d   \n",b[cs[i]][0],b[cs[i]][1],b[cs[i]][2]);	
	return a;
}
