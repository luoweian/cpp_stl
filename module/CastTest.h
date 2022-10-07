#pragma once
#include <iostream>


void cast_test_01() {
	int a = 97;
	char c = static_cast<char>(a);
	std::cout << c << std::endl;
}

int main() {
	cast_test_01();
}

