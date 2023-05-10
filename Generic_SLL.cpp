//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma Kawade
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
    struct Node *Next;
};

template <class T>
class SinglyLL
{
    public:
    struct Node<T> * First;   //charactristics
    int iCount;

    SinglyLL();
        void InsertAtFirst(T);
        void InsertAtLast(T);
        void InsertAtPos(T,T);

        void DeleteAtFirst();
        void DeleteAtLast();
        void DeleteAtPos(T);

        void Display();

};

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////


template <class T>
void SinglyLL<T> :: InsertAtFirst(T No)
{
    // Step1 : Allocate memory for node
    struct Node<T> *Newn = new struct Node<T>;

    // Step2 : Initialise node
    Newn->Data = No;
    Newn->Next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = Newn;
        iCount++;
    }
    else    // If LL contains atleast one node
    {
        Newn->Next = First;
        First = Newn;
        iCount++;
    }
}
/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////


template <class T>
void SinglyLL<T> :: InsertAtLast(T No)
{
    struct Node<T> *Newn = new struct Node<T>;

    Newn->Data = No;
    Newn->Next = NULL;

    if(First == NULL)
    {
        First = Newn;
        iCount++;
    }
    else
    {
        struct Node<T> *temp = First;
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = Newn;
        iCount++;
    }
}

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: InsertAtPos(T No,T iPos)
{
    if((iPos < 1) || (iPos > iCount +1))
    {
        cout<<"Invalid Position"<<"\n";
    }
    if(iPos == 1)
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
        struct Node<T> *Newn = new struct Node<T>;

        Newn->Data = No;
        Newn->Next = NULL;

        struct Node<T> *temp = First;
        for(iCnt = 1;iCnt < iPos-1;iCnt++)
        {
            temp = temp->Next;
        }
        Newn->Next = temp->Next;
        temp->Next = Newn;
        iCount++;
    }
}

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////


template <class T>
void SinglyLL<T> :: DeleteAtFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> Next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct Node<T> *temp = First;
        First = First -> Next;
        delete temp;
        iCount--;
    }
}

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DeleteAtLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct Node<T> *temp = First;
        while(temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        delete temp->Next;
        temp->Next = NULL;
        iCount--;

    }
}

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DeleteAtPos(T iPos)
{
    if((iPos < 1) || (iPos > iCount +1))
    {
        cout<<"Invalid Position"<<"\n";
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
        struct Node<T> *temp1 = First;
        int iCnt = 0;

        for(iCnt = 1;iCnt < iPos-1;iCnt++)
        {
            temp1 = temp1->Next;
        }
        struct Node<T> *temp2 = temp1->Next;
        temp1->Next = temp2->Next;
        delete temp2;
        iCount--;

    }

}

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////


template <class T>
void SinglyLL<T> :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct Node<T> *temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->Data<<" |->";
        temp = temp->Next;
    }
    cout<<"NULL"<<"\n";
}

//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL <int> obj1;

    obj1.InsertAtFirst(101);
    obj1.InsertAtFirst(51);
    obj1.InsertAtFirst(21);
    obj1.InsertAtFirst(11);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtLast(111);
    obj1.InsertAtLast(121);

    obj1.Display(); 
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtPos(151,2);
    obj1.InsertAtPos(221,4);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtFirst();

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtLast();

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtPos(3);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";



    
}