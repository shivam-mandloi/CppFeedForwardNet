#include <vector>

#include "numpy.hpp"
#include "layer.hpp"
#include "sequential.hpp"


int main()
{
    layer ly1("weight_0_1.txt", "Bias_0_1.txt", RELU);
    layer ly2("weight_1_2.txt", "Bias_1_2.txt", RELU);
    std::vector<layer> layers = {ly1, ly2};
    sequential sq(layers);
    numpy<double> input = {2,5,1,67,23,15,87,32,425,12};
    input = sq.Forward(input);
    std::cout << "output: " << input << std::endl;
}