#pragma once

#include <string>
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
                // std::cout << temp << std::endl;
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
};