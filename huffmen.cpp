#include<bits/stdc++.h>
using namespace std;
struct MinHeapNode
{
	char data;
	unsigned freq;
	MinHeapNode *left,*right;
	MinHeapNode(char data,unsigned freq)
	{
		left=right=NULL;
		this->data=data;
		this->freq=freq;
	}
};
struct compare
{
	bool operator()(MinHeapNode *l,MinHeapNode *r )
	{
		return(l->freq>r->freq);
	}
};
void printcodes(struct MinHeapNode *root,string str)
{
	if(!root)
		return;
		if(root->data!='$')
			cout<<root->data<<":"<<str<<endl;
		printcodes(root->left,str+"0");
		printcodes(root->right,str+"1");
}
void huffmancodes(char data[],int freq[],int size)
{
	 struct MinHeapNode *left,*right,*top;
	priority_queue<MinHeapNode *,vector<MinHeapNode *>,compare>minheap;
	for(int i=0;i<size;i++)
	{
		minheap.push(new MinHeapNode(data[i],freq[i]));
	
		
		
	}
	while(minheap.size()!=1)
	{
		left=minheap.top();
		minheap.pop();
		right=minheap.top();
		minheap.pop();
		top=new MinHeapNode('$',left->freq+right->freq);
		top->left=left;
		top->right=right;
		minheap.push(top);
		
	}
	printcodes(minheap.top()," ");
}
int main()
{
	char arr[]={'a','b','c','d','e','f'};
	int freq[]={5,9,12,13,16,45};
	int size=sizeof(arr)/sizeof(arr[0]);
	huffmancodes(arr,freq,size);
	return 0;
}
