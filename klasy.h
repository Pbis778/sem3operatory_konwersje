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

enum class TypPaczki
{
	zwykla,
	priorytetowa,
	ekspresowa,
};

class Paczka
{
	double m_waga;
	double m_wymiary[3];
	std::string m_adres;
	TypPaczki m_typ;
	double nieUjemna(double wart) noexcept
	{
		return (wart > 0) ? wart : 0;
	}
public:
	Paczka(double wg, double wys, double sz, double gl, std::string adr, TypPaczki typ)
	{
		setWaga(wg); setWymiary(wys, sz, gl); setAdres(adr), setTyp(typ);
	}
	void setWaga(double w) noexcept
	{
		m_waga = nieUjemna(w);
	}
	void setWymiary(double w, double sz, double gl) noexcept
	{
		m_wymiary[0] = nieUjemna(w);
		m_wymiary[1] = nieUjemna(sz);
		m_wymiary[2] = nieUjemna(gl);
	}
	//Seter przenosz¹cy  (argument adr jest lokaln¹ kopi¹, wiêc mo¿emy jej treœæ przenieœæ do pola m_adres)
	void setAdres(std::string adr) noexcept
	{
		m_adres = std::move(adr);
	}
	void setTyp(TypPaczki typ) noexcept
	{
		m_typ = typ;
	}
	double getWaga() const noexcept { return m_waga; }
	double getWysokosc() const noexcept { return m_wymiary[0]; }
	double getSzerokosc() const noexcept { return m_wymiary[1]; }
	double getGlebokosc() const noexcept { return m_wymiary[2]; }
	std::string getAdres() const noexcept { return m_adres; }
	TypPaczki getTyp() const noexcept { return m_typ; }
};

std::vector<Paczka> tworzTabliceTestowa()
{
	std::vector<Paczka> tablica =
	{
		{ 30.0, 0.4, 0.5, 0.6, "ul. ... Katowice ...", TypPaczki::zwykla },
		{ 20.0, 0.2, 0.5, 0.6, "ul. ... Bytom ...", TypPaczki::zwykla },
		{ 15.0, 0.2, 0.5, 0.6, "ul. ... Bytom ...", TypPaczki::priorytetowa },
		{ 20.0, 0.3, 0.3, 0.2, "ul. ... Szczecin ...", TypPaczki::zwykla },
		{ 120.0, 0.8, 1.5, 1.6, "ul. ... Gdansk ...", TypPaczki::zwykla },
		{ 0.5, 0.1, 0.2, 0.2, "ul. ... Poznan ...", TypPaczki::ekspresowa },
		{ 1.5, 0.2, 0.2, 0.2, "ul. ... Katowice ...", TypPaczki::ekspresowa },
		{ 11.5, 0.5, 1.2, 1.2, "ul. ... Katowice ...", TypPaczki::priorytetowa },
		// Dopisz jeszcze przynajmnej 10 przyk³¹dowych instancji.
	};
	return tablica;
}

