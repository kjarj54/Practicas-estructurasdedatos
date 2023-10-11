#include<iostream>
#include<stdlib.h>
using namespace std;
int **v;
int *t;
int main (int argc, char *argv[]) {
	v=(int**) malloc(4 * sizeof(int*));
	v[0]=(int*)(2);
	v[1]=(int*)(3);
	v[2]=(int*)(7);
	v[3]=(int*)(11);
	t=(int*) malloc(4 * sizeof(int));
	for (int i=0;i<4;i++)
	{
		t[i]=(int)v[i];
		v[i]=(int*) malloc(4 * sizeof(int));
		cout<<t[i]<<" ";
	}
	cout<<endl;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			if (j==0)
			{
				v[i][j]=t[i];
			}
			else
			{
				v[i][j]=v[i][j-1]+t[i];	
			}
		}
	}
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
	return 0;
}

