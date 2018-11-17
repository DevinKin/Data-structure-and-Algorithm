#ifndef _CURSOR_H
#define _CURSOR_H

#define SpaceSize 13

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

void InitializeCursorSpace(void);

List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, const List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
ElementType Retireve(const Position P);
List FromArray(int[], int);
void PrintCursorList(List);

struct Node {
    ElementType Element;
    Position Next;
};

#endif


