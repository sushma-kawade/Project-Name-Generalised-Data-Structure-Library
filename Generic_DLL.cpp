/=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================
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

template <class T>
class DoublyLL
{
    public:
    struct Node<T> *First;   //charactristics
    int iCount;

    DoublyLL();
    void InsertAtFirst(T);
    void InsertAtLast(T);
    void InsertAtPos(T,T);

    void DeleteAtFirst();
    void DeleteAtLast();
    void DeleteAtPos(T);

    void Display();

};
/=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================
template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

/=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================
template <class T>
void DoublyLL<T>::InsertAtFirst(T No)
{
    struct Node<T> *Newn = new struct Node<T>;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Prev = NULL;

    if(First == NULL)
    {
        First = Newn;
    }
    else
    {
        Newn->Next = First;
        First->Prev = Newn;
        First = Newn;
        iCount++;
    }

}
//=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================


template <class T>
void DoublyLL<T> :: InsertAtLast(T No)
{
    struct Node<T> *Newn = new struct Node<T>;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Prev = NULL;

    struct Node<T> *temp = First;

    if(First == NULL)
    {
        First = Newn;
    }
    else
    {
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = Newn;
        Newn->Prev = temp;
        iCount++;

    }
}

/=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================
template <class T>
void DoublyLL<T> :: InsertAtPos(T No, T iPos)
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
        Newn->Next = temp -> Next;
        temp->Next->Prev = Newn;    // X
        temp->Next = Newn;
        Newn->Prev = temp; 
        iCount++;
    }
}

/=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================
template <class T>
void DoublyLL<T> :: DeleteAtFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next== NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct Node<T> *temp = First;
        First = First->Next;
        delete temp -> Prev;
        First->Prev = NULL;
        iCount--;
    }
}

/=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================
template <class T>
void DoublyLL<T> :: DeleteAtLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next == NULL)
    {
        delete First;
        First = NULL;
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
/=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================
template <class T>
void DoublyLL<T>:: DeleteAtPos(T iPos)
{

    if((iPos <1) || (iPos > iCount + 1))
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

/=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================
template<class T>
void DoublyLL<T> :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    cout<<"NULL"<<"<=>";
    struct Node<T> *temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->Data<<" |<=>";
        temp = temp->Next;
    }
    cout<<"NULL"<<"\n";
}
/=========================================================================
//
//
// Class Name       :   DoublyLL
// Function Date    :   25 Dec 2022
// Function Author  :   Sushma Kawade
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================
int main()
{  
    DoublyLL <int> obj1;
    obj1.InsertAtFirst(30);
    obj1.InsertAtFirst(20);
    obj1.InsertAtFirst(10);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtLast(40);
    obj1.InsertAtLast(50);

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

    obj1.DeleteAtPos(4);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";





}