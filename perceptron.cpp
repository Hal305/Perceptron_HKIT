#include "Perceptron.h"
#include <iostream>
#include <ctime>

Perceptron::Perceptron(std::vector<TrainingSet> set)
{
    InitialisedWeight();
}

Perceptron::~Perceptron()
{
    ;
}

void Perceptron::InitialisedWeight()
{
    srand(time(NULL));
    double w = ((double)(rand()%21) - 10.f) / 10.f;
    std::cout <<  w << "\n";
    weights.push_back(w);
    w = ((double)(rand()%21) - 10.f) / 10.f;
    std::cout <<  w << "\n";
    weights.push_back(w);
}

void Perceptron::CalculateOutput(int i, int j)
{
    ;// Input1 * Weight1 + Input2 * Weight2 + Bias
}

void Perceptron::UpdateWeight(int i, int j)
{
    ;//Input(x) * ErrorDifference + Weight(x)
}

double Perceptron::DotProductBias(std::vector<double> inputs, std::vector<double> weights)
{
    return 0;
}

void Perceptron::Train(int epochs)
{
    ;
}
