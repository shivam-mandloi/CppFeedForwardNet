#pragma once

#include <vector>
#include "layer.hpp"
#include "loss.hpp"


/*
    sequential take vector<layer>
*/

class sequential
{
public:
    sequential(std::vector<layer> _layers, loss _ls):layers(_layers),ls(_ls){}
    numpy<double> Forward(numpy<double> input)
    {        
        for(int i = 0; i < layers.size(); i++)
        {
            input = layers[i].ForwardPropagation(input);
        }
        return input;
    }

    void BackPropagation(numpy<double> predicted, numpy<double> actual)
    {
        numpy<double> derivative = ls.derivative(predicted, actual);
        for(int i = layers.size()-1; i > 0; i--)
        {
            derivative = layers[i].BackPropagation(derivative);
            std::cout << "Layer " << i  << " Complete" << std::endl;
        }
    }

private:
    std::vector<layer> layers;
    loss ls;
};