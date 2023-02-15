#include "Perceptron.h"
#include <iostream>
#include <ctime>

Perceptron::Perceptron(std::vector<TrainingSet> &set)
{
    trainingSets = set;
    InitialisedWeight();
}

Perceptron::~Perceptron()
{
    ;
}

void Perceptron::InitialisedWeight()
{
    srand(time(NULL));
    std::pair<double, double> w = {((double)(rand()%21) - 10.f) / 10.f,
                           ((double)(rand()%21) - 10.f) / 10.f};

    weights.push_back(w);
}

double Perceptron::CalculateOutput(int i)
{   // Input1 * Weight1 + Input2 * Weight2 + Bias
    double output = trainingSets[i].inputs.first * weights[0].first
            + trainingSets[i].inputs.second * weights[0].second + bias;

    if(output > 0.f)
        output = 1.f;
    else
        output = 0.f;

    return output;
}

void Perceptron::UpdateWeight(int i, int j)
{
    ;//Input(x) * ErrorDifference + Weight(x)
}

double Perceptron::DotProductBias(std::pair<double, double>, std::pair<double, double> weights)
{
    return 0;
}

void Perceptron::Train(int epochs)
{
    ;
}
