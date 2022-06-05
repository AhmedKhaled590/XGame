#pragma once

#include "../ecs/world.hpp"
#include "../components/collider.hpp"
#include "../components/movement.hpp"
#include "../components/mesh-renderer.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/fast_trigonometry.hpp>
#include <iostream>
namespace our
{

    class CollisionSystem
    {
        std::vector<ColliderComponent *> cars, hearts;

    public:
        // cube-->heart,bullet-->car
        bool checkCollision(ColliderComponent *heartComponent, ColliderComponent *carComponent)
        {

            auto car = carComponent->getOwner();
            auto heart = heartComponent->getOwner();
         
            glm::vec3 carCenter = carComponent->position + glm::vec3(car->getLocalToWorldMatrix() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
            glm::vec3 heartCenter = heartComponent->position + glm::vec3(heart->getLocalToWorldMatrix() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
            glm::vec3 heartLengths = glm::vec3(heartComponent->length, heartComponent->length, heartComponent->length) * heart->localTransform.scale;

            glm::vec3 difference = carCenter - heartCenter;
            // min(max(x, minVal), maxVal)
            glm::vec3 clampedDifference = glm::clamp(difference, heartLengths * glm::vec3(-1.0f, -1.0f, -1.0f), heartLengths);

            glm::vec3 heartPoint = heartCenter + clampedDifference;
            difference = heartPoint - carCenter;
            float carRadius = carComponent->length * glm::length(car->localTransform.scale);
            return glm::length(difference) < carRadius;
        }
        bool update(World *world, float deltaTime)
        {
            // cout << "update collision" << endl;
            // cout << cars.size() << " " << hearts.size() << endl;
            hearts.clear();
            cars.clear();
            for (const auto &entity : world->getEntities())
            {
                if (entity->name == "heart")
                {
                    // cout << "heart" << endl;
                    auto heart = entity->getComponent<ColliderComponent>();
                    hearts.push_back(heart);
                }
                else if (entity->name == "car")
                {
                    auto car = entity->getComponent<ColliderComponent>();
                    cars.push_back(car);
                }
            }
            // cout << cars.size() << " " << hearts.size() << endl;
            // cout << "before for" << endl;
            for (auto heart : hearts)
            {
                if (checkCollision(heart, cars[0]))
                {
                    cout << "collision" << endl;
                }
                // cout << "in for" << endl;
            }

            // world->deleteMarkedEntities();

            return hearts.empty();
        }
    };
}