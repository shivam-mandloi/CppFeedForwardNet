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
};