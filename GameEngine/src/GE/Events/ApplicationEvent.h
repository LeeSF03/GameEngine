#pragma once

#include <gepch.h>

#include <Events/Event.h>

namespace ge {
  class GE_API WindowdResizeEvent: public Event
  {
  public:
    WindowdResizeEvent(unsigned int width, unsigned int height)
      : m_Width(width), m_Height(height) {}

    inline unsigned int GetWidth() const { return m_Width; }
    inline unsigned int Getheight() const { return m_Height; }

    std::string ToString() const override
    {
      std::stringstream ss;
      ss << "WindowsResizeEvent: " << m_Width << ", " << m_Height;
      return ss.str();
    } 

    EVENT_CLASS_TYPE(WindowResize)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)

  private:
    unsigned int m_Width, m_Height;
  };

  class GE_API WindowdCloseEvent: public Event
  {
  public:
    WindowdCloseEvent() {}

    EVENT_CLASS_TYPE(WindowClose)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };

  class GE_API AppTickEvent : public Event
  {
  public:
    AppTickEvent() {}

    EVENT_CLASS_TYPE(AppTick)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };

  class GE_API AppUpdateEvent : public Event
  {
  public:
    AppUpdateEvent() {}

    EVENT_CLASS_TYPE(AppUpdate)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };

  class GE_API AppRenderEvent : public Event
  {
    AppRenderEvent() {}
    
    EVENT_CLASS_TYPE(AppRender)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
}