#include <iostream>
#include "perceptron.h"

void initTrainingSets(std::vector<TrainingSet> &sets);

int main()
{

    std::cout << "Setup the Training Set" << std::endl;
    std::vector<TrainingSet> sets;
    initTrainingSets(sets);

    Perceptron p(sets);

    std::cout << "Training the perceptron" << std::endl;
    p.Train(6);

    std::cout << "Press Enter to see calculate output..." << std::endl;
    getchar();

//    std::cout <<  "Test 0 0 -> " << p.CalculateOutput(0,0) << "\n";
//    std::cout <<  "Test 0 0 -> " << p.CalculateOutput(0,1) << "\n";
//    std::cout <<  "Test 0 0 -> " << p.CalculateOutput(1,0) << "\n";
//    std::cout <<  "Test 0 0 -> " << p.CalculateOutput(1,1) << "\n";;

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
    double outputs[4] {0.f, 1.f, 1.f, 0.f};

    for(unsigned int i = 0; i < input.size(); i++)
    {
        TrainingSet set;
        set.inputs.push_back(input[i]);
        set.desiredOutput = outputs[i];
        sets.push_back(set);
    }

}
