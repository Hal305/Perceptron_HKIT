#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <vector>

struct TrainingSet
{
    std::vector<std::pair<double, double>> inputs;
    double desiredOutput;
    int inputCount;
};

class Perceptron
{
public:
    Perceptron(std::vector<TrainingSet> set);
    ~Perceptron();
    std::vector<TrainingSet> trainingSets;
    std::vector<std::pair<double, double>> weights;
    double bias;
    double totalError = 0;

    void InitialisedWeight();
    double CalculateOutput(int i);
    void UpdateWeight(int i, int j);
    double DotProductBias(std::pair<double, double>, std::pair<double, double> weights);
    void Train(int epochs);
};

#endif // PERCEPTRON_H
