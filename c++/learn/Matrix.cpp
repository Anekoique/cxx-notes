// #include<iostream>
// #include<cstdio>
// #include<cstdlib>

// using namespace std;
// class Matrix
// {
// public:
//     Matrix(int m, int n);
//     void ReadMatrix();
//     void WriteMatrix();
//     void Transpose(Matrix& B);
// private:
//     int** M;
//     int row, column;
// };
// Matrix::Matrix(int m,int n)
// {
//     row = m;
//     column = n;
//     M = new int* [row];
//     for (int i = 0; i < row; i++){
//         M[i] = new int[column];
//     }
// }
// void Matrix::ReadMatrix()
// {
//     int t;
//     for (int i = 0; i < row; i++){
//         for (int j = 0; j < column; j++){
//             scanf("%d", &t);
//             M[i][j] = t;
//         }
//     }
// }
// void Matrix::WriteMatrix()
// {
//     for (int i = 0; i < row; i++){
//         for (int j = 0; j < column; j++){
//             printf("%d ", M[i][j]);
//         }
//         printf("\n");
//     }
// }
// void Matrix::Transpose(Matrix& B)
// {
//     for (int j = 0; j < column; j++){
//         for (int i = 0; i < row; i++){
//             B.M[j][i] = M[i][j];
//         }
//     }
// }
// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     Matrix A(m, n);
//     A.ReadMatrix();
//     A.WriteMatrix();
//     Matrix B(n, m);
//     A.Transpose(B);
//     B.WriteMatrix();
//     system("pause");
//     return 0;
// }

// #include<iostream>
// #include<cstdio>

// using namespace std;



// int num = 0;
// class student
// {
// public:
//     char* name;
//     int height, weight;
//     student(char* name, int height, int weight) : name(name), height(height), weight(weight){};
// private:
    
// };

// typedef struct Labs{
//     int mem;
//     student S;
//     struct Labs* next;
// }Node;


// void addNode(Node* head, int mem, student s)
// {
//     Node* current = head;
//     while (current->next != NULL){
//         current = current->next;
//         if (mem == current->mem)
//         {
//             if (s.height > current->S.height)
//                 current->S = s;
//             return;
//         }
//     }
//     current->next = new Node;
//     current = current->next;
//     current->next = NULL;
//     current->mem = mem;
//     current->S = s;
//     num++;
// }

// void sortLabs(Node* head)
// {
//     Node* current = head->next;
//     Node* pre = head;
//     for (int i = 0; i < num; i++)
//     {
//         for (int j = 0; j < num - i - 1; j++)
//         {
//             if(current->mem > current->next->mem){
//                 pre->next = current->next;
//                 current->next = current->next->next;
//                 current->next->next = current;
//             }
//             pre = pre->next;
//             current = current->next;
//         }
//     }
// }



// int main()
// {
//     Node* lab;
//     lab = new Node;
//     lab->next = NULL;
//     int n;
//     cin >> n;
//     int mem, height, weight;
//     char name[16];
//     for (int i = 0; i < n; i++){
//         scanf("%d%s%d%d", &mem, name, &height, &weight);
//         student S(name, height, weight);
//         addNode(lab, mem, S);
//     }
//     sortLabs(lab);
//     struct Labs* current = lab;
//     while(current->next != NULL){
//         current = current->next;
//         printf("%06d %s %d %d", current->mem, current->S.name, current->S.height, current->S.weight);
//     }
// }


#include<bits/stdc++.h>
using namespace std;
struct student
{
	int room;
	char name[16];
	int h;int w;
}a[1000000];
bool cmp(struct student a1,struct student b1)
{
	return a1.room<b1.room;
}
int main()
{
	int n,count=1,i,j,flag;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %s %d %d",&a[i].room,a[i].name,&a[i].h,&a[i].w);
	}
	struct student x[999];//数组用来存储每个宿舍最高的人的信息
	x[0]=a[0];
	for(i=1;i<n;i++)//排查每一个a[i]
	{flag=0;
	    for(j=0;j<count;j++)
	    {
	    	if(a[i].room==x[j].room)//如果此宿舍出现过信息的录入
	    	{flag=1;
	    		if(a[i].h>x[j].h) x[j]=a[i];//宿舍内比较是不是最高的人
			}
		}
		if(flag==0)//该宿舍信息之前没有出现过
		x[count++]=a[i];//登记，方便下次的比较
	}
	sort(x,x+count,cmp);//按照宿舍号的大小排序
	for(i=0;i<count;i++)
	{
		printf("%06d %s %d %d\n",x[i].room,x[i].name,x[i].h,x[i].w);
	}
	return 0;
}
//总结：
//分步管理宿舍和身高，在遍历数据时逐步建立每个宿舍最高的信息，属于遍历+模拟法
