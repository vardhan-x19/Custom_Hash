#include <iostream>
#include <vector>
#include <unordered_set>

// Custom hash function for vector<int>
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
    // Define an unordered_set with vector<int> as key and custom hash function
    std::unordered_set<std::vector<int>, VectorHash> uset;

    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    std::vector<int> vec3 = {1, 2, 3}; // Duplicate of vec1

    uset.insert(vec1);
    uset.insert(vec2);
    uset.insert(vec3); // This won't be added again since sets store unique elements

    // Checking if vec1 exists
    if (uset.find(vec1) != uset.end()) {
        std::cout << "vec1 exists in unordered_set." << std::endl;
    }

    // Print elements of the set
    std::cout << "Elements in unordered_set:\n";
    for (const auto& v : uset) {
        for (int num : v) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
