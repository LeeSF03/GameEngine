#include <Application.h>
#include <windows.h>
#include <iostream>

namespace ge
{

  Application::Application()
  {
  }

  Application::~Application()
  {
  }

  void Application::Run()
  {
    while (true)
    {
      Sleep(1000);
      std::cout << "Running" << std::endl;
    }
  }

} // namespace ge