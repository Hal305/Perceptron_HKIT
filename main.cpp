#include <iostream>
#include "perceptron.h"

const int size = 4;
void initTrainingSets(std::vector<TrainingSet> &sets);

int main()
{

    std::cout << "Setup the Training Set" << std::endl;
    std::vector<TrainingSet> sets;
    initTrainingSets(sets);
    Perceptron p(sets);

//    std::cout << "Training the perceptron" << std::endl;
//    p.Train(6);

    std::cout << "Press Enter to see calculate output..." << std::endl;
    getchar();

    for (int i = 0; i < size; i++)
    {
        std::cout <<  "Test " << sets[i].inputs.first << " " << sets[i].inputs.second << " -> " << p.CalculateOutput(i) << "\n";
    }

    getchar();
    return 0;
}

void initTrainingSets(std::vector<TrainingSet> &sets)
{

    std::vector<std::pair<double, double>> input;
    input.push_back({0.f, 0.f});
    input.push_back({0.f, 1.f});
    input.push_back({1.f, 0.f});
    input.push_back({1.f, 1.f});
    double outputs[size] {0.f, 1.f, 1.f, 0.f};

    for(unsigned int i = 0; i < size; i++)
    {
        TrainingSet tempSet;
        std::pair<double, double> inputParam = input[i];
        tempSet.inputCount = i;
        tempSet.inputs = inputParam;
        tempSet.desiredOutput = outputs[i];
        sets.push_back(tempSet);
        std::cout << sets[i].inputs.first << " " << sets[i].inputs.second << "\n";
    }

}
