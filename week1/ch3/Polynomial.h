#pragma once
#ifndef _LinkedPolynomial_H
struct  Node;
typedef struct Node* Polyminal;
void AddPolyminal(const Polyminal P1, const Polyminal P2, Polyminal Res);
void MulPolyminal(const Polyminal P1, const Polyminal P2, Polyminal Res);
#endif // !_LinkedPolynomial_H
