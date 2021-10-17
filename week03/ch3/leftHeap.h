#ifndef _LeftHeap_H
struct TreeNode;
typedef struct TreeNode* PriorityQueue;
PriorityQueue Initialize(void);
int  FindMin(PriorityQueue P);
int  IsEmpty(PriorityQueue P);
#define Insert(X,H) (H=Insert1(X,H));
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Insert1(int x, PriorityQueue P);
PriorityQueue DeleteMin1(PriorityQueue P);

#endif // !_LeftHeap_H

