#include <iostream>
#include <string>
#include <vector>
#include <print>

#define vec std::vector
typedef std::string str;
typedef vec<str> strvec;
typedef strvec::iterator vsi;
typedef vec<int> ivec;
typedef vec<double> dVec;
typedef std::vector<std::vector<std::vector<int>>> iVector3d;
typedef std::vector<std::vector<int>> iVector2d;

int main() {

    std::vector<std::vector<std::vector<int>>> ivecGrid;
    std::vector<std::vector<int>> ivecLayer;
    std::vector<int> ivecRow;

    int layers = 2;  // Número de camadas
    int rows = 12;    // Número de linhas
    int cols = 3;    // Número de colunas

    int value = 1; // Valor inicial

    // Preenchendo o vetor 3D usando push_back
    for (int i = 0; i < layers; ++i) {

        for (int j = 0; j < rows; ++j) {


            for (int k = 0; k < cols; ++k) {

                ivecRow.push_back(value++); // Adiciona um valor à linha
            }

            ivecLayer.push_back(ivecRow); // Adiciona a linha à camada
        }

        ivecGrid.push_back(ivecLayer); // Adiciona a camada ao vetor 3D
    }

    // Exibindo o conteúdo do vetor 3D
    for (int i = 0; i < layers; ++i) {

        std::cout << "Layer " << i + 1 << ":\n";

        for (int j = 0; j < rows; ++j) {

            for (int k = 0; k < cols; ++k) {

                std::cout << ivecGrid [i][j][k] << ' ';
            }
            std::println();
        }
        std::println();
    }

    return 0;
}

