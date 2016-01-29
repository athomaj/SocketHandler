#ifndef FUNCTION_HPP_
# define FUNCTION_HPP_

#include <iostream>
#include <exception>

template<class C>
class Function;

template<typename R, typename A>
class Function<R (A)>
{	
public:
	typedef R (*type)(A);

public:
	// functor interface
	class IFunctor
	{
	public:
		virtual R operator()(A) = 0;
	};

private:
	IFunctor* _foncteur;

public:
	// std class for callableClasses template
	template<typename X>
	class Functor : public IFunctor
	{
	public:
		Functor(X& arg) :
			_foncteur(X(arg))
		{
		}
		R operator()(A arg)
		{
			return (_foncteur.operator()(arg));
		}
	private:
		X _foncteur;
	};

public:
	// class for function pointer templates
	template<typename RB, typename AB>
	class Functor<RB (AB)> : public IFunctor
	{
	public:
		typedef RB (*ltype)(AB);

		Functor(ltype foncteur) :
			_foncteur(foncteur)
		{
		}
		RB operator()(AB arg)
		{
			return (_foncteur(arg));
		};
	private:
		ltype _foncteur;
	};
public:
	//constructor with function pointeur
	Function(type foncteur)
	{
		_foncteur = new Functor<R (A)>(foncteur);
	}
	//constructor with callable classes
	template<typename Z>
	Function(Z foncteur)
	{
		_foncteur = new Functor<Z>(foncteur);
	}
	// default constructor
	Function()
	{
		_foncteur = NULL;
	}

	R operator()(A arg)
	{
		if (_foncteur)
			return (_foncteur->operator()(arg));
		throw std::runtime_error("Trying to call uninitialised functor");
	}

	// assignment for fptr
	Function& operator=(type foncteur)
	{
		_foncteur = new Functor<R (A)>(foncteur);
		return (*this);
	}

	// assignment for callable class
	template<typename T>
	Function& operator=(T foncteur)
	{
		_foncteur = new Functor<T>(foncteur);
		return (*this);
	}
};

#endif