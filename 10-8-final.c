#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX1 15
#define MAX2 15
/* #define MAX4 3 */
/*�����������������! (a=get_choice())*/
/*�������� ������(�������, ���, �������, ���, �����, �������). ���������� �� �������, ����� �� ��������.*/
/*���������� ��������� ��������� (���������) */
struct names { char name[MAX1], surename[MAX2];};
/*���������� �������� ��������� (���������) */
struct knizhka { struct names handle;/* [MAX4] �����������! ��� ��� ���������� ��������� handle �� �����������!*/ char sex; int age, phone_number; };
/*����� �������� �������� ���������� ��������� (������-�� ���, �� ��� ����� ����������� �������, ������ ��������� ����� ���������) */
/*��������� ������� (!!! ATTENTION!!! ACHTUNG!!! POZOR PROGRAMMING POLICIA VORUJE!!!
��������!!!  �������� ������� ������ ���� ��������� ����� ���������� �������� �����!!!)*/
void samo_menu(void);
int get_choice(void);
struct knizhka vvod (void);
void otobragenie (struct knizhka *);
char * s_gets(char * st, int n);
void sort(struct knizhka  *);
void search(struct knizhka  *, int k);
int check_number (void);
int check_age (void);
char put_check_sex(void);
int put_checkphone_number(void);
char put_check_operation(void);
void cleaner(void);
int check_nomer (void);
void copy (struct knizhka *, int a, int b);
void delete (struct knizhka *, int a);
/*������ 2. ������ � �������.*/
int get_choice_file(void);
void samo_menu_file(void);
int check_name_file (char *name);
int MAX4=1; /*���������� �������� ������� ������� ��������*/
/*������� ������� */
int main (void) { int i=0, a, b, c, count=0, nomer, nomer_1;  struct knizhka * zapisnaya= NULL; char operation; /*�� ��������! ��� �� ���������! ��� ������ ��������! */
    zapisnaya = (struct knizhka*) malloc (sizeof(struct knizhka) * MAX4);    /*������ ������ ������*/
	FILE *fp;
    char name[MAX2];
    int kkk=0; struct knizhka kkk_1 = {{'\0', '\0'}, '\0', '\0', '\0'};
    printf ("Vvedite imya fila: \n\n");
    s_gets(name, MAX2);
    while ((check_name_file(name))!=1){
    	s_gets(name, MAX2);}
    int filecount=0;
    FILE * pbooks;
    int size = sizeof (struct knizhka);
    if ((pbooks = fopen(name, "a+b")) == NULL){
        fputs("Can't open file \n",stderr);
        exit(1);}
	while ((a=get_choice())!=8){
    	    switch (a){
    	        case 1:
    	        	cleaner();
    	        	for (i; i<MAX4; i++){
						zapisnaya = (struct knizhka*) realloc (zapisnaya, sizeof(struct knizhka) * MAX4); /*�������� �������������� ������ ��� ����� ������ (�� ���� ����������� ������ �������)*/
    	        		MAX4++;
						if (i>0){
						    printf ("If you wanna choose another operation. Press Y (Yes) or N (No): \n");
    	        		        operation=put_check_operation();
    	        		            if (operation=='Y'){
    	        		            	MAX4 -=2;
    	        		                zapisnaya = (struct knizhka*) realloc (zapisnaya, sizeof(struct knizhka) *MAX4); /*��������� ������ ����� � �� �� ���� ������ �����*/
    	        		                break;}
									else 
									    cleaner();}
    	        		printf ("Enter the next book: \n");
    	        		zapisnaya[i]=vvod();}
    	        	break;
				case 2:
                    otobragenie(zapisnaya);
                    break;
                case 3:
                    sort(zapisnaya);
                    otobragenie(zapisnaya);
                    break;
                case 4:
		            printf ("Vvedite vozrast kotoriy ishete. \n\n");
		            scanf ("%d", &b);
                    search(zapisnaya, b);
			        break;
			    case 5:
			    	printf ("Vvedite nomer elementa massiva  kotoriy hotite skopirovat. \n\n");
			    	nomer=check_nomer ();
			    	printf ("Vvedite nomer elementa  massiva kuda  hotite skopirovat. \n\n");
			    	nomer_1=check_nomer ();
			    	copy(zapisnaya, nomer, nomer_1);
			    	i++;
					break;
				case 6:
					printf ("Vvedite nomer elementa massiva  kotoriy hotite udalit. \n\n");
					nomer=check_nomer ();
					delete (zapisnaya, nomer);
				    break;
				case 7:
				    while ((a=get_choice_file())!=4){
				    	switch (a){
				    		case 1:
				    			if (i > 0){
									fwrite(&zapisnaya[filecount], size, i-filecount, pbooks);}
				    			break;
				    		case 2:
				    			rewind(pbooks);            /*��� � ������ ����� */
							    while (count < MAX4 &&  fread(&zapisnaya[count], size, 1, pbooks) == 1){count++;}
								filecount=count;
				    			break;
				    		case 3:
				    			for (kkk; kkk<MAX4; kkk++){zapisnaya[kkk]=kkk_1;}
				    			fopen(name, "w+b");
				    			free(zapisnaya);
								exit(2);
				    			break;}
				    		break;}
				    break;}}
	free(zapisnaya);
	fclose(pbooks);
	system("pause");
	puts("Bye.\n");
	return 0;}
int get_choice(void) {int b; /*������� ������ � ����*/
    samo_menu();
    b=check_number();
    while (b!=1 &&b!=2 &&b!=3 &&b!=4 &&b!=5 &&b!=6 &&b!=7&& b!=8){
	    printf ("Please choose right choice again!\n\n");
		b=check_number();}
	return b;}
struct knizhka vvod (void){struct knizhka zapisnaya; /*������� ����� ������*/
    printf ("Vvedite imya: \n");
    s_gets (zapisnaya.handle.name, MAX1);
	printf ("Vvedite familiyu: \n");
	s_gets (zapisnaya.handle.surename, MAX2);
	printf ("Vvedite pol M (male) ili F (female): \n");
	zapisnaya.sex=put_check_sex();
	printf ("Vvedite vozrast: \n");
	zapisnaya.age=check_age();
	printf ("Vvedite nomer telephona: \n");
	zapisnaya.phone_number= put_check_phonenumber();
	printf("FI : %s %s Sex: %c Age: %d Phone number: %d \n",
	zapisnaya.handle.name, zapisnaya.handle.surename, zapisnaya.sex, 
	zapisnaya.age, zapisnaya.phone_number);
	cleaner();
	printf ("Enter the next book: \n");
	return zapisnaya;}
void samo_menu(void){ /*������� �������� ���� ����*/
    printf(" \n Vyberite deystvie: \n\n "
    "1. Vvesty dannye\n\n 2. Otobragenie\n\n 3. Sortirovat po familii \n\n "
	"4. Iskat po vozrastu \n\n 5. Kopirovat dannye \n\n 6. Udalit dannye \n\n 7. Rabota s filamy \n\n 8. Exit \n\n ");}
void otobragenie (struct knizhka  * ukazatel) { int index; /*������� ����������*/
		printf ("Vasha zapisnaya knizhka: \n");
		for (index=0; index<MAX4; index++){ printf("FI : %s %s, Sex: %c, Age: %d, Phone number: %d \n\n",
		ukazatel[index].handle.name, ukazatel[index].handle.surename, ukazatel[index].sex,
		ukazatel[index].age, ukazatel[index].phone_number);}}
char * s_gets(char * st, int n) { /*������� ��������� ������*/
	char *ret_val;
	char *find;
	ret_val = fgets (st, n, stdin);
	if (ret_val){
		find = strchr (st, '\n');
		if (find)
		   *find = '\0';
		else
		    cleaner();}
    return ret_val;}
void sort(struct knizhka *ukazatel) {int j,k; /*������� ����������*/
 struct knizhka p;
 for(j=0; j<MAX4; j++) {
   for(k=0; k<MAX4; k++) {
     if(strcmp(ukazatel[j].handle.surename, ukazatel[k].handle.surename)<0) {
       p=ukazatel[j];
       ukazatel[j]=ukazatel[k];
       ukazatel[k]=p; } } } }
void search(struct knizhka *ukazatel, int key) { int count=0, i; /*������� ������*/ /*loop-zalup ������ �� ������������� ����������
������� for � �� ���������� �������� ������, ���������������� ����� �� �����*/
    for (i = 0; i < MAX4; i++)  {
	    if (ukazatel[i].age == key){
            printf("FI : %s %s, Sex: %c, Age: %d, Phone number: % d \n\n",
		    ukazatel[i].handle.name, ukazatel[i].handle.surename, ukazatel[i].sex, ukazatel[i].age, ukazatel[i].phone_number);
		    count++;}}
	    if (count==0 && i==MAX4 );
	        printf ("Takix netu!\n\n");}
/*������� �������� ������������ �����*/
int check_number (){ int c; char ch; /*������� �������� ����� �������������� ��������*/
	while (scanf("%ld", &c)!=1){
		while ((ch=getchar ())!= '\n')
		    putchar (ch);
		printf ("Put the whole number like 1 or 25  or -150.\n");}
	return c;}
int check_age (void){int c; /*������� �������� ����� ��������*/
	while ((c=check_number())>150 || c<0){
		if (c>100)
	        printf ("You are too old! Human on earth don't live so long! Try again.\n");
	    if (c<0)
		    printf ("Minus?! No, is not possible! Try again!\n");}
	return c;}
char put_check_sex(void){char sex; /*������� � ����� � �������� ����� ����*/
    sex=getchar ();
	while (sex != 'F'&& sex != 'M' && sex != 'f'&& sex != 'm'){
		printf ("Try again! \n");
		cleaner();
		sex=getchar();}
	if (sex== 'm')
	   sex='M';
	if (sex == 'f')
	   sex='F';
	return sex;}
int put_check_phonenumber(void){int a, b, c=0 ,count=0; /*������� �������� ����� �������� ������ ��������*/
	while (c!=9){
		if (count>0)
		    printf ("Unncorrect phone number. Try again! \n");
		b=check_number();
		a=b;
		abs(a);
		printf (" %d \n", abs(a));
		count++;
		while (b!=0){
		    c++;
			b /=10;}
		if (c!=9)
			c=0;}
	return abs(a);}
char put_check_operation(void){char operation; /*������� � ����� � �������� ����� ������*/
    operation=getchar ();
	while (operation != 'Y' && operation != 'N' && operation != 'y' && operation != 'n'){
		printf ("Try again! \n");
		operation=getchar();
		cleaner();}
	if (operation== 'y')
	   operation='Y';
	return operation;}
void cleaner(void){    /*������� ������� ������*/
	while (getchar() !='\n')
		continue;}
int check_nomer(){int c;      /*������� ��������  ������ �������*/
	while ((c=check_number())>MAX4 || c<0){
		if (c>MAX4)
	        printf ("Too much!\n");
	    if (c<0)
		    printf ("Minus?! No, is not possible! Try again!\n");}
	return c;}
void copy (struct knizhka *ukazatel, int a, int b){ /*������� ����������� �������� �������*/
	ukazatel[b]=ukazatel[a];}
void delete (struct knizhka *ukazatel, int a){ /*������� �������� �������� �������*/
	struct knizhka kkk = {{'\0', '\0'}, '\0', '\0', '\0'};
	for(a; a<MAX4; a++){
	    ukazatel[a]=ukazatel[a+1];}
	ukazatel[MAX4-1]= kkk;}
                    /*������ 2. ������ � �������.*/
int get_choice_file(void) {int b; /*������� ������ � ���� ������ � �������*/
    samo_menu_file();
    b=check_number();
    while (b!=1 &&b!=2 &&b!=3 &&b!=4){
	    printf ("Please choose right choice again!\n\n");
		b=check_number();}
	return b;}
void samo_menu_file(void){ /*������� �������� ���� ���� ������ � �������*/
    printf(" \nVyberite deystvie: \n\n "
    "1. Zagruzit dannye massiva v file. \n\n 2. Zagrusit dannye is fila v programmu. \n\n "
	"3. Steret dannye. \n\n 4. Viyti is raboty s filamy. \n\n");}
int check_name_file (char *name){ int a, i=0; /*������� �������� ������������ ����� ����� �����*/
    if (name[(i=strlen(name))-1]!='t' && name[i-2]!='a' && name[i-3]!='d' && name[i-4]!='.'){
	    printf ("You enter uncorrect namefile. Try again. \n");
		i=0;
		return 2;}
	else
	    return 1;}
