// Generic  code for Doubly Linear Linked LIST


#include<iostream>
using namespace std ;

template<class T>
struct node 
{
  T data;
  struct node* next ;
  struct node* prev ;
} ;


template<class T>
using NODE = struct node<T> ;

template<class T>
using PNODE = struct node<T>* ;



template<class T>
class DoublyLL
{
  private :
      PNODE<T> first ;
      PNODE<T> last ;
      int size  ;

  public :
      DoublyLL()
      {
        first = NULL ;
        last = NULL ;
        size = 0 ;
      }

     void Display();
     int Count();
     void InsertFirst(T) ;
     void InsertLast(T) ;
     void InsertAtPos(T,int) ;
     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(int ipos);

}; //Class ENDS


template<class T>
void DoublyLL<T> :: Display()
{   
  PNODE<T> temp = first ;

  for(int i=1 ; i<=size ;i++)
  {
    cout<<"|"<<temp->data<<"|->" ;
    
    temp= temp->next ;
  }
  cout<<"\n" ;
}//Display()

template<class T>
int DoublyLL<T> :: Count() 
{ 
  return size ; 
} // Count


template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{   
        PNODE<T> newn = new NODE<T> ;
        
        newn->data=no ;
        newn->next = NULL ;
        newn->prev =NULL ;

        if((first==NULL) && (last==NULL)) // LL is Empty
        {
          first = newn ; 
          last =newn   ;
        }
        else                               // LL has more than 1 node
        {
            newn->next = first ;
            first->prev = newn ;
            first=newn ;
        }
        size++ ;              
}//InsertFirst()


template<class T>
void DoublyLL<T> :: InsertLast(T no)
{   
  PNODE<T> newn = new NODE<T> ;
        
  newn->data=no ;
  newn->next = NULL ;
  newn->prev =NULL ;

    if((first==NULL) && (last==NULL)) // LL is Empty
    {
        first = newn ; 
        last =newn   ;
    }
    else                               // LL has more than 1 node
    {
        last->next = newn  ;
        newn->prev = last  ;
        last = newn ;
    }
   size++ ;              
}//InsertLast()


template<class T>
void DoublyLL<T> :: DeleteFirst()
{   
    if((first==NULL) && (last==NULL)) // LL is Empty
    {
      return ;
    }

    else if(first == last)  // LL contains only 1 node
    {
        delete first ;
        first = NULL ; 
        last = NULL  ; 
    }
    else                  // LL has more than 1 element
    {
        first = first->next ;
        delete last->next ;
    }
    size-- ;
}//DeleteFirst()

template<class T>
void DoublyLL<T> :: DeleteLast()
{   
  
    if((first==NULL) && (last==NULL)) // LL is Empty
    {
      return ;
    }

    else if(first == last)  // LL contains only 1 node
    {
        delete last ;
        first = NULL ; 
        last = NULL  ; 
    }
    else                  // LL has more than 1 element
    {
        last = last->prev ;
        delete last->next ; 
    }
    size-- ;
}//DeleteLast()

template<class T>
void DoublyLL<T> :: InsertAtPos(T no , int ipos)
{   
  if((ipos<1) || (ipos>(size+1)))
  {
    return ;
  }

  if(ipos==1)
  {       InsertFirst(no) ;   }

  else if(ipos==size+1)
  {       InsertLast(no) ;     }

  else
  {
      PNODE<T> newn = new NODE<T> ;

      newn->data = no ;
      newn->next = NULL ;
      newn->prev = NULL ;
  
      PNODE<T> temp = first ;

      for(int i=1 ; i<ipos-1 ;i++)
      {
        temp= temp->next ;
      }

      newn->next = temp->next ;
      newn->next->prev = newn ; 
      temp->next = newn ;
      newn->prev = temp ;

      size ++ ; 
  }        
}//InsertAtPos()


template<class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{   
    if((ipos<1) || (ipos>size))
  {
    return ;
  }

  if(ipos==1)
  {       DeleteFirst() ;   }

  else if(ipos==size)
  {       DeleteLast() ;     }

  else
  {
    PNODE<T> temp = first ;

      for(int i=1 ; i<ipos-1 ;i++)
      {
        temp= temp->next ;
      }

      temp->next = temp->next->next ; 
      delete temp->next->prev ;
      temp->next->prev =   temp ;

      size-- ;
  }
}//DeleteAtPos()

int main()
{
  int iRet = 0 ;
  DoublyLL<int> obj ;

  obj.InsertFirst(21) ;
  obj.InsertFirst(11) ;
  obj.InsertLast(51);
  obj.InsertLast(101);
  obj.InsertAtPos(75,3) ;
  obj.Display() ;
  
  iRet = obj.Count() ;
  cout<<"Number of nodes : "<<iRet <<"\n" ;

  obj.DeleteAtPos(3);
  obj.DeleteFirst() ;
  obj.DeleteLast() ;

  obj.Display() ;
  iRet = obj.Count() ;
  cout<<"Number of nodes : "<<iRet <<"\n" ;

  cout<<"\n" ;

  DoublyLL<char> cobj ;

  cobj.InsertFirst('A') ;
  cobj.InsertFirst('B') ;
  cobj.InsertLast('C');
  cobj.InsertLast('D');
  cobj.InsertAtPos('E',3) ;
  cobj.Display() ;
  
  iRet = cobj.Count() ;
  cout<<"Number of nodes : "<<iRet <<"\n" ;

  cobj.DeleteAtPos(3);
  cobj.DeleteFirst() ;
  cobj.DeleteLast() ;

  cobj.Display() ;
  iRet = cobj.Count() ;
  cout<<"Number of nodes : "<<iRet <<"\n" ;



  DoublyLL<float> fobj ;

  fobj.InsertFirst(11.5) ;
  fobj.InsertFirst(21.5) ;
  fobj.InsertLast(51.5);
  fobj.InsertLast(101.5);
  fobj.InsertAtPos(111.5,3) ;
  fobj.Display() ;
  
  iRet = fobj.Count() ;
  cout<<"Number of nodes : "<<iRet <<"\n" ;

  fobj.DeleteAtPos(3);
  fobj.DeleteFirst() ;
  fobj.DeleteLast() ;

  fobj.Display() ;
  iRet = fobj.Count() ;
  cout<<"Number of nodes : "<<iRet <<"\n" ;

  return 0 ;
}