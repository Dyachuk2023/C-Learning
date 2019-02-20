#include <iostream>
#include <string>
using namespace std;


template<typename T>
class SmartPoint�r
{
public:
	SmartPoint�r(T *ptr) { this->ptr = ptr; }
	~SmartPoint�r() { delete ptr; }
	T& operator*() { return *ptr; }

private:
	T *ptr;
};

int main(void)
{
	SmartPoint�r<int> pointer = new int(5);
	return 0;
}