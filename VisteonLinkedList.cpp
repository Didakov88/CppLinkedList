#include <string>
#include <iostream>
#include "Main.h"


int main()
{
    PrintMemoryUsage();
    LinkedList* listA = new LinkedList();
    PrintMemoryUsage();

    Node* n1 = new Node('A');
    Node* n2 = new Node('B');
    Node* n3 = new Node('C');
    Node* n4 = new Node('D');
    Node* n5 = new Node('E');
    Node* n6 = new Node('F');
    Node* n7 = new Node('G');
    PrintMemoryUsage();

    listA->Push(n1);
    listA->Push(n2);
    listA->Push(n3);
    listA->Push(n4);
    listA->Push(n5);
    listA->Push(n6);
    listA->Push(n7);
    listA->Print();
    PrintMemoryUsage();
    
    LinkedList* listB = listA->SubList(2,6);
    listB->Print();
    PrintMemoryUsage();

    LinkedList* listC = listB->SubList(4,3);
    listC->Print();
    PrintMemoryUsage();
    
    //delete n1;
    //delete n2;
    //delete n3;
    //delete n4;
    //delete n5;
    //delete n6;
    //delete n7;
    delete listA;
    delete listB;
    delete listC;

    PrintMemoryUsage();
    return 0;
}