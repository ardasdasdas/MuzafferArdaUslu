/**
* @author	: Muzaffer Arda Uslu -> e-mail -> usluarda60@icloud.com
* @date		: 11 Ekim 2019 Cuma
* @brief	: Bu kod Veri Yap�lar� Lab 1 icin yaz�lm�� bir koddur. Basit bir ogrenci bilgi sistemi kodudur.
*/
#include<iostream>
#include<string>
#include<ctime>
#include<conio.h>//_getch() fonksiyonunu kullanmak icin eklendi.
#include<iomanip>//setw() fonksiyonu ve left komutunu kullanmak icin eklendi.
#include<locale.h>//Koda T�rk�e karakterleri eklemek icin eklendi.
using namespace std;
struct liste {
	int OgrNo;
	string isim;
	int Not;
};
int ogrenciSayisi, i, j, k, min, mak;
double ort = 0;
/**
* @brief	: Bu fonksiyon girilen ogrenci sayisi kadar rastgele isim, ogrenci numarasi ve not uretir.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void RastgeleOgrenci(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencileri duzgun bir sekilde ekrana yazdirir. Menu fonksiyonunun icerisinde calisir.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void listele(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden numarasi girilen ogrencinin notunu degistirmemizi saglar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void degistir(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden hangi ogrenci(ler)nin en yuksek ve en dusuk not aldigini bulur ve not ortalamasini hesaplar.
* @param	: Pointer struct, ogrenci sayisi, minimum, maksimum ve ortalama parametrelerini icerir.
*/
void min_mak_ort_Hesaplama(struct liste *ogrenci, int ogrenciSayisi, int &min, int &mak, double &ort);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden hangi ogrenci(ler)nin en yuksek ve en dusuk not aldigini bulur ve not ortalamasini ekrana yazdirir.
* @param	: Pointer struct, ogrenci sayisi, minimum, maksimum ve ortalama parametrelerini icerir.
*/
void min_mak_ort_Yazd�rma(struct liste *ogrenci, int &ogrenciSayisi, int &min, int &mak, double &ort);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerini notlarina gore buyukten kucuge dogru siralar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void kabarcik_siralama(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden, kullanicidan alinan k. en buyuk sayiyi hesaplar ve ekrana yazdirir. Ayrica bu fonksiyon icerisine buuble_sort() fonksiyonunu cagirir.
* @param	: Pointer struct, ogrenci sayisi ve k parametrelerini icerir.
*/
void k_en_buyuk_hesaplama_ve_yazdirma(struct liste *ogrenci, int &ogrenciSayisi, int k);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerde en buyuk, en kucuk not alan(lar)i, not ortalamalarini ve k. en buyuk nota erismemizi saglar. Ayrica bu fonksiyon min_mak_ort_Yazd�rma() ve k_en_buyuk_hesaplama_ve_yazdirma() fonksiyonlarini icerir.
* @param	: Pointer struct, ogrenci sayisi ve k parametrelerini icerir.
*/
void istatistik(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerin bilgileri uzerinde hangi islemi yapacagimiza erismemizi saglar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void menu(struct liste *ogrenci, int &ogrenciSayisi);
int main()
{
	system("color 30");//Ekran� a��k mavi yapmak i�in yaz�ld�.
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	cout << "��renci say�s�n� giriniz: ";
	cin >> ogrenciSayisi;
	if (ogrenciSayisi == 0)//��renci say�s�n�n tam say� bir de�er olmas� gerekti�i icin yanl��l�kla tam say� d���nda bir girdi al�nmas� engellenmesi ad�na if else yap�s� kullan�ld�.
	{
		cout << "Hatal� giri�." << endl;
		_getch();
		exit(0);
	}
	else
	{
		liste *ogrenci = new liste[ogrenciSayisi];//Mevcut ��renci say�s� bilinmedi�i icin haf�zada fazla yer tutumamak ad�na struct dinamik olark olu�turuldu.
		RastgeleOgrenci(ogrenci, ogrenciSayisi);
		menu(ogrenci, ogrenciSayisi);
	}
	system("pause");
}
void RastgeleOgrenci(struct liste *ogrenci, int &ogrenciSayisi)
{
	static const string Alfabe = "abcdefg�h�ijklmnopqrs�tuv�wxyz";//Rastgele harf alabilmek icin alfabe sabit bir stringe yaz�ld�.
	string rastgeleHarf = "", str;
	for (i = 0; i < ogrenciSayisi; i++)
	{
		for (j = 0; j < rand() % 25; j++)//Kac harfli isim olaca�� rastgele �retildi.
		{
			rastgeleHarf += Alfabe[rand() % Alfabe.size()];
		}
		ogrenci[i].isim = rastgeleHarf;

		if (ogrenci[i].isim == "")
			i--;
		rastgeleHarf = "";
	}
	ogrenci[0].OgrNo = rand() % 10000;
	for (i = 1; i < ogrenciSayisi; i++)
	{
		ogrenci[i].OgrNo = ogrenci[i - 1].OgrNo + 1;

	}
	for (i = 0; i < ogrenciSayisi; i++)
	{
		ogrenci[i].Not = rand() % 99 + 1;
	}
}
void listele(struct liste *ogrenci, int &ogrenciSayisi)
{
	cout << "\t******��renci Listesi******\n\n";
	cout << left << setw(30) << "�sim";
	cout << left << setw(30) << "��renci No";
	cout << left << setw(30) << "Not" << endl;
	cout << left << setw(30) << "-----------";
	cout << left << setw(30) << "-----------";
	cout << left << setw(30) << "-----------";

	for (int i = 0; i < ogrenciSayisi; i++)
	{
		cout << endl;
		cout << left << setw(30) << ogrenci[i].isim;
		cout << left << setw(30) << ogrenci[i].OgrNo;
		cout << left << setw(30) << ogrenci[i].Not;
	}
	cout << endl;
}
void degistir(struct liste *ogrenci, int &ogrenciSayisi)
{
	cout << "\t******De�i�tir Men�s�******\n\n";
	listele(ogrenci, ogrenciSayisi);
	int OgrenciNo, yeniNot;
	cout << "Ogrenci no giriniz: ";
	cin >> OgrenciNo;
	if (cin.fail())
	{
		cout << "Hatal� giri�! Program sonlan�yor." << endl << endl;
		_getch();
		exit(0);

	}
	for (i = 0; i < ogrenciSayisi; i++)
	{
		if (ogrenci[i].OgrNo == OgrenciNo)
		{
			cout << ogrenci[i].OgrNo << "(" << ogrenci[i].isim << ")" << "��rencisi i�in yeni notu (" << ogrenci[i].Not << ") giriniz: ";
			cin >> yeniNot;
			if (yeniNot > 100)
			{
				system("color A0");//Ekran� ye�il yapmak i�in yaz�ld�.
				cout << endl << "Bonusun s�n�r� yok :)" << endl;
			}
			if (yeniNot < 0)
			{
				system("color 40");//Ekran� k�rm�z� yapmak i�in yaz�ld�.
				cout << endl << "Puan k�rman�n s�n�r� yok!" << endl;
			}
			ogrenci[i].Not = yeniNot;
			break;
		}
		else if (i == ogrenciSayisi - 1)
		{
			cout << "Hatal� numara girdiniz. L�tfen tekrar giriniz: " << endl;
			cin >> OgrenciNo;
			i = 0;
		}
	}
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden hangi ogrenci(ler)nin en yuksek ve en dusuk not aldigini bulur ve not ortalamasini hesaplar.
* @param	: Pointer struct, ogrenci sayisi, minimum, maksimum ve ortalama parametrelerini i�erir.
*/
void min_mak_ort_Hesaplama(struct liste *ogrenci, int ogrenciSayisi, int &min, int &mak, double &ort)
{
	min = ogrenci[0].Not;
	mak = ogrenci[0].Not;

	for (i = 0; i < ogrenciSayisi; i++)
	{
		ort += ogrenci[i].Not;
		if (mak < ogrenci[i].Not)
		{
			mak = ogrenci[i].Not;
		}
		if (min > ogrenci[i].Not)
		{
			min = ogrenci[i].Not;
		}
	}
	ort /= float(ogrenciSayisi);
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden hangi ogrenci(ler)nin en yuksek ve en dusuk not aldigini bulur ve not ortalamasini ekrana yazdirir.
* @param	: Pointer struct, ogrenci sayisi, minimum, maksimum ve ortalama parametrelerini i�erir.
*/
void min_mak_ort_Yazd�rma(struct liste *ogrenci, int &ogrenciSayisi, int &min, int &mak, double &ort)
{
	min_mak_ort_Hesaplama(ogrenci, ogrenciSayisi, min, mak, ort);
	cout << "***************************************************" << endl;
	for (i = 0; i < ogrenciSayisi; i++)
	{
		if (ogrenci[i].Not == min)
			cout << "min -> " << min << "(" << ogrenci[i].OgrNo << " numaral� " << ogrenci[i].isim << " isimli ��renci)" << endl;
	}
	for (i = 0; i < ogrenciSayisi; i++)
	{
		if (ogrenci[i].Not == mak)
			cout << "mak -> " << mak << "(" << ogrenci[i].OgrNo << " numarali " << ogrenci[i].isim << " isimli ��renci)" << endl;
	}
	cout << "ort -> " << ort << endl << endl;
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerini notlarina gore buyukten kucuge dogru siralar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void kabarcik_siralama(struct liste *ogrenci, int &ogrenciSayisi)
{
	liste temp;
	for (int i = 1; i < ogrenciSayisi; i++)
	{
		for (int j = 0; j < ogrenciSayisi - i; j++)
		{
			if (ogrenci[j].Not < ogrenci[j + 1].Not)
			{
				temp = ogrenci[j];
				ogrenci[j] = ogrenci[j + 1];
				ogrenci[j + 1] = temp;
			}
		}
	}
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden, kullanicidan alinan k. en buyuk sayiyi hesaplar ve ekrana yazdirir. Ayrica bu fonksiyon icerisine buuble_sort() fonksiyonunu cagirir.
* @param	: Pointer struct, ogrenci sayisi ve k parametrelerini icerir.
*/
void k_en_buyuk_hesaplama_ve_yazdirma(struct liste *ogrenci, int &ogrenciSayisi, int k)
{
	cout << "k de�erini giriniz: ";
	cin >> k;
	if (k > ogrenciSayisi || k < 0)
	{
		cout << endl << "Girdi�iniz s�rada bir ��renci yoktur." << endl;
	}
	else
	{
		kabarcik_siralama(ogrenci, ogrenciSayisi);
		min_mak_ort_Hesaplama(ogrenci, ogrenciSayisi, min, mak, ort);
		cout << "Azalan s�ralamadaki " << k << ". not ->" << ogrenci[k - 1].Not << "(" << ogrenci[k - 1].OgrNo << " numaral� " << ogrenci[k - 1].isim << "'li(�) ��renci)" << endl;
		cout << endl;
	}
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerde en buyuk, en kucuk not alan(lar)i, not ortalamalarini ve k. en buyuk nota erismemizi saglar. Ayrica bu fonksiyon min_mak_ort_Yazd�rma() ve k_en_buyuk_hesaplama_ve_yazdirma() fonksiyonlarini icerir.
* @param	: Pointer struct, ogrenci sayisi ve k parametrelerini icerir.
*/
void istatistik(struct liste *ogrenci, int &ogrenciSayisi)
{
	char secim;
	cout << "\t******�statistik Menusu******\n\n";
	cout << "[1]-Se�enek-1 (en k���k, en b�y�k ve ortalama): " << endl;
	cout << "[2]-Se�enek 2 (k. en b�y�k): " << endl;
	secim = _getch();
	if (secim == '1')
	{
		min_mak_ort_Yazd�rma(ogrenci, ogrenciSayisi, min, mak, ort);
		ort = 0;
	}
	else if (secim == '2')
	{
		k_en_buyuk_hesaplama_ve_yazdirma(ogrenci, ogrenciSayisi, k);
		ort = 0;
	}
	else
	{
		system("cls");
		cout << endl << "Girdi�iniz de�erde bir se�enek bulunamad�." << endl;
	}

}/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerin bilgileri uzerinde hangi islemi yapacagimiza erismemizi saglar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void menu(struct liste *ogrenci, int &ogrenciSayisi)
{
	char secim;
	do {
		cout << "\t MEN� \n";
		cout << "\n\tListele - [L]";
		cout << "\n\tDe�i�tir - [D]";
		cout << "\n\t�statistik - [I]";
		cout << "\n\t��k�� - [Q]";
		cout << "\n\n Bir se�enek giriniz: ";
		secim = _getch();
		system("cls");
		if (secim == 'L' || secim == 'l')
			listele(ogrenci, ogrenciSayisi);
		else if (secim == 'D' || secim == 'd')
			degistir(ogrenci, ogrenciSayisi);
		else if (secim == 'I' || secim == 'i' || secim == '�')
			istatistik(ogrenci, ogrenciSayisi);
		else if (secim == 'Q' || secim == 'q')
			exit(0);
		else
		{
			cout << "\n\n Hatal� giri�!";
			secim = _getch();
			system("cls");
			menu(ogrenci, ogrenciSayisi);
		}
		cout << endl << "Men�ye d�nmek i�in bir tu�a bas�n�z." << endl;
		_getch();
		system("cls");
	} while (secim != 'Q' || secim != 'q');
}