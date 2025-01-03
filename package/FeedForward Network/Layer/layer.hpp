#pragma once

#include <fstream>
#include <string>

#include "numpy.hpp"
#include "HelpingFunction.hpp"
#include "ActivationFunction.hpp"

class layer
{
public:
    layer(std::string weightTxt, std::string biasTxt, std::string activationType)
    {
        LoadTxtWeightAndBias(weightTxt, biasTxt);
        activationFunction.AddActivationFunction(activationType);
    }

    numpy<double> ForwardPropagation(numpy<double> input)
    {

    }

    void BackPropagation()
    {

    }
private:
    void LoadTxtWeightAndBias(std::string weightTxt, std::string biasTxt)
    {
        std::fstream newFile;
        newFile.open(weightTxt, std::ios::in);
        std::string temp;

        if (!newFile.is_open()) {
            std::cerr << "Error: Could not open file " << weightTxt << std::endl;
            return;
        }
        while(getline(newFile, temp))
        {
            if(temp != "")
                weight.push_back(hf.SplitString(temp));
        }
        std::cout << weight.size() << " X " << weight[0].size() << std::endl;

        newFile.close();
        newFile.open(biasTxt, std::ios::in);
        if (!newFile.is_open()) {
            std::cerr << "Error: Could not open file " << biasTxt << std::endl;
            return;
        }
        while(getline(newFile, temp))
        {
            if(temp != "")
                bias.push_back(std::stod(temp));
        }
        std::cout << bias.size() << std::endl;
    }
    numpy<numpy<double>> weight;
    numpy<double> bias;
    HelpingFunction hf;
    ActivationFunction activationFunction;
};