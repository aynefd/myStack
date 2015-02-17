//I Ayne, have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//I understand that any violation of this disclaimer will result in a 0 for the project.


// FILE: stack1.h (part of the namespace main_savitch_7A)
// TEMPLATE CLASS PROVIDED: stack<T>
//
// CONSTRUCTOR for the stack<T> template class:
//   stack( )
//     Postcondition: The stack has been initialized as an empty stack.
//
// MODIFICATION MEMBER FUNCTIONS for the stack<T> class:
//   void push(const T& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the stack.
//
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top item of the stack has been removed.
//
// CONSTANT MEMBER FUNCTIONS for the stack<T> class:
//   bool empty( ) const
//     Postcondition: Return value is true if the stack is empty.
//
//   usigned size( ) const
//     Postcondition: Return value is the total number of items in the stack.
//
//   T top( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the top item of the stack (but the
//     stack is unchanged. This differs slightly from the STL stack (where
//     the top function returns a reference to the item on top of the stack).
//
//-------------------

#ifndef MAIN_SAVITCH_STACK1_H
#define MAIN_SAVITCH_STACK1_H
#include <cassert>
namespace main_savitch_7A
{
	template <class T>
	class stack
	{
	public:
		//Const for Array
		static const unsigned CAPACITY = 30;
		// CONSTRUCTOR
		stack() { used = 0; }

		// MODIFICATION MEMBER FUNCTIONS
		void push(const T& entry);
		void pop();
		// CONSTANT MEMBER FUNCTIONS
		bool empty() const { return (used == 0); }
		unsigned size() const { return used; }
		T top() const;
	private:
		T data[CAPACITY];        // Partially filled array
		unsigned used;             // How much of array is being used
	};
}
namespace main_savitch_7A
{
	template <class T>
	void stack<T>::push(const T& entry)
	{
		assert(size()<CAPACITY);
		data[used] = entry;
		used++;
	}

	template <class T>
	void stack<T>::pop()
	{
		assert(!empty());
		used--;


	}

	template <class T>
	T stack<T>::top() const
	{
		assert(size()>0);
		return data[used - 1];


	}
}
#endif
