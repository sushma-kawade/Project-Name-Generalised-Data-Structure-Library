/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
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
};

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
    struct Node<T> *First; 
    struct Node<T> *Last;  //charactristics
    int iCount;

    SinglyCL();
        void InsertAtFirst(T No);
        void InsertAtLast(T No);
        void InsertAtPos(T No,T iPos);

        void DeleteAtFirst();
        void DeleteAtLast();
        void DeleteAtPos(T iPos);

        void Display();

};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    Last = NULL;
    First = NULL;
    iCount = 0;
}
/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: InsertAtFirst(T No)
{
    struct Node<T> *Newn = new struct Node<T>;
    Newn -> Data = No;
    Newn -> Next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First= Newn;
        Last = Newn;
    }
    else
    {
        Newn -> Next = First;
        First = Newn;
    }
    Last -> Next = First;
    iCount++;
}
/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>:: InsertAtLast(T No)
{
    struct Node<T> *Newn = new struct Node <T>;

    Newn->Data = No;
    Newn->Next = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Newn;
        Last = Newn;
    }
    else
    {
        
        Last->Next = Newn;
        Last = Last->Next;
    }
    Last->Next = First;
    iCount++;

}

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertAtPos(T No,T iPos)
{
    struct Node<T> *Newn = new struct Node <T>;

    Newn->Data = No;
    Newn->Next = NULL;

    if((iPos < 1) || (iPos > iCount +1))
    {
        cout<<"Invalid Position :"<<"\n";
    }
    else if(iPos == 1)
    {
        InsertAtFirst(No);
    }
    else if(iPos == iCount +1)
    {
        InsertAtLast(No);
    }
    else
    {
        struct Node<T> *temp = First;
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> Next;
        }
        Newn -> Next = temp -> Next;
        temp -> Next = Newn;
        iCount++;
    } 
    
}
/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAtFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else
    {
        struct Node<T> *temp = First;
        First = First->Next;
        Last->Next = First;
        delete(temp);
        iCount--;
    }
}
/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>::DeleteAtLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else
    { 
        struct Node<T> *temp = First;
        for(int iCnt = 1; iCnt < iCount - 1; iCnt++)
        {
            temp = temp -> Next;
        }
        delete Last;
        Last = temp;
        Last -> Next = First;
        iCount--;
    }
}
/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>::DeleteAtPos(T iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
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
        struct Node<T> *temp1 = First;
        for(int iCnt = 1;iCnt < iPos-1;iCnt++)
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
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>:: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct Node<T> *temp = First;
    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout << temp -> Data << " <->\t";
        temp = temp -> Next;
    }
    cout << "NULL\n";
}

/////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC SINGLY CIRCULAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
// Author        :  Sushma kawade
// Date          :  25 Dec 2022
//
/////////////////////////////////////////////////////////////////


int main()
{
    SinglyCL <int> obj1;

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

    obj1.InsertAtPos(151,3);

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

    