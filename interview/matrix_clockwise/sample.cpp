#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrix;

void print(const Matrix& matrix)
{
    for (const auto& row: matrix) {
        for (const auto& el: row) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }   
}


void printClockwise(const Matrix& matrix)
{
    const size_t rowCount = matrix.size();
    if (!rowCount) {
        return;
    }
    const size_t columnCount = matrix[0].size();
    if (!columnCount) {
        return;
    }

    int leftColumn = 0;
    int rightColumn = columnCount - 1;
    int topRow = 0;
    int bottomRow = rowCount - 1;

    while (leftColumn <= rightColumn and topRow <= bottomRow) {
        for (int j = leftColumn; j <= rightColumn; ++j) {
            std::cout << matrix[topRow][j] << " ";
        }
        ++topRow;
        for (int i = topRow; i <= bottomRow; ++i) {
            std::cout << matrix[i][rightColumn] << " ";
        }
        --rightColumn;
        if (topRow <= bottomRow) {
            for (int j = rightColumn; j >= leftColumn; --j) {
                std::cout << matrix[bottomRow][j] << " ";
            }
            --bottomRow;           
        }
        if (leftColumn <= rightColumn) {
            for (int i = bottomRow; i >= topRow; --i) {
                std::cout << matrix[i][leftColumn] << " ";
            }
            ++leftColumn;
        }
    }

}

int main()
{
    // Matrix matrix{
    //     {1, 2},
    //     {3, 4}
    // };
    // Matrix matrix{
    //     {1, 2, 3, 4, 5},
    //     {6, 7, 8, 9, 10},
    //     {11, 12, 13, 14, 15},
    //     {16, 17, 18, 19, 20}
    // };
    // Matrix matrix{
    //     {1, 2},
    //     {3, 4},
    //     {5, 6},
    //     {7, 8},
    //     {9, 10}
    // };
    Matrix matrix{
        {1, 2, 3, 4, 5}
    };
    print(matrix);
    printClockwise(matrix);
    return 0;
}
