#include <iostream>


template <class T, int low, int high>
class IntervalValue
{
public:
  IntervalValue()=default;
  IntervalValue(const IntervalValue &tmp) 
  : _low(tmp.getLow()), _high(tmp.getHigh())
  {
    
  }
  
  void operator=(const IntervalValue &tmp)
  {
    _low = tmp.getLow();
    _high = tmp.getHigh(); 
  }  
  IntervalValue &operator++()
  {
    ++_high;
    return *this;
  } 
  IntervalValue &operator--()
  {
    --_low;
    return *this;
  }
   
  
 
  T getLow() { return _low; }
  T getHigh() { return _high;}
  ~IntervalValue() {}
private:
  T _low = low;
  T _high = high; 
};


template<class T, int low, int high>
std::ostream &operator<<(std::ostream &out, IntervalValue<T, low, high> &tmp)
{
  out << tmp.getLow() << " " << tmp.getHigh();
  return out;	
}



int main()
{
  IntervalValue<int, 2, 15> a, b;
  std::cout << ++a << std::endl;
  std::cout << --a << std::endl;
  std::cout << a;
}
