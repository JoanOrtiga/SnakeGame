#pragma once

#include <stdexcept>
#include <WinUser.h>

namespace Lamter
{
	enum class KeyCode
	{
		None = 0,
		BackSpace = 8,
		Tab = 9,
		Return = 13,
		Escape = 27,
		

		UpArrow = WM_KEYUP,
		DownArrow = WM_KEYDOWN,

		A = 65,
		D = 68,
		S = 83,
		W = 87,

		Delete = 127,
		INTERNAL = 500
	};

	inline KeyCode& operator ++ (KeyCode& e)
	{
		if (e == KeyCode::INTERNAL) {
			throw std::out_of_range("for E& operator ++ (E&)");
		}
		e = KeyCode(static_cast<std::underlying_type<KeyCode>::type>(e) + 1);
		return e;
	}
}

