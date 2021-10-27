
#include "../vector.hpp"
#include "../stack.hpp"
#include "vectorTests.cpp"
#include "stackTests.cpp"

int main(int argc, char** argv) {

	(void)argc;
	(void)argv;
	
	// vectorTest< ft::vector<int> >();
	stackTest< ft::stack<int, ft::vector<int> > > ();

	return (0);
}
