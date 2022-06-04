#pragma once

#include "../ecs/world.hpp"
#include "../components/collider.hpp"
#include "../components/movement.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/fast_trigonometry.hpp>
namespace our
{

    class CollisionSystem
    {
        std::vector<ColliderComponent *> car, hearts;

    public:
        bool checkCollision(ColliderComponent *heartComponent, ColliderComponent *carComponent)
        {
            auto heart = heartComponent->getOwner();
            auto car = carComponent->getOwner();

            glm::vec3 heartCenter = heartComponent->position + glm::vec3(heart->getLocalToWorldMatrix() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
            glm::vec3 carCenter = carComponent->position + glm::vec3(car->getLocalToWorldMatrix() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
            glm::vec3 carLengths = glm::vec3(carComponent->length, carComponent->length, carComponent->length) * car->localTransform.scale;

            glm::vec3 difference = heartCenter - carCenter;
            glm::vec3 clampedDifference = glm::clamp(difference, carLengths * glm::vec3(-1.0f, -1.0f, -1.0f), carLengths);

            glm::vec3 carPoint = carCenter + clampedDifference;
            difference = carPoint - heartCenter;
            float heartRadius = heartComponent->length * glm::length(heart->localTransform.scale);
            return glm::length(difference) < heartRadius;
        }
        bool update(World *world, float deltaTime)
        {
            hearts.clear();
            car.clear();
            auto heart = entity->getComponent<ColliderComponent>();
            auto c = entity->getComponent<ColliderComponent>();
            for (const auto &entity : world->getEntities())
                if (heart && entity->name == "heart")
                    hearts.push_back(heart);
                else if (c && entity->name == "car")
                    car.push_back(c);

            for (auto heart : hearts)
            {
                if (checkCollision(heart, car[0]))
                {
                    auto heartMaterial = cube->getOwner()->getComponent<MeshRendererComponent>()->material;
                    auto heartColor = (dynamic_cast<TintedMaterial *>(cubeMaterial))->tint;
                    glm::vec3 white = glm::vec3(1, 1, 1);
                    glm::vec3 red = glm::vec3(1, 0, 0);
                    glm::vec3 green = glm::vec3(0, 1, 0);
                    glm::vec3 blue = glm::vec3(0, 0, 1);
                    glm::vec3 black = glm::vec3(0, 0, 0);
                    if (heartColor == white)
                    {
                    }
                }

                world->deleteMarkedEntities();

                return cubes.empty();
            }
        };
    }