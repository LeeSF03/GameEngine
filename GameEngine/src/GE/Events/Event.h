#pragma once

#include <gepch.h>

#include <Core.h>

namespace ge
{
  /**
   * Events are blocking, meaning an an event occurs it gets dispatched
   * immediately and dealt with.
   * In the future, using an event buffer in an event bus and process
   * process them during "event" part of the update stage
   */

  enum class EventType
  {
    None = 0,
    WindowClose,
    WindowResize,
    WindowFocus,
    WindowLostFocus,
    WindowMoved,
    AppTick,
    AppUpdate,
    AppRender,
    KeyPressed,
    KeyReleased,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled
  };

  enum EventCategory
  {
    None = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryInput = BIT(1),
    EventCategoryKeyboard = BIT(2),
    EventCategoryMouse = BIT(3),
    EventCategoryMouseBUtton = BIT(4)
  };

#define EVENT_CLASS_TYPE(type)                                                \
  static EventType GetStaticType() { return EventType::type; }                        \
  virtual EventType GetEventType() const override { return GetStaticType(); } \
  virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
  virtual int GetCategoryFlags() const override { return category; }

  class GE_API Event {
    friend class EventDispatcher;
  public:
    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual std::string ToString() const { return GetName(); }

    inline bool IsInCategory(EventCategory category) {
      return GetCategoryFlags() & category;
    }
  
  protected:
    bool m_Handled = false;
  };

  class GE_API EventDispatcher {
    template<typename T>
    using EventFn = std::function<bool(T&)>;

  public:
    EventDispatcher(Event& event)
      : m_Event(event)
    {
    }

    template<typename T>
    bool Dispatch(EventFn<T> func)
    {
      if (m_Event.GetEventType() == T::GetStaticType()) {
        m_Event.m_Handled = func(*(T*)&m_Event);
        return true;
      }
      return false;
    }
  
  private:
    Event& m_Event;
  };

  inline std::ostream& operator<<(std::ostream& os, const Event& e)
  {
    return os<< e.ToString();
  }
}