// Author: Mohamad Elchami Date: September 26th Description: arranges given information in proper format //

#include <stdio.h>

int main(void)
{
  int item, day, month, year;
  float price;

  printf("Enter item number: ");
  scanf("%d", &item);
  printf("Enter the price: ");
  scanf("%f", &price);
    if(price>999.99)
    {
      price=999.99;
    }
  printf("Enter the date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  printf("Item \t Unit Price \t Purchase Date\n");
  printf("%d \t $%6.2f \t %d/%d/%d\n", item, price, month, day, year);

  return 0;
}
