#include <iostream>
#include <malloc.h>
using namespace std;

class SomeClass
{
	int some;
public:
	void* operator new(size_t size,const char* str = "New");
	void operator delete(void* ptr);
	void* operator new[](size_t fullsize,const char* str = "New []");
	void operator delete[](void* ptr);
};

void* SomeClass::operator new(size_t size,const char* str)
{
	cout << "\n" << str << "\n";
	/*Здесь для выделения памяти используется
	стандартная функция *malloc(size_t size);
	В неё передаётся size - количество байт, которое
	нужно выделить. Если память выделяется, то из 
	malloc возвращается адрес начала выделенного блока*/
	void* ptr = malloc(size);
	if (!ptr)
		cout << "\nError memory new!!!\n";
	else
		cout << "\nMemory new - OK!!!\n";
	return ptr;
}
void* SomeClass::operator new[](size_t fullsize,const char* str)
{
	cout << "\n" << str << "\n";
	void* ptr = malloc(fullsize);
	if (!ptr)
		cout << "\nError memory new!!!\n";
	else
		cout << "\nMemory new - OK!!!\n";
	return ptr;
}
void SomeClass::operator delete(void* ptr)
{
	/*Для очистки памяти используется стандартная
	функция void free(void* memblock);
	Функция free очищает память, memblok - адрес
	начала очищаемого участка*/
	free(ptr);
	cout << "\nDelete memory\n";
}
void SomeClass::operator delete[](void* ptr)
{
	free(ptr);
	cout << "\nDelete memory\n";
}

int main()
{
	SomeClass* p = new SomeClass;
	SomeClass* r = new SomeClass[10];
	delete p;
	delete[] r;
	return 0;
}