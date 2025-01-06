#include <vector>

#include "numpy.hpp"
#include "layer.hpp"
#include "sequential.hpp"

int main()
{
    layer ly1("weight_0_1.txt", "Bias_0_1.txt", RELU);
    layer ly2("weight_1_2.txt", "Bias_1_2.txt", RELU);
    std::vector<layer> layers = {ly1, ly2};
    loss ls;
    sequential sq(layers, ls);
    numpy<double> input = {2, 5, 1, 67, 23, 15, 87, 32, 425, 12};
    numpy<double> output = {10};

    numpy<double> temp;
    int i = 1000;

    while (i)
    {
        temp = sq.Forward(input);
        std::cout << "Error: " << ls.Evaluate(temp, output) << std::endl;
        std::cout << "output " << temp << " actual: " << output << std::endl;
        sq.BackPropagation(temp, output);

        std::cout << std::endl << std::endl;
        i--;
    }

    std::cout << "complete" << std::endl;
    
}