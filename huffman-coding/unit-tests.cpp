#include <catch2/catch_test_macros.hpp>

#include <map>
#include <vector>

#include "huffman.hpp"

using namespace std::literals;


TEST_CASE("Letters Codes Table 1", "[codes]") {
    const auto message = "ABACA"sv;
    auto tree_root = huffman::build_tree(message);
    const auto table = huffman::get_lookup_table(*tree_root);

    REQUIRE(table.at('A') == "1");
    REQUIRE(table.at('B') == "00");
    REQUIRE(table.at('C') == "01");
}

//TEST_CASE("Letters Codes Table 2", "[codes]") {
//    const auto message = "ABRACADABRA"sv;
//    auto tree_root = huffman::build_tree(message);
//    const auto table = huffman::get_lookup_table(*tree_root);
//
//    REQUIRE(table.at('A') == "0");
//    REQUIRE(table.at('B') == "111");
//    REQUIRE(table.at('C') == "1100");
//    REQUIRE(table.at('D') == "1101");
//    REQUIRE(table.at('R') == "10");
//}

TEST_CASE("Letters Codes Table 3", "[codes]") {
    const auto message = "BCAADDDCCACACAC"sv;
    auto tree_root = huffman::build_tree(message);
    const auto table = huffman::get_lookup_table(*tree_root);

    REQUIRE(table.at('A') == "11");
    REQUIRE(table.at('B') == "100");
    REQUIRE(table.at('C') == "0");
    REQUIRE(table.at('D') == "101");
}

// TEST_CASE("Letters Codes Table 4", "[codes]") {
//     const auto message = "this is an example of a huffman tree"sv;
//     auto tree_root = huffman::build_tree(message);
//     const auto table = huffman::get_lookup_table(*tree_root);
//
//     REQUIRE(table.at(' ') == "111");
//     REQUIRE(table.at('a') == "010");
//     REQUIRE(table.at('e') == "000");
//     REQUIRE(table.at('f') == "1101");
//     REQUIRE(table.at('h') == "1010");
//     REQUIRE(table.at('i') == "1000");
//     REQUIRE(table.at('m') == "0111");
//     REQUIRE(table.at('n') == "0010");
//     REQUIRE(table.at('s') == "1011");
//     REQUIRE(table.at('t') == "0110");
//     REQUIRE(table.at('l') == "11001");
//     REQUIRE(table.at('o') == "00110");
//     REQUIRE(table.at('p') == "10011");
//     REQUIRE(table.at('r') == "11000");
//     REQUIRE(table.at('u') == "00111");
//     REQUIRE(table.at('x') == "10010");
// }

//TEST_CASE("Encoding", "[coding]") {
//    const std::map<std::string_view, std::string_view> cases{
//        {"ABACA", "1001011"}, {"ABRACADABRA", "01111001100011010111100"}
//    };
//
//    for (const auto [message, expected_encoding] : cases) {
//        auto tree_root = huffman::build_tree(message);
//        REQUIRE(huffman::encode_message(*tree_root, message) == expected_encoding);
//    }
//}


TEST_CASE("Decoding", "[coding]") {
    const std::vector<std::string_view> cases{
        "ABACA", "ABRACADABRA", "BCAADDDCCACACAC", "this is an example of a huffman tree"
    };

    for (const auto message : cases) {
        auto tree_root = huffman::build_tree(message);
        const auto encoded = huffman::encode_message(*tree_root, message);
        const auto decoded = huffman::decode_message(*tree_root, encoded);
        REQUIRE(decoded == message);
    }
}