//Generic code for Stack implementation


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
class Stack     
{
private:
    PNODE<T> first;
    int size;
    
public:
    Stack() ;
    void push(T no) ;
    T pop()    ;
    void Display() ;
    int Count() ;
};


template<class T>
Stack<T> :: Stack()
{
    first = NULL;
    size = 0;
}
    
template<class T>
void Stack<T> :: push(T no)
{
    PNODE<T> newn = new NODE<T> ;

    newn->data = no ;
    newn->next = NULL ;

    if((first==NULL))
    {
        first = newn ;
    }
    else
    {
        newn->next = first ;
        first=newn ;
    }
    size++ ;
}//push()
    
template<class T>
T Stack<T> :: pop()   
{
    T no  ;
    PNODE<T> temp = first ;

    if(size==0)
    {
        cout<<"Stack is empty\n"  ;
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

}//POP()
    
template<class T>
void Stack<T> ::  Display()
{
    PNODE<T> temp = first ;
        
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"\n" ;
        temp= temp->next ;
    }
}//display()
    
template<class T>
int Stack<T> :: Count()
{
   return size;
}

int main()
{
    int iret =  0 ;
    char cRet = '\0' ;

    Stack<int> obj;
    
    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);
    
    cout<<"Elements of stack \n" ;
    obj.Display() ;
    
    iret = obj.pop();       
    cout<<"Popped element : "<<iret<<"\n";                     

    iret = obj.Count();
    cout<<"Size of stack is : "<<iret<<"\n";        

    cout<<"Elements of stack \n" ;
    obj.Display();          


    Stack<char> cobj;
    
    cobj.push('A');
    cobj.push('B');
    cobj.push('C');
    cobj.push('D');
    
    cout<<"Elements of stack \n" ;
    cobj.Display() ;
    
    cRet = cobj.pop();       
    cout<<"Popped element : "<<cRet<<"\n";                     

    iret = cobj.Count();
    cout<<"Size of stack is : "<<iret<<"\n";        

    cout<<"Elements of stack \n" ;
    cobj.Display();          

    return 0;
}
