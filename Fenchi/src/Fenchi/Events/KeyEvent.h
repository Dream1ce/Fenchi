#pragma once
#include"Event.h"
#include<sstream>

namespace Fenchi
{
	class FENCHI_API KeyEvent: public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

	protected:
		KeyEvent(int keycode) :m_KeyCode(keycode) {};
		int m_KeyCode;
	};
	class FENCHI_API KeyPressEvent :public KeyEvent
	{
	public:
		KeyPressEvent(int keycode, int repeatcount) :KeyEvent(keycode), m_RepeatCount(repeatcount) {}
		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_KeyCode << "(" << m_RepeatCount << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	private:
		int m_RepeatCount;
	};

	class FENCHI_API KeyReleaseEvent :public KeyEvent
	{
	public:
		KeyReleaseEvent(int keycode) :KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent:" << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryInput|EventCategoryKeyboard)
		EVENT_CLASS_TYPE(KeyReleased)
	};
}