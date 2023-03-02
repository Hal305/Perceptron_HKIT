#ifndef PERCEPTRON_HKIT_H
#define PERCEPTRON_HKIT_H
#include <vector>
#include <string>

struct TrainingSet_HKIT
{
    std::vector<double> inputs;
    double desiredOutput;
};

class Perceptron_HKIT
{
    double error = 0;

    void UpdateWeightAndBias(double input1, double input2);

public:
    Perceptron_HKIT(std::vector<TrainingSet_HKIT> set);
    ~Perceptron_HKIT();
    std::vector<TrainingSet_HKIT> trainingSets;
    std::vector<double> weights = {0.0f, 0.0f};
    double bias = 0;
    double totalError = 0;
    double CalculateOutput(double input1, double input2);
    void RandomiseWeightAndBias();

    std::string Train(int epochs);
};

#endif // PERCEPTRON_HKIT_H
