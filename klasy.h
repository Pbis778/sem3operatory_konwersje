#include <cmath>
#include <string>
#include <vector>


class Punkt
{
	double m_x = 0.0, m_y = 0.0;
public:
	void setXY(double x, double y)
	{
		m_x = x;
		m_y = y;
	}
	double getX() const { return m_x; }
	double getY() const { return m_y; }
	Punkt(double x, double y)
		:m_x(x), m_y(y)
	{}
};

class Kolo
{
	double m_promien = 1.0;
	Punkt m_srodek;
public:
	void setPromien(double r)
	{
		m_promien = (r > 0) ? r : 0;
	}
	void setSrodek(Punkt p)
	{
		m_srodek = p;
	}
	double getPromien() const { return m_promien; }
	Punkt getSrodek() const { return m_srodek; }
	Kolo(Punkt sr, double r)
		: m_srodek(sr), m_promien(r)
	{}
};

class Kwadrat
{
	Punkt m_lewy_dolny, m_prawy_gorny;
public:
	void setRogi(Punkt ld, Punkt pg)
	{
		m_lewy_dolny = ld;
		m_prawy_gorny = pg;
	}
	Punkt getLewyDolny() const { return m_lewy_dolny; }
	Punkt getPrawyGorny() const { return m_prawy_gorny; }
	Kwadrat(Punkt ld, Punkt pg)
		:m_lewy_dolny(ld), m_prawy_gorny(pg)
	{}
};

class Wektor
{
	double m_dx = 0.0, m_dy = 0.0;
public:
	void setDXY(double dx, double dy)
	{
		m_dx = dx;
		m_dy = dy;
	}
	double getDX() const { return m_dx; }
	double getDY() const { return m_dy; }
	double dlugosc() const { return sqrt(m_dx*m_dx + m_dy*m_dy); }
	Wektor(double dx, double dy)
		:m_dx(dx), m_dy(dy)
	{}
};

void main(void)
{
	Kolo({ 1.0, 2.0 }, 5.0);
	Kwadrat({ 3.0,5.0 }, { 6.0,7.0 });
}