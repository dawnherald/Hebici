#pragma once
#ifndef  _List_H
struct  Node;
typedef struct Node* PtrToNode;//???
typedef PtrToNode List;//È¡±ðÃû
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List l);
Position Find(int  x, List l);
void Delete(int x,List L);
Position FindPrevious(int x ,List L);
void Insert(int x, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);
#endif // ! _List_H

