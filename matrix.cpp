#include <iostream>
#include <vector>


double determinant(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    if (n == 1) {
        return matrix[0][0];
    }

    double det = 0.0;
    for (int col = 0; col < n; ++col) {
        std::vector<std::vector<double>> submatrix(n - 1, std::vector<double>(n - 1));
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j != col) {
                    submatrix[i - 1][j < col ? j : j - 1] = matrix[i][j];
                }
            }
        }
        det += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * determinant(submatrix);
    }
    return det;
}

int main() {
    
    std::vector<std::vector<double>> matrix = {
        {5.0, 1.0, 0.0},
        {2.0, 2.0, 3.0},
        {4.0, 0.0, -1.0}
    };

    double det = determinant(matrix);
    std::cout << "DETERMINANT: " << det << std::endl;

    return 0;
}
