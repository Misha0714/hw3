#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> data; 
  int m; 
  PComparator c; 
  void heapify(std::vector<T>& data);

};

// Add implementation of member functions here
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) {
  int m_=m; 
	PComparator c_= c; 
}


template <typename T, typename PComparator>
Heap<T,PComparator>::Heap::~Heap() { } 

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  if (data.empty()) {
    return true; 
  } 
  return false; 
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  size_t size_ = data.size(); 
  return size_; 
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const {
   if(data.empty()) {
    throw std::underflow_error("heap is empty");
  }
  return data.front(); 
}
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(std::vector<T>& data) { 
  
  //set index 
  std::size_t index = 0;
  
  //parent index
  //std::size_t parent_index = (index - 1) / m;
  //parent value 
  //T& parent = data[parent_index];
  //left and right nodes index 
  //while this is true 
  int leftIndex = m * index + 1; 
  int rightIndex = m * index + m;
  bool trickle = true; 
  data[0] = data[data.size()-1]; 
  data.pop_back(); 
  while(trickle) {
    if(leftIndex >= data.size) { 
      break;
    } 
    int bestIndex = leftIndex;
    //iterate through the children
      for(int i=leftIndex; i<rightIndex; i++) {
        //best node
        //check to see you are not at the last child 
        if(i+1 < data.size()) {
          //if best is worse compared to the next index 
          if(c(data[i+1], data[bestIndex])) {
            //update best 
            bestIndex = i+1; 
          } 
        }
      }
      //compare child node with parent node 
      if(c(data[bestIndex], data[index])) {
        std::swap(data[bestIndex], data[index]);
        index=bestIndex; 
      }
      else { trickle=false; }
  
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::pop() {
  //if vector is empty throw error 
  if(data.empty()){
    throw std::underflow_error("heap is empty");
  }
  //if size of vector is one just pop_back() the vector 
	if (data.size() == 1) {
       data.pop_back(); 
       return; 
  }
  //otherwise call heapify on the vector 
  heapify(data); 

}  

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
    	data.push_back(item);
    	//adjust the index for the new item 
    	std::size_t index = data.size() - 1;
    	while (index != 0) {
        //while index does not equal 0 compare current node to parent node 
        std::size_t parent_index = (index - 1) / m;
        if(parent_index < 0) {
          break; 
        }
        T& current = data[index];
        T& parent = data[parent_index];
        //if current node is less than parent you are done
        if (c(current, parent)) {
          //if the current node is less than swap the two nodes and adjust the index you are at to the parent
          std::swap(current, parent);
          index = parent_index;
        }
        else {
          break; 
        }
    }
}





#endif

