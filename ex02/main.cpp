#include <iostream>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}

// #include <iostream>
// #include <sstream>
// #include <string>
// #include <exception>
// #include <cstdlib>
// #include "Array.hpp"

// #define GREEN  "\033[32m"
// #define RED    "\033[31m"
// #define CYAN   "\033[36m"
// #define YELLOW "\033[33m"
// #define BOLD   "\033[1m"
// #define RESET  "\033[0m"

// static int g_pass = 0;
// static int g_fail = 0;

// static void title(const std::string &s)
// {
// 	std::cout << "\n" << BOLD << CYAN << "=== " << s << " ===" << RESET << std::endl;
// }

// static void check(bool ok, const std::string &name)
// {
// 	if (ok)
// 	{
// 		g_pass++;
// 		std::cout << GREEN << "  [ OK ] " << RESET << name << std::endl;
// 	}
// 	else
// 	{
// 		g_fail++;
// 		std::cout << RED << "  [FAIL] " << RESET << name << std::endl;
// 	}
// }

// // Retourne true si a[i] leve une exception
// template <typename A>
// static bool throwsAt(A &a, int i)
// {
// 	try
// 	{
// 		(void)a[i];
// 	}
// 	catch (std::exception &)
// 	{
// 		return true;
// 	}
// 	return false;
// }

// // Affiche un Array<T> : [ 1 2 3 ]
// template <typename T>
// static void show(const std::string &label, const Array<T> &a)
// {
// 	std::cout << YELLOW << "  " << label << " (size " << a.size() << ") : " << RESET << "[ ";
// 	for (unsigned int i = 0; i < a.size(); i++)
// 		std::cout << a[i] << " ";
// 	std::cout << "]" << std::endl;
// }

// // Classe qui compte ses instances vivantes (detecte les fuites / double delete)
// class Dummy
// {
// public:
// 	static int alive;
// 	int value;
// 	Dummy() : value(42) { alive++; }
// 	Dummy(const Dummy &o) : value(o.value) { alive++; }
// 	Dummy &operator=(const Dummy &o) { value = o.value; return *this; }
// 	~Dummy() { alive--; }
// };
// int Dummy::alive = 0;

// static void testDefaultConstructor()
// {
// 	title("1. Constructeur par defaut");
// 	Array<int> a;
// 	check(a.size() == 0, "size() == 0");
// 	check(throwsAt(a, 0), "a[0] leve une exception (tableau vide)");
// 	check(throwsAt(a, -1), "a[-1] leve une exception (tableau vide)");
// }

// static void testSizeConstructor()
// {
// 	title("2. Constructeur avec n (init par defaut)");
// 	Array<int> a(5);
// 	show("Array<int>(5)", a);
// 	bool zeros = true;
// 	for (unsigned int i = 0; i < a.size(); i++)
// 		if (a[i] != 0)
// 			zeros = false;
// 	check(a.size() == 5, "size() == 5");
// 	check(zeros, "tous les int valent 0");

// 	Array<double> d(3);
// 	show("Array<double>(3)", d);
// 	check(d[0] == 0.0 && d[1] == 0.0 && d[2] == 0.0, "tous les double valent 0.0");

// 	Array<char> c(3);
// 	check(c[0] == 0 && c[1] == 0 && c[2] == 0, "tous les char valent '\\0'");

// 	Array<bool> b(3);
// 	check(!b[0] && !b[1] && !b[2], "tous les bool valent false");

// 	Array<int *> p(3);
// 	check(p[0] == NULL && p[1] == NULL && p[2] == NULL, "tous les pointeurs valent NULL");

// 	Array<std::string> s(3);
// 	check(s[0].empty() && s[1].empty() && s[2].empty(), "toutes les std::string sont vides");

// 	Array<int> z(0);
// 	check(z.size() == 0, "Array(0) : size() == 0");
// 	check(throwsAt(z, 0), "Array(0) : a[0] leve une exception");
// }

// static void testAccessAndWrite()
// {
// 	title("3. Lecture / ecriture via []");
// 	Array<int> a(5);
// 	for (unsigned int i = 0; i < a.size(); i++)
// 		a[i] = (i + 1) * 10;
// 	show("apres ecriture", a);
// 	check(a[0] == 10 && a[4] == 50, "les valeurs ecrites sont relues");

// 	a[2] += 5;
// 	check(a[2] == 35, "a[2] += 5 fonctionne (operator[] renvoie une reference)");

// 	int &ref = a[1];
// 	ref = 999;
// 	check(a[1] == 999, "modification via une reference");
// }

// static void testOutOfBounds()
// {
// 	title("4. Acces hors limites");
// 	Array<int> a(5);
// 	check(!throwsAt(a, 0), "a[0] : pas d'exception");
// 	check(!throwsAt(a, 4), "a[size-1] : pas d'exception");
// 	check(throwsAt(a, 5), "a[size] leve une exception");
// 	check(throwsAt(a, 6), "a[size+1] leve une exception");
// 	check(throwsAt(a, 1000), "a[1000] leve une exception");
// 	check(throwsAt(a, -1), "a[-1] leve une exception");
// 	check(throwsAt(a, -2), "a[-2] leve une exception");

// 	std::cout << "  message de l'exception : ";
// 	try
// 	{
// 		a[42];
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << YELLOW << e.what() << RESET << std::endl;
// 	}
// }

// static void testConst()
// {
// 	title("5. Tableau const");
// 	Array<int> a(3);
// 	a[0] = 1; a[1] = 2; a[2] = 3;
// 	const Array<int> c(a);
// 	check(c[0] == 1 && c[1] == 2 && c[2] == 3, "lecture via const operator[]");
// 	check(c.size() == 3, "size() sur un const");
// 	check(throwsAt(c, 3), "const : a[size] leve une exception");
// 	check(throwsAt(c, -1), "const : a[-1] leve une exception");
// }

// static void testCopyConstructor()
// {
// 	title("6. Constructeur par copie (copie profonde)");
// 	Array<int> a(4);
// 	for (unsigned int i = 0; i < 4; i++)
// 		a[i] = i + 1;
// 	Array<int> b(a);
// 	show("original", a);
// 	show("copie   ", b);
// 	check(b.size() == a.size(), "meme taille");
// 	check(b[0] == 1 && b[3] == 4, "memes valeurs");

// 	b[0] = 100;
// 	check(a[0] == 1, "modifier la copie ne modifie PAS l'original");
// 	a[3] = 400;
// 	check(b[3] == 4, "modifier l'original ne modifie PAS la copie");
// 	show("original apres modifs", a);
// 	show("copie    apres modifs", b);

// 	Array<int> e;
// 	Array<int> e2(e);
// 	check(e2.size() == 0, "copie d'un tableau vide : size() == 0");

// 	Array<int> c = a; // syntaxe differente, meme constructeur
// 	check(c[3] == 400 && c.size() == 4, "Array<int> c = a; fonctionne");
// }

// static void testAssignment()
// {
// 	title("7. Operateur d'affectation");
// 	Array<int> a(3);
// 	a[0] = 7; a[1] = 8; a[2] = 9;

// 	Array<int> b(10);
// 	b = a;
// 	show("a", a);
// 	show("b = a", b);
// 	check(b.size() == 3, "b a pris la taille de a (10 -> 3)");
// 	check(b[0] == 7 && b[2] == 9, "b a pris les valeurs de a");
// 	b[0] = 0;
// 	check(a[0] == 7, "copie profonde : modifier b ne touche pas a");

// 	Array<int> big(8);
// 	for (unsigned int i = 0; i < 8; i++)
// 		big[i] = i;
// 	a = big;
// 	check(a.size() == 8 && a[7] == 7, "a (3) = big (8) : agrandissement");

// 	Array<int> empty;
// 	a = empty;
// 	check(a.size() == 0, "affecter un tableau vide : size() == 0");
// 	check(throwsAt(a, 0), "...et l'acces leve bien une exception");

// 	Array<int> s(3);
// 	s[0] = 1; s[1] = 2; s[2] = 3;
// 	Array<int> &self = s;
// 	s = self;
// 	check(s.size() == 3 && s[0] == 1 && s[2] == 3, "auto-affectation (s = s) ne casse rien");

// 	Array<int> x(2), y(2), z(2);
// 	z[0] = 5; z[1] = 6;
// 	x = y = z;
// 	check(x[0] == 5 && y[1] == 6, "affectation chainee x = y = z");
// }

// static void testOtherTypes()
// {
// 	title("8. Autres types");
// 	Array<std::string> s(3);
// 	s[0] = "Hello";
// 	s[1] = "42";
// 	s[2] = "Paris";
// 	show("Array<std::string>", s);
// 	Array<std::string> s2(s);
// 	s2[0] = "Bye";
// 	check(s[0] == "Hello", "std::string : copie profonde");

// 	Array<float> f(2);
// 	f[0] = 3.14f;
// 	f[1] = -1.5f;
// 	show("Array<float>", f);
// 	check(f[0] > 3.13f && f[0] < 3.15f, "float : lecture/ecriture");

// 	Array<char> c(3);
// 	c[0] = 'a'; c[1] = 'b'; c[2] = 'c';
// 	show("Array<char>", c);
// 	check(c[1] == 'b', "char : lecture/ecriture");

// 	Array<Array<int> > nested(2);
// 	nested[0] = Array<int>(3);
// 	nested[0][1] = 77;
// 	check(nested[0].size() == 3 && nested[0][1] == 77, "Array<Array<int> > fonctionne");
// 	check(nested[1].size() == 0, "...les sous-tableaux non touches sont vides");
// }

// static void testObjectLifetime()
// {
// 	title("9. Constructeurs / destructeurs (fuites, double delete)");
// 	check(Dummy::alive == 0, "au depart : 0 Dummy vivant");
// 	{
// 		Array<Dummy> a(5);
// 		std::cout << "  apres Array<Dummy>(5)  : " << Dummy::alive << " vivants" << std::endl;
// 		check(Dummy::alive == 5, "5 Dummy construits");
// 		check(a[0].value == 42, "constructeur par defaut de Dummy appele");

// 		Array<Dummy> b(a);
// 		std::cout << "  apres copie            : " << Dummy::alive << " vivants" << std::endl;
// 		check(Dummy::alive == 10, "la copie cree 5 nouveaux Dummy (copie profonde)");

// 		Array<Dummy> c(2);
// 		c = a;
// 		std::cout << "  apres c(2) = a         : " << Dummy::alive << " vivants" << std::endl;
// 		check(Dummy::alive == 15, "l'ancien contenu de c a bien ete libere");
// 	}
// 	check(Dummy::alive == 0, "fin de scope : 0 Dummy vivant (aucune fuite)");
// }

// static void testBig()
// {
// 	title("10. Gros tableau");
// 	const unsigned int N = 1000000;
// 	Array<int> a(N);
// 	for (unsigned int i = 0; i < N; i++)
// 		a[i] = i;
// 	Array<int> b(a);
// 	bool same = true;
// 	for (unsigned int i = 0; i < N; i++)
// 		if (a[i] != b[i])
// 			same = false;
// 	check(same, "1 000 000 d'elements copies correctement");
// 	check(throwsAt(a, N), "a[1000000] leve une exception");
// }

// static void testSubject()
// {
// 	title("11. Test du sujet (version courte)");
// 	const int MAX_VAL = 750;
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}
// 	bool same = true;
// 	for (int i = 0; i < MAX_VAL; i++)
// 		if (mirror[i] != numbers[i])
// 			same = false;
// 	check(same, "les valeurs sont conservees apres copies dans un scope");
// 	check(throwsAt(numbers, -2), "numbers[-2] leve une exception");
// 	check(throwsAt(numbers, MAX_VAL), "numbers[MAX_VAL] leve une exception");
// 	delete[] mirror;
// }

// int main()
// {
// 	std::cout << BOLD << "\n######## TESTS Array<T> ########" << RESET << std::endl;

// 	testDefaultConstructor();
// 	testSizeConstructor();
// 	testAccessAndWrite();
// 	testOutOfBounds();
// 	testConst();
// 	testCopyConstructor();
// 	testAssignment();
// 	testOtherTypes();
// 	testObjectLifetime();
// 	testBig();
// 	testSubject();

// 	std::cout << "\n" << BOLD << "######## BILAN ########" << RESET << std::endl;
// 	std::cout << GREEN << "  Reussis : " << g_pass << RESET << std::endl;
// 	if (g_fail)
// 		std::cout << RED << "  Echoues : " << g_fail << RESET << std::endl;
// 	else
// 		std::cout << GREEN << BOLD << "  Tout est OK !" << RESET << std::endl;
// 	std::cout << std::endl;
// 	return (g_fail ? 1 : 0);
// }
