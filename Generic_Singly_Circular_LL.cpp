//Generic code for  SINGLY CIRCULAR Linked LIST



#include<iostream>
using namespace std ;

template<typename T>
struct node
{
  T data;
  struct node *next ;
} ;


template<class T>
class SinglyCL 
{
    private :
           node<T>* first ;
           node<T>* last ;
          int size ;

    public :
        SinglyCL() ;
        void Display() ;
        int Count() ;
        void InsertFirst(T no) ;
        void InsertLast(T no) ;
        void InsertAtPos(T no , int ipos)  ;
        void DeleteFirst() ;
        void DeleteLast() ;
        void DeleteAtPos(int ipos)  ;
}; // class ends


        template<class T>
       SinglyCL<T> :: SinglyCL()
        {
          first = NULL  ;
          last = NULL   ;
          size = 0      ;
        }      

    template<class T>
    void SinglyCL<T> :: Display()
    {   
       node<T>* temp = first ;

        if((first == NULL) && (last == NULL)) // LL is empty
        {
          return ;
        }

        do
        {
          cout<<"|"<<temp->data<<"|->" ;
          temp = temp->next ;
        }while(temp != last->next) ;
        cout<<endl ;

        
    }//Display()

    template<class T>
    int SinglyCL<T> :: Count()
    {
        return size ;  
    }//Count()

    template<class T>
    void SinglyCL<T> ::  InsertFirst(T no)
    {
        node<T>* newn = new node<T> ;

        newn->data = no ;
        newn->next = NULL ;

        if((first==NULL) && (last==NULL)) // if(size==0) 
        {
          first = newn ;
          last = newn ;
        }
        else
        {
          newn->next = first ;
          first = newn ;
        }
        last->next = first ;  
        size++ ;              
    }//InsertFirst()

    template<class T>
    void SinglyCL<T> ::  InsertLast(T no)
    {     
      node<T>* newn = new node<T> ;

        newn->data = no ;
        newn->next = NULL ;

        if((first==NULL) && (last==NULL)) // if(size==0) 
        {
          first = newn ;
          last = newn ;
        }
        else
        {
            last->next = newn ;
            last = newn ;
        }
        last->next = first ;  
        size++ ;              
    }//InsertLast()

    
    template<class T>
    void SinglyCL<T> :: InsertAtPos(T no , int ipos) 
    {   
      if((ipos<1) || (ipos>(size+1))) // filter 
      {
        return ;
      }

      if(ipos ==1)            // 1st position
        InsertFirst(no) ;

      else if(ipos== size+1)  // Last Position
          InsertLast(no) ;

      else
      {
          node<T>* newn = new node<T> ;
          node<T>* temp = first ;

          newn->data = no ;
          newn ->next = NULL ;

          for(int i=1 ; i<ipos-1 ; i++)
          {
            temp = temp->next ;
          }
            newn->next = temp->next ;
            temp->next = newn ;

            size++ ; 
      }    

    }//InsertAtPos()
    
    template<class T>
    void SinglyCL<T> :: DeleteFirst()
    {   
      if((first ==NULL) && (last ==NULL)) // if(size ==0) 
      {
        return ;
      }
      else if(first==last) // if(size ==1) 
      {
        delete first ;
        first = NULL ;
        last = NULL ;
      }
      else                  // More than 1 node in LL
      {
        first = first->next ;
        delete last->next ;
        last->next = first ;
      }
      size -- ;
    }//DeleteFirst()

    template<class T>
    void SinglyCL<T> ::  DeleteLast()
    {   
        node<T>* temp = first ;

        if((first ==NULL) && (last ==NULL)) // if(size ==0)
      {
        return ;
      }
      else if(first==last) // if(size ==1) 
      {
        delete first ;
        first = NULL ;
        last = NULL ;
      }
      else                  // More than 1 node in LL
      {
        while(temp ->next != last)
        {
          temp = temp->next ;
        }
        delete last ;
        last = temp ;
        last->next = first ;
      }
      size -- ;
    }//DeleteLast()


    template<class T>
    void SinglyCL<T> ::  DeleteAtPos(int ipos) 
    {   
      if((ipos <1) || (ipos>size))
        return ;

      if(ipos==1) 
          DeleteFirst() ;

      else if(ipos==size)
          DeleteLast() ;

      else
      {
        node<T>* temp = first ;

        for(int i=1 ; i<ipos-1 ; i++)
        {
          temp = temp->next ;
        }
        
      node<T>* targeted = temp->next ;

      temp->next  = targeted->next ;
      delete targeted ;   

        size-- ; 
      }          
    }//DeleteAtPos()


int main()
{
  int iRet = 0 ;
  SinglyCL<int> obj ;

  obj.InsertFirst(51);
  obj.InsertFirst(21);
  obj.InsertFirst(11);

  obj.InsertLast(101) ;

  obj.Display() ;

  iRet = obj.Count() ;
  cout<<"Number of elements : "<<iRet<<"\n" ;

  obj.DeleteFirst() ;
  obj.DeleteLast() ;

  obj.Display() ;

  iRet = obj.Count() ;
  cout<<"Number of elements : "<<iRet<<"\n" ;


//////////////////////////////////////


  SinglyCL<char> cobj ;

  cobj.InsertFirst('A');
  cobj.InsertFirst('B');
  cobj.InsertFirst('C');

  cobj.InsertLast('D') ;

  cobj.Display() ;

  iRet = cobj.Count() ;
  cout<<"Number of elements : "<<iRet<<"\n" ;

  cobj.DeleteFirst() ;
  cobj.DeleteLast() ;

  cobj.Display() ;

  iRet = cobj.Count() ;
  cout<<"Number of elements : "<<iRet<<"\n" ;

  

  return 0 ;
}