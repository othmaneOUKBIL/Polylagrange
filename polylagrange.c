#include<stdio.h>
#include<math.h>

float polylag(float *X,float x,int i,int l)
{
	float y=X[i];
	float L=1;
	for(int j=0;j<l;j++)
	{
		if(y!=X[j])		
			L=L*((x-X[j])/(y-X[j]));
	}
	return L;		

}

float interpolag(float *X,float x,double(*f)(double),int l)
{
	float s=0;
	for(int i=0;i<l;i++)
	{
		s+=f(X[i])*polylag(X,x,i,l);
	}
	return s;






}

int main()
{
	float X[]={-1,1,2,0,3,-2,-3};
	float x=3.14;
	int i=2;
	float L=interpolag(X,x,cos,7);
	printf("%f\n",L);




}
