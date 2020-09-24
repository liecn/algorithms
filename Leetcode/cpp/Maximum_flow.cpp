/* Maximum_flow.cpp
Question:None
Link:None
Maximum_flow based on Edmonds-Karp
Input:
A nertwork flow N within capacity C and flow f on each edge.
edge,vertex,origin,terminal

corresponding coding:
cin>>edge>>vertex>>origin>>terminal;
for(int i=0;i<edge;++i)
{
  cin>>start>>end>>weight;
}

eg:
5 4 0 3
0 1 40
0 3 20
1 2 30
1 3 20
2 3 10

Output:
Print a single number — the maximum flow

eg:
50

Edit by Liecn on 2018.4.17
*/

#include <iostream>
#include <queue>
#include<string.h>
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
	for(int i=0;i<vertex;i++)
	{
		pre[i]=-1;
	}
	pre[src]=0;
	flow[src]= maxData;
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
				flow[i] = min(capacity[index][i],flow[index]);   //关键：迭代的找到增量
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

	cin>>edge>>vertex>>origin>>terminal;
	capacity = (int **)malloc( sizeof(int*) * vertex );    //定义二维数组用以接受邻接矩阵
	for(int i=0; i<vertex; i++ )
	{
		capacity[i] = (int *)malloc( sizeof(int) * vertex );
		for(int j=0;j<vertex;j++)    
		{    
			capacity[i][j]=0;  
		}  
	}
	flow=(int *)malloc( sizeof(int) * vertex );
	for (int i = 0; i < vertex; i++)
	{
		flow[i] = 0;              // 顶点i的最短路径还没获取到
	}
	pre=(int *)malloc( sizeof(int) * vertex );
	for(int i=0;i<edge;++i)
	{
		cin>>start>>end>>weight;
		if(start == end)               //考虑起点终点相同的情况
			continue;
		capacity[start][end] +=weight;     //此处注意可能出现多条同一起点终点的情况
	}
	cout<<maxFlow(origin,terminal,vertex)<<endl;
	return 0;
}
