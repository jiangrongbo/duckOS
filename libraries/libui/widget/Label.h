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

#ifndef DUCKOS_LIBUI_LABEL_H
#define DUCKOS_LIBUI_LABEL_H

#include "Widget.h"

namespace UI {
	class Label: public Widget {
	public:
		WIDGET_DEF(Label)

		//Label
		std::string label();
		void set_label(const std::string& new_label);
		Color color();
		void set_color(Color new_color);
		TextAlignment vertical_alignment();
		TextAlignment horizontal_alignment();
		void set_alignment(TextAlignment vertical, TextAlignment horizontal);
		Gfx::Font* font();
		void set_font(Gfx::Font* font);
		Dimensions padding();
		void set_padding(const Dimensions& padding);

		//Widget
		virtual Dimensions preferred_size() override;

	private:
		explicit Label(const std::string& label);

		//Widget
		void do_repaint(const DrawContext& ctx) override;

		std::string _label;
		Color _color;
		TextAlignment _v_alignment = CENTER;
		TextAlignment _h_alignment = CENTER;
		Gfx::Font* _font;
		Dimensions _padding = {0, 0};
	};
}

#endif //DUCKOS_LIBUI_LABEL_H
