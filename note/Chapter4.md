# 第四章-树

## 预备知识

- 每一个节点可以有任意多个儿子，也可能是零个儿子。
- 没有儿子的节点称为树叶（leaf）
- 具有相同父亲的节点称为兄弟（sibling）
- 对于任意节点 $n_i$ ，$n_i$ 的深度为从根到$n_i$的唯一路径长。
- 根的深度为0，$n_i$的高是从$n_i$到一片树叶的==最长路径==的长。
- 一棵树的高等于它的根的高。

### 树的实现

```c
typedef struct TreeNode *PtrToNode;
struct TreeNode {
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
}
```

- 先序遍历：对节点的处理工作是在它的诸==儿子节点被处理之前==进行的。
- 后序便利：对节点的处理工作是在它的诸==儿子节点被处理之后==进行的

## 二叉树

- 二叉树是一棵树，其中每个节点都不能有多于两个的儿子。

- 二叉树的一个性质是平均二叉树的深度要比N小得多。平均深度为$O(\sqrt N)$

- 特殊类型的二叉树，二叉查找树，其深度的平均值是$O(\log N)$

- 二叉树节点声明

  ```c
  typedef struct TreeNode *PtrToNode;
  typedef struct PtrToNode Tree;
  
  struct TreeNode {
      ElementType Element;
      Tree		Left;
      Tree		Right;
  }
  ```

## 查找树ADT——二叉查找树

- 二叉树变为二叉查找树的性质是：对于树的任意节点X，它的左子树中所有关键字值小于X的关键字值，而它的右子树中所有关键字值大于X的关键字值。

### 二叉查找树的声明

```c
#ifndef _BINARY_SORT_TREE

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

#endif
```

### MakeEmpty

```c
SearchTree
MakeEmpty(SearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
```

### Find，FindMin，FindMax

```c
Position
Find(int X, SearchTree T) {
    if (T == NULL) {
        return NULL;
    }
    if (X < T->Element) {
        return Find(X, T->Left);
    } else if (X > T->Element) {
        return Find(X, T->Right);
    } else {
        return T;
    }
}

Position
FindMin(SearchTree T) {
    if (T == NULL) {
        return NULL;
    } else if (T->Left == NULL) {
        return T;
    } else {
        return FindMin(T->Left);
    }
}

Position
FindMax(SearchTree T) {
    if (T != NULL) {
        while (T->Right != NULL) {
            T = T->Right;
        }
    }
    return T;
}
```

### Insert

```c
SearchTree
Insert(int X, SearchTree T) {
    if(T == NULL) {
        /* Create and return a one-node tree */
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL) {
            perror("malloc TreeNode fail!");
            exit(1);
        } else {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    } else if(X < T->Element) {
        T->Left = Insert(X, T->Left);
    } else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
    }
    /* Else X is in the tree already; we'll do nothing */
    return T;
}
```

### Delete

- 删除的节点是一片树叶，那么它可以被立即删除。
- 如果节点有一个儿子，则该节点可以在其父节点调整指针绕过该节点后被删除。
- 如果节点有两个儿子，一般的删除策略是用其右子树的最小的数据代替该节点的数据并递归地从其右子树删除替换的节点。
- 如果删除的次数不多，通常使用的策略是懒惰删除。在被删除的元素上做了个记号。

```c
SearchTree
Delete(int X, SearchTree T) {
    Position TmpCell;

    if (T == NULL) {
        perror("Element not found");
        exit(1);
    } else if (X < T->Element){
        /* Go left */
        T->Left = Delete(T->Element, T->Left);
    } else if (X > T->Element){
        /* Go Right */
        T->Right = Delete(T->Element, T->Right);
    } else if (T->Left && T->Right){
        /* Found element to be deleted */
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    } else {
        /* One or zero childre */
        TmpCell = T;
        if (T->Left == NULL) {
            /* Also handles 0 children*/
            T = T->Right;
        } else if (T->Right == NULL) {
            T = T->Left;
        }
        free(TmpCell);
    }
    return T;
}
```

### 平均情形分析

- 一棵树的所有节点的深度的和称为内部路径长。

## AVL树

- AVL树是带有平衡条件的二叉查找树。
- 平衡条件必须容易保持，而且它必须保证树的深度是$O(logN)$。最简单的想法是要求其左右子树具有相同的高度。
- 一棵AVL树是其每个节点的左子树和右子树的高度最多差1的二叉查找树。（空树的高度定义为-1）
- 把重新平衡的节点叫做$a​$。由于任意节点最多有两个儿子，因此高度不平衡时，$a​$点的两棵子树的高度差为2。这种不平衡可能出现在下面4种情况。
  - 对a的左儿子的左子树进行一次插入。（左-左情形）
  - 对a的左儿子的右子树进行一次插入。（左-右情形）
  - 对a的右儿子的左子树进行一次插入。（右-左情形）
  - 对a的右儿子的右子树进行一次插入。（右-右情形）
- 理论上只有两种情况，但编程角度是四种情形。
  - 左-左情形和右-右情形可以通过一次单旋转完成a节点平衡调节。
  - 左-右情形和右-左情形可以通过双旋转完成a节点平衡调节。

### 单旋转

- 此处讨论的根节点是指原来AVL不平衡的节点。
- 平衡的想象图景：抓住在通向不平衡根节点路径上破坏AVL平衡的第一个节点。在重力的作用下，节点自动向下滑动。其中会形成新的根节点。

### 双旋转

- 左-右情形需要通过一次右-左旋转进行平衡。
- 右-左情形需要通过一次左-右旋转进行平衡。

## 伸展树

- 伸展树（splay tree），它保证从空树开始任意连续M次对树的操作最多花费$O(M\log N)$时间。
- 一般来说，当M次操作的序列总的最坏情形是运行时间为$O(M(F))$，我们就说它的摊还（amortized）运行时间为$O(F(N))$。因此，一棵伸展树每次操作的摊还代价是$O(\log{N})$。
- 伸展树是基于这样的事实，对于二叉查找树来说，每次操作最坏情形时间$O(N)$并不坏，只要它相对不常发生就行了。
- 如果任意特定操作可以由最坏时间界$O(N)$，而我们仍然要求一个$O(\log{N})$的摊还时间界，那么很清楚，只要一个节点被访问，它就必须被移动。如果节点不移动，访问该节点（比较深层次），M次访问将花费$O(M \cdot N)$。
- 伸展树的基本想法是，当一个节点被访问后，它就要经过一系列AVL树的旋转放到根上。
  - 注意，如果一个节点很深，那么其路径上就存在许多的节点也相对较深，通过重新构造可以使对所有这些节点的进一步访问所花费的时间变少。因此，如果节点过深，那我们还要求重新构造应具有平衡这棵树（到某种程度）的作用。

### 展开

- 展开（SPlaying）的思路类似于avl的旋转。
- 从底部向上沿着访问路径旋转。令X是在访问路径上的一个（非根）节点，我们将在这个路径上实施旋转操作。
- 如果X的父节点是树根，那么我们只要旋转X和树根。这就是沿着访问路径上的最后的旋转。
- 如果X有父亲（P）和祖父亲（G），存在两种情况以及对称情形要考虑。
  - 第一种情况是==之字形（zig-zag）==情形，X是右儿子的形式，P是左儿子的形式。（对称情形是X是左儿子形式，P是右儿子形式）。这种情况需要执行一次AVL那样的双旋转。
  - 第二种情形是==一字形（zig-zig）==情形，X和P都是左儿子（对称情形是X和P都是右儿子）。这种情况下需要执行两次AVL那样的单旋转。

## 树的遍历

- 中序遍历，总的运行时间是$O(N)$

  ```c
  static
  void PrintElement(int Element) {
      printf("%d\t", Element);
  }
  
  static void
  PrintTree(AvlTree T) {
      if (T != NULL) {
          PrintTree(T->Left);
          PrintElement(T->Element);
          PrintTree(T->Right);
      }
  }
  ```

- 后序遍历，总的运行时间为$O(N)$。先处理两个子树才能处理当前节点。

- 先序遍历，当前节点在其节点处理之前处理。


## B-树

- 阶为M的B-树是一颗具有下列结构特性的树
  - 树的根或者一片树叶，或者其儿子数在2和M之间。
  - 除根外，所有非树叶节点的儿子数在[M/2]和M之间。
  - 所有的树叶都在相同的深度上。
- 所有的数据都存储在树叶上。在每一个内部节点上皆含有指向该节点各儿子的指针$P_1，P_2，\dots，P_M$和分别在子树$P_2，P_3，\dots，P_M$中发现的最小关键字的值$k_1，k_2，\dots，k_{M-1}$。

