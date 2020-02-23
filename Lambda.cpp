#include <iostream>
#include <array>
#include <algorithm>
#include <functional>


using MyArray = std::array<int, 5>;

void PrintArray(const std::function<void(MyArray::value_type)>& myfunction) {
	MyArray myarray{ 1,2,3,4,5 };

	std::for_each(myarray.begin(), myarray.end(), myfunction);
}

int main() {

	auto myCluser = [](auto&& element) {
		std::cout << element << std::endl;
	};

	std::cout << typeid(myCluser).name() << std::endl;

	PrintArray(myCluser);

	return 0;
}
