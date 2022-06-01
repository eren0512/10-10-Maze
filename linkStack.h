#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H
#include <iostream>
#include "stack.h"
using namespace std;
template <class elemType>
class linkStack:public stack<elemType>
{
private:
	struct node {
		elemType data;
		node *next;
		node(const elemType &x, node *N = NULL)
		{
			data = x;
			next = N;
		}
		node():next(NULL){}
		~node(){}
	};
	node *top_p;
public:
	linkStack();
	~linkStack();
	bool isEmpty()const;
	void push(const elemType &x);
	elemType pop();
	elemType top()const;

};
template<class elemType>
linkStack<elemType>::linkStack()
{
	top_p = NULL;
}
template<class elemType>
linkStack<elemType>::~linkStack()
{
	node *tmp;
	while (top_p)
	{
		tmp = top_p;
		top_p = top_p->next;
		delete tmp;
	}
}
template<class elemType>
bool linkStack<elemType>::isEmpty()const
{
	return top_p == NULL;
}
template<class elemType>
void linkStack<elemType>::push(const elemType &x)
{
	top_p = new node(x, top_p);
}
template<class elemType>
elemType linkStack<elemType>::pop()
{
	node *tmp = top_p;
	top_p = top_p->next;
	elemType x = tmp->data;
	delete tmp;
	return x;
}
template<class elemType>
elemType linkStack<elemType>::top()const
{
	return top_p->data;
}

#endif
