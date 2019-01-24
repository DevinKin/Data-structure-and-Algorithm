#include <stdio.h>
#include "BinarySortTree.h"

int main(int argc, char const *argv[])
{
    int arr[] = {2,3,6,4,5,8,7,9,10,1};
    SearchTree T = MakeEmpty(NULL);
    for (size_t i = 0; i < 10; i++)
    {
        T = Insert(arr[i], T);
    }
    Position min = FindMin(T);
    Position max = FindMax(T);
    Position find_3 = Find(3, T);
    SearchTree del3 = Delete(3, T);
    Position del_find_3 = Find(3, del3);
    printf("min in Tree: %d\n", min->Element);
    printf("max in Tree: %d\n", max->Element);
    printf("3 in Tree T ? ");
    if (find_3 != NULL) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    printf("Is 3 del? ");
    if (del_find_3 != NULL) {
        printf("no\n");
    } else {
        printf("yes\n");
    }
    return 0;
}