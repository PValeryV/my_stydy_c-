#include "rectangle.h"


//rectangle::rectangle(point<int> one, point<int> two,const std::string& name):shape(name){
	//center_.x = (one.x + static_cast<double>(two.x)) / 2;
	//center_.y = (one.y + static_cast<double>(two.y)) / 2;
	//area_ = abs(one.x - two.x) * abs(one.y - two.y);
	//point<int>* mas = new point<int>[4];
	//mas[0] = one;
	//mas[1] = point<int>(one.x, two.y);
	//mas[2] = two;
	//mas[3] = point<int>(two.x,one.y);
//}
rectangle::rectangle() :shape("text") {
	//point<int> fa(1, 2);
	point<double>* doubleStack = new point<double>{1, 2};
}
int rectangle::getarea() {
	return area_;
}
int rectangle::scale() {
	return 1;
}
//point<double>& rectangle::getCenter() {
//	return center_;
//}
rectangle::~rectangle() {

//	delete[]&mas;
}