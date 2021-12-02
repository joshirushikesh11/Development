// Generic  code for Queue Implementation


#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
} ;


template<class T>
using NODE = struct node<T> ; 

template<class T>
using PNODE = struct node<T>* ; 


template<class T>
class Queue     
{
private:
    PNODE<T> first;
    int size;
    
public:
    Queue() ;
    void Enqueue(T no) ;
    T Dequeue()   ;
    void Display() ;
    int Count() ;
};

template<class T>
Queue<T> :: Queue()
{
    first = NULL;
    size = 0;
}

template<class T>
void Queue<T> :: Enqueue(T no)   
{
    PNODE<T> newn = new NODE<T> ;

    newn->data = no ;
    newn->next = NULL ;

    if(size==0) 
    {
        first = newn ;
    }
    else
    {
        PNODE<T> temp = first ;

        while(temp->next != NULL)
        {
            temp= temp->next ;
        }
        temp->next = newn ;
    }
    size++ ;
}//Enqueue()



template<class T>
T Queue<T> :: Dequeue()   
{
    int no = 0 ;
    PNODE<T> temp = first ;

    if(size==0)
    {
        cout<<"Queue is empty\n"  ;
        return -1 ;
    }

    if(size == 1)
    {
        no = first->data ;
        delete first ;
        first = NULL ;
    }

    else
    {
        no= first->data ;
        first= first->next ;
        delete temp ;
    }
    size-- ;
    return no ;
}// Dequeue()

template<class T>
void Queue<T> :: Display()
{
    PNODE<T> temp = first  ;
    for(int i =1  ; i<=size ; i++)
    {
        cout<<"|"<<temp->data<<"|->" ;
        temp=temp->next ;
    }
    cout<<"\n" ;
}//Display()

template<class T>
int Queue<T> :: Count()
{
   return size;
}//count()


int main()
{
     int iret = 0 ;
     char cRet = '\0' ;
    Queue<int> obj;
    
    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);

    cout<<"Elements of Queue \n" ;
    obj.Display();    

    iret = obj.Dequeue();       
    cout<<"Removed elemnt from queue : "<<iret<<"\n" ;    
    
    cout<<"Elements of Queue \n" ;
    obj.Display();          
    iret = obj.Count();     
    
    cout<<"Size of queue is : "<<iret<<"\n";        


    Queue<char> cobj;
    
    cobj.Enqueue('A');
    cobj.Enqueue('B');
    cobj.Enqueue('C');
    cobj.Enqueue('D');

    cout<<"Elements of Queue \n" ;
    cobj.Display();    

    cRet = cobj.Dequeue();       
    cout<<"Removed elemnt from queue : "<<cRet<<"\n" ;    
    
    cout<<"Elements of Queue \n" ;
    cobj.Display();          
    cRet = cobj.Count();     
    
    cout<<"Size of queue is : "<<cRet<<"\n";        
    
    return 0;
}
