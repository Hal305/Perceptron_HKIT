#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <vector>

struct TrainingSet
{
    std::vector<double> inputs;
    double output;
    int inputCount;
};

class Perceptron
{
public:
    Perceptron(std::vector<TrainingSet> set);
    ~Perceptron();
    std::vector<TrainingSet> trainingSets;
    std::vector<double> weights;
    double bias;
    double totalError = 0;

    void InitialisedWeight();
    void CalculateOutput(int i, int j);
    void UpdateWeight(int i, int j);
    double DotProductBias(std::vector<double> inputs, std::vector<double> weights);
    void Train(int epochs);
};

#endif // PERCEPTRON_H
