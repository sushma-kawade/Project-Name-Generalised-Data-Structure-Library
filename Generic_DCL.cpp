//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
struct Node
{
    T Data;
    struct Node<T> *Next;
    struct Node<T> *Prev;
};

//=========================================================================
//
//
// Class Name  :  DoublyCL
// Description :  This Class represents Generic Doubly Circular linked list
//
//
//=========================================================================

template <class T>
class DoublyCL
{
    public:
    struct Node<T> *First;
    struct Node<T> *Last;
    int iCount;

    DoublyCL();
    void InsertAtFirst(T);
    void InsertAtLast(T);
    void InsertAtPos(T,T);

    void DeleteAtFirst();
    void DeleteAtLast();
    void DeleteAtPos(T);

    void Display();
};

//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////
template <class T>
DoublyCL <T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T> :: InsertAtFirst(T No)
{
    struct Node<T> *Newn = new struct Node<T>;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Prev = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Newn;
        Last = Newn;
    }
    else
    {
        Last-> Next = Newn;
        Newn->Prev = Last;
        Last = Newn;
    }

    First->Prev = Last;
    Last->Next = First;
    iCount++;
}

//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertAtLast(T No)
{
    struct Node<T> *Newn = new struct Node<T>;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Next = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Newn;
        Last = Newn;
    }
    else
    {
        Last->Next = Newn;
        Newn->Prev = Last;
        Newn->Next = First;
        Last = Newn;
        iCount++;
    }
}

//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL <T>:: InsertAtPos(T No,T iPos)
{
    struct Node<T> *Newn = new struct Node <T>;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Prev = NULL;

    if((iPos < 1) || (iPos > iCount +1))
    {
        return;
    }
    else if(iPos == 1)
    {
        InsertAtFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertAtLast(No);
    }
    else
    {
        int iCnt = 0;
        struct Node<T> *temp = First;

        for(iCnt = 1; iCnt <iPos-1; iCnt++)
        {
            temp = temp->Next;
        }
        
        Newn->Next = temp->Next;
        temp->Next->Prev = Newn;

        temp->Next = Newn;
        Newn->Prev = temp;
        iCount++;
    }
}
//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL <T> :: DeleteAtFirst()
{
    if((First == NULL) && (Last== NULL))
    {
        return;
    }

    else if(First == Last)
    {
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->Next;
        First->Prev = Last;
        delete Last->Next;
        Last->Next = First;
        iCount--;
    }
}

//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T> :: DeleteAtLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        First = NULL;
        Last == NULL;
    }
    else
    {
        Last = Last->Prev;
        delete First->Prev;

        First->Prev = Last;
        Last->Next = First;
        iCount--;
    }
}

//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////


template <class T>
void DoublyCL <T>::DeleteAtPos(T iPos)
{
    if((iPos < 1) || (iPos > iCount +1))
    {
        return;
    }
    else if(iPos == 1)
    {
        DeleteAtFirst();
    }
    else if(iPos == iCount + 1)
    {
        DeleteAtLast();
    }
    else
    {
        int iCnt = 0;
        struct Node<T> *temp2 = NULL;
        struct Node<T> *temp1 = First;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->Next;
        }
        temp2 = temp1->Next;
        temp1->Next = temp2->Next;
        temp2->Next->Prev = temp1;
        delete temp2;
        iCount--;
    }
}

//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct Node<T> *temp = First;

    do
    {
        cout<<"|"<<temp->Data<<"|<=>";
        temp = temp->Next;
    }while(temp != Last->Next);
    cout<<"\n";
}
//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

int main()
{
    DoublyCL<int> obj1;
    obj1.InsertAtFirst(10);
    obj1.InsertAtFirst(20);
    obj1.InsertAtFirst(30);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtLast(40);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtPos(15,2);
    obj1.InsertAtPos(25,4);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtFirst();

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtLast();

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtPos(2);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";
}