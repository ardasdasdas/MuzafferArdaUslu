/**
* @author	: Muzaffer Arda Uslu -> e-mail -> usluarda60@icloud.com |
* @date		: 4 Kasim 2019 Pazartesi
* @brief	: Bu kod Veri Yapilari Lab 3 icin yazilmis bir koddur. Basit bir Is Basvurusu kodudur. Class yapisi ve class icerisinde struct kullan�lm�st�r. Dizi yapisindan kuyruk olusturulmustur.
*/
#include<iostream>
#include"isBasvuruKuyrugu.h"
#include<conio.h>
#include<iomanip>.
#include<locale.h>
#include<Windows.h>
using namespace std;
int count;
Kuyruk K;//Bir kuyruk olu�turuldu.
/**
* @brief	: Bu fonksiyon, olu�turulan liste uzerinde hangi i�lemi yapacag�m�za erismemizi saglar.
*/
void menu()
{
	int secim;
	do {
		cout << "\t MEN� \n";
		cout << "\n\t[1] - Ba�vuru Ekle";
		cout << "\n\t[2] - Ba�vuru Sil";
		cout << "\n\t[3] - Ba�vurular� Listele";
		cout << "\n\t[4] - Basvuru Say�s�";
		cout << "\n\t[5] - Ba�vuru Ya� Ortalamas�";
		cout << "\n\t[6] - Ba�vuru Cinsisiyet Oran�";
		cout << "\n\t[7] - ��k��";
		cout << "\n\n Bir se�enek giriniz: ";
		cin >> secim;
		system("cls");
		if (secim <= 0 || secim > 9 || cin.fail())//Herhangi bir hatali giriste ana men�ye geri gidilmesi icin yaz�ld�.
		{
			cout << "Hatal� giri�! Men�ye y�nlendiriliyorsunuz..." << endl;
			Sleep(600);
			cout << "3" << endl;
			Sleep(600);
			cout << "2" << endl;
			Sleep(600);
			cout << "1" << endl;
			Sleep(600);
			system("cls");
			cin.clear();
			cin.ignore();
			menu();
		}
		else if (secim == 1)
		{
			if (K.doluMu())
				cout << "Kuyruk dolu." << endl;
			else
				K.isBasvurusuEkle();				
		}
		else if(secim == 2)
		{
			if (K.bosMu())
				cout << "Kuyruk bo�." << endl;
			else
				K.isBasvurusuSil();
		}
		else if (secim == 3)
		{
			if (K.bosMu())
				cout << "Kuyruk bo�." << endl;
			else
			{
				K.isBasvurusuListele();
			}
		
		}
		else if (secim == 4)
		{
			K.isBasvuruSayisi();
		}
		else if (secim == 5)
		{
			if (K.bosMu())
				cout << "Kuyruk bo�." << endl;
			else
				cout << "Ba�vuranlar�n ya� ortalamas� -> " << K.isBasvurusuYasOrt() << endl;
		}
		else if (secim == 6)
		{
			if (K.bosMu())
				cout << "Kuyruk bo�." << endl;
			else
				K.isBasvurusuCinsiyetOrani();
		}
		else if (secim == 7)
			exit(0);
		cout << endl << "Men�ye d�nmek i�in bir tu�a bas�n�z." << endl;
		_getch();
		system("cls");
	} while (secim != 'Q' || secim != 'q');
}
int main()
{
	setlocale(LC_ALL, "Turkish");//Turkce karakterleri eklemek i�in eklendi.
	menu();
	system("pause");
}