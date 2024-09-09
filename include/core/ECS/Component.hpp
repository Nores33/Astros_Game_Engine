#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream> 
#include <unordered_map>

#include <glm/glm.hpp>
#include <tiny_gltf.h>

struct Transform{
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};

struct Model {
    tinygltf::Model gltfModel;
};

// Registry to store all the components
struct Registry{
    std::unordered_map<int, Transform> transforms;
    std::unordered_map<int, Model> models;
};

#endif