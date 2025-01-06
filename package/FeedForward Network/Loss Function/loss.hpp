#include "numpy.hpp"

/*
    Mean Squared error
*/

class loss
{
public:
    double Evaluate(numpy<double> actual, numpy<double> predicted)
    {
        double res = 0;
        for (int i = 0; i < actual.size(); i++)
        {
            res += ((actual[i] - predicted[i]) * (actual[i] - predicted[i]));
        }
        return res;
    }

    numpy<double> derivative(numpy<double> predicted, numpy<double> actual)
    {
        return (predicted - actual);
    }
};