#pragma once
#include <iostream>

namespace dsg {

	enum class WindowType {
		DefaultWindow,
		FancyWindow
	};

	class Window {
	public:
		virtual ~Window() {};
		virtual WindowType getType() const = 0;
		virtual std::string getName() const = 0;
	};

	class DefaultWindow : public Window {
	public:
		WindowType getType() const override {
			return WindowType::DefaultWindow;
		}
		std::string getName() const override {
			return "DefaultWindow";
		}
	};

	class FancyWindow : public Window {
	public:
		WindowType getType() const override {
			return WindowType::FancyWindow;
		}
		std::string getName() const override {
			return "FancyWindow";
		}
	};

	Window* getNewWindow(Window* window) {
		switch (window->getType()) {
		case WindowType::DefaultWindow:
			return new DefaultWindow();
			break;
		case WindowType::FancyWindow:
			return new FancyWindow();
			break;
		}
		return nullptr;
	}

};