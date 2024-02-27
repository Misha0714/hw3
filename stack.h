#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T>  
{
private: 

public:
    Stack() {
    }
    ~Stack() {}
		
    bool empty() const {
      	return std::vector<T>::empty(); 
    } 

    size_t size() const {
      	return std::vector<T>::size(); 
    }
    void push(const T& item) {
       std::vector<T>::insert(std::vector<T>::begin(),item);
    }
    void pop() {
        if(std::vector<T>::empty()) { 
            throw std::underflow_error("empty"); 
				}

	    	std::vector<T>::erase(std::vector<T>::begin()); 
    }
    const T& top() const {
			if(std::vector<T>::empty()) { 
					throw std::underflow_error("empty"); 
			}
	    return std::vector<T>::front(); 
    }
 

  
};



#endif