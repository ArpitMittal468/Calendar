#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int leapyear(int i)
{
  if (i % 100 == 0)
  {
    if (i % 400 == 0)
      return 1;
    else
      return 0;
  }
  else
  {
    if (i % 4 == 0)
      return 1;
    else
      return 0;
  }
}
void printcalendar(int years, int months)
{
  long long int day = 1;
  int index, pdate, c;
  char o[49], t[49];
  char pmon[12][10] = {"January", "Febraury", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  for (int i = 0; i < 49; i++)
    o[i] = 32, t[i] = 32;
  if (leapyear(years))
    day -= 1;
  for (int i = 1901; i <= years; i++)
  {
    day += 365;
    if (leapyear(i))
      day += 1;
  }
  if (leapyear(years) && months > 2)
    day += 1;
  switch (months - 1)
  {
  case 12:
    day += 31;
  case 11:
    day += 30;
  case 10:
    day += 31;
  case 9:
    day += 30;
  case 8:
    day += 31;
  case 7:
    day += 31;
  case 6:
    day += 30;
  case 5:
    day += 31;
  case 4:
    day += 30;
  case 3:
    day += 31;
  case 2:
    day += 28;
  case 1:
    day += 31;
  }
  switch (months)
  {
  case 12:
    pdate = 31;
    break;
  case 11:
    pdate = 30;
    break;
  case 10:
    pdate = 31;
    break;
  case 9:
    pdate = 30;
    break;
  case 8:
    pdate = 31;
    break;
  case 7:
    pdate = 31;
    break;
  case 6:
    pdate = 30;
    break;
  case 5:
    pdate = 31;
    break;
  case 4:
    pdate = 30;
    break;
  case 3:
    pdate = 31;
    break;
  case 2:
    if (leapyear(years))
      pdate = 29;
    else
      pdate = 28;
    break;
  case 1:
    pdate = 31;
    break;
  }
  index = day % 7;
  int a, b;
  //printf("%d %d\n",index,pdate);
  c = months - 1;
  for (int i = index; i < pdate + index; i++)
  {
    a = i - index + 1;
    b = a % 10;
    o[i] = 48 + b;
    b = a / 10;
    if (b != 0)
      t[i] = b + 48;
  }
  int dp = 186, sp = 205, upr = 187, upl = 201, lwr = 188, lwl = 200, s = 32;
  //dp=sp=upr=upl=lwr=lwl=176;
  printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", upl, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, upr);
  printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", dp, s, upl, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, upr, s, dp);
  printf("      %c%c%c     %10s %6d   %6c%c%c\n", dp, s, dp, pmon[c], years, dp, s, dp);
  printf("      %c%c%c%30c%c%c%c\n", dp, s, dp, s, dp, s, dp);
  printf("      %c%c%c SUN MON TUE WED THU FRI SAT  %c%c%c\n", dp, s, dp, dp, s, dp);
  printf("      %c%c%c%30c%c%c%c\n", dp, s, dp, s, dp, s, dp);
  printf("      %c%c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c%c\n", dp, s, dp, t[0], o[0], t[1], o[1], t[2], o[2], t[3], o[3], t[4], o[4], t[5], o[5], t[6], o[6], dp, s, dp);
  printf("      %c%c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c%c\n", dp, s, dp, t[7], o[7], t[8], o[8], t[9], o[9], t[10], o[10], t[11], o[11], t[12], o[12], t[13], o[13], dp, s, dp);
  printf("      %c%c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c%c\n", dp, s, dp, t[14], o[14], t[15], o[15], t[16], o[16], t[17], o[17], t[18], o[18], t[19], o[19], t[20], o[20], dp, s, dp);
  printf("      %c%c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c%c\n", dp, s, dp, t[21], o[21], t[22], o[22], t[23], o[23], t[24], o[24], t[25], o[25], t[26], o[26], t[27], o[27], dp, s, dp);
  printf("      %c%c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c%c\n", dp, s, dp, t[28], o[28], t[29], o[29], t[30], o[30], t[31], o[31], t[32], o[32], t[33], o[33], t[34], o[34], dp, s, dp);
  printf("      %c%c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c%c\n", dp, s, dp, t[35], o[35], t[36], o[36], t[37], o[37], t[38], o[38], t[39], o[39], t[40], o[40], t[41], o[41], dp, s, dp);
  printf("      %c%c%c%30c%c%c%c\n", dp, s, dp, s, dp, s, dp);
  printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", dp, s, lwl, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, lwr, s, dp);
  printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", lwl, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, lwr);
}
int main()
{
  HWND wh = GetConsoleWindow();
  MoveWindow(wh, 500, 300, 390, 400, TRUE);
  system("title Calendar");

  int years, months;
  int j;
  system("color e0"); // YELLOW
again:
  system("cls");
  printf("\n\n                  > CALENDAR <\n\n");
  printf("\e[?25l");
  printf("                     Press:\n\n");
  printf("               1 : Years Calendar\n");
  printf("               2 : Month Calendar\n");
  j = getch();
  if (j == 49)
  {
  again2:
    system("cls");
    printf("\n\n                  > CALENDAR <\n\n");
    printf("                 Enter Year : ");
    scanf("%d", &years);
    if (years < 1900)
      goto again2;
    system("cls");
    printf("\n\n                  > CALENDAR <\n\n");
    for (int i = 1; i <= 12; i++)
      printcalendar(years, i);
  }
  else if (j == 50)
  {
  again1:
    system("cls");
    printf("\n\n                  > CALENDAR <\n\n");
    printf("                 Enter Year : ");
    scanf("%d", &years);
    printf("                 Enter Month: ");
    scanf("%d", &months);
    if (months > 12 || years < 1900)
      goto again1;
    system("cls");
    printf("\n\n                  > CALENDAR <\n\n");
    printcalendar(years, months);
  }
  else
    goto again;
  printf("          Press any key to continue. . .");
  getch();
  system("cls");
  goto again;
}
