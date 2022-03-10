#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>


#define MAX_HAT 100


typedef struct {
	int id;
	float x1,y1,x2,y2;
}indirici;

typedef struct {
	int id;
	int tip;
	float x1,y1,x2,y2;
}musteri;

typedef struct {
	int id;
	float x1,y1,x2,y2;
}hat;


/*
void write (const char* name,string desc){
	ofstream fileW(name);
	//Böylede yazýlabilir;
	//fileW.open("dosya1.txt");
	
	fileW << desc;
	fileW << endl;
	
	fileW.close();
	
}


string hatOku (const char* name){
	
	ifstream fileR(name);
	string line;
	
	getline(fileR, line);
	//Bu þekilde kullanýmda kelime kelime alýnýr.
	//fileR>>line;
	//cout<<line<<endl;
	//Sürekli kelime olarak alýr.
	//while(fileR>>line){}
	//while(!fileR.eof()){}
	
	//Böyle kullanýrsan sonuna kadar okur.
	//while(getline(fileR, line)){}
	
	fileR.close();
	return line;
}
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

float kusUcusuMesafeHesapla (float x1,float y1,float x2,float y2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void tekHatBilgisi (int bul){
	
	tekhatbilgisi:
	
	hat ht;
	int kontrol=0;
	string kelime;
	
	ifstream fileR("test.txt");
	
	
	while(fileR>>kelime)
		if(kelime=="HAT_ID")
			break;
	
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	
	while(fileR>>ht.id>>ht.x1>>ht.y1>>ht.x2>>ht.y2){
		if(bul==ht.id){
			cout<<endl<<"Hat "<<ht.id<<"\tKordinantlar ( "<<ht.x1<<" / "<<ht.y1<<" / "<<ht.x2<<" / "<<ht.y2<<" ).";
			kontrol=1;
			break;
		}
	}
	
	if(kontrol==0)
		cout<<endl<<"Girdiginiz id'ye karsilik gelen hat bulunamadi. Tekrar giriniz. Ana menu için 0 giriniz.\t";
	else
		cout<<endl<<endl<<"Yeni bir arama yapmak icin id giriniz. Ana menu icin 0 giriniz.\t";	
		
	cin>>bul;
	if(bul!=0)	
	goto tekhatbilgisi;	
	
	fileR.close();	
	
	
}

void hatBilgileri (){
	system("CLS");
	hat ht;
	int hatSayisi=0,tekid;
	float hatUzunlugu=0.0;
	
	ifstream fileR("test.txt");
	string kelime;
	
	
	while(fileR>>kelime)
		if(kelime=="HAT_ID")
			break;
	
	
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	
	while(fileR>>ht.id>>ht.x1>>ht.y1>>ht.x2>>ht.y2){
		//cout<<endl<<"Hat_id:"<<ht.id<<"\t"<<ht.x1<<"\t"<<ht.y1<<"\t"<<ht.x2<<"\t"<<ht.y2;
		hatSayisi++;
		hatUzunlugu+=kusUcusuMesafeHesapla(ht.x1,ht.y1,ht.x2,ht.y2);
	}	
	
	fileR.close();	
	
	cout<<endl<<"Toplam hat sayisi: "<<hatSayisi<<endl;
	cout<<"Toplam hat uzunlugu: "<<hatUzunlugu<<" metre"<<endl;
	
	cout<<endl<<endl<<endl<<"Ozel hat aramak isteiyorsaniz id giriniz.Ana menu icin 0 giriniz:";
	cin>>tekid;
	
	if(tekid!=0)
		tekHatBilgisi(tekid);
	
}

void tekMusteriBilgisi (int bul){
	
	tekmusteribilgisi:
	musteri mst;
	int kontrol=0;
	
	ifstream fileR("test.txt");
	string kelime;
	
	
	while(fileR>>kelime)
		if(kelime=="MUSTERI_ID")
			break;
	
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	
	while(fileR>>mst.id>>mst.tip>>mst.x1>>mst.y1>>mst.x2>>mst.y2){
		if(bul==mst.id){
			cout<<endl<<"Musteri "<<mst.id;
			switch(mst.tip){
				case 1:cout<<", Mesken,";
					break;
				case 2:cout<<", Ticari,";
					break;
				case 3:cout<<", Sanayi,";
					break;
			}
			cout<<"\tKordinantlar ( "<<mst.x1<<" / "<<mst.y1<<" / "<<mst.x2<<" / "<<mst.y2<<" ).";
			kontrol=1;
			break;
		}
	}
	
	if(kontrol==0)
		cout<<endl<<"Girdiginiz id'ye karsilik gelen musteri bulunamadi. Tekrar giriniz. Ana menu için 0 giriniz.\t";
	else
		cout<<endl<<endl<<"Yeni bir arama yapmak icin id giriniz. Ana menu icin 0 giriniz.\t";	
		
	cin>>bul;
	if(bul!=0)	
	goto tekmusteribilgisi;	
	
	fileR.close();	
	
	
}

void musteriBilgileri (){
	system("CLS");
	musteri mst;
	int musteriSayisi=0,musteriTipi[3]={0,0,0},tekid;
	
	ifstream fileR("test.txt");
	string kelime;
	
	
	while(fileR>>kelime)
		if(kelime=="MUSTERI_ID")
			break;
	
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	
	while(fileR>>mst.id>>mst.tip>>mst.x1>>mst.y1>>mst.x2>>mst.y2){
		//cout<<endl<<"Musteri_id:"<<id<<"\t"<<x1<<"\t"<<y1<<"\t"<<x2<<"\t"<<y2;
		musteriSayisi++;
		musteriTipi[mst.tip-1]++;
	}	
	
	fileR.close();	
	
	cout<<endl<<"Toplam musteri sayisi: "<<musteriSayisi<<endl;
	cout<<musteriTipi[0]<<" adet mesken, "<< musteriTipi[1] << " adet ticari, " << musteriTipi[2] << " adet sanayi."<< endl;
	
	cout<<endl<<endl<<endl<<"Ozel musteri aramak isteiyorsaniz id giriniz.Ana menu icin 0 giriniz:";
	cin>>tekid;
	
	if(tekid!=0)
		tekMusteriBilgisi(tekid);
	
}

void indiriciBilgileri (){
	system("CLS");
	
	indirici ind;
		
	ifstream fileR("test.txt");
	string kelime;

	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	
	fileR>>ind.id>>ind.x1>>ind.y1>>ind.x2>>ind.y2;
		cout<<endl<<"Indirici_id:"<<ind.id<<"\t x1:"<<ind.x1<<"\t y1:"<<ind.y1<<"\t x2:"<<ind.x2<<"\t y2:"<<ind.y2;
	
	fileR.close();	
	
	cout<<endl<<endl<<endl<<"Ana menu icin herhangi bir tusa basiniz.";
	getch();
	
}

void musteriIndiriciMesafe (){
	system("CLS");
	
	musteri mst;
	indirici ind;
	
	string kelime;
	
	
	ofstream fileW("musteri_indirici_mesafesi.txt");
	ifstream fileR("test.txt");
	
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	
	fileR>>ind.id>>ind.x1>>ind.y1>>ind.x2>>ind.y2;
	
	
	
	while(fileR>>kelime)
		if(kelime=="MUSTERI_ID"){
			fileW<<kelime<<"\t";
			break;
		}
	
	fileR>>kelime;
	fileW<<kelime<<"\t";
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileW<<"KUS_UCUSU_MESAFE\t\n";
	
	while(fileR>>mst.id>>mst.tip>>mst.x1>>mst.y1>>mst.x2>>mst.y2){
		//cout<<endl<<"Musteri_id:"<<id<<"\t"<<x1<<"\t"<<y1<<"\t"<<x2<<"\t"<<y2;
		fileW<<mst.id<<"\t"<<mst.tip<<"\t"<<kusUcusuMesafeHesapla(ind.x1,ind.y1,mst.x1,mst.y1)<<"\t\n";
	}	
	
	fileR.close();
	fileW.close();
		
	cout<<endl<<endl<<endl<<"\"musteri_indirici_mesafesi.txt\" Dosyasi olusturuldu. Kus ucusu mesafeler kaydedildi. Ana menuye donmek icin bir tusa basiniz.";
	getch();
	
}

hat yolBul(float x2,float y2){
	
	hat ht;
		
	ifstream fileR("test.txt");
	string kelime;
	
	
	while(fileR>>kelime)
		if(kelime=="HAT_ID")
			break;
	
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	
	while(fileR>>ht.id>>ht.x1>>ht.y1>>ht.x2>>ht.y2){
		if(ht.x2==x2 && ht.y2==y2)
		{
			fileR.close();
			return ht;
		}
	}	
	
	fileR.close();	
}

void musteriIndiriciHatBul (int mid){
	system("CLS");
	
	int ht_index=0;
	musteri mst;
	indirici ind;
	hat ht[MAX_HAT];
	string kelime,fileName="",nameTip;
	const string nameSabit="_hat_guzergahi.txt";
	char degisken[100];
	
	ifstream fileR("test.txt");

	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	
	fileR>>ind.id>>ind.x1>>ind.y1>>ind.x2>>ind.y2;
	
	
	
	while(fileR>>kelime)
		if(kelime=="MUSTERI_ID"){
			break;
		}
	
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	
	while(fileR>>mst.id>>mst.tip>>mst.x1>>mst.y1>>mst.x2>>mst.y2){
		if(mst.id==mid){
			ht[ht_index]=yolBul(mst.x1,mst.y1);
			cout<<endl<<"Hat_id:"<<ht[ht_index].id;
			while(ht[ht_index].x1!=ind.x1 && ht[ht_index].y1!=ind.y1 ){
				ht_index++;
				ht[ht_index]=yolBul(ht[ht_index-1].x1,ht[ht_index-1].y1);
				cout<<endl<<"Hat_id:"<<ht[ht_index].id;
			}
			break;
		}
	}
	
	
	sprintf(degisken, "%d", mst.id);
	
	switch(mst.tip){
				case 1:nameTip="Mesken";
					break;
				case 2:nameTip="Ticari";
					break;
				case 3:nameTip="Sanayi";
					break;
			}
	
	fileName=nameTip+degisken+nameSabit;
	
	ofstream fileW(fileName.c_str());
	
	fileW<<"Ýndirici Merkez 1"<<endl;
	
	for(ht_index;ht_index>=0;ht_index--){
		fileW<<"Hat "<<ht[ht_index].id<<endl;
	}
	
	fileW<<nameTip<<" ";		
	fileW<<mst.id;
	
	fileR.close();
	fileW.close();
		
	cout<<endl<<endl<<endl<<"\""+fileName+"\" Dosyasi olusturuldu. Indirici ve musteriler arasindaki hat mesafeleri kaydedildi. Ana menuye donmek icin bir tusa basiniz.";
	getch();
	
}

void musteriIndiriciHatMesafe (){
	system("CLS");
	
	int ht_index=0;
	float hatUzunlugu=0;
	musteri mst;
	indirici ind;
	hat ht[MAX_HAT];
	string kelime;
	const string nameSabit="_hat_guzergahi.txt";
	
	ifstream fileR("test.txt");
	ofstream fileW("Musteri_Hat_Uzunlugu.txt");
	
	
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	

	fileR>>ind.id>>ind.x1>>ind.y1>>ind.x2>>ind.y2;
	
	
	
	while(fileR>>kelime)
		if(kelime=="MUSTERI_ID"){
			fileW<<kelime<<"\t";
			break;
		}
	
	fileR>>kelime;
	fileW<<kelime<<"\t";
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileR>>kelime;
	fileW<<"HAT_UZUNLUGU"<<"\n";
	
	while(fileR>>mst.id>>mst.tip>>mst.x1>>mst.y1>>mst.x2>>mst.y2){
		
			ht[ht_index]=yolBul(mst.x1,mst.y1);
			while(ht[ht_index].x1!=ind.x1 && ht[ht_index].y1!=ind.y1 ){
				ht_index++;
				ht[ht_index]=yolBul(ht[ht_index-1].x1,ht[ht_index-1].y1);
				
			}
			
			for(ht_index;ht_index>=0;ht_index--){
				hatUzunlugu+=kusUcusuMesafeHesapla(ht[ht_index].x1,ht[ht_index].y1,ht[ht_index].x2,ht[ht_index].y2);
			}
			
			fileW<<mst.id<<"\t"<<mst.tip<<"\t"<<hatUzunlugu<<"\t"<<endl;
			hatUzunlugu=0;
			ht_index=0;		
	}
	
	
	fileR.close();
	fileW.close();
		
	cout<<endl<<endl<<endl<<"\"Musteri_Hat_Uzunlugu.txt\" Dosyasi olusturuldu. Indirici ve musteriler arasindaki hat mesafeleri kaydedildi. Ana menuye donmek icin bir tusa basiniz.";
	getch();
	
}



int main(int argc, char** argv) {
	
	int menu=10;
	
	while(menu!=0){
		
		system("CLS");
		
		cout<<"Proje 1'e hos geldiniz. Programi kullanabilmek icin programi calistirmis oldugunuz dosya konumuna giris verilerinin oldugu dosyayi test.txt adi ile yerlestiriniz."<<endl<<endl<<endl;
		
		cout<<"1) Indirici Merkez Bilgileri"<<endl;
		cout<<"2) Musteri Bilgileri"<<endl;
		cout<<"3) Hat Bilgileri"<<endl;
		cout<<"4) Indirici Merkez ile Musteri Arasindaki Hat Mesafelerini Dosyaya Yazdirma."<<endl;
		cout<<"5) Indirici Merkez ile Musteri Arasindaki Kus Ucusu Mesafesini Dosyaya Yazdirma."<<endl;
		cout<<"6) Indirici Merkez ile Musteri Arasindaki Hat Guzergahi Dosyaya Yazdirma."<<endl;
		cout<<endl<<"Lutfen yapmak istediginiz islemin sira numarasini giriniz. Programi sonlandirmak icin menudeki sayilar haric bir giris yapiniz."<<endl;
		cin>>menu;
		
		
		
		switch(menu){
			case 1:indiriciBilgileri();
				break;
			case 2:musteriBilgileri();
				break;
			case 3:hatBilgileri();
				break;
			case 4:musteriIndiriciHatMesafe();
				break;
			case 5:musteriIndiriciMesafe();
				break;
			case 6:
				cout<<endl<<"Lutfen hat mesafesini ogrenmek istediginiz musterinin id'sini giriniz:"<<endl;
				cin>>menu;
				musteriIndiriciHatBul(menu);
				break;
			default:menu=0;
				break;
		}
	}
	
	
	
	
	return 0;
}
