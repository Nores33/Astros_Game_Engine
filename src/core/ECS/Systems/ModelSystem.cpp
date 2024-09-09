#include "core/ECS/Systems/ModelSystem.hpp"

void ModelSystem::render(Registry& registry, Renderer& renderer) {
    for (auto& [entity, model] : registry.models) {
        // logica para renderizar el modelo usando el renderer
    }
}