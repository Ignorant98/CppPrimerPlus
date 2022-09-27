#include <iostream>
#include <string.h>
#include <stdio.h>
#include <direct.h>
#include <vector>

using namespace std;

namespace MyCpp
{


	//class A
	//{
	//public:
	//	
	//	static A& GetInStance();
	//	//void setup(){}
	//
	////private:
	////	A();
	////	A(const A& rhs);
	//
	//
	//};
	//
	//A& A::GetInStance()
	//{
	//	static A a;
	//	return a;
	//}

	class String
	{

	public:

		inline String(const char* cstr = 0)
		{
			if (cstr)
			{
				m_Data = new char[strlen(cstr) + 1];

				strcpy_s(m_Data, strlen(cstr) + 1, cstr);

			}
			else
			{
				//未指定初始值
				m_Data = new char[1];

				*m_Data = '\0';

			}

		}

		inline String(const String& str)
		{
			this->m_Data = new char[strlen(str.m_Data) + 1];

			strcpy_s(this->m_Data, strlen(str.m_Data) + 1, str.m_Data);

		}

		//String(const String&) = delete;
		String& operator =(const String&) = delete;
		//inline String& operator = (const String& str)
		//{
		//	//防止自我赋值
		//	if (this == &str)
		//	{		
		//		
		//		return *this;
		//	}
		//	
		//	delete[] this->m_Data;

		//	this->m_Data = new char[strlen(str.m_Data)+1];
		//	
		//	strcpy_s(this->m_Data, strlen(str.m_Data)+1, str.m_Data);

		//	return *this;
		//}

		inline ~String()
		{
			delete[] m_Data;
		}

		inline char* Get_C_Str() const { return m_Data; }

		virtual void PrintChar()
		{
			cout << "String" << "\n" << endl;
		}


	private:

		char* m_Data;
	};

	//template <class T>
	//class queue
	//{
	//protected:
	//	//deque<T> c;
	//public:
	//
	//};
	//#define _DEBUG

	//#ifdef _DEBUG 
	//
	//class StringB :public String
	//{
	//public:
	//
	//	StringB()
	//	{
	//		cout << "TemClassB Constructor\n" << endl;
	//	}
	//	~StringB()
	//	{
	//		cout << "~TemClassB Constructor \n" << endl;
	//	}
	//
	//	virtual void PrintChar() override
	//	{
	//		__super::PrintChar();
	//
	//		cout << "StringB " << "\n" << endl;
	//	}
	//	
	//
	//
	//};
	//
	//#else _DEBUG
	//
	//class TemClassC :public TemClassA
	//{
	//public:
	//	virtual void TestFuntion()override
	//	{
	//
	//		cout << "TemClassB" << endl;
	//	}
	// 
	//};
	//
	//#endif // 

}