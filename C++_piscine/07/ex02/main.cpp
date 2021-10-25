#include <iostream>
#include <Array.hpp>
#include <cstdlib>
#include <iomanip>

template<typename T>
void print(T* t, unsigned int size, std::string name)
{
	std::cout << "print_" << name << ":\t";
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << std::setprecision( 3 ) << t[i];
		if ((i + 1) != size)
			std::cout <<  " , ";
	}
	std::cout << std::endl;
}

template<typename T>
void fill(T* a, int size)
{
	for (int i = 0; i < size; i++)
		a[i] = static_cast <T> (rand()) / static_cast <T> (RAND_MAX / (10));
}

template<typename T>
void test()
{
	#define MY_SIZE 10
    Array<T> numbers(MY_SIZE);
    Array<T> numbers1(MY_SIZE + 1);
	T* mirror = new T[MY_SIZE];

	fill(mirror, MY_SIZE);
	fill(numbers1.address(), MY_SIZE + 1);
    for (int i = 0; i < MY_SIZE; i++)
        numbers[i] = mirror[i];
    print(mirror, MY_SIZE, "mirror");
	print(numbers.address(), MY_SIZE, "my");
	std::cout << std::endl;
	std::cout << "Change element[0]" << std::endl;
	mirror[0] = static_cast <T> (rand()) / static_cast <T> (RAND_MAX / (125 - 35));
	print(mirror, MY_SIZE, "mirror");
	print(numbers.address(), MY_SIZE, "my");
	std::cout << std::endl;
	std::cout << "Assignment operator" << std::endl;
	numbers = numbers1;
	print(numbers.address(), MY_SIZE, "my_numbers");
	print(numbers1.address(), MY_SIZE, "my_numbers1");
	std::cout << std::endl;
	std::cout << "Copy constructor" << std::endl;
    Array<T> numbers2(numbers1);
	print(numbers1.address(), MY_SIZE, "my_numbers1");
	print(numbers2.address(), MY_SIZE, "my_numbers2");
	std::cout << std::endl;
	std::cout << "Change element[0]" << std::endl;
	numbers1[0] = static_cast <T> (rand()) / static_cast <T> (RAND_MAX / (125 - 35));
	print(numbers1.address(), MY_SIZE, "my_numbers1");
	print(numbers2.address(), MY_SIZE, "my_numbers2");
	std::cout << std::endl;
	try
    {
        std::cout << "index[-1]:\t\t" << numbers[-1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	try
    {
        std::cout << "index[MY_SIZE]:\t\t" << numbers[MY_SIZE + 1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout << "index[0]:\t\t" << numbers[0] << std::endl;
    std::cout << "index[MY_SIZE - 1]:\t" << numbers[MY_SIZE - 1] << std::endl;
	delete []mirror;
}

///////////////////////ORIGINAL//////////////////////////////////////

#define MAX_VAL 750
int main(int, char**)
{
    srand(time(NULL));
    {
    	std::cout << "-original--" << std::endl;
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;
    }

/////////////////////////////////////////////////////////////

	std::cout << "-my---------" << std::endl;
    {

    	Array<int> array_null;
        try
        {
            std::cout << array_null[1] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
    	std::cout << "-----" << std::endl;

    	std::cout << std::endl << "-----------test char-----------------" << std::endl;
    	test<char>();
    	std::cout << std::endl << "-----------test int----------------" << std::endl;
    	test<int>();
    	std::cout << std::endl << "-----------test float-----------------" << std::endl;
    	test<float>();
    }
    return 0;
}
