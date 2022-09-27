#include "Main.h"
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

template<typename T>
class Vector
{
private:
	T* elem;
	int sz;
public:
	Vector(int s);
	~Vector();

	T& operator[](int i);
	//const T& operator[](int i)const;
	int size()const { return sz; }
	T* begin(Vector<T>& x);
	T* end(Vector<T>& x);


};

template<typename T>
Vector<T>::Vector(int s)
{
	if (s < 0) throw;
	elem = new T[s];
	sz = s;
	
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] elem;
}

template<typename T>
 T& Vector<T>::operator[](int i) 
{
	// TODO: 在此处插入 return 语句
	if (i < 0 || size() <= i)
		throw out_of_range{ "Vector::operator[]" };
	return elem[i];
}

template<typename T>
T* Vector<T>::begin(Vector<T>& x)
{
	return &x[0];
}

template<typename T>
T* Vector<T>::end(Vector<T>& x)
{

	return x.begin()+x.size();

}

template<typename T>
class Less_than
{
	const T val;
public:

	Less_than(const T& v)
		:val(v)
	{

	};
	bool operator < (const T& x)const
	{
		return x < val;
	}
	bool operator > (const T& x)const
	{
		return x > val;
	}
	~Less_than() {};

private:


};

//可变参数模板
void tempfunction() {}

template<typename T, typename... Tail>
void tempfunction(const T hand,const Tail... tail)
{

	cout << hand << " ";
	cout << sizeof ...(tail) << endl;
	tempfunction(tail...);
}


int main()
{

	Vector<int> vs(17);
	//for (int i = 0; i != vs.size(); ++i)
	//{
	//	cin >> vs[i];
	//}
	//for(int i = 0; i != vs.size(); ++i)
	//{
	//	cout << vs[i] << endl;
	//	
	//}
	//for (auto V : vs)
	//{
	//	cin >> V;
	//}
	
	//Less_than<string> lti{ "AA" };
	//
	//string N { "AAA" };

	//lti < N ? cout << "true" << endl : cout << "false" << endl;
	tempfunction(1,2.2,"ABCD",'A');

	cout << "\n";

	return 0;

}

