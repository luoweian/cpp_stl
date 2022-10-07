// module.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// 模板技术
template<typename T> // = template<class T>
void MySwap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

void test01() {
    int a = 10, b = 20;
    std::cout << a << " " << b << std::endl;
    // 1. 自动类型推导
    MySwap(a, b);
    std::cout << "after swap   " << a << " " << b << std::endl;

    // 2. 显示指定类型
    MySwap<int>(a, b);
    std::cout << "after swap   " << a << " " << b << std::endl;
}

//int main()
//{
//    test01();
//    std::cout << "Hello World!\n";
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
