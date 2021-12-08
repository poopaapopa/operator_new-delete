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
	/*����� ��� ��������� ������ ������������
	����������� ������� *malloc(size_t size);
	� �� ��������� size - ���������� ����, �������
	����� ��������. ���� ������ ����������, �� �� 
	malloc ������������ ����� ������ ����������� �����*/
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
	/*��� ������� ������ ������������ �����������
	������� void free(void* memblock);
	������� free ������� ������, memblok - �����
	������ ���������� �������*/
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