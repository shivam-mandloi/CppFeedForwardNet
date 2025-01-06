#pragma once

#include <fstream>
#include <string>

#include "numpy.hpp"
#include "HelpingFunction.hpp"
#include "ActivationFunction.hpp"

/*          size
    Weight: m X n
    Bias:   n
    input:  m
*/
class layer
{
public:
    layer(std::string weightTxt, std::string biasTxt, FunctionType activationType = RELU, double _alpha = 0.001)
    {
        LoadTxtWeightAndBias(weightTxt, biasTxt);
        activationFunction.AddActivationFunction(activationType);
        alpha = _alpha;
    }

    numpy<double> ForwardPropagation(numpy<double> _input)
    {
        input = _input;
        outputWithoutActi = hf.MatVecMul(input, weight) + bias;
        return activationFunction.Evaluate(outputWithoutActi);
    }

    numpy<double> BackPropagation(numpy<double> lossDerivative)
    {
        /*
            k1 = X W1 + b1
            h = f(k1)
            k2 = h W2 + b2
            Y = f(k2)
            L = $(A, Y)

            f = activation function
            $ = loss function
            X = input
            W1, W2 = weight matrix
            b1, b2 = bias vector

            dL/dW1 => dL/dY * dY/dk2 * dk2/dh * dh/dk1 * dk1/dW1
                   => $'(A, Y) * f'(k2) * W2.T * f'(k1) * X
            

            here every element is matrix we can write it like

                   => ( ($'(A, Y) * f'(k2)) @ W2.T * f'(k1)) @ X

            * = element wise product (Hadamard product)
            @ = dot product

            same can be find for b1, b2, W2
        */

        lossDerivative = activationFunction.Derivative(outputWithoutActi, lossDerivative);
        numpy<numpy<double>> weightChange = hf.FindWeightChange(lossDerivative, input);

        // Bias Update
        for(int i = 0; i < lossDerivative.size(); i++)
        {
            bias[i] -= (alpha * lossDerivative[i]);
        }
        
        lossDerivative = hf.FindNextDerivative(lossDerivative, weight); // chain rule next derivative
        
        // Weight Update
        for(int i = 0; i < weight.size(); i++)
        {
            for (int j = 0; j < weight[i].size(); j++)
            {
                weight[i][j] -=  (alpha * weightChange[i][j]);
            }
        }
        return lossDerivative;
    }

private:
    void LoadTxtWeightAndBias(std::string weightTxt, std::string biasTxt)
    {
        std::fstream newFile;
        newFile.open(weightTxt, std::ios::in);
        std::string temp;

        if (!newFile.is_open())
        {
            std::cerr << "Error: Could not open file " << weightTxt << std::endl;
            return;
        }
        while (getline(newFile, temp))
        {
            if (temp != "")
                weight.push_back(hf.SplitString(temp));
        }
        // std::cout << weight.size() << " X " << weight[0].size() << std::endl;

        newFile.close();
        newFile.open(biasTxt, std::ios::in);
        if (!newFile.is_open())
        {
            std::cerr << "Error: Could not open file " << biasTxt << std::endl;
            return;
        }
        while (getline(newFile, temp))
        {
            if (temp != "")
                bias.push_back(std::stod(temp));
        }
    }
    numpy<numpy<double>> weight;
    numpy<double> bias;
    HelpingFunction hf;
    ActivationFunction activationFunction;
    numpy<double> outputWithoutActi; // for back propagation
    numpy<double> input;
    double alpha;
};