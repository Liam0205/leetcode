#include <iostream>

static constexpr const size_t WIDTH  = 4;
static constexpr const size_t HEIGHT = 3;

int** construct_matrix(const size_t width, const size_t height);
void destruct_matrix(int** matrix, const size_t height);
void print_matrix(int** matrix, const size_t width, const size_t height);
void rotate_matrix(int** input, const size_t width, const size_t height, int** output);

int main() {
    auto input  = construct_matrix(WIDTH, HEIGHT);
    auto output = construct_matrix(HEIGHT, WIDTH);

    // assign input matrix
    int i = 0;
    for (size_t h = 0; h != HEIGHT; ++h) {
        for (size_t w = 0; w != WIDTH; ++i, ++w) {
            input[h][w] = i;
        }
    }
    print_matrix(input, WIDTH, HEIGHT);

    rotate_matrix(input, WIDTH, HEIGHT, output);
    print_matrix(output, HEIGHT, WIDTH);

    destruct_matrix(output, WIDTH);
    destruct_matrix(input, HEIGHT);

    return 0;
}

int** construct_matrix(const size_t width, const size_t height) {
    int** m = new int*[height];
    for (size_t h = 0; h != height; ++h) {
        m[h] = new int[width];
    }
    return m;
}

void destruct_matrix(int** m, const size_t height) {
    for (size_t h = 0; h != height; ++h) {
        delete[] m[h];
    }
    delete[] m;
    return;
}

void print_matrix(int** matrix, const size_t width, const size_t height) {
    if (nullptr == matrix) {
        return;
    }
    for (size_t h = 0; h != height; ++h) {
        for (size_t w = 0; w != width; ++w) {
            std::cout << matrix[h][w] << '\t';
        }
        std::cout << std::endl;
    }
}

void rotate_matrix(int** input, const size_t width, const size_t height, int** output) {
    if (nullptr == input or nullptr == output) {
        return;
    }
    for (size_t h = 0; h != height; ++h) {
        for (size_t w = 0; w != width; ++w) {
            output[w][height - 1 - h] = input[h][w];
        }
    }
    return;
}
