#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <locale.h>

//Struct types

typedef struct Ogrenci {
	char ogrID[10];
	char ad[30];
	char soyad[30];
	int puan;
	struct Ogrenci* next;
	struct Ogrenci* prev;
}ogrenci;

typedef struct KitapOrnek {
	char EtiketNo[20];
	char Durum[10];
	struct KitapOrnek* next;
}kitapOrnek;

typedef struct Kitap {
	char kitapAd[30];
	char ISBN[13];
	int adet;
	struct Kitap* next;
	struct KitapOrnek* head;
}kitap;

typedef	struct Yazar {
	int yazarID;
	char yazarAd[30];
	char yazarSoyad[30];
	struct Yazar* next;
}yazar;

typedef struct Tarih {
	int gun;
	int ay;
	int yil;
}tarih;

typedef struct KitapOdunc {
	char EtiketNo[20];
	char ogrID[10];
	int islemTipi;
	struct Tarih islemTarihi;
}Kitapodunc;
//Function definitions
int Sort_Ascending(int first, int second);
int Sort_Descending(int first, int second);

//ogrenci* sort_ogrenci(ogrenci* head,int(*Sort_condition)(int,int));
void split_ogrenci(ogrenci* holder, char buf[255], char delimeter[2]);
ogrenci* ogrenci_oku(char* dosya, char delimiter[2]);
void ogrenci_ekle(ogrenci** head);
void print_ogrenci(ogrenci* head);
void write_ogrenci(ogrenci* head, char* dosya, char delimiter);
void ogrenci_sil(ogrenci** heado, kitap* headk);
void kitap_teslim(ogrenci * heado,kitap*headk);
void split_kitap(kitap* holder, char buf[255], char delimeter[2]);
kitap* kitap_oku(char* dosya, char delimiter[2]);
void kitap_ekle(kitap** head);
void print_kitap(kitap* head);
void write_kitap(kitap* head, char* dosya, char delimiter);
kitapOrnek* kitap_ornek(kitap* kitap);
void yeni_kitap_ekle(kitap** head);
void mevcut_kitap_ekle(kitap** head);
void kitap_ara(kitap* head);
Kitapodunc* kitap_alma(kitap* headk, ogrenci* heado, int* size, Kitapodunc* head);
Kitapodunc* kitap_iade(kitap* headk, ogrenci* heado, int* size, Kitapodunc* head);
Kitapodunc* veri_kayit(kitapOrnek* headk, ogrenci* heado, int*, Kitapodunc* dizi, int x);
void print_veritabani(Kitapodunc* dizi, int* size);
void write_veritabani(Kitapodunc* dizi, char* dosya, char delimiter, int* size);
void ogr_bilgisi(ogrenci* head, Kitapodunc* headk, int* size);
void ceza_list(ogrenci *head);
void split_yazar(yazar* holder, char buf[255], char delimeter[2]);
yazar* yazar_oku(char* dosya, char delimiter[2]);
void yazar_ekle(yazar** head);
void print_yazar(yazar* head);
void write_yazar(yazar* head, char* dosya, char delimiter);
int main() {

	setlocale(LC_ALL, "Turkish");
	int sel;
	int size = 1;//
	Kitapodunc* dizi_Kitapodunc = (Kitapodunc*)malloc(sizeof(Kitapodunc));
	kitap* head_kitap = NULL;
	kitap* head_kitap_ekle = NULL;
	ogrenci* head_ogrenci = NULL;
	yazar* head_yazar = NULL;
	head_ogrenci = ogrenci_oku("Ogrenciler.csv", ",\0");
	head_yazar = yazar_oku("Yazarlar.csv", ",\0");
	head_kitap = kitap_oku("Kitaplar.csv", ",\0");





	do {
		system("cls");
		printf("\n-------------------------ANA MENU-------------------------\n");
		printf("1-Öðrenci iþlemleri\n");
		printf("2-Kitap iþlemleri\n");
		printf("3-Yazar iþlemleri\n");
		printf("4-Veri tabani iþlemleri\n");
		printf("Cikis icin yukaridakilerden farkli herhangi bir secim numarasi giriniz.\n");
		printf("\n------------------\nIslem:");
		scanf("%d", &sel);
		printf("\n------------------\n");
		switch (sel) {


		case 1:
			system("cls");

	do{
		printf("\n------------------------ÖÐRENCÝ ÝÞLEMLERÝ------------------------\n");
		printf("1-ÖÐRENCÝ EKLE\n");
		printf("2-KÝTAP AL\n");
		printf("3-KÝTAP ÝADE\n");
		printf("4-ÖÐRENCÝ BÝLGÝSÝ\n");
		printf("5-ÖÐRENCÝ DOSYA Yaz\n");
		printf("6-Öðrenci SÝL\n");
		printf("7-Öðrenci hareketleri\n");
	 	printf("8-Cezalý Öðrenciler\n");
	 	printf("9- Teslim etmemiþ ögrenciler\n");
		printf("Cikis icin yukaridakilerden farkli herhangi bir secim numarasi giriniz.\n");
		scanf("%d",&sel);
		printf("\n------------------\n");
		switch(sel){
				case 1:
					ogrenci_ekle(&head_ogrenci);
					break;
				case 2:
					dizi_Kitapodunc = kitap_alma(head_kitap, head_ogrenci, &size, dizi_Kitapodunc);
					break;
				case 3:
					kitap_iade(head_kitap, head_ogrenci, &size, dizi_Kitapodunc);
					break;

				case 4:
					print_ogrenci(head_ogrenci);
					break;

				case 5:
					write_ogrenci(head_ogrenci, "New_ogrenci.csv", ',');
					break;
				case 6:
					ogrenci_sil(&head_ogrenci, head_kitap);
					break;
				case 7:
					ogr_bilgisi(head_ogrenci, dizi_Kitapodunc, &size);
					break;
					case 8:
					ceza_list(head_ogrenci);
					break;
						case 9:
					 kitap_teslim(head_ogrenci,head_kitap);
					break;
				}
			} while (sel == 1 || sel == 2 || sel == 3 || sel == 4 || sel == 5 || sel == 6 || sel == 7|| sel == 8 || sel == 9);
			sel = 1;
			break;
		case 2:
			system("cls");



		
		do{
		printf("\n------------------------KÝTAP ÝÞLEMLERÝ------------------------\n");
		printf("1-YENÝ KÝTAP EKLE\n");
		printf("2-MEVCUT KÝTAP EKLE\n");
		printf("3-KÝTAPLARI DOSYAYA YAZ\n");
		printf("4-KÝTAP BÝLGÝSÝ\n");
		printf("5-KÝTAP ARA\n");
		printf("Cikis icin yukaridakilerden farkli herhangi bir secim numarasi giriniz.\n");
		
		scanf("%d",&sel);
				printf("\n------------------\n");
				switch (sel) {

				case 1:
					yeni_kitap_ekle(&head_kitap);
					break;
				case 2:
					mevcut_kitap_ekle(&head_kitap);
					break;
				case 3:
					write_kitap(head_kitap, "New_kitaplar.csv", ',');
				case 4:
					print_kitap(head_kitap);
					break;
				case 5:
					kitap_ara(head_kitap);


				}
			} while (sel == 1 || sel == 2 || sel == 3 || sel == 4 || sel == 5 || sel == 6 || sel == 7);
			sel = 2;
			break;



		case 3:
			system("cls");

				do{
		printf("\n------------------------YAZAR ÝÞLEMLERÝ------------------------\n");
		printf("1-YAZAR EKLE\n");
		printf("2-YAZAR SÝL\n");
		printf("3-YAZAR GÜNCELLE\n");
		printf("4-YAZAR BÝLGÝSÝ\n");
		printf("5-Yazar dosyaya yaz");
			printf("Cikis icin yukaridakilerden farkli herhangi bir secim numarasi giriniz.\n");
		scanf("%d",&sel);
		printf("\n------------------\n");

				switch (sel) {
				case 1:
					yazar_ekle(&head_yazar);
					break;
				case 4:
					print_yazar(head_yazar);
					break;
				case 5 :
					 write_yazar(head_yazar, "New_yazar.csv", ',');
					break;
				}
			} while (sel == 1 || sel == 2 || sel == 3 || sel == 4|| sel == 5);
			sel = 3;
		case 4:
			system("cls");

			do{
		printf("\n------------------------VeriTabaniÝþlemleri------------------------\n");
		printf("1-Veritabani Görüntüle\n");
		printf("2-Veri Tabani Dosya yazdýr\n");
	
		scanf("%d",&sel);
				printf("\n------------------\n");
				switch (sel) {
				case 1:
					print_veritabani(dizi_Kitapodunc, &size);
					break;
				case 2:
					write_veritabani(dizi_Kitapodunc, "New_veritabani.csv", ',', &size);
					break;

				}
			} while (sel == 1 || sel == 2 || sel == 3 || sel == 4);
			sel = 4;
		}
	} while (sel == 1 || sel == 2 || sel == 3 || sel == 4);

	return 0;
}
int Sort_Ascending(int first, int second) {
	return first < second;
}

int Sort_Descending(int first, int second) {
	return first > second;
}

void split_ogrenci(ogrenci* holder, char buf[255], char delimeter[2]) {
	char* token;
	
	token = strtok(buf, delimeter);
	strcpy(holder->ogrID, token);
	token = strtok(NULL, delimeter);
	strcpy(holder->ad, token);
	token = strtok(NULL, delimeter);
	strcpy(holder->soyad, token);
	token = strtok(NULL, delimeter);
	holder->puan = atoi(token);//char to int
}

ogrenci* ogrenci_oku(char* dosya, char delimiter[2]) {
	FILE* fp = fopen(dosya, "r");
	char buf[255];

	ogrenci* head = (ogrenci*)malloc(sizeof(ogrenci));
	ogrenci* curr_data;
	ogrenci* prev_data;
	if (fgets(buf, 255, fp) != NULL) {
		printf("%s", buf);
		split_ogrenci(head, buf, delimiter);
	}
	else {
		return NULL;
	}
	prev_data = head;
	while (fgets(buf, 255, fp) != NULL) {
		printf("%s", buf);
		curr_data = (ogrenci*)malloc(sizeof(ogrenci));
		prev_data->next = curr_data;
		split_ogrenci(curr_data, buf, delimiter);
		prev_data = curr_data;
	}
	prev_data->next = NULL;
	fclose(fp);
	return head;
}
void ogrenci_ekle(ogrenci** head) {

	ogrenci* iter = *head, * temp = (ogrenci*)malloc(sizeof(ogrenci));
	temp->next = NULL;
	printf("Ogrenci Idsi giriniz.\n");
	scanf("%s", temp->ogrID);
	printf("\nOgrenci Adi giriniz.");
	scanf("%s", temp->ad);
	printf("\nOgrenci SoyAdi giriniz.");
	scanf("%s", temp->soyad);
	temp->puan = 100;
	if (head == NULL) {
		*head = temp;
	}
	else {
		while (iter->next != NULL) {
			iter = iter->next;
		}
		iter->next = temp;
	}
}




void ogrenci_sil(ogrenci **heado,kitap *headk){
	
	char num[10];
	ogrenci *p = *heado,*temp;
	kitap *temp1 = headk;
	
	//Silmek istenilen ogrencinin numara bilgilerini al
	printf("\nKaydini sildirmek istediginiz ogrenci numarasi:");
	scanf("%s",num);
	//Ogrenci listesinin bos olup olmadigini kontrol et	
	if(*heado == NULL){
		printf("\nOgrenci listesi bos. Silmek icin oncelikle listeye bir ogrenci ekleyin.\n");
		return;
	}
//Boþ degilse önce öðrenci linked listini eðer numarayý bulursan  aldýðý kitap varmý diye kontrol et
// eðer  teslim etmediði kitap varsa  uyarý yap. silme iþlemini gerçekleþtirme.
	
	
	while(p->next!=NULL){
	if(strcmp(num ,p->ogrID)==0){
		while(temp1->next!=NULL){
			while(temp1->head!=NULL){
				if(strcmp(num,temp1->head->Durum)==0){
					printf("Kayýt silinemez bu öðrencinin teslim etmediði kitap vardýr!");
					return ;
				}
				temp1->head=temp1->head->next;
			}
			
			temp1=temp1->next;
		}
	}
		p=p->next;
}

// Öðrenciyi silelim þimdi üstteki þartlar saðlanmadýðýna göre.

p=*heado;	// en baþta olabilir eleman.
	if((strcmp(p->ogrID,num)==0)){
		*heado=(p->next);
		free(p);
		
	}
	else{
	
	
	// baþta deðilse de silebiliriz
	while(strcmp(p->ogrID,num)!=0&& p->next!=NULL){
		temp=p;
		p=p->next;
	}
	temp->next=p->next;
	free(p);	
}}
void write_ogrenci(ogrenci* head, char* dosya, char delimiter) {
	FILE* fp = fopen(dosya, "w");

	while (head != NULL) {
		fprintf(fp, "%s,%s,%s,%d\n", head->ogrID, head->ad, head->soyad, head->puan);
		head = head->next;
	}
	head->next == NULL;
	fclose(fp);
	return;
}

/*
ogrenci* sort_ogrenci(ogrenci* head,int(*Sort_condition)(int,int)){
	if(head == NULL || head->next == NULL)
	return head;
	int max = head->ogrID;
	ogrenci*prev=head;
	ogrenci*to_move=NULL;
	ogrenci*tmp=head->next;
	while(tmp!=NULL){
		if(Sort_condition(tmp->puan,max)){
			max=tmp->ogrID;
			to_move=prev;

		}
		prev=tmp;
		tmp=tmp->next;
	}


	if(to_move==NULL){
		head->next=sort_ogrenci(head->next,Sort_condition);
	}
	prev=to_move;
	to_move=prev->next;
	prev->next=prev->next->next;
	to_move->next=sort_ogrenci(head,Sort_condition);
	return to_move;
}
*/

void print_ogrenci(ogrenci* head) {
	while (head != NULL) {
		printf("ogrID:%s ad:%s  Soyad :%s puan:%d\n", head->ogrID, head->ad, head->soyad, head->puan);
		head = head->next;
	}
}

void split_kitap(kitap* holder, char buf[255], char delimeter[2]) {
	char* token;
	token = strtok(buf, delimeter);
	strcpy(holder->kitapAd, token);
	token = strtok(NULL, delimeter);
	strcpy(holder->ISBN, token);
	token = strtok(NULL, delimeter);
	holder->adet = atoi(token);
}
kitapOrnek* kitap_ornek(kitap* kitap) { //holder = head
	char buf[255] = "";
	char buf2[2] = "";
	int kitapCount = kitap->adet;
	int i = 1;

	kitapOrnek* headk = (kitapOrnek*)malloc(sizeof(kitapOrnek));
	//kitapOrnek* prevdatak;
	//kitapOrnek* currdatak;
	strcpy(headk->Durum, "Rafta");

	strcpy(buf, kitap->ISBN);
	strcat(buf, "_");
	snprintf(buf2, 2, "%d", i);
	strcat(buf, buf2);
	strcpy(headk->EtiketNo, buf);

	printf("Ornek kitap: %s %s %s\n", kitap->kitapAd, headk->EtiketNo, headk->Durum);
	kitapOrnek* tmp = headk;
	kitapOrnek* curr;

	for (i = 2; i < kitapCount + 1; i++) {
		curr = (kitapOrnek*)malloc(sizeof(kitapOrnek));
		strcpy(buf, "");
		strcpy(curr->Durum, "Rafta");
		strcpy(buf, kitap->ISBN);
		strcat(buf, "_");
		snprintf(buf2, 2, "%d", i);;
		strcat(buf, buf2);
		strcpy(curr->EtiketNo, buf);
		printf("Ornek kitap: %s %s %s\n", kitap->kitapAd, curr->EtiketNo, curr->Durum);
		tmp->next = curr;
		tmp = curr;
	}
	tmp->next = NULL;
	return headk;

}

kitap* kitap_oku(char* dosya, char delimiter[2]) {
	FILE* fp = fopen(dosya, "r");
	char buf[255];
	kitap* head = (kitap*)malloc(sizeof(kitap));
	kitap* curr_data;
	kitap* prev_data;
	if (fgets(buf, 255, fp) != NULL) {
		printf("%s", buf);
		split_kitap(head, buf, delimiter);
		head->head = kitap_ornek(head);
	}

	else {
		return NULL;
	}
	prev_data = head;
	while (fgets(buf, 255, fp) != NULL) {
		printf("%s", buf);
		curr_data = (kitap*)malloc(sizeof(kitap));
		prev_data->next = curr_data;
		split_kitap(curr_data, buf, delimiter);
		prev_data = curr_data;
		prev_data->head = kitap_ornek(prev_data);
	}
	prev_data->next = NULL;
	fclose(fp);



	return head;
}
void yeni_kitap_ekle(kitap** head) {
	kitap* temp = (kitap*)malloc(sizeof(kitap));
	kitap* iter1 = *head;
	//char isim[20];
	printf("Kitap adi giriniz");
	scanf("%s", temp->kitapAd);
	printf("\nKitab adedi giriniz...");
	scanf("%d", &temp->adet);
	printf("\nKitap ISBN giriniz.");
	scanf("%s", temp->ISBN);

	if (head == NULL) {
		*head = temp;
	}
	else {
		while (iter1->next != NULL) {
			iter1 = iter1->next;
		}
		iter1->next = temp;
		temp->next = NULL;
	}
	temp->head = kitap_ornek(temp);
}




void mevcut_kitap_ekle(kitap** head) {
	kitap* iter = *head;
	char tma[20];
	int adet, yeniadet;
	printf("\nKitap Adi giriniz.");
	scanf("%s", tma);
	while (iter->next != NULL) {
		if (strcmp(tma, iter->kitapAd) == 0) {
			printf("\nKitab adedi giriniz.");
			scanf("%d", &adet);
			yeniadet = adet + iter->adet;

			char buf[255] = "";
			char buf2[2] = "";
			int kitapCount = yeniadet;
			int i = iter->adet + 1;
			iter->adet = yeniadet;
			kitapOrnek* tmp = iter->head;
			kitapOrnek* curr;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			for (i; i < yeniadet + 1; i++) {
				curr = (kitapOrnek*)malloc(sizeof(kitapOrnek));
				strcpy(buf, "");
				strcpy(curr->Durum, "Rafta");
				strcpy(buf, iter->ISBN);
				strcat(buf, "_");
				snprintf(buf2, 2, "%d", i);;
				strcat(buf, buf2);
				strcpy(curr->EtiketNo, buf);
				printf("Ornek kitap: %s %s %s\n", iter->kitapAd, curr->EtiketNo, curr->Durum);
				tmp->next = curr;
				tmp = curr;
			}


			tmp->next = NULL;
		}
		iter = iter->next;

	}

}
void kitap_ara(kitap* head) {
	char tma[20];
	kitap* iter = head;
	printf("Lütfen Kitap ismi giriniz.");
	scanf("%s", tma);

	while (iter != NULL) {
		if (strcmp(tma, iter->kitapAd) == 0) {
			printf("\nKÝTAPLAR VE DURUMLARI\n");
			kitapOrnek* tnp;
			tnp = iter->head;
			while (tnp != NULL) {
				printf("%s  %s  %s\n", iter->kitapAd, tnp->EtiketNo, tnp->Durum);
				tnp = tnp->next;

			}
			return;
		}

		iter = iter->next;
	}
	printf("Aradiðiniz kitap mevcut deðildir.");
}
void write_kitap(kitap* head, char* dosya, char delimiter) {
	FILE* fp = fopen(dosya, "w");

	while (head != NULL) {
		fprintf(fp, "%s,%s,%d\n", head->kitapAd, head->ISBN, head->adet);
		head = head->next;
	}
	fclose(fp);
	return;
}
void print_kitap(kitap* head) {
	kitap* tmp = head;
	kitapOrnek* tnp;
	while (tmp != NULL) {
		tnp = tmp->head;
		while (tnp != NULL) {
			printf("%s  %s  %s\n", tmp->kitapAd, tnp->EtiketNo, tnp->Durum);
			tnp = tnp->next;
		}
		printf("\n");
		tmp = tmp->next;
	}

	printf("\n");



}
Kitapodunc* kitap_alma(kitap* headk, ogrenci* heado, int* size, Kitapodunc* head) {
	int x;
	ogrenci* tmpo = heado;
	int* p = size;
	kitap* tmpk = headk;
	char no[11];
	char tma[20];
	printf("Lütfen öðrenci ID'nizi giriniz");
	scanf("%s", no);

	while (tmpo != NULL) {

		if (strcmp(no, tmpo->ogrID) == 0) {

			if (tmpo->puan >= 0) {

				printf("Almak istediðin kitabi gir.");
				scanf("%s", tma);
				while (tmpk != NULL) {
					if (strcmp(tma, tmpk->kitapAd) == 0) {
						kitapOrnek* tnp;
						tnp = tmpk->head;
						while ((strcmp(tnp->Durum, "Rafta") != 0) && tnp->next != NULL) {
							tnp = tnp->next;
						}
						if ((tnp->next == NULL) && (strcmp(tnp->Durum, "Rafta") != 0)) {
							printf("Üzgünüz Tüm kitaplar alýndý stoklara eklenince bilgilendirme mesajý alacaksýnýz...");
							return head;
						}
						else {
							strcpy(tnp->Durum, no);
							printf("Kitabý baþariyla  aldiniz..");
							x = 0;
							head = veri_kayit(tnp, tmpo, p, head, x);
							return head;


						}
					}

					tmpk = tmpk->next;

				}


	if(tmpk==NULL){
			printf("Bu kitap yoktur");
		}return;

}	
printf("Bu öðrenci Cezalidir");return;
	
	}tmpo = tmpo->next;
		} if(tmpo == NULL){
		printf("Bu öðrenci kayýtlý deðildir");
	}
		
	
}
Kitapodunc* kitap_iade(kitap* headk, ogrenci* heado, int* size, Kitapodunc* head) {
	int x;
	ogrenci* tmpo = heado;
	int* p = size;
	kitap* tmpk = headk;
	char no[11];
	char tma[20];

	printf("Lütfen öðrenci ID'nizi giriniz");
	scanf("%s", no);
	while (tmpo != NULL) {
		if (strcmp(no, tmpo->ogrID) == 0) {
			printf("Ýade etmek istediðin kitabi gir.");
			scanf("%s", tma);
			while (tmpk != NULL) {
				if (strcmp(tma, tmpk->kitapAd) == 0) {
					kitapOrnek* tnp;
					tnp = tmpk->head;
					while ((strcmp(tnp->Durum, no) != 0) && tnp->next != NULL) {
						tnp = tnp->next;
					}
					if ((tnp->next == NULL) && (strcmp(tnp->Durum, no) != 0)) {

						printf("Bu kitap Raftadýr.");
						return;
					}
					else {
						strcpy(tnp->Durum, "Rafta");
						printf("Kitabý baþarýyla iade ettiniz.");
						x = 1;
						head = veri_kayit(tnp, tmpo, p, head, x);
						return head;

					}	


				}

				tmpk = tmpk->next;

			}

		}
		tmpo = tmpo->next;
	}
	printf("Bu Öðrenci kayýtlý deðildir");

}

Kitapodunc* veri_kayit(kitapOrnek* headk, ogrenci* heado, int* size, Kitapodunc* dizi, int x) {

	dizi = (Kitapodunc*)realloc(dizi, (*size) *sizeof(Kitapodunc));
	int c = *size;
	int i = 0;
	int gun, ay, yil;


	strcpy(dizi[c-1].EtiketNo, headk->EtiketNo);
	strcpy(dizi[c-1].ogrID, heado->ogrID);
	dizi[c-1].islemTipi = x;
	printf("Ýþlem tarihi giriniz: gün\n");
	scanf("%d", &gun);
	printf("Ýþlem tarihi giriniz: ay\n");
	scanf("%d", &ay);
	printf("iþlem tarihi giriniz: yil\n");
	scanf("%d", &yil);
	dizi[c-1].islemTarihi.gun = gun;
	dizi[c-1].islemTarihi.ay = ay;
	dizi[c-1].islemTarihi.yil = yil;
	if (x = 1) {
		for (i; i < c; i++) {
			if ((strcmp(dizi[i].EtiketNo, dizi[c-1].EtiketNo) == 0) && (strcmp(dizi[i].ogrID, dizi[c-1].ogrID) == 0)) {
				if (dizi[c-1].islemTarihi.gun - dizi[i].islemTarihi.gun > 15) {
					printf("Ceza yediniz puanýnýz 15 düþtü..");

					heado->puan -= 15;
				}
			}
		}
	}

	(*size)++;

	return dizi;
}




void print_veritabani(Kitapodunc* dizi, int* size) {

	Kitapodunc* tmpko = dizi;
	int i = 0;
	int c = *(size);
	for (i; i < c - 1; i++) {

		printf("%s,", tmpko[i].EtiketNo);
		printf("%s,", tmpko[i].ogrID);
		printf("%d,", tmpko[i].islemTipi);
		printf("%d.", tmpko[i].islemTarihi.gun);
		printf("%d.", tmpko[i].islemTarihi.ay);
		printf("%d", tmpko[i].islemTarihi.yil);
		printf("\n");
	}




}

void write_veritabani(Kitapodunc* dizi, char* dosya, char delimiter, int* size) {
	FILE* fp = fopen(dosya, "w");



	Kitapodunc* tmpko = dizi;
	int i = 0;
	int c = *(size);
	for (i; i < c - 1; i++) {
		fprintf(fp, "%s,%s,%d,%d,%d,%d\n", tmpko[i].EtiketNo, tmpko[i].ogrID, tmpko[i].islemTipi, tmpko[i].islemTarihi.gun, tmpko[i].islemTarihi.ay, tmpko[i].islemTarihi.yil);

	}


	fclose(fp);
	return;
}




void split_yazar(yazar* holder, char buf[255], char delimeter[2]) {
	char* token;
	// strtok; Delim parametresi ile gï¿½sterinel karakter dizisi iï¿½erisindeki sï¿½nï¿½rlayï¿½cï¿½ karakterleri kullanarak buf parametresi ile gï¿½sterilen karakter dizisini parï¿½alar
	token = strtok(buf, delimeter);
	holder->yazarID = atoi(token);
	token = strtok(NULL, delimeter);
	strcpy(holder->yazarAd, token);
	token = strtok(NULL, delimeter);
	strcpy(holder->yazarSoyad, token);

}
yazar* yazar_oku(char* dosya, char delimiter[2]) {
	FILE* fp = fopen(dosya, "r");
	char buf[255];

	yazar* head_yazar = (yazar*)malloc(sizeof(yazar));
	yazar* curr_data;
	yazar* prev_data;
	if (fgets(buf, 255, fp) != NULL) {
		printf("%s", buf);
		split_yazar(head_yazar, buf, delimiter);
	}
	else {
		return NULL;
	}
	prev_data = head_yazar;
	while (fgets(buf, 255, fp) != NULL) {
		printf("%s", buf);
		curr_data = (yazar*)malloc(sizeof(yazar));
		prev_data->next = curr_data;
		split_yazar(curr_data, buf, delimiter);
		prev_data = curr_data;
	}
	prev_data->next = NULL;
	fclose(fp);
	return head_yazar;
}
void yazar_ekle(yazar** head) {
	yazar* iter = *head, * temp = (yazar*)malloc(sizeof(yazar));
	temp->next = NULL;
	printf("\nYazar Adi giriniz.");
	scanf("%s", temp->yazarAd);
	printf("\nYazar SoyAdi giriniz.");
	scanf("%s", temp->yazarSoyad);
	if (head == NULL) {
		*head = temp;
	}
	else {
		while (iter->next != NULL) {
			iter = iter->next;
		}
		iter->next = temp;
		iter->next->yazarID = iter->yazarID + 1;
	}
}
void print_yazar(yazar* head) {
	while (head != NULL) {
		printf("YazarID:%d ad:%s  Soyad :%s\n", head->yazarID, head->yazarAd, head->yazarSoyad);
		head = head->next;
	}
}
void write_yazar(yazar* head, char* dosya, char delimiter) {
	FILE* fp = fopen(dosya, "w");

	while (head != NULL) {
		fprintf(fp, "%d,%s,%s\n", head->yazarID, head->yazarAd, head->yazarSoyad);
		head = head->next;
	}
	fclose(fp);
	return;
}





void ceza_list(ogrenci *head){
	while(head!=NULL){
		
		if(head->puan<0){
			printf("Cezali ögrenci ad:%s soyad:%s	ID:%s Puan:%d\n",head->ad,head->soyad,head->ogrID,head->puan);
		}
		
		head=head->next;
	}
}

void kitap_teslim(ogrenci * heado,kitap*headk){
	kitapOrnek *tmp;
	
	
	while(headk!=NULL){
		while(headk->head!=NULL){
			if(strcmp(headk->head->Durum,"Rafta")!=0){
			printf("%s\n",headk->head->Durum);
			
		}
	
		headk->head=headk->head->next;
		
		
	}headk=headk->next;
}


}




void ogr_bilgisi(ogrenci* head, Kitapodunc* headk, int* size) {

	int i = 0;
	ogrenci* iter = head;
	Kitapodunc* tmp = headk;
	char id[10];
	printf("Ogrenci ID'nizi giriniz");
	scanf("%s",id);

	while (iter->next != NULL) {
	
		if (strcmp(id,iter->ogrID) == 0) {
			printf("Ad:%s Soyad:%s ID:%s Puan:%d\n", iter->ad, iter->soyad, iter->ogrID, iter->puan);
			for (i; i <= (*(size)); i++) {
				if (strcmp(tmp[i].ogrID, id) == 0) {
					printf("Aldiðiniz Kitabin etiketi:%s Tarih:Gün:%d/Ay:%d/Yil:%d", tmp[i].EtiketNo, tmp[i].islemTarihi.gun, tmp[i].islemTarihi.ay, tmp[i].islemTarihi.yil);
				}
			}
		}
		
		iter = iter->next;
	}
}


