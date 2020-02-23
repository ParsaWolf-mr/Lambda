#include <iostream>
#include <algorithm>
#include <functional>
#include <array>
#include <vector>

using MyArray = std::array <int, 5>;
using MyVector = std::vector<MyArray::value_type>;


void PrintArray(const std::function<void(MyArray::value_type)>& myfunction) {
	MyArray myarray{ 1,2,3,4,5 };

	std::for_each(myarray.begin(), myarray.end(), myfunction);
}

int main() {

	MyVector myCopy;
	auto myCluster = [&myCopy](const MyArray::value_type& element) {
		std::cout << element << std::endl;
		myCopy.push_back(element);
	};

	std::cout << "myCluster type: " << typeid(myCluster).name() << std::endl;

	PrintArray(myCluster);


	std::cout << "MyCopy: " << std::endl;

	std::for_each(myCopy.begin(), myCopy.end(), [](const MyArray::value_type& number) {
		std::cout << number << std::endl;
		});



	return 0;
}
