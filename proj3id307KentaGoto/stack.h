/*! \author  Kenta Goto
 *  \class  MCS 360
 *  \instructor Professor Lowman
 *  \assignment Project 1
 *  \file stach.h
 *  \brief Header file for class Stack.
 */
#include <iostream>
#ifndef STACK_H
#define STACK_H
template <class Object>
class Stack{
    public:
        Stack();
        Stack( const Stack & rhs );
        ~Stack();

        bool isEmpty() const;
        bool isFull() const;
        const Object & top() const;

        void makeEmpty();
        void pop();
        void push( const Object & x);
        Object topAndPop();

        const Stack & operator=( const Stack & rhs );

    private:
        struct ListNode{
            Object element;
            ListNode *next;

            ListNode( const Object & theElement, ListNode * n = NULL )
                :element( theElement ), next(n) {}
        };
        ListNode * topOfStack;
};
#include "stack.cpp"
#endif
