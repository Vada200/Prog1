#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{100,100},600,400,"My window"};

	Axis xa {Axis::x, Point(50,320),300,30,"X tengely"};
	Axis ya {Axis::y, Point(50,320),300,30,"Y tengely"};

	xa.set_color(Color::dark_green);
	ya.set_color(Color::blue);

	Function sine {sin,0,100,Point{20,350},1000,5,5};
	sine.set_color(Color::red);

	Graph_lib::Polygon poly;
	poly.add(Point{350,50});
	poly.add(Point{250,200});
	poly.add(Point{450,200});
	
	poly.set_fill_color(Color::dark_blue);
	poly.set_style(Line_style::dot);


	Graph_lib::Rectangle tegla {Point{250,200},200,100};
	tegla.set_fill_color(Color::red);

	Circle kor {Point{350,150},30};
	kor.set_fill_color(Color::blue);

	Mark pont {Point{352,157},'X'};

	Image img {Point{350,300},"pointing.jpg"};

	Text szoveg {Point{200,40}, "Kellemes nekem eme rengeteg e. S ez, eszperente nyelven nem lehetetlen"};
	szoveg.set_font_size(20);
	szoveg.set_font(Font::times_bold_italic);

	win.attach(img);
	win.attach(tegla);
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(kor);
	win.attach(pont);
	win.attach(szoveg);
	win.wait_for_button();
}