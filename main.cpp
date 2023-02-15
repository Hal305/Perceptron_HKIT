#include <iostream>
#include "perceptron.h"


int main()
{

    std::cout << "Setup the Training Set" << std::endl;
    std::vector<TrainingSet> ts;

    TrainingSet set1;
    set1.inputs.push_back(0); set1.inputs.push_back(0);
    set1.output = 1;
    ts.push_back(set1);

    TrainingSet set2;
    set2.inputs.push_back(0); set2.inputs.push_back(1);
    set2.output = 1;
    ts.push_back(set2);

    TrainingSet set3;
    set3.inputs.push_back(1); set3.inputs.push_back(0);
    set3.output = 1;
    ts.push_back(set3);

    TrainingSet set4;
    set4.inputs.push_back(1); set4.inputs.push_back(1);
    set4.output = 1;
    ts.push_back(set4);

    Perceptron p(ts);

    std::cout << "Training the perceptron" << std::endl;
    p.Train(6);

    std::cout << "Press Enter to see calculate output..." << std::endl;
    getchar();

//    std::cout <<  "Test 0 0 -> " << p.CalculateOutput(0,0) << "\n";
//    std::cout <<  "Test 0 0 -> " << p.CalculateOutput(0,1) << "\n";
//    std::cout <<  "Test 0 0 -> " << p.CalculateOutput(1,0) << "\n";
//    std::cout <<  "Test 0 0 -> " << p.CalculateOutput(1,1) << "\n";

    getchar();
    return 0;
}
