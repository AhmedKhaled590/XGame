#pragma once

#include <application.hpp>

class ClearColorState: public our::State {
    // onInitialize() function is called once before the state starts
    void onInitialize() override {
        //TODO(DONE): Read the color from the configuration file and use it to set the clear color for the window
        const auto &config = getApp()->getConfig()["scene"]["clear-color"];
        //CONFIG NOW READS THE CONFIG FILE AND RETURNS A JSON OBJECT
        //THEN WE CAN USE THE .value() METHOD TO GET THE VALUE OF A KEY
        float RED = config.value("r", 0.0f);
        float GREEN = config.value("g", 0.0f);
        float BLUE = config.value("b", 0.0f);
        float ALPHA = config.value("a", 0.0f);
        glClearColor(RED, GREEN, BLUE, ALPHA);
        //HINT: you can the configuration for the whole application using "getApp()->getConfig()"
        //To see how the clear color is written in the json files, see "config/blue-screen.json"
        //To know how read data from a nlohmann::json object, 
        //look at the following documentation: https://json.nlohmann.me/features/element_access/
    }

    // onDraw(deltaTime) function is called every frame 
    void onDraw(double deltaTime) override {
        //At the start of frame we want to clear the screen. Otherwise we would still see the results from the previous frame.
        glClear(GL_COLOR_BUFFER_BIT);
    }
};