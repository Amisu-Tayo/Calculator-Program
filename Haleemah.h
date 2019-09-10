#pragma once
#ifndef HALEEMAH_H
#define HALEEMAH_H
namespace savage
{
	template <class ctype>
	class stack
	{
	public:
		stack()
		{
			count = -1;
		}
		bool empty()
		{
			if (count == -1)
				return true;
			else
				return false;
		}
		int size()
		{
			return (count + 1);
		}
		void push(const ctype& v)
		{
			arr[++count] = v;
		}
		
	ctype top()
		{
			return arr[count];
		}
	void pop()
	{
	
			count = count--;
	}
	private :
		static const int STACK_SIZE = 20;
		ctype arr[STACK_SIZE];
		int count;
		
	};


}
#include "Haleemah.template"
#endif 

