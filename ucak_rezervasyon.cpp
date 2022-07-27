#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


class Bilet
{
private:
    string mevcutKonum, hedef;
    int rezerveKoltuk, biletNo;;
public:

    Bilet (string mKonum, string mhedef,  int koltuk, int bilet)
    {
        mevcutKonum = mKonum;
        hedef = mhedef;
        rezerveKoltuk = koltuk;
        biletNo = bilet;
    }

    string getKonum()
    {
        return mevcutKonum;
    }

    void setKonum(string fUcus)
    {
        mevcutKonum = fUcus;
    }

    string getHedef()
    {
        return hedef;
    }

    void setHedef(string fHedef)
    {
        hedef = fHedef;
    }

    int getKoltukRezerve()
    {
        return rezerveKoltuk;
    }

    void setKoltuk(int fKoltuk)
    {
        rezerveKoltuk = fKoltuk;
    }

    int getBiletNo()
    {
        return biletNo;
    }

    void setBiletNo(int c_bilet)
    {
        biletNo = c_bilet;
    }


};



class Yolcu
{
private:
    string isim, soyisim, kimlikNo;

public:
    vector <Bilet> biletler;


    Yolcu(string _isim, string _Soyisim, string _KimlikNo)
    {
        isim = _isim;
        soyisim = _Soyisim;
        kimlikNo = _KimlikNo;
    }

    string getIsim()
    {
        return isim;
    }

    void setIsim(string c_isim)
    {
        isim = c_isim;
    }

    string getSoyisim()
    {
        return soyisim;
    }

    void setSoyisim(string c_Soyisim)
    {
        soyisim = c_Soyisim;
    }

    string getTcNo()
    {
        return kimlikNo;
    }

    void setTcNo(string c_TCNo)
    {
        kimlikNo = c_TCNo;
    }



};



int setKoltukRezerve()
{

    int a,b, koltuk[42];

    for (b=1; b<=30;b++)
    {
        koltuk[b]=0;
    }

    srand(time(0));
    for ( a=0;a<40; a++ )
    {
        b = (rand  () %40 +1) ;
        koltuk[b]=-1;
    }

    cout << "\n\n\t   Mevcut kullanilabilir koltuklar" << endl;

    for(b=1;b<=40;b++)
    {
        if (koltuk[b]>=0)
        {
            cout << b << endl;
        }
    }

    cout << "\n\n\t   Secmek istediginiz koltuk no: " << endl;

    cin >> b;

    return b;



}


void ucusYazdir(Yolcu y,int biletsayisi)
{

    cout << "\t\t Bilet Bilgileriniz" << endl << endl;
    cout << "Isim: " << y.getIsim() << "\nSoyisim: " << y.getSoyisim()  << "\nTC Kimlik No: " << y.getTcNo() <<endl;
    cout << "Ucus Bilgileriniz: "<< "\n\n";
    for(int x = 0; x < biletsayisi; x++)
    {
        cout << "\tUcus: " << x+1 << "\n";
        cout << "Bilet No:" << y.biletler[x].getBiletNo() << endl;
        cout << "Kalkis: " << y.biletler[x].getKonum() << endl;
        cout << "Varis: " << y.biletler[x].getHedef() << endl;
        cout << "Koltuk no: " << y.biletler[x].getKoltukRezerve() << "\n\n";
    }



}


class Yonetici
{

public:
    static const string kullaniciAdi;
    static const int password;


    static void yolculariGoruntule()
    {
        fstream kayitdosyasi;

        kayitdosyasi.open("ucuskayitlari.txt", ios::in);

        if (!kayitdosyasi)
        {
            cout << "Dosyaniz acilmamistir";
        } else {
            cout << "Dosyaniz acilmistir\n";

            string str, dosyaicerigi;

            while (getline(kayitdosyasi, str)) {
                dosyaicerigi += str;
                dosyaicerigi.push_back('\n');
            }
            cout << dosyaicerigi;

            kayitdosyasi.close();
        }

    }



};

const string Yonetici::kullaniciAdi {"Umeyr"};
const int Yonetici::password = 199813;


int randTicketNoGenerator()
{
    int ucusno = 999;

    srand(time(0));

    return ucusno + (rand  () %1000 +1);

}


int main() {


    int giristercih;
    cout << "\t\t*     Uygun Bilete Hos Geldiniz       *" << endl;
    cout << "\t\t*1. Yonetici Girisi                   *" << endl;
    cout << "\t\t*2. Musteri Girisi                    *" << endl;
    cout << "Tercihiniz: ";
    cin >> giristercih;


    if (giristercih == 1)
    {
        string yoneticiAd;
        int yoneticiSifre;
        cout << "\tYonetici kullanici adi girin: ";
        cin >> yoneticiAd;
        cout << "\tYonetici sifresini girin: ";
        cin >> yoneticiSifre;

        if (yoneticiAd == Yonetici::kullaniciAdi && yoneticiSifre == Yonetici::password)
        {
            int yoneticiTercih;
            cout << "\tYonetici arayuzune hos geldiniz, bu panel altindan tum yolculari goruntuleyebilirsiniz" << endl;
            cout << "1. Yolculari Goruntule " << endl;
            cout << "2. Cikis yap " << endl;
            cout << "Tercihiniz: ";
            cin >> yoneticiTercih;

            if (yoneticiTercih == 1)
            {
                string dosyaTercih;
                cout << "\nKayit dosyasini acmak istiyor musunuz (y/n): ";
                cin >> dosyaTercih;

                if (dosyaTercih == "y")
                {
                    Yonetici::yolculariGoruntule();
                }
            }
        }
        else
        {
            cout << "Yanlis kullanici adi ve sifre girdiniz: " << endl;
        }
        return 0;
    }


    int yolcuSayisi = 0, y = 1;


        cout << "Bilet almak istediginiz yolcu sayisini giriniz: " << endl;
        cin >> yolcuSayisi;

        string _isim[yolcuSayisi], _soyisim[yolcuSayisi], _tcNo[yolcuSayisi];

        int _biletNo[yolcuSayisi];



        for (int x = 0; x < yolcuSayisi; x++)
        {
            cout <<  y << " No'lu yolcu icin isim girin: ";
            cin >> _isim[x];

            cout <<  y << " No'lu yolcu icin soyisim girin: ";
            cin >> _soyisim[x];

            cout <<  y << " No'lu yolcu icin TC kimlik no girin: ";
            cin >> _tcNo[x];

            _biletNo[x] = randTicketNoGenerator();

            cout << "\n\n";

            y++;
        }

        vector <Yolcu> yolcular;

        for(int x = 0; x < yolcuSayisi; x++)
        {
            Yolcu y1(_isim[x],_soyisim[x],_tcNo[x]);
            yolcular.push_back(y1);
        }


        int biletsayisi;

        cout << "Ucus Tercih kismina hos geldiniz" << endl;

        cout << "Lutfen kac adet bilet satin alacaginizi giriniz: " << endl;

        cin >> biletsayisi;

        string konum[biletsayisi], hedef[biletsayisi];

        for (int x = 0; x < biletsayisi; x++)
        {
            cout <<  x+1 << " No'lu bilet icin kalkis konumunu girin: ";
            cin >> konum[x];

            cout <<  x+1 << " No'lu bilet icin varis noktasini girin: ";
            cin >> hedef[x];

            cout << "\n\n";
        }



        for (int y = 0; y < yolcuSayisi; y++)
        {
            for(int x = 0; x < biletsayisi; x++)
            {
                Bilet b1(konum[x],hedef[x],0,randTicketNoGenerator()+x);
                yolcular[y].biletler.push_back(b1);
            }
        }



        cout << "*********    Koltuk Rezerve Etme Kismina Hos Geldiniz    *********" << "\n\n\n";

        for (y = 0; y < yolcuSayisi; y++)
        {
            cout << y+1 << " No'lu yolcunun ";
            {
                for(int x = 0; x < biletsayisi; x++)
                {
                    cout << x+1 << " No'lu bileti icin koltuk tercihiniz: " << endl;
                    yolcular[y].biletler[x].setKoltuk(setKoltukRezerve());
                }
            }

        }



    ucusYazdir(yolcular[0],biletsayisi);

    char ayrilma;
    cout << "Ayrilmak istediginiz ucus var mi? (y/n) ";
    cin >> ayrilma;

    if(ayrilma == 'y')
    {
        int iptalBiletno;
        cout << "Ayrilmak istediginiz ucus no girin: " << endl;
        cin >> iptalBiletno;

    }



    return 0;
}