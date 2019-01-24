#ifndef _BINARY_SORT_TREE
#define _BINARY_SORT_TREE

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;



SearchTree MakeEmpty(SearchTree T);
Position Find(int X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree X);
Position Insert(int X, SearchTree T);
Position Delete(int X, SearchTree T);
int Retireve(Position P);

// 要在多个c文件中调用此数据结构，需要把结构体定义在h文件中。
struct TreeNode
{
    int Element;
    SearchTree Left;
    SearchTree Right;
};

#endif
