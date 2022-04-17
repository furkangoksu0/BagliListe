 /*
 Adý Soyadý:Furkan GÖKSU
Öðrenci No:02210224008
Ödev-1
 */
 #include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *link;
};

struct Node* ilk=NULL;
  	
	

 void ElemanEkle(int veri,int siraNo){
	int boyut=0;
	int flag=0;
	struct Node *push;
	push=(struct Node*)malloc(sizeof(struct Node));
	push->data=veri;
	push->link=NULL;
	//Ýlk sýraya eklemeyi saðlar
	if(siraNo==1){
		if(ilk==NULL){
			ilk=push;
			
		}
		else{
			push->link=ilk;
			ilk=push;
		}
	}
	//Ýlk sýraya üstte atama yapýtðýmýz için ondan sonraki ve araya eklemek için alttaki kodlarý kullandým
    else if(boyut>=siraNo){
	 	struct Node *gecici=ilk;
		 flag=2;
		 
		while(flag<siraNo){
		 gecici=gecici->link;
		 flag++;
		 
		 }
	
	    push->link = gecici->link;	
		gecici->link=push;
	
	}
	else {
	 	if(ilk==NULL){
		 ilk=push;
		 
		}
	else{
		struct Node *gecici2=ilk;
	    while(gecici2->link!=NULL){
		 gecici2=gecici2->link;
	}

	     gecici2->link=push;
		}
	
	}
boyut++;
 }
void ElemanSil(int siraNo){
	
	
	
		if(ilk==NULL){
		printf("\nListe BOS!\n");
	}
	else{
	//Ýlk sýradakini silmek için yazýldý
	   if(siraNo==1){
	  	struct Node* gecici2=ilk;
	    ilk=ilk->link;
			free(gecici2);
	
     }
		else{
		//Burda kullanýcýdan aldýðýmýz sýra noya kadar gidip ordaki sayýyý buldum onu da konuma aktardým
		//konumda tuttuðu sayýyý sildim
		//Ýlk sýradaki sayýyý sildiðim için i yi 2 den baþlattým
		struct Node*konum;
        struct Node*gecici;
		int i=2;
		int k=1;
        gecici=ilk;
        while(i<siraNo ){
        	gecici=gecici->link;
        	i++;
        	k++;
		}
		konum=gecici->link;
        //sonraki düðümü baðlýyorum
		gecici->link=konum->link;
		free(konum);
	}

}
}
void ElemanAra(int siraNo){
    int a;
    int i=1;

    if(ilk==NULL){
        printf("Liste BOS!");
    }
    else
    {
        struct Node* gecici=ilk;
        //i yi 1 den baþlatarak girilen sira noya kadar ilerletip ordaki sayýyý yazdýrdým
        while(i<siraNo){
         if(gecici->link==NULL){//Listedeki sayý adedinden fazla girerse eleman olmadýðýný yazdýrdým
                printf("Eleman bulunamadi\n");
                return;
            }
            else{
			
            gecici=gecici->link;
            i++;
       }

        }

            a=gecici->data;
          printf("%d\n",a);
    }
  
}



void Yazdir(){
	//Yazdýrma iþlemi
	printf("\n");
	if(ilk==NULL){
		printf("Liste BOS!");
	}
	else{
		struct Node* gecici=ilk;
		while(gecici!=NULL){
			printf("%d->",gecici->data);
			gecici=gecici->link;
		}
		printf("NULL\n");
	}
}

void OrtadakiEleman(){

    struct Node *gecici=ilk;
    int elemanSayisi=0;
    if(ilk==NULL){
		printf("Liste BOS!");
	}
	else{

   
	//Nulla kadar döndürüp girilen eleman sayýsýný buldum
	while(gecici!=NULL){
        gecici=gecici->link;
        elemanSayisi++;
    }
    	if(elemanSayisi<=2){
    printf("Arada eleman yok\n");
	  
  }
   else{
    int orta;
    orta=elemanSayisi/2;
    gecici=ilk;
    //eleman sayýsýný yarýya bölerek oratadaki sayýya ulaþtým
    int i;
    for(i=1; i<orta+1; i++)
        gecici=gecici->link;
        //Girilen sayýlarda ortasýndakilere kadar vardým
    printf("Listenin Ortadaki elemani:\n");
    printf("%d\n",gecici->data);
}
}

}	

void TamSayiyaDonustur(){

     struct Node* gecici=ilk;
       int carp=1,tamsayi=0;
       if(ilk==NULL){
		printf("Liste BOS!");
	}
	else{
	
       while(gecici->link!=NULL){//Eleman deðeri kadar basamak ekledim
      gecici=gecici->link;
        carp=carp*10;
      }
      
     gecici=ilk;
       while(gecici->link!=NULL){
   int toplam=gecici->data; 
      if (carp>=10){
      toplam=toplam*carp;//Girilen sayýlarý 10la çarptým
         tamsayi=tamsayi+toplam;
          carp=carp/10;
     }
     gecici=gecici->link;
     }
    tamsayi=tamsayi+gecici->data;
    printf("%d\n",tamsayi);
    
 }
}

 
int main() {
     int secim;
     int b,a;
     int sira;
    do{
	
		printf("\nMENU\n");	
		printf("1.EKLEME\n");
		printf("2.SILME\n");
		printf("3.ELEMAN ARA\n");
		printf("4.YAZDIR\n");
		printf("5.ORTADAKI SAYIYI BUL\n");
		printf("6.TAM SAYIYA DONUSTUR\n");
		printf("Bir Islem Seciniz:");
		scanf("%d",&secim);
		switch(secim){
			case 1: 
         printf("Eklencek Sayiyi Giriniz:\n");
         scanf("%d",&b);
         printf("Konumunu Giriniz:\n");
         scanf("%d",&sira);
         ElemanEkle(b,sira);
         Yazdir(); 
			
			break;
			
			case 2: 
				
				 printf("sirasini giriniz\n");
                 scanf("%d",&sira);
				 ElemanSil(sira);
				 Yazdir();
			break;
			
			case 3: 
				
				 printf("sirasini giriniz\n");
                 scanf("%d",&sira);
			     ElemanAra(sira);
				
			break;
			
			case 4:
					Yazdir();
			break;
			
			case 5:
			       OrtadakiEleman();
			break;
		
			case 6:
		       TamSayiyaDonustur();
		      
              break; 		
		    case -1:
		    	printf("Cikis");
				return;
			default:
			printf("Hatali Secim");
			break;	
		}
}
while(-1);	
}
