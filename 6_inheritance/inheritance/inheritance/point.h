#pragma once
#ifndef POINT_H
#define POINT_H

template<class Type> 
class point{
public:
//	point();
//	template<class Type1>
	point(Type x_, Type y_);

	Type x;
	Type y;
};
#endif