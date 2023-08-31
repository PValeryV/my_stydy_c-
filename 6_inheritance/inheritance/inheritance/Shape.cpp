#include"Shape.h"

shape::shape(const std::string& name):name_(name){}
std::string shape::getname() {
	return name_;
}
bool shape::operator<(shape& object) {
	return area_ > object.area_ ? true : false;
}