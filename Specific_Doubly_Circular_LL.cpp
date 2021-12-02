//Generic code for Doubly CIRCULAR Linked LIST


#include<iostream>
using namespace std ;

template<class T>
struct node
{
    T data ; 
    struct node *next ;
    struct node *prev ;
} ;


template<class T>
using NODE = struct node<T> ;

template<class T>
using PNODE = struct node<T>* ;


template<class T>
class DoublyCL
{
  private :
      PNODE<T> first ;
      PNODE<T> last ;
      int size  ;

  public :
      DoublyCL()
      {
        first = NULL ;
        last = NULL ;
        size = 0 ;
      }

     void Display();
     int Count();
     void InsertFirst(T no) ;
     void InsertLast(T no) ;
     void InsertAtPos(T no ,int ipos) ;
     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(int ipos);

}; //Class ENDS


template<class T>
void DoublyCL<T> :: Display()
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
int DoublyCL<T> :: Count() 
{ 
  return size ; 
} // Count()
      

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{   
        PNODE<T> newn = new NODE<T> ;
        
        newn->data=no ;
        newn->next = NULL ;
        newn->prev =NULL ;

        if((first==NULL) && (last==NULL)) 
        {
          first = newn ; 
          last =newn   ;
        }
        else                               
        {
            newn->next = first ;
            first->prev = newn ;
            first=newn ;
        }
        last->next = first ;  
        first->prev = last ;  
        size++ ;              

}//InsertFirst()

        
template<class T>
void DoublyCL<T> :: InsertLast(T no)
{   
  PNODE<T> newn = new NODE<T> ;
        
  newn->data=no ;
  newn->next = NULL ;
  newn->prev =NULL ;

    if((first==NULL) && (last==NULL)) 
    {
        first = newn ; 
        last =newn   ;
    }
    else                              
    {
        last->next = newn  ;
        newn->prev = last  ;
        last = newn ;

    }
   last->next = first ;  
   first->prev = last ;  
   size++ ;              

}//InsertLast()



template<class T>
void DoublyCL<T> :: DeleteFirst()
{   
    if((first==NULL) && (last==NULL)) 
    {
      return ;
    }

    else if(first == last)  
    {
        delete first ;
        first = NULL ; 
        last = NULL  ; 
    }
    else               
    {
        first = first->next ;
        delete last->next ;
        
       first->prev = last ;
       last->next  = first ;
    }
    size-- ;

}//DeleteFirst()

template<class T>
void DoublyCL<T> :: DeleteLast()
{   
  
    if((first==NULL) && (last==NULL)) 
    {
      return ;
    }

    else if(first == last)  
    {
        delete first ; 
        first = NULL ; 
        last = NULL  ; 
    }
    else               
    {
        last = last->prev ;
        delete last->next ; 

        first->prev = last  ;
        last->next  = first ;
    }
    size-- ;
}//DeleteLast()


template<class T>
void DoublyCL<T> :: InsertAtPos(T no , int ipos)
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
void DoublyCL<T> :: DeleteAtPos(int ipos)
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
  DoublyCL<int> obj ;

  obj.InsertFirst(21) ;
  obj.InsertFirst(11) ;
  obj.InsertLast(51);
  obj.InsertLast(101);
  obj.InsertAtPos(75,3) ;
  obj.Display() ;
  
  obj.Count() ;
  cout<<"Number of nodes : "<<iRet <<"\n" ;

  obj.DeleteAtPos(3);
  obj.DeleteFirst() ;
  obj.DeleteLast() ;

  obj.Display() ;
  iRet = obj.Count() ;
  cout<<"Number of nodes : "<<iRet <<"\n" ;


  cout<<"\n" ;

   DoublyCL<char> cobj ;

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

  return 0 ;
}