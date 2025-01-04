#pragma once

#include <vector>
#include "layer.hpp"


/*
    sequential take vector<layer>
*/

class sequential
{
public:
    sequential(std::vector<layer> _layers):layers(_layers){}
    numpy<double> Forward(numpy<double> input)
    {        
        for(int i = 0; i < layers.size(); i++)
        {
            input = layers[i].ForwardPropagation(input);
        }
        return input;
    }
private:
    std::vector<layer> layers;
};