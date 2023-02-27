#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <vector>
#include <string>

struct TrainingSet
{
    double inputs[2];
    double desiredOutput;
    int inputCount;
};

class Perceptron
{
public:
    Perceptron(std::vector<TrainingSet> &set);
    ~Perceptron();
    std::vector<TrainingSet> trainingSets;
    double weights[2];
    double bias;
    double totalError = 0;

    void InitialisedWeight();
    double CalculateOutput(double in1, double in2, int index);
    void UpdateWeightAndBias(double input1, double input2);
    std::string Train(int epochs);
};

#endif // PERCEPTRON_H
