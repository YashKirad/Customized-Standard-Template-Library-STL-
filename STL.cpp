///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project Name :     Standard Template Library (STL)
//  Description :         Collection of all the LinkedList function libraries
//  Input :	                 -      
//  Output :	                 -
//  Date :                     17-06-2022
//  Author :                  Yash Yogesh Kirad
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////// SINGLY     LINEAR      LINKEDLIST   //////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
    public:
        struct node<T> *Head;
        int Count;

        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,T);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(T);
        void Display();
        int CountNode();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
            struct node<T> *temp = Head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }

            temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertAtPosition(T no, T pos)
{
    if((Head==NULL) || (pos>Count+1) || (pos<=0))
    {
       return;
     }
    if(pos==1)
     {
       return(InsertFirst(no));
     }
   else if(pos == (Count+1))
    {
       return(InsertLast(no));
     }
   else
    {
       struct node<T> *newn =NULL;
       struct node<T> *temp = Head;

         newn = new node<T>;
         newn->data = no;
         newn->next = NULL;

         for(int i = 1; i <=(pos-2);i++)
         {
             temp = temp->next;
          }
      newn->next = temp -> next;
      temp->next = newn;
    }
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
   struct node<T>*temp = Head;
    
    if(Head==NULL)
    {
        return;
     }
   else
    {
       Head = Head->next;
       delete(temp);
    }
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
   if(Head->next==NULL)
   {
      delete Head;
       Head = NULL;
    }
   else
    {
       struct node<T>*temp1 = Head;
       struct node<T>*temp2 = NULL;

      while(temp1->next->next!=NULL)
      {
        temp1 = temp1->next;
      }
     temp2 = temp1->next;
     temp1->next = NULL;
     delete(temp2);
    }
}

template<class T>
void SinglyLL<T>::DeleteAtPosition(T pos)
{
   if((Head==NULL) || (pos>Count) || (pos<=0))
   {
      return;
   }
  else if(pos==1)
   {
      DeleteFirst();
   }
   else if(pos==(Count))
    {
       DeleteLast();
    }
   else
   {
      struct node<T>*temp1 = Head;
      struct node<T>*temp2 = NULL;

       for(int i = 1; i<=(pos-2);i++)
       {
          temp1 = temp1->next;
            i++;
       }
     temp2 = temp1->next;
     temp1->next = temp2->next;

     delete(temp2);
   }
}

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements from Linked list are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////// SINGLY   CIRCULAR    LINKEDLIST  //////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
 struct node
{
  T  Data;
  struct node* Next;
};

template<class T>
class SinglyCLL
{
   public:				
         struct node<T> *Head;
         struct node<T>  *Tail;
         int Count;   

				
      SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,T);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(T);
        void Display();
        int CountNode();
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
   Head = NULL;
   Tail = NULL;
   Count = 0;
}  

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
        struct node<T> *newn = NULL;
        newn = new node<T>;

        newn->Data = no;
        newn->Next = NULL;

       if((Head==NULL)&&(Tail==NULL))		//if LL is empty
       {
            Head = newn;
            Tail = newn;
       }      
     else					//if LL contains atleast one node
      {
          newn->Next = Head;
          Head = newn;
      }  
    Tail->Next = Head;
     Count++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
         struct node<T> *newn = NULL;
         newn = new node<T>;

        newn->Data = no;
        newn->Next = NULL;

       if((Head==NULL)&&(Tail==NULL))		//if LL is empty
       {
            Head = newn;
            Tail = newn;
       }      
     else					//if LL contains atleast one node
      {
         Tail->Next = newn;
          Tail = newn;	//Tail=Tail->Next;
      }  
    Tail->Next = Head;
    Count++;
}

template<class T>
void SinglyCLL<T>::InsertAtPosition(T no, T ipos)
{

    if((ipos<1)||(ipos>Count+1) || (ipos<=0))
    {
       cout<<"Invalid position\n";
       return; 
    }
     if(ipos==1)
   {
      return(InsertFirst(no));
   }
   else if(ipos == (Count+1))
    {
       return(InsertLast(no));
    }
   else
    {
        struct node<T> *newn = NULL;
         newn = new node<T>;

        newn->Data = no;
        newn->Next = NULL;

       struct node<T> *temp = Head;

        for(int iCnt = 1; iCnt<=(ipos-1); iCnt++)
       {
           temp= temp->Next;
        }
        
       newn->Next = temp->Next;
       temp->Next = newn;
    }
   Count++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
   if(Head==NULL && Tail==NULL)		//if LL is empty
   {
       return;
   }
   else if(Head == Tail)			//if LL contains atleast one node
   {
        delete Head;		
        Head = NULL;
        Tail = NULL;
   }
   else					//if LL contains more than one nodes
   {
      Head = Head->Next;
      delete Tail->Next;
        Tail->Next = Head;
   }
  Count--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
      if(Head==NULL && Tail==NULL)		//if LL is empty
   {
       return;
   }
   else if(Head == Tail)			//if LL contains atleast one node
   {
        delete Head;		
        Head = NULL;
        Tail = NULL;
   }
   else					//if LL contains more than one nodes
   {
      struct node<T> *temp = Head;

       while(temp->Next!=Tail)
       {
          temp = temp->Next;
       }
    delete Tail;
     Tail = temp;

     Tail->Next = Head;
   }
  Count--;
}

template<class T>
void SinglyCLL<T>::DeleteAtPosition(T ipos)
{
    if((ipos<1)|| (ipos>Count))
    {
        cout<<"Invalid position\n";
        return;
    }
     if(ipos==1)
   {
      DeleteFirst();
   }
   else if(ipos == Count)
    {
       DeleteLast();
    }
   else
     {
       struct node<T> *temp1 = Head;
       struct node<T> *temp2 = NULL;

        for(int iCnt = 1; iCnt<=(ipos-1); iCnt++)
       {
           temp1= temp1->Next;
        } 
        temp2 = temp1->Next;

            temp1->Next = temp2->Next;
            delete temp2;
     }
  Count--;
}

template<class T>
void SinglyCLL<T>::Display()
{
   struct node<T> *temp = Head;

    if((Head==NULL)&&(Tail==NULL))	//if LL is empty
    {
       return;
    }
   do
   {
      cout<<"|"<<temp->Data<<"|->";
      temp = temp->Next;
   }while(temp!= Tail->Next);		

   cout<<"|11d|"<<endl;
}

template<class T>
int SinglyCLL<T>::CountNode()
{
/*   int iCnt = 0;
  PNODE temp = Head;
    if((Head==NULL)&&(Tail==NULL))	//if LL is empty
    {
       return 0;
    }
   do
   {
      iCnt++;
      temp = temp->Next;
   }while(temp!= Tail->Next);		//while(temp!=Head);
*/
  return Count;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////// DOUBLY   LINEAR    LINKEDLIST  //////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node* prev;
};

template<class T>
class DoublyLL
{
    public:
        struct node<T> *Head;
        int Count;

        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,T);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(T);
        void Display();
        int CountNode();
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        Head->prev = newn;
        newn -> next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
             struct node<T> *temp = Head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = newn;
            newn->prev = temp;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertAtPosition(T no, T pos)
{
    if((Head==NULL) || (pos>Count+1) || (pos<=0))
    {
       return;
     }
    if(pos==1)
     {
       return(InsertFirst(no));
     }
   else if(pos == (Count+1))
    {
       return(InsertLast(no));
     }
   else
    {
       struct node<T> *newn =NULL;
       struct node<T> *temp = Head;

         newn = new node<T>;
         newn->data = no;
         newn->next = NULL;

         for(int i = 1; i <=(pos-2);i++)
         {
             temp = temp->next;
          }
      newn->next = temp -> next;
      temp->next->prev = newn;
      newn->prev = temp;
      temp->next = newn;
    }
Count++;
}


template<class T>
void DoublyLL<T>::DeleteFirst()
{
   struct node<T> *temp = Head;
    
    if(Head==NULL)
    {
        return;
     }
   else
    {
       Head = Head->next;
        Head->prev = NULL;

       delete(temp);
    }
  Count--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
   if(Head->next==NULL)
   {
      delete Head;
       Head = NULL;
    }
   else
    {
       struct node<T> *temp = Head;

      while ((temp->next!=NULL))
      {
        temp = temp->next;
      }
     temp->prev->next = NULL;
     delete temp;
    }
   Count--;
}

template<class T>
void DoublyLL<T>::DeleteAtPosition(T pos)
{
   if( (pos>Count) || (pos<1))
   {
      return;
   }
  else if(pos==1)
   {
      DeleteFirst();
   }
   else if(pos==(Count+1))
    {
       DeleteLast();
    }
   else
   {
      struct node<T> *temp = Head;

       for(int i = 1; i<=(pos-2);i++)
       {
          temp = temp->next;
       }
     temp->next = temp->next->next;
     delete temp->next->prev;
     temp->next->prev = temp;
   }
   Count--;
}

template<class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements from Linked list are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


template<class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////// DOUBLY   CIRCULAR     LINKEDLIST ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCLL
{
     public:
        struct node<T> *Head;
        struct node<T> *Tail;
        int CountNode;

        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, T);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T);

        int Count();
        void Display();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    CountNode = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(CountNode == 0)  // if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head -> prev = newn;
        Head = newn;
    }

    Head->prev = Tail;
    Tail->next = Head;

    CountNode++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T iNo)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(CountNode == 0)  // if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
           Tail->next = newn;
           newn->prev = Tail;

           Tail = newn;
    }

    Head->prev = Tail;
    Tail->next = Head;

    CountNode++;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T iNo,T iPos)
{
        if((iPos < 1) || (iPos > CountNode+1))
        {
            cout<<"Invalid position\n";
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if(iPos == CountNode+1)
        {
            InsertLast(iNo);
        }
        else
        {
    struct node<T> *newn = NULL;
    newn = new node<T>;

            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;

            struct node<T> *temp = Head;

            for(int i = 1; i<iPos-1; i++)
            {
                temp = temp->next;
            }

                newn->next = temp->next;
                temp->next->prev = newn;
                temp->next = newn;
                newn->prev = temp;

                CountNode++;
        }
}


template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(CountNode == 0)
    {
            return;
    }
    else if(CountNode == 1)
    {
            delete Head;
            Head = NULL;
            Tail = NULL;
    }
    else
    {
            Head = Head->next;
            delete Tail->next;          // delete Head->prev;
    }

    Tail->next = Head;
    Head->prev = Tail;
    CountNode--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
  if(CountNode == 0)
    {
            return;
    }
    else if(CountNode == 1)
    {
            delete Tail;
            Head = NULL;
            Tail = NULL;
    }
    else
    {
            Tail = Tail->prev;
            delete Tail->next;          // delete Head->prev;
    }

    Tail->next = Head;
    Head->prev = Tail;
    CountNode--;
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(T iPos)
{
        if((iPos < 1) || (iPos > CountNode))
        {
            cout<<"Invalid position\n";
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == CountNode)
        {
            DeleteLast();
        }
        else
        {
             struct node<T> *temp = Head;

            for(int i = 1; i<iPos-1; i++)
            {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;

            CountNode--;
        }
}

template<class T>
void DoublyCLL<T>::Display()
{
       int i = 0;
       struct node<T> *temp = Head;

       for(i = 1; i<= CountNode; i++)
       {
            cout<<"|"<<temp->data<<"|<=>";
            temp = temp->next;
       }
       cout<<"\n";
}

template<class T>
int DoublyCLL<T>::Count()
{
    return CountNode;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// STACK   USING  NODES  OF  A  LINKEDLIST /////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Stack
{
    public:
        struct node<T> *Head;
        int Count;

        Stack();
        void Push(T);       
        void Pop();           
        void Display();
        int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
            struct node<T> *temp = Head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }

            temp->next = newn;
    }
    Count++;
}

template<class T>
void Stack<T>::Pop()
{
   if(Head->next==NULL)
   {
      delete Head;
       Head = NULL;
    }
   else
    {
       struct node<T>*temp1 = Head;
       struct node<T>*temp2 = NULL;

      while(temp1->next->next!=NULL)
      {
        temp1 = temp1->next;
      }
     temp2 = temp1->next;
     temp1->next = NULL;
     delete(temp2);
    }
  Count--;
}

template<class T>
void Stack<T>::Display()
{
    cout<<"Elements from Stack are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int Stack<T>::CountNode()
{
    return Count;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// QUEUE   USING  NODES  OF  A  LINKEDLIST /////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Queue
{
    public:
        struct node<T> *Head;
        int Count;

        Queue();
        void Enqueue(T);        // InsertLast
        void Dequeue();            // DeleteFirst
        void Display();
        int CountNode();
};

template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Queue<T>::Enqueue(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
            struct node<T> *temp = Head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }

            temp->next = newn;
    }
    Count++;
}

template <class T>
void Queue<T>::Dequeue()       // Deletefirst
{
    T no;   // int no;

    if(Count == 0)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    no = Head -> data;
    struct node<T> *temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

template<class T>
void Queue<T>::Display()
{
    cout<<"Elements from Queue are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int Queue<T>::CountNode()
{
    return Count;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////