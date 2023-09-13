
#include <iostream>
#include <queue>
//The std::queue class is a container adaptor that gives the programmer the functionality of a queue - specifically, a FIFO (first-in, first-out) data structure.
//The queue pushes the elements on the back of the underlying container and pops them from the front.

using namespace std;
int main() {
    
    //Creating a queue name "s"
    queue <int>s;
    
    //Pushing the Element in the Queue
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    cout<<" Before pop operation the element at the front is:"<<s.front()<<endl;
    
    //Printing the size of the QUEUE
    cout<<"The size of the queue is:"<<s.size()<<endl;
    cout<<endl;
    
    //Pop operation 
    s.pop();
    cout<<endl;
    
    //printing the front Element
    cout<<"After the Pop operation the element at the front is:"<<s.front()<<endl;
    
    //Printing the size  after pop operation of the QUEUE
    cout<<"After pop operation size is:"<<s.size()<<endl;
    cout<<endl;
    
    //Empty Operation
    if(s.empty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Queue is not Empty"<<endl;
    }
}
