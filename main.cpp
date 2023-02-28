#include <iostream>
#include "perceptron_hkit.h"

int main()
{

    std::cout << "Setup the Training Set" << std::endl;
    std::vector<TrainingSet_HKIT> ts;

    const int in[2][4] ={
        {0,0,1,1},
        {0,1,0,1}
    };
    const int out[4] = {0,1,1,1};

    for (int i = 0; i < 4; i++)
    {
        TrainingSet_HKIT set;
        set.inputs.push_back(in[0][i]);
        set.inputs.push_back(in[1][i]);
        set.desiredOutput = out[i];
        ts.push_back(set);
    }

    Perceptron_HKIT p(ts);

    std::cout << "Training the preceptron" << std::endl;
    std::cout << p.Train(6) << "\n";

    std::cout << "Press Enter to see calculate output..." << std::endl;
    getchar();

    for (int i = 0; i < 4; i++)
        std::cout <<  "Test " << i + 1 << ": " << in[0][i] << " " << in[1][i] <<
                      " -> " << p.CalculateOutput(in[0][i], in[1][i], i) << "\n";

    return 0;
}
