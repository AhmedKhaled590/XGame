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
        std::vector<MeshRendererComponent *> healthBar;

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
        int update(World *world, float deltaTime)
        {
            // cout << "update collision" << endl;
            // cout << cars.size() << " " << hearts.size() << endl;
            hearts.clear();
            cars.clear();
            healthBar.clear();
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
                else if (entity->name == "healthbar")
                {
                    auto healthBar = entity->getComponent<MeshRendererComponent>();
                    this->healthBar.push_back(healthBar);
                }
            }
            cout << "BEFOR SORT" << endl;
            healthBar = sortHealthBars(healthBar);
            cout << "AFTER SORT" << endl;
            // cout << cars.size() << " " << hearts.size() << endl;
            // cout << "before for" << endl;
            for (auto heart : hearts)
            {
                if (checkCollision(heart, cars[0]))
                {
                    // //remove heart after collision
                    // world->markForRemoval(heart->getOwner());
                    // world->deleteMarkedEntities();
                    // //remove last health bar after collision
                    // world->markForRemoval(healthBar[healthBar.size() - 1]->getOwner());
                    // world->deleteMarkedEntities();
                    // healthBar.pop_back();
                    // add last health bar after collision with special color heart
                    //-----------------------------------------------------------------
                    Entity *addedHealthBar = world->add();
                    addedHealthBar = healthBar[healthBar.size()-1]->getOwner();
                    addedHealthBar->localTransform.position.x = healthBar[healthBar.size() - 1]->getOwner()->localTransform.position.x + 0.15;
                }
            }

            // world->deleteMarkedEntities();

            return healthBar.size();
        }
        // sort based on x of position
        std::vector<MeshRendererComponent *> sortHealthBars(std::vector<MeshRendererComponent *> vec)
        {
            std::sort(vec.begin(), vec.end(), [](MeshRendererComponent *a, MeshRendererComponent *b)
                      { return a->getOwner()->localTransform.position.x < b->getOwner()->localTransform.position.x; });
            return vec;
        }
    };
}