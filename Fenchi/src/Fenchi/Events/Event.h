#pragma once
#include"Fenchi/core.h"

#include<string>
#include<functional>

namespace Fenchi
{
	//now events in fenchi is blocking, maybe can buffer and process them in the update stage

	enum class EventTypes
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonRelease, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0) ,
		EventCategoryInput       = BIT(1) ,
		EventCategoryKeyboard    = BIT(2) ,
		EventCategoryMouse       = BIT(3) ,
		EventCategoryMouseButton = BIT(4) 
	};

#define EVENT_CLASS_TYPE(types) static EventTypes GetStaticType(){return EventTypes::types;}\
							    virtual EventTypes GetEventType() const override{ return GetStaticType();}\
							    virtual const char* GetName() const override {return #types;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class FENCHI_API Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;
		virtual EventTypes GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event) {}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}