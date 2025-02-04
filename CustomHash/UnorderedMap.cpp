#include <iostream>
#include <vector>
#include <unordered_map>

struct VectorHash {
    std::size_t operator()(const std::vector<int>& v) const {
        std::size_t hash = 0;
        for (int num : v) {
            hash ^= std::hash<int>{}(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

int main() {
    std::unordered_map<std::vector<int>, int, VectorHash> mpp;

    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    mpp[vec1] = 10;
    mpp[vec2] = 20;

    // Accessing values
    std::cout << "Value for {1, 2, 3}: " << mpp[vec1] << std::endl;
    std::cout << "Value for {4, 5, 6}: " << mpp[vec2] << std::endl;

    return 0;
}
