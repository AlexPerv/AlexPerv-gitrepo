#include <stdio.h>
#include <string.h>
int main(void)
/*
i-значени€ матрицы по горизонтали
j-значени€ матрицы по вертикали
l-значени€ промежуточной матрицы по горизонтали
k-значени€ промежуто матрицы по вертикали
n-счЄтчик є 1
x-промежуточна€ переменна€ є 1
y-промежуточна€ переменна€ є 2
o-промежуточна€ переменна€ є 1
p-промежуточна€ переменна€ є 2
*/
{
  int i, j, l, k, n, x, y, o, p, r;
  int A[15][15];
  char C[15][15];
  printf ("Vvedite znachenie pervogo ryada massiva v vide 0 ili 1.\n\n");
/*
ѕроивзольно вводим значени€ первого р€да матрицы
*/
  for (j=0, i=0; i<=14; i++) { 
    scanf ("%d", &A[0][i]);
        while (A[0][i]!=0 && A[0][i]!=1) {
        	printf ("Vi vveli nevernoe znachenie, poprobuyte snova:\n");
            scanf ("%d", &A[0][i]);
        }
    printf (" A[%d][%d]= %d \n", j, i, A[0][i]);
  }
/*
“ак как наша матрица размерностью 15 на 15, то соотвествеенно ручной ввод
остальных значений нашей матрицы довольно трудЄмок и затратен по времени.
ѕоэтому был создан алгоритм который по знаени€м первого р€да матрицы задает
значени€ остальных р€дов матрицы.
*/
  printf ("Seichas budut avtomotichescky opredeletsya ostalnyye" 
  "znacheniya dvuhmernogo massiva 15 na 15.\n\n\t\t");
  for (j=0, i=0; i<=14; i++) {
  	printf ("%d", A [j][i]); 
  }
  for (j=1; j<=14; j++) {
  	    printf ("\n");
        for (i=0; i<=14; i++) {
        	if (i==0) {
        		A[j][i]=A[j-1][i]^A[j-1][i+1]^A[j-1][14];}
			else if (i==14) {
        		A[j][i]=A[j-1][i]^A[j-1][i-1]^A[j-1][0];}
			else {
                A[j][i]=A[j-1][i-1]^A[j-1][i]^A[j-1][i+1];}
			printf ("%d", A [j][i]);
        }
   }
   printf ("\n");
/*
¬водим значени дл€ промежуточного массива
*/
  int a, b; 
  for (a=0; a<=14; a++){
        printf ("\n"); 
		for(b=0; b<=14; b++){
		    C[a][b]='*';}}
/*
Ќа данном этапе собственно выполн€етс€ условие саомой задачи. 
“о есть поиск четырехугольников предствленных значени€ми в виде 1 
и не соприкасающихс€ друг с другом.
*/
   for (j=0; j<=13; j++) {
        for (i=0; i<=13; i++) {
        	if ((A[j][i]*A[j][i+1]*A[j+1][i]*A[j+1][i+1])==1){
        		n++;
        		B[j][i]=1; B[j][i+1]=1; B[j+1][i]=1; B[j+1][i+1]=1;}	
        }
   }
/*
ƒанный цикл выводит второй массив, где можно более менее нагл€дно увидеть
какие многоугольники у нас вышли.
*/
   printf ("Kolichestvo 4ugolnikov ravno: %d", n);
   printf ("Seichas otobrsitsya massive c naydenymy 4ugolnikami ne peresekayushimsya grug s drugom.");
  int a, b; 
  for (a=0; a<=14; a++){
        printf ("\n"); 
		for(b=0; b<=14; b++){
			printf ("%с", C[a][b]); }}
   printf ("\n");
   system("pause");
   return 0;
}







