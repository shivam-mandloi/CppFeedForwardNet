#pragma once

#include <vector>

#include "numpy.hpp"

enum FunctionType
{
    RELU,
    tanH,
    sigmoid,
    softmax,
    NoActivation
};

class Relu
{
public:
    numpy<double> Evaluate(numpy<double> npArr)
    {
        for(int i = 0; i < npArr.size(); i++)
        {
            if(npArr[i] < 0)
                npArr[i] = 0;
        }
        return npArr;
    }

    numpy<double> Derivative(numpy<double> npArr, numpy<double> lossDerivative)
    {
        for(int i = 0; i < npArr.size(); i++)
        {
            if(npArr[i] < 0)
                lossDerivative[i] = 0;
        }
        return lossDerivative;
    }
};

class TanH
{
public:    
    numpy<double> Evaluate(numpy<double> npArr)
    {
    }

    numpy<double> Derivative(numpy<double> npArr)
    {
    }
};

class Sigmoid
{
public:
    numpy<double> Evaluate(numpy<double> npArr)
    {
    }

    numpy<double> Derivative(numpy<double> npArr)
    {
    }
};

class Softmax
{
public:
    numpy<double> Evaluate(numpy<double> npArr)
    {
    }

    numpy<double> Derivative(numpy<double> npArr)
    {
    }
};

class ActivationFunction
{
public:
    void AddActivationFunction(FunctionType type)
    {
        fType = type;
    }
    
    numpy<double> Evaluate(numpy<double> npArr)
    {
        if(fType == RELU)
            return relu.Evaluate(npArr);
        if(fType == tanH)
            return tan.Evaluate(npArr);
        if(fType == sigmoid)
            return sg.Evaluate(npArr);
        if(fType == softmax)
            return sfMax.Evaluate(npArr);
        return npArr;
    }

    numpy<double> Derivative(numpy<double> npArr, numpy<double> derivative)
    {
        if(fType == RELU)
            return relu.Derivative(npArr, derivative);
        if(fType == tanH)
            return tan.Derivative(npArr);
        if(fType == sigmoid)
            return sg.Derivative(npArr);
        if(fType == softmax)
            return sfMax.Derivative(npArr);
        return derivative;
    }

private:
    FunctionType fType;
    Relu relu;
    TanH tan;
    Sigmoid sg;
    Softmax sfMax;
};
