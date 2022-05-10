#pragma once

#include <glad/gl.h>
#include <glm/vec4.hpp>
#include <json/json.hpp>

namespace our
{
    // There are some options in the render pipeline that we cannot control via shaders
    // such as blending, depth testing and so on
    // Since each material could require different options (e.g. transparent materials usually use blending),
    // we will encapsulate all these options into a single structure that will also be responsible for configuring OpenGL's pipeline
    struct PipelineState
    {
        // This set of pipeline options specifies whether face culling will be used or not and how it will be configured
        struct
        {
            bool enabled = false;
            GLenum culledFace = GL_BACK;
            GLenum frontFace = GL_CCW;
        } faceCulling;

        // This set of pipeline options specifies whether depth testing will be used or not and how it will be configured
        struct
        {
            bool enabled = false;
            GLenum function = GL_LEQUAL;
        } depthTesting;

        // This set of pipeline options specifies whether blending will be used or not and how it will be configured
        struct
        {
            bool enabled = false;
            GLenum equation = GL_FUNC_ADD;
            GLenum sourceFactor = GL_SRC_ALPHA;
            GLenum destinationFactor = GL_ONE_MINUS_SRC_ALPHA;
            glm::vec4 constantColor = {0, 0, 0, 0};
        } blending;

        // These options specify the color and depth mask which can be used to
        // prevent the rendering/clearing from modifying certain channels of certain targets in the framebuffer
        glm::bvec4 colorMask = {true, true, true, true}; // To know how to use it, check glColorMask
        bool depthMask = true;                           // To know how to use it, check glDepthMask

        // This function should set the OpenGL options to the values specified by this structure
        // For example, if faceCulling.enabled is true, you should call glEnable(GL_CULL_FACE), otherwise, you should call glDisable(GL_CULL_FACE)

        // TODO: (Req 3) Write this function (depth testing, face culling, blending and color/depth mask options).
        void setup() const
        {
            //==// faceCulling: allows non-visible objects of closed surfaces to be removed before expensive Rasterization and Fragment Shader operations.
            if (faceCulling.enabled)
            {
                glEnable(GL_CULL_FACE);             // To enable face culling
                glCullFace(faceCulling.culledFace); // select which face to be culled
                glFrontFace(faceCulling.frontFace); // select which face to be rendered (counter-clockwise or clockwise)
            }
            else
                glDisable(GL_CULL_FACE); // To disable face culling


            //==//depthTesting: The Depth Test is a per-sample processing operation performed after the Fragment Shader (and sometimes before).
            //The Fragment's output depth value may be tested against the depth of the sample being written to. If the test fails, the fragment is discarded. 
            //If the test passes, the depth buffer will be updated with the fragment's output depth, unless a subsequent per-sample operation prevents it (such as turning off depth writes).
            if (depthTesting.enabled)
            {
                glEnable(GL_DEPTH_TEST);            // To enable depth testing
                glDepthFunc(depthTesting.function); // Specify when to replace the written depth value with the new value
            }
            else
                glDisable(GL_DEPTH_TEST); // To disable depth testing

            // result color = src factor * src color + dest factor * dest color
            if (blending.enabled)
            {
                glEnable(GL_BLEND);
                // Specify the the source and destination blending factors according to "constant color" and it is defaulted to be 0.
                glBlendColor(blending.constantColor[0], blending.constantColor[1], blending.constantColor[2], blending.constantColor[3]);
                glBlendEquation(blending.equation);                             // Add the two colors together including the factor (GL_FUNC_ADD)
                glBlendFunc(blending.sourceFactor, blending.destinationFactor); // Specify the factor for source color and destination color
            }
            else
                glDisable(GL_BLEND);

            // Enable the changes in all color channels (if set to be true)
            glColorMask(colorMask[0], colorMask[1], colorMask[2], colorMask[3]);
            glDepthMask(depthMask);
        }

        // Given a json object, this function deserializes a PipelineState structure
        void deserialize(const nlohmann::json &data);
    };

}