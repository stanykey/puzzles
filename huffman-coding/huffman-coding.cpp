#include <iostream>

#include "huffman.hpp"

using namespace std::literals;

template<typename T>
T read(std::istream& input) {
    T value{};
    input >> value;
    return value;
}

int main() {
    std::ios::sync_with_stdio(false);

    std::cout << "Input message to encode: ";
    const auto message = read<std::string>(std::cin);

    const auto tree_root = huffman::build_tree(message);

    const auto encoded_message = huffman::encode_message(*tree_root, message);
    std::cout << "Encoded message: " << encoded_message << std::endl;

    const auto decoded_message = huffman::decode_message(*tree_root, encoded_message);
    std::cout << "Decoded message: " << decoded_message << std::endl;

    return 0;
}
