#ifndef  _HashSep_H
/// <summary>
/// 散列表 关键字为整数值
/// </summary>
struct  ListNode;
typedef struct ListNode* Position;
struct  HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void      DestoryTable(HashTable H);
Position  Find(int Key, HashTable H);
void      Insert(int Key,HashTable H);
int       Retrieve(Position P);
#endif // ! _HashSep_H

