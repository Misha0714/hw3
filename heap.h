#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

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
T const & Heap<T,PComparator>::top() const {
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(data.empty()){
    throw std::out_of_range("heap is empty");
  }
  return data.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
void Heap<T,PComparator>::heapify(std::vector<T>& data) { 
  
  //set index 
  std::size_t index = 0;
  //parent index
  std::size_t parent_index = (index - 1) / m;
  //parent value 
  T& parent = data[parent_index];
  //left and right nodes index 
  int leftIndex = m * index + 1; 
  int rightIndex = m * index + m;
  //while this is true 
  while(true) {
    //iterate through the children 
    for(int i=leftIndex; i<rightIndex; i++) {
      //best node 
      T& best = data[leftIndex];
      //check to see you are not at the last child 
      if(leftIndex >= m || rightIndex >= m) {
        //if best is worse compared to the next index 
        if(c(best, data[i+1])) {
          //then swap the two places 
          std::swap(best, data[i+1]);
          //update best 
          best = data[i+1]; 
        }
        break; 
      }
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::pop() {
  if(data.empty()){
    throw std::underflow_error("heap is empty");
  }

	if (data.size() == 1) {
        //if there is one data member then just pop back the only element 
       data.pop_back(); 
  }
  heapify(data); 
}  


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

