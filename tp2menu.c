/* Menu du TP 2 - Base de donnees sur des personnes*/
#include<stdio.h>
#include<string.h>
#define N 50

/* Définition du type date (jour, mois, année) */
typedef struct { int jour, mois, an; } t_date;

/* Définition du type sexe avec la convention INSEE */
typedef enum { homme = 1, femme } t_sexe;

/* Définition du type personne (prénom, sexe, date de naissance) */
typedef struct { char prenom[20] ; t_sexe sexe ; t_date naissance ; } t_personne ;

void afficher_date(t_date d) {
	printf("%i ", d.jour);
	printf("%i ", d.mois);
	printf("%i\n", d.an);
}

void afficher_sexe(t_sexe s) {
	if(s==1) {
		printf("Homme ");
	} else {
		printf("Femme ");
	}
}
	
void afficher_base(t_personne* amis, int nb_amis){
	int i = 0;
	for(i=0; i < nb_amis; i++) {
		printf("%s ", amis[i].prenom);
		afficher_sexe(amis[i].sexe);
		afficher_date(amis[i].naissance);
	}
}

void afficher_nombre_fh(t_personne* amis, int nb_amis){	
	int i,f = 0,h = 0;
	for(i=0; i<nb_amis; i++) {
		if(amis[i].sexe == 1) {
			h++;
		} else {
			f++;
		}
	}
	printf("Il y a %i Hommes\n", h);
	printf("Il y a %i Femmes", f);
}

void afficher_cadet(t_personne* amis, int nb_amis) {
	int i = 0;
	int j = i;
	for(i=1; i<nb_amis; i++) {
		if(amis[i].naissance.an > amis[j].naissance.an) {
			j=i;
		} else if(amis[i].naissance.an==amis[j].naissance.an) {
				if(amis[i].naissance.mois < amis[j].naissance.an) {
					j=i;				
				} else if(amis[i].naissance.mois==amis[j].naissance.mois) {
					if(amis[i].naissance.jour > amis[j].naissance.jour){
						j=i;
					}
				}
		}
	}
	printf("Le cadet est : %s\n", amis[j].prenom);
}

void afficher_anniv(t_personne* amis, int nb_amis) {	
	int i;
	char prenom[20];
	printf("donnez un prénom : ");
	scanf("%s", prenom);
	for(i=0;i<nb_amis; i++) {
		if(strcmp(prenom, amis[i].prenom) == 0) {
			afficher_date(amis[i].naissance);
		}
	}
}	

void ajouter_personne(t_personne* amis, int* nb_amis) {	
	char prenom[20];
    

}

/* Programme principal */
int main()
{	

	/* Déclaration de la base de données, de taille maximale 50 et de taille utile nb_amis */
	t_personne amis[N]={{"Elodie",femme,{30,5,1996}}, {"Julien",homme,{8,11,1996}},{"Camille",femme,{2,6,1995}}, {"Adrien",homme,{20,11,1996}},{"Camille",homme,{12,5,1994}}, {"Lise",femme,{5,10,1995}}} ;
	int nb_amis = 6 ;

	int choix;	/* Choix de l'utilisateur */

	do
	{	/* Affichage du menu */
		printf("\nMenu :\n");
		printf(" 1 - Afficher le contenu de la base\n");
		printf(" 2 - Afficher le nombre d'hommes et de femmes\n");
		printf(" 3 - Afficher le prenom de la personne la plus jeune\n");
		printf(" 4 - Afficher les anniversaires d'un prenom\n");
		printf(" 5 - Ajouter une personne\n");
		printf(" 6 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1 : afficher_base(amis,nb_amis); break;
			case 2:  afficher_nombre_fh(amis,nb_amis); break;
			case 3:  afficher_cadet(amis,nb_amis); break;
			case 4:  afficher_anniv(amis,nb_amis); break;
			case 5:  ajouter_personne(amis,&nb_amis); break;
			case 6:  break;
			default: printf("Erreur: votre choix doit être compris entre 1 et 6\n");
		}
	}
	while(choix!=6);
	printf("Au revoir !\n");
	return 0;
}
