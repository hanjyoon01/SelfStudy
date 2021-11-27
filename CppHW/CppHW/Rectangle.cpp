#include "Rectangle.h"

Rectangle::Rectangle() :Rectangle(1, 1) {
}
Rectangle::Rectangle(int a, int b)
	: width(a), height(b) {
}
Rectangle::Rectangle(int a)
	: width(a), height(a) {
}

bool Rectangle::isSquare()
{
	if (width == height)
		return true;
	else
		return false;
}

