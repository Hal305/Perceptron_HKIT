#include "Perceptron.h"
#include <iostream>
#include <ctime>

Perceptron::Perceptron(std::vector<TrainingSet> &set)
{
    trainingSets = set;
    InitialisedWeight();
    bias = ((double)(rand()%21) - 10.f) / 10.f;
}

Perceptron::~Perceptron()
{

}

void Perceptron::InitialisedWeight()
{
    srand(time(NULL));
    double w[2] = {((double)(rand()%21) - 10.f) / 10.f,
                           ((double)(rand()%21) - 10.f) / 10.f};

    weights[0] = w[0];
    weights[1] = w[1];
}

double Perceptron::CalculateOutput(double input1, double input2, int index)
{   // Input1 * Weight1 + Input2 * Weight2 + Bias
    double output = input1 * weights[0] + input2 * weights[1] + bias;

    if(output > 0.0f)
        output = 1.0f;
    else
        output = 0.0f;

    totalError = trainingSets[index].desiredOutput - output;
    UpdateWeightAndBias(input1, input2);
    return output;
}

void Perceptron::UpdateWeightAndBias(double input1, double input2)
{   // Input(x) * ErrorDifference + Weight(x)
    weights[0] += input1 * totalError;
    weights[1] += input2 * totalError;
    bias += totalError;
}

std::string Perceptron::Train(int epochs)
{
    return " ";
}
