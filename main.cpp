#include "Graph.cpp"
#include <array>

int main(){
    std::array<array<int, 5>,5> test_arr = { 0,1,0,1,1,
					     1,0,0,1,0,
					     0,0,0,1,1,
					     1,1,1,0,1,
					     1,0,1,1,0};
    std::array<array<int, 5>,5> test_arr2 = { 0,1,0,1,0,
					     1,0,1,1,1,
					     0,1,0,1,1,
					     1,1,1,0,0,
					     0,1,1,0,0};

    std::array<array<int, 6>, 6> test_arr3 = {0,1,1,0,1,0,
					      1,0,1,0,0,1,
					      1,1,0,1,0,0,
					      0,0,1,0,1,1,
					      1,0,0,1,0,1,
					      0,1,0,1,1,0};

    std::array<array<int,6>, 6> test_arr4 = {0,1,0,1,1,0,
					     1,0,1,0,0,1,
					     0,1,0,1,1,0,
					     1,0,1,0,0,1,
					     1,0,1,0,0,1,
					     0,1,0,1,1,0};

    std::cout<<"Problem 1:\n";
    Graph<6> graph3 = Graph<6>(test_arr3, "ABCDEF");
    Graph<6> graph4 = Graph<6>(test_arr4, "123456");
    graph3.isomorph(graph4);

    std::cout<<"Problem 2:\n";
    Graph<5> graph1 = Graph<5>(test_arr, std::string("12345"));
    Graph<5> graph2 = Graph<5>(test_arr2,std::string("ABCDE")); 
    graph1.isomorph(graph2);


    return 0;
}
