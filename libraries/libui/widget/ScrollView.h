/*
    This file is part of duckOS.

    duckOS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    duckOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with duckOS.  If not, see <https://www.gnu.org/licenses/>.

    Copyright (c) Byteduck 2016-2020. All rights reserved.
*/

#ifndef DUCKOS_LIBUI_SCROLLVIEW_H
#define DUCKOS_LIBUI_SCROLLVIEW_H

#include "Widget.h"
#include "Scrollable.h"

#define LIBUI_SCROLLVIEW_MAX_PREFERRED_WIDTH 300
#define LIBUI_SCROLLVIEW_MAX_PREFERRED_HEIGHT 200

namespace UI {
	class ScrollView: public Widget {
	public:
		WIDGET_DEF(ScrollView)

		//ScrollView
		void set_scrollable(Scrollable::ArgPtr contents);
		void set_contents(Widget::ArgPtr contents);
		void scroll(int pixels);
		Point scroll_position();

		//Widget
		void calculate_layout() override;
		void on_child_added(const std::shared_ptr<Widget>& child) override;
		Dimensions preferred_size() override;
		void do_repaint(const UI::DrawContext& ctx) override;
		bool on_mouse_move(Pond::MouseMoveEvent evt) override;
		bool on_mouse_scroll(Pond::MouseScrollEvent evt) override;
		bool on_mouse_button(Pond::MouseButtonEvent evt) override;
		void on_layout_change(const Rect& old_rect) override;

	private:
		explicit ScrollView();

		Scrollable::Ptr _scrollable = nullptr;
		Point _scroll_position = {0, 0};
		Rect scrollbar_area;
		Rect handle_area;
		bool dragging_scrollbar = false;
	};
}


#endif //DUCKOS_LIBUI_SCROLLVIEW_H
