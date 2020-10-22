#include <iostream>
#include <string>
#include <string_view>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <chrono>
#include <stdexcept>
#include "networkHandler.hpp"
#include "informedNodes.hpp"
#include "independentCascadeModel.hpp"

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        std::cerr << "To few arguments" << std::endl;
        return 1;
    }
    else if (4 < argc && argc < 6)
    {
        std::cerr << "To many arguments to run multiple cases " <<
                     "and to few arguments to run one case." << std::endl;
        return 1;
    }

    if (argc == 4)
    {
        std::string graphRepresentationFile = argv[1];
        unsigned int nodeAmount = std::stoul(argv[2]);
        std::fstream testCasesFile;
        
        //write tests on files
        std::string line;
        std::string_view currentLine;

        testCasesFile.open(std::string_view(argv[3]).data());

        while (std::getline(testCasesFile, line))
        {
            std::vector<std::string_view> parameters;
            currentLine = line;

            while (currentLine.find(' ') < currentLine.length())
            {
                unsigned int end = currentLine.find(' ');
                parameters.push_back(currentLine.substr(0, end));
                currentLine = currentLine.substr(end + 1, currentLine.length() - (end + 1));
            }
            parameters.push_back(currentLine);
        
            std::vector<unsigned int> seed;

            for (unsigned int i = 2; i != parameters.size(); ++i)
            {
                seed.push_back(std::stoul(parameters[i].data()));
            }
            std::string_view timeCase = parameters[0];

            NetworkHandler handler = NetworkHandler(graphRepresentationFile, nodeAmount);
            InformedNodes reachedNodes = icm::diffuseInformation(handler, seed, nodeAmount, timeCase);
            
            if (parameters[1] == "terminal")
                reachedNodes.outputNodesToTerminal();
            else
                reachedNodes.outputNodesToFile(std::string(parameters[1]));

        }
        testCasesFile.close();
    }
    else
    {
        std::string graphRepresentationFile = argv[1];
        unsigned int nodeAmount = std::stoul(argv[2]);
        std::string timeCase = argv[3];
        std::string output = argv[4];
        std::vector<unsigned int> seed;

        if (graphRepresentationFile.length() < graphRepresentationFile.find(".txt"))
            throw std::logic_error("Input error | wrong file type in path to network.");
        if (timeCase != "best_case" && timeCase != "average_case" && timeCase != "worst_case")
            throw std::logic_error("Input error | wrong time case type.");
        if (output.length() < output.find(".txt") && output != "terminal")
            throw std::logic_error("Input error | wrong file type in path to output.");
        
        for (int i = 5; i != argc; ++i)
        {
            seed.push_back(std::stoul(argv[i]));
        }

        auto startTime = std::chrono::steady_clock::now();
        NetworkHandler handler = NetworkHandler(graphRepresentationFile, nodeAmount);
        auto endTime = std::chrono::steady_clock::now();

        std::chrono::duration<double> time = endTime - startTime;
        std::cout << "input took: " << time.count() * 1000 << " milliseconds." << std::endl;

        startTime = std::chrono::steady_clock::now();
        InformedNodes reachedNodes = icm::diffuseInformation(handler, seed, nodeAmount, timeCase);
        endTime = std::chrono::steady_clock::now();

        time = endTime - startTime;
        std::cout << "icm-algorithm took: " << time.count() * 1000 << " milliseconds." << std::endl;

        if (output == "terminal")
            reachedNodes.outputNodesToTerminal();
        else
            reachedNodes.outputNodesToFile(output);


    }
}