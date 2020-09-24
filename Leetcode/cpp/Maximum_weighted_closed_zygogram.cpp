/* Maximum_weighted_closed_zygogram.cpp
Buying_set---CODEFORCES_103E
Link:http://codeforces.com/problemset/problem/103/E
Maximum_weighted_closed_zygogram+Minimum_cut+Maximum_flow
Input:
The first line contains the only number n (1 ≤ n ≤ 300) — the number of sets available in the market.

Next n lines describe the goods: first we are given mi (1 ≤ mi ≤ n) — the number of distinct numbers in the i-th set, then follow mi numbers — the set's elements. We know that the set's elements are distinct positive integers and they do not exceed n.

The last line contains n integers whose absolute values do not exceed 106 — the price of each set.

corresponding coding:
cin>>vertex
for(int i=0; i<vertex; i++ )
{
	cin>>size_row;
	for(int j=1;j<(a[i][0]+1);j++) cin>>a[i][j];
}
for (int i = 0; i < vertex; i++) cin>>weights[i]; 

eg:
3
1 1
2 2 3
1 3
10 20 -3

Output:
Print a single number — the minimum price the virus will have to pay for such a collection of k sets that union of the collection's sets would have exactly k distinct numbers ().

eg:
-3

Edit by Liecn on 2018.4.17
*/

#include <iostream>
#include <queue>
#include<string.h>
#include <cstdlib>
using namespace std;

int maxData = 0x7fffffff;
int ** capacity;
int *flow;                //标记从源点到当前节点实际还剩多少流量可用
int *pre;                 //标记在这条路径上当前节点的前驱,同时标记该节点是否在队列中
queue<int> myqueue;

int BFS(int src,int des,int vertex)
{
	while(!myqueue.empty())       //队列清空
		myqueue.pop();
	for(int i=0;i<vertex;i++)pre[i]=-1;//初始化前驱序列
	pre[src]=0;
	flow[src]= maxData;//初始化始点
	myqueue.push(src);
	while(!myqueue.empty())
	{
		int index = myqueue.front();
		myqueue.pop();
		if(index == des)            //找到了增广路径
			break;
		for(int i=0;i<vertex;i++)
		{
			if(i!=src && capacity[index][i]!=0 && pre[i]==-1)//确定下一访问节点
			{
				pre[i] = index; //记录前驱
				flow[i] = min(capacity[index][i],flow[index]);   //取最小值为增流量
				myqueue.push(i);
			}
		}
	}
	if(pre[des]==-1) return -1;     //未走到T，残留图中不再存在增广路径
	else return flow[des];
}
int maxFlow(int src,int des,int vertex)
{
	int increasement= 0;
	int sumflow = 0;
	while((increasement=BFS(src,des,vertex))!=-1)//尚存在增广路径
	{
		int k = des;				//利用前驱寻找路径
		while(k!=src)				//更新流量
		{
			int last = pre[k];
			capacity[last][k] -= increasement; //改变正向边的容量
			capacity[k][last] += increasement; //改变反向边的容量
			k = last;
		}
		sumflow += increasement;
	}
	return sumflow;
}
int main()
{
	int start,end,weight;
	int vertex, edge,terminal,origin;
	int positive_weights=0;
	int sigle_weight=0;
	int max_bulk=0;
	cin>>vertex;//记录数据
	int size_row=0;
	int ** a;
	a = (int **)malloc( sizeof(int*) * vertex );    //定义二维数组用以接受邻接矩阵
	int flag;
	for(int i=0; i<vertex; i++ )
	{
		flag=0;
		cin>>size_row;
		a[i] = (int *)malloc( sizeof(int) *  (size_row+1));
		a[i][0]=size_row;
		for(int j=1;j<(a[i][0]+1);j++) cin>>a[i][j];
	}
	int *weights;
	weights=(int *)malloc( sizeof(int) * vertex );
	for (int i = 0; i < vertex; i++) cin>>weights[i];             // 顶点i的最短路径还没获取到
	vertex=vertex+2;
	edge=0;
	origin=0;
	terminal=vertex-1;
	capacity = (int **)malloc( sizeof(int*) * vertex );    //定义二维数组用以接受邻接矩阵
	for(int i=0; i<vertex; i++ )
	{
		capacity[i] = (int *)malloc( sizeof(int) * vertex );
		for(int j=0;j<vertex;j++)capacity[i][j]=0;  
	}
	flow=(int *)malloc( sizeof(int) * vertex );
	for (int i = 0; i < vertex; i++) flow[i] = 0;              // 顶点i的最短路径还没获取到
	pre=(int *)malloc( sizeof(int) * vertex );

	for(int i=1;i<vertex-1;++i)
	{
		for(int j=1;j<a[i-1][0]+1;++j)capacity[i][a[i-1][j]] +=maxData;     //此处注意可能出现多条同一起点终点的情况
	}
	for(int i=0;i<vertex-2;++i)
	{
		if (weights[i]<0) {
			capacity[origin][i+1] -=weights[i];     //此处注意可能出现多条同一起点终点的情况
			positive_weights-=weights[i];
		}
		if (weights[i]>0) capacity[i+1][terminal] +=weights[i]; 
		if (a[i][0]==1){
			if(weights[i]<sigle_weight)sigle_weight=weights[i];
		}
	}
	max_bulk=-positive_weights+maxFlow(origin,terminal,vertex);
	cout<<min(min(max_bulk,sigle_weight),0)<<endl;
	return 0;
}
