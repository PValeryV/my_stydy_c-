#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include"point.h"
#include<string>

class shape {
public:
	shape(const std::string& name);
	virtual int getarea()=0;
	virtual int scale()=0;
//	virtual point<double>& getCenter()=0;
	virtual ~shape() = default;
	std::string getname();
	bool operator<(shape& object);
protected:
	const std::string name_;
//	point<double> center_;
	int area_;
};


#endif