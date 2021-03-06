


#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

//Yapı oluşturma
struct n {
	int x;
	n *next;  //kendine dönüşlü yapı, düğümleri birbirine bağlamak için kullenacağız.

};

typedef struct n node; // struct n ifadesini "node" kelimesiyle ifade edeceğiz. 
//ekleme işlemi
node * siraliekle(node * r, int x)  
{
	
	node *temp;
  //eğer root umuz Null sa yeni düğüm oluşturacak.
	if (r == NULL)
	{
		r = (node *)malloc(sizeof(node));
		r->x = x;
		r->next = NULL;
		return r;
	}

// eğer ilk düğümden sonra büyük-küçük kontrolü yapıyor.
	if (r->next == NULL)

	{
		if (r->x < x)
		{
			temp = (node *)malloc(sizeof(node));
			temp->x = x;
			temp->next = r->next;
			r->next = temp;
			
			return r;
		}
		else
		{
			temp = (node *)malloc(sizeof(node));
			temp->next = r;
			temp->x = x;
			r = temp;
			
			return r;
		}

	}
//sonraki düğümlerin karşılaştırılması burada yapılıyor.
	node * iter = r;// iter ile ilerleme yapıyoruz.root sabit kalacak.
	if (r->next != NULL)
	{


		while (iter->next != NULL)
		{


			if (iter->x > x)
			{
				temp = (node *)malloc(sizeof(node));
				temp->x = x;
				temp->next = iter;
				iter = temp;
				return temp;
			}

			else if (iter->x <= x && iter->next->x >= x)
			{
				temp = (node *)malloc(sizeof(node));
				temp->x = x;
				temp->next = iter->next;
				iter->next = temp;

				return r;

			}
			else
				{
				if (iter->next->next == NULL && iter->next->x < x) {
					temp = (node *)malloc(sizeof(node));
					temp->x = x;
					temp->next = iter->next->next;
					iter->next->next = temp;
					return r;

				}
			
			
			}
			
			
				


			


			iter = iter->next;


		}
	}
	return r;
}
//Silme fonsiyonu
node * sil(node *r, int x) {
	node * temp;
	node * iter = r;
	//Eğer silinecek eleman rootsa root u bir sonraki noda kaydır.
	if (r->x == x) {
		temp = r;
		r = iter->next;
		free(temp);
		return r;
	}
	//Eğer silencek düğüm root değilse sona kadar ara. eşitse sil .Değilse iter i ilerlet.
	while (iter->next != NULL) 
	{
		
		if (iter->next->x == x) 
		{
			temp = iter->next;
			iter->next = iter->next->next;
			temp->next = NULL;
			free(temp);
			
			
		}
		else 
		{
			iter = iter->next;
		}
	}
	return r;
	
}

//yazdırma işlemi 
void yazdir(node *r)
{
	while (r != NULL)
	{

		cout << r->x << "\t";
		r = r->next;
	}
	cout << endl;
}
int main()
{
	node *root;
	root = NULL;

	root = siraliekle(root, 7);

	root = siraliekle(root, 16);
	root = siraliekle(root, 15);
	root = siraliekle(root, 3);
	root = siraliekle(root, 20);
	root = siraliekle(root, 12);
	root = siraliekle(root, 5);
	root = siraliekle(root, 15);
	root = siraliekle(root, 8);
	root = siraliekle(root, 18);
	root = siraliekle(root, 20);
	root = siraliekle(root, 22);
	root = siraliekle(root, 21);
	yazdir(root);
	root = sil(root, 3);
	root = sil(root, 16);
	root = sil(root, 15);
	yazdir(root);





	system("pause");
	return 0;
}








