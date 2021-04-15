#include "Simple_window.h""
#include "Graph.h"
//inline talán ((törzs beillesztés)

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); } //slope - lényegében fenti method-ra dõl el

int main()
{
//-------axis-------
	using namespace Graph_lib;

	int xmax = 600;
	int ymax = 600;

	Simple_window win{ Point{100, 100}, xmax, ymax, "Function graphs" };

	int x_orig = 300; //kiinduló pont
	int y_orig = 300;

	Point origo{ x_orig, y_orig };

	int xlength = 400;
	int ylength = 400;

	int xscale = 25; 
	int yscale = 25;



	// length/scale = behúzások száma

	Axis x{ Axis::x, Point {100, y_orig}, xlength, xlength / xscale, "1 == 20 pixels" };
	Axis y{ Axis::y, Point {x_orig, ylength + 100}, ylength, ylength / yscale, "1 == 20 pixels" }; //+ 20 hogy beférjen a képernyõr
	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

//-------functions--------

	int n_points = 400;

	int rmin = -10; //fv-ek hossza
	int rmax = 11;

	xscale = 20;
	yscale = 20;

	Function s(one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sl(slope, rmin, rmax, origo, n_points, xscale, yscale);

	win.attach(s);
	win.attach(sl);

	Text label(Point(100,385), "x/2");

	win.attach(label);

	Function sq(square, rmin, rmax, origo, n_points, xscale, yscale);
	win.attach(sq);

	Function cosine(cos, rmin, rmax, origo, n_points, xscale, yscale);
	cosine.set_color(Color::blue);
	win.attach(cosine);

	Function sloping_cosine(sloping_cos, rmin, rmax, origo, n_points, xscale, yscale);
	win.attach(sloping_cosine);


	win.wait_for_button();
}
