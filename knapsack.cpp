#include<bits/stdc++.h>
using namespace std;
struct Item
{
	int value, weight;
	Item(int value,int weight)
	{
		this->value=value;
		this->weight=weight;
	}
};
bool cmp( struct Item a,struct Item b)
{
	double r1=(double)a.value/(double)a.weight;
	double r2=(double)b.value/(double)b.weight;
	return r1>r2;
}
double fractionalknapsack(int w,struct Item arr[],int n)
{
	sort(arr,arr+n,cmp);
	double finalvalue=0.0;
	for(int i=0;i<n;i++)
	{
		if(arr[i].weight<=w)
		{
			w-=arr[i].weight;
			finalvalue+=arr[i].value;
		}
		else
		{
			finalvalue+=arr[i].value*((double)w/(double)arr[i].weight);
		}
	}
	return finalvalue;
}
int main()
{
	int w=50;
	Item arr[]={{60,10},{100,20},{120,30}};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<fractionalknapsack(w,arr,n);
	return 0;
}
