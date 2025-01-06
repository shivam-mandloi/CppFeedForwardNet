#pragma once

#include <string>
#include<assert.h>

#include "numpy.hpp"


class HelpingFunction
{
public:
    numpy<double> SplitString(std::string str)
    {
        numpy<double> arr;
        std::string temp;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ' ')
            {
                if(temp != " " && temp != "")
                    arr.push_back(std::stod(temp));
                temp = "";
                continue;
            }
            temp += str[i];
        }
        if(temp != "" && temp != " ")
            arr.push_back(std::stod(temp));
        return arr;
    }

    numpy<double> MatVecMul(numpy<double> vec, numpy<numpy<double>> mul)
    {
        assert(vec.size() == mul.size());
        numpy<double> res;
        for(int i = 0; i < mul[0].size(); i++)
        {
            double temp = 0;
            for(int j = 0; j < mul.size(); j++)
            {
                temp += (mul[j][i] * vec[j]);
            }

            res.push_back(temp);
        }
        return res;
    }

    numpy<numpy<double>> FindWeightChange(numpy<double> derivative, numpy<double> input)
    {
        numpy<numpy<double>> res;
        for(int i = 0; i < input.size(); i++)
        {
            numpy<double> temp;
            for(int j = 0; j < derivative.size(); j++)
            {
                temp.push_back(derivative[j] * input[i]);
            }
            res.push_back(temp);
        }
        return res;
    }

    numpy<double> FindNextDerivative(numpy<double> derivative, numpy<numpy<double>> weight)
    {
        numpy<double> arr;
        for(int i = 0; i < weight.size(); i++)
        {
            double sum = 0;
            for(int j = 0; j < weight[i].size(); j++)
            {
                sum += (derivative[j] * weight[i][j]);
            }
            arr.push_back(sum);
        }
        return arr;
    }
};