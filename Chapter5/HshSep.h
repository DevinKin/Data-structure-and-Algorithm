#ifndef  _HashSep_H
#define  _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
typedef Position List;
struct HashTb1;
typedef struct HashTb1 *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
void DestoryList(List L);
Position Find(int Key, HashTable H);
void Insert(int Key, HashTable H);
int Retrieve(Position P);



#endif
