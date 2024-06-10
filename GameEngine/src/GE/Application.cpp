#include <Application.h>

#include <Events/ApplicationEvent.h>
#include <Log.h>

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
    WindowdResizeEvent e(1280, 720);
    if (e.IsInCategory(EventCategoryApplication))
    {
      GE_TRACE(e.ToString());
    }
    while (true)
      ;
  }

} // namespace ge