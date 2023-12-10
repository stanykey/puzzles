#ifndef PUZZLES_HUFFMAN_HPP
#define PUZZLES_HUFFMAN_HPP

#include <cstdint>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <string_view>
#include <vector>


namespace huffman {
    struct Node {
        using Pointer = std::unique_ptr<Node>;

        Node(char letter, std::uint32_t frequency, Pointer left = {}, Pointer right = {})
            : letter(letter)
            , frequency(frequency)
            , left(std::move(left))
            , right(std::move(right)) {}

        char letter = '\0';
        std::uint32_t frequency = 0;
        Pointer left;
        Pointer right;
    };


    struct CompareByFrequency {
        bool operator()(const Node::Pointer& lhs, const Node::Pointer& rhs) const {
            return lhs->frequency > rhs->frequency;
        }
    };

    using MinNodeHeap = std::priority_queue<Node::Pointer, std::vector<Node::Pointer>, CompareByFrequency>;

    std::map<char, std::uint32_t> get_letters_stats(std::string_view message) {
        std::map<char, std::uint32_t> stats;
        for (auto letter : message) {
            stats[letter]++;
        }
        return stats;
    }

    Node::Pointer build_tree(std::string_view message) {
        MinNodeHeap heap;
        const auto stats = get_letters_stats(message);
        for (const auto [letter, counter] : stats) {
            heap.emplace(std::make_unique<Node>(letter, counter));
        }

        const auto heap_pop = [&heap] {
            auto value = std::move(const_cast<Node::Pointer&>(heap.top()));
            heap.pop();
            return value;
        };

        while (heap.size() != 1) {
            auto left = heap_pop();
            auto right = heap_pop();
            const auto frequency = left->frequency + right->frequency;
            heap.emplace(std::make_unique<Node>('\0', frequency, std::move(left), std::move(right)));
        }

        return heap_pop();
    }

    std::map<char, std::string> get_lookup_table(const Node& root) {
        std::map<char, std::string> table;

        std::stack<std::tuple<const Node*, std::string>> stack;
        stack.emplace(root.right.get(), "1");
        stack.emplace(root.left.get(), "0");

        while (!stack.empty()) {
            const auto [current, code] = stack.top();
            stack.pop();

            if (current->letter) {
                table[current->letter] = code;
            }

            if (current->right) {
                stack.emplace(current->right.get(), code + '1');
            }

            if (current->left) {
                stack.emplace(current->left.get(), code + '0');
            }
        }
        return table;
    }

    std::string encode_message(Node& root, std::string_view message) {
        const auto lookup_table = get_lookup_table(root);

        std::string encoded;
        for (char const i : message) {
            encoded += lookup_table.at(i);
        }
        encoded.shrink_to_fit();
        return encoded;
    }

    std::string decode_message(const Node& root, std::string_view encoded_message) {
        const auto* node = &root;

        std::string result;
        for (auto digit : encoded_message) {
            node = digit == '0' ? node->left.get() : node->right.get();
            if (!node->left && !node->right) {
                result += node->letter;
                node = &root;
            }
        }
        return result;
    }
}  // namespace huffman

#endif  // PUZZLES_HUFFMAN_HPP
