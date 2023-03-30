#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;

class Tablet {// класс родитель
protected:
	string title;
	bool dirty;
public:

	Tablet() {//конструктор без параметров
		title = "title";
		dirty = 0;
		cout << "Tablet()" << endl;
	}

	Tablet(string title, bool dirty) {//конструктор с параметрами
		this->title = title;
		this->dirty = dirty;
		cout << "Tablet(string title, bool dirty)" << endl;
	}
	
	Tablet(const Tablet& tb) {//конструктор копирования 
		this->title = tb.title;
		this->dirty = tb.dirty;
		cout << "Tablet(const Tablet& tb)" << endl;
	}

	void print() {//функция вывода
		int size;
		size = title.length();
		cout << "|";
		for (int i = 0; i < size; i++) {
			cout << "-";
		}
		cout << "|" << endl;
		cout << "|";
		for (int i = 0; i < size; i++) {
			if (dirty) {
				cout << "?";
			}
			else {
				cout << title[i];
			}
		}
		cout << "|" << endl;
		cout << "|";
		for (int i = 0; i < size; i++) {
			cout << "-";
		}
		cout << "|" << endl;
		if (dirty) {
			cout << "Tablet is dirty" << endl;
		}
		else {
			cout << "Tablet is clear" << endl;
		}
	} 
	void clear() {//функция "Очистить"
		dirty = 0;
		cout << "Tablet is clear now" << endl;
	}
	~Tablet() { //деструктор
		cout << "~Tablet" << endl;
	}
};

class TabletDistanse : public Tablet {// класс наследник
protected:
	int distanse;
public:
	
	
	TabletDistanse():Tablet() {//конструктор без параметров
		distanse = 676;
		cout << "TabletDistanse()" << endl;
	}
	TabletDistanse(string title, bool dirty, int distanse) : Tablet(title,dirty) {//конструктор с параметрами
		this->distanse = distanse;
		cout << "TabletDistanse(string title, bool dirty, int distanse)" << endl;
	}
	TabletDistanse(const TabletDistanse& tb) {//конструктор копирования
		title = tb.title;
		dirty = tb.dirty;
		distanse = tb.distanse;
		cout << "TabletDistanse(const TabletDistanse& tb)" << endl;
	}
	~TabletDistanse() {//деструктор 
		cout << "~TabletDistanse" << endl; 
	}
	  
	void add_distanse(int n) {//добавление дистанции
		distanse += n;
	}

	void print() {//функция печати
		int size,sizeall;
		int sd;
		size = title.length();
		sizeall = size;
		string dist;
		dist = to_string(distanse);
		sd = dist.length();
		sizeall += sd;
		sizeall++;
		cout << "|";
		for (int i = 0; i < sizeall; i++) {
			cout << "-";
		}
		cout << "|" << endl;
		cout << "|";
		for (int i = 0; i < size; i++) {
			if (dirty) {
				cout << "?";
			}
			else {
				cout << title[i];
			}
		}
		cout << " ";
		for (int i = 0; i < sd; i++) {
			if (dirty) {
				cout << "?";
			}
			else {
				cout << dist[i];
			}
		}
		cout << "|" << endl;
		cout << "|";
		for (int i = 0; i < sizeall; i++) {
			cout << "-";
		}
		cout << "|" << endl;
		if (dirty) {
			cout << "Tablet is dirty" << endl;
		}
		else {
			cout << "Tablet is clear" << endl;
		}
	}
};

class Post {
protected:
	Tablet* tb;
	TabletDistanse* tbdist;
public:
	Post() {//конструктор без параметров
		tb = new Tablet;
		tbdist = new TabletDistanse;
		cout << "Post()" << endl;
	}
	Post(Tablet* tb, TabletDistanse* tbdist) {//конструктор с параметрами
		this->tb = tb;
		this->tbdist = tbdist;
		cout << "Post(Tablet* tb, TabletDistanse* tbdist)" << endl;
	}
	Post(const Post &Ps) {//конструктор копирования
		this->tb = new Tablet(*(Ps.tb));
		this->tbdist = new TabletDistanse(*(Ps.tbdist));
		cout << "Post(const Post &Ps)" << endl;
	}
	~Post() {//деструктор
		delete tb;
		delete tbdist;
		cout << "~Post" << endl;
	}
};

int main() {
	string st{ "Znak" };
	bool bl{ 1 };
	int nt{ 676 };
	cout << "Static:" << endl;
	Tablet tb1;//создание конструктором без параметров
	Tablet tb2(st,bl);//создание конструктором с параметрами
	Tablet tb3(tb1);//создание конструктором копирования
	tb1.print();
	tb2.print();
	tb2.clear();
	tb2.print();
	tb3.print();
	cout << "Dynamic:" << endl;
	Tablet* tb4 = new Tablet;//создание конструктором без параметров
	Tablet* tb5 = new Tablet(st,bl);//создание конструктором с параметрами
	Tablet* tb6 = new Tablet(*tb4);//создание конструктором копирования
	tb4->print();
	tb5->print();
	tb5->clear();
	tb5->print();
	tb6->print();
	delete tb4;
	delete tb5;
	delete tb6;
	//класс наследник
	cout <<"Nasledovanie:"<< endl;
	TabletDistanse* tb7 = new TabletDistanse;//создание конструктором без параметров
	TabletDistanse* tb8 = new TabletDistanse(st,bl,nt);//создание конструктором с параметрами
	TabletDistanse* tb9 = new TabletDistanse(*tb7);//создание конструктором копирования
	tb7->print();
	tb8->print();
	tb8->clear();
	tb8->print();
	tb9->Tablet::print();
	delete tb7;
	delete tb8;
	delete tb9;
	//Композиция
	cout << "Composition:" << endl;
	Tablet* tb = new Tablet();
	TabletDistanse* tbdist = new TabletDistanse();
	Post* p2 = new Post;
	Post* p = new Post(tb, tbdist);
	Post* p1 = new Post(*p);
	delete p;
	delete p1;
	delete p2;
	system("pause");
}