#pragma once
#include <iostream>

class Building {};
class Animal {};

class Cat : public Animal {};


void cast_test_01() {
	int a = 97;
	char c = static_cast<char>(a);
	std::cout << c << std::endl;

	// 基础数据类型指针
	int* p = NULL;
	/*char* sp = static_cast<char*>(p);*/

	// 对象指针
	Building* building = NULL;
	//Animal* ani = static_cast<Animal*>(building);

	// 转换具有继承关系的对象指针，父类转子类
	Animal* ani = NULL;
	Cat* cat = static_cast<Cat*>(ani);

	// 子类指针转换成父类指针
	Cat* soncat = NULL;
	Animal* anifather = static_cast<Animal*>(soncat);

	Animal aniobj;
	Animal& aniref = aniobj;
	Cat& cat2 = static_cast<Cat&>(aniref);

	Cat catobj;
	Cat& catref = catobj;
	Animal& aniref2 = static_cast<Animal&>(catref);

	// static_cast用于内置的数据类型，还有具有继承关系的指针或引用

}





int main() {
	cast_test_01();
}

