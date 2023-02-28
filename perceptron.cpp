#include "Perceptron.h"
#include <iostream>
#include <ctime>

Perceptron::Perceptron(std::vector<TrainingSet> &set)
{
    trainingSets = set;
    RandomiseWeightAndBias();
}

Perceptron::~Perceptron()
{

}

void Perceptron::RandomiseWeightAndBias()
{
    srand(time(NULL));
    double w[2] = {((double)(rand()%21) - 10.f) / 10.f,
                    ((double)(rand()%21) - 10.f) / 10.f};
    weights[0] = w[0];
    weights[1] = w[1];
    bias = (double)((rand()%21) - 10.f) / 10.f;
}

double Perceptron::CalculateOutput(double input1, double input2, int index)
{   // Input1 * Weight1 + Input2 * Weight2 + Bias
    double output = input1 * weights[0] + input2 * weights[1] + bias;

    if(output > 0.0f)
        output = 1.0f;
    else
        output = 0.0f;

    // desired output - calculated output
    error = trainingSets[index].desiredOutput - output;
    UpdateWeightAndBias(input1, input2);
    return output;
}

void Perceptron::UpdateWeightAndBias(double input1, double input2)
{   // Input(x) * ErrorDifference + Weight(x)
    weights[0] += input1 * error;
    weights[1] += input2 * error;
    bias += error;
}

std::string Perceptron::Train(int epochs)
{
    std::string fullOutput = "";

    for (int i = 0; i < epochs; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fullOutput += "W1: ";
            fullOutput += std::to_string(weights[0]);
            fullOutput += " W2: ";
            fullOutput += std::to_string(weights[1]);
            fullOutput += " B: ";
            fullOutput += std::to_string(bias);
            fullOutput += "\n";
            totalError += error;
            CalculateOutput(trainingSets[j].inputs[0], trainingSets[j].inputs[1], j);
        }
        fullOutput += "Epoch#: ";
        fullOutput += std::to_string(i+1);
        fullOutput += " Total error: ";
        fullOutput += std::to_string(totalError);
        totalError = 0;
        fullOutput += "\n";
    }
    return fullOutput;
}
