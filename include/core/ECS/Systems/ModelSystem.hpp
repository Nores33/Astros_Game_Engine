#ifndef MODELSYSTEM_HPP
#define MODELSYSTEM_HPP

#include <unordered_map>
#include "core/ECS/Component.hpp"
#include "graphics/Renderer.hpp"

class ModelSystem {
public:
    void render(Registry& registry, Renderer& renderer);
};

#endif