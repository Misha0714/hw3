#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T>  
{
public:
    Stack() {
        std::vector<T> {}
    }
    ~Stack();
    bool empty() const {
        std::vector<T>::empty(); 
    } 

    size_t size() const {
       std::vector<T>::size(); 
    }
    void push(const T& item) {
       insert(0,item);
    }
    void pop() {
        if(std::vector<T>::empty()) { 
            throw std::underflow_error(“empty”); 
            }

	    std::vector<T>::erase(0); 

    }
    const T& top() const {
        if(data.empty()) { 
            throw std::underflow_error("empty"); 
        }
	    std::vector<T>::front(); 
    }
 

  
};



#endif