#include <iostream>
#include <string>
using namespace std;


template<typename T>
class SmartPointår
{
public:
	SmartPointår(T *ptr) { this->ptr = ptr; }
	~SmartPointår() { delete ptr; }
	T& operator*() { return *ptr; }

private:
	T *ptr;
};

int main(void)
{
	SmartPointår<int> pointer = new int(5);
	return 0;
}