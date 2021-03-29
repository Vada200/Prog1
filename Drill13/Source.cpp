
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	int winx = 800;
	int winy = 1000;
	Simple_window win{ Point{100, 100}, winx, winy, "Sample Text" };

	int x_size = win.x_max();   // get the size of our window
	int y_size = win.y_max();

	int x_grid = 100;
	int y_grid = 100;


	Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)
		grid.add(Point{ x,0 }, Point{ x,y_size - 200 });  // vertical line

	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point{ 0,y }, Point{ x_size,y });  // horizontal line


	win.attach(grid);

	Graph_lib::Rectangle négyzet{ Point{0, 0}, 100, 100 };
	négyzet.set_fill_color(Color::red);
	win.attach(négyzet);
	Graph_lib::Rectangle négyzet2{ Point{100, 100 }, 100, 100
	};
	négyzet2.set_fill_color(Color::red);
	win.attach(négyzet2);

	Vector_ref<Graph_lib::Rectangle> vr;

	for (int i = 0; i < 8; ++i) {
		vr.push_back(new Graph_lib::Rectangle{ Point{i * 100,i * 100},100,100 });
		vr[i].set_fill_color(Color::red);
		win.attach(vr[i]);
	}
	///////////////////////////

	Image p1{ Point{300,100}, "rsz_dipper.jpg" };
	win.attach(p1);
	Image p2{ Point{600,200}, "rsz_dipper.jpg" };
	win.attach(p2);
	Image p3{ Point{0,400}, "rsz_dipper.jpg" };
	win.attach(p3);
	Image p4{ Point{400,600}, "rsz_dipper.jpg" };
	win.attach(p4);
	
	Image p5{ Point{0, 0}, "rsz_dipper2.jpg" };
	win.attach(p5);

	win.wait_for_button();

	int sor = 0;
	while (true)
	{
		for (int i = 0; i < 7; i++)
		{
			p5.move(100, 0);
			win.wait_for_button();
			sor++;
		}
		
		if (sor == 7)
		{
			sor = 0;
			p5.move(-700, 100);
		}
		
		win.wait_for_button();
	}
	win.wait_for_button();
}