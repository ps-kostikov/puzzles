#include "common.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

constexpr size_t SIZE = 20;
constexpr size_t LENGTH = 4;

std::vector<Naturals>
readInput()
{
    std::ifstream inf("11.in");
    std::vector<Naturals> result;
    std::string line;
    for (size_t i = 0; i < SIZE; ++i) {
        std::getline(inf, line);
        std::stringstream ss;
        ss << line;
        Natural n;
        Naturals naturals;
        for (int j = 0; j < SIZE; ++j) {
            ss >> n;
            naturals.push_back(n);
        }
        result.push_back(naturals);
    }
    return result;
}

int main()
{
    Natural maxProd = 0;
    auto matrix = readInput();

    // for (size_t i = 0; i < SIZE; ++i) {
    //     for (size_t j = 0; j < SIZE; ++j) {
    //         std::cout << matrix[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    for (size_t i = 0; i + LENGTH < SIZE; ++i) {
        for (size_t j = 0; j + LENGTH < SIZE; ++j) {
            {
                Natural prod = matrix[i][j];
                for (size_t k = 1; k < LENGTH; ++k) {
                    prod *= matrix[i + k][j];
                }
                maxProd = std::max(maxProd, prod);
            }
            {
                Natural prod = matrix[i][j];
                for (size_t k = 1; k < LENGTH; ++k) {
                    prod *= matrix[i][j + k];
                }
                maxProd = std::max(maxProd, prod);
            }
            {
                Natural prod = matrix[i][j];
                for (size_t k = 1; k < LENGTH; ++k) {
                    prod *= matrix[i + k][j + k];
                }
                maxProd = std::max(maxProd, prod);
            }
        }
    }
    for (size_t i = LENGTH - 1; i < SIZE; ++i) {
        for (size_t j = 0; j + LENGTH < SIZE; ++j) {
            {
                Natural prod = matrix[i][j];
                for (size_t k = 1; k < LENGTH; ++k) {
                    prod *= matrix[i - k][j + k];
                }
                maxProd = std::max(maxProd, prod);
            }
        }
    }
    std::cout << maxProd << std::endl;
}