#pragma once

#include "Core.h"

namespace ge
{

  class GE_API Application
  {
  public:
    Application();
    virtual ~Application();
    void Run();
  };

  // To be defined in CLIENT
  Application* CreateApplication();
} // namespace ge
