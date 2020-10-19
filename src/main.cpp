#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <chrono>
#include "networkHandler.hpp"
#include "independentCascadeModel.hpp"
#include "informedNodes.hpp"
#include "node.hpp"

int main(int argc, char** argv)
{

    if (argc < 7)
    {
        std::cerr << "To few arguments" << std::endl;
        return 1;
    }

    auto totalStartTime = std::chrono::steady_clock::now();
    auto startTime = std::chrono::steady_clock::now();
    
    std::string file = argv[1];
    unsigned int size = std::stoul(std::string(argv[2]));
    std::string dtCase = argv[3];
    float beta = stof(std::string(argv[4]));
    std::string output = argv[5];
    std::string testCases = argv[6];

    NetworkHandler handler = NetworkHandler(file, size);
    auto endTime = std::chrono::steady_clock::now();

    std::cout << "Input read" << std::endl;

    std::chrono::duration<double> time = endTime - startTime;

    std::cout << "took: " << time.count() << " seconds." << std::endl;

    std::vector<unsigned int> seed;
    for (int i = 7; i != argc; ++i)
    {
        seed.push_back(std::stoul(argv[i]));
    }
    
    if (testCases == "single") //maybe change this "command"??
    {
        startTime = std::chrono::steady_clock::now();

        InformedNodes reachedNodes = icm::diffuseInformation(handler, seed, size, beta, dtCase);

        endTime = std::chrono::steady_clock::now();
        time = endTime - startTime;

        std::cout << "Ran ICM algorithm" << std::endl;
        std::cout << "took: " << time.count() << " seconds." << std::endl;

        time = endTime - startTime;

        if (output == "terminal")
            reachedNodes.outputNodesToTerminal();
        else
            reachedNodes.outputNodesToFile(output);

        std::cout << "reached end of program" << std::endl;

        endTime = std::chrono::steady_clock::now();
        time = endTime - totalStartTime;

        std::cout << "took in total: " << time.count() << " sec" << std::endl;
    }
    else
    {
        std::ifstream input;
        input.open(testCases);
        std::string line = "";
        std::string currentLine = "";

        while (std::getline(input, line))
        {
            //parameters: timecase, output, beta, single or multiple start nodes.
            currentLine = line;
            std::vector<std::string> parameters;

            while (currentLine.find(" ") <= currentLine.length())
            {
                unsigned int endIndex = currentLine.find(" ");
                parameters.push_back(currentLine.substr(0, endIndex));
                unsigned int newStart = endIndex + 1;
                currentLine = currentLine.substr(newStart, currentLine.length() - newStart);
            }
            
            std::vector<unsigned int> seed;
            dtCase = parameters[0];
            output = parameters[1];
            beta = stoul(parameters[2]);

            for (unsigned int i = 3; i != parameters.size(); ++i)
            {
                seed.push_back(std::stoul(parameters[i]));
            }

            InformedNodes reachedNodes = icm::diffuseInformation(handler, seed, size, beta, dtCase);

            if (output == "terminal")
                reachedNodes.outputNodesToTerminal();
            else
                reachedNodes.outputNodesToFile(output);
        }

        input.close();
    }

    return 0;
}