#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
class rectangle: public shape {
public:
//	rectangle(point<int> one, point<int> two, const std::string& name = "rectangle");
	rectangle();
	int getarea();
	int scale();
//	point<double>& getCenter();
	~rectangle();
private:
//	point<int>* mas[4];
};

#endif