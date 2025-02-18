/**
 * @file openglContext.hpp
 * @brief This file contains the declaration of the OpenglContext class and
 * related structures.
 */

#pragma once

#include <environment.h>
#include <openglBuffersManager.h>

/**
 * @struct AdditionalCallbackParameters
 * @brief Additional parameters to be passed to GLFW callback functions.
 */
typedef struct {
  Camera* camera;      ///< Camera object.
  GLFWwindow* window;  ///< GLFW window handle.
  UI* userInterface;   ///< User interface object.
} AdditionalCallbackParameters;

/**
 * @class OpenglContext
 * @brief Manages the OpenGL context and rendering loop.
 */
class OpenglContext {
 public:
  AdditionalCallbackParameters*
      AdditionalParameters;  ///< Additional callback parameters.

  GLFWwindow* swarmSimulatorWindow;  ///< GLFW window handle for the simulator.
  Camera* camera;                    ///< Camera object.
  UI* userInterface;                 ///< User interface object.
  Environment* environment;          ///< Environment object.
  ParameterAssigner* parameterAssigner;  ///< Parameter assigner object.

  unsigned int frameCounter;        ///< Frame counter.
  int openGlRenderUpdateFrameRate;  ///< Frame rate for OpenGL rendering
                                    ///< updates.

  OpenglContext() {};  ///< Constructor.
  ~OpenglContext();   ///< Destructor.

  void init();        ///< Initialize the OpenGL context.
  void pollEvents();  ///< Poll GLFW events.
  void run(
      OpenglBuffersManager* openglBuffersManager);  ///< Run the rendering loop.
  void pre_render();   ///< Perform pre-render setup.
  void post_render();  ///< Perform post-render tasks.
};

