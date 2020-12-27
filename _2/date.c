#include<stdio.h>
#include<time.h>
int main(){

	time_t mytime;

	struct tm * ptm;

	time ( &mytime ); // Get local time in time_t

	ptm = gmtime ( &mytime ); // Find out UTC time

	int day = ptm->tm_wday;
	int date = ptm->tm_mday;
	int month = ptm->tm_mon;
	int year = ptm->tm_year+1900;
	int hour = ptm->tm_hour;
	int minute = ptm->tm_min;
	int second = ptm->tm_sec;

	if(day==0)
		printf("Sunday");
	if(day==1)
		printf("%s ", "Monday");
	if(day==2)
		printf("%s ", "Tuesday");
	if(day==3)
		printf("%s ", "Wednesday");
	if(day==4)
		printf("%s ", "Thursday");
	if(day==5)
		printf("%s ", "Friday");
	if(day==6)
		printf("%s ", "Saturday");

	printf("%d ", date);

	if(month==0)
		printf("%s ", "January");
	if(month==1)
		printf("%s ", "February");
	if(month==2)
		printf("%s ", "March");
	if(month==3)
		printf("%s ", "April");
	if(month==4)
		printf("%s ", "May");
	if(month==5)
		printf("%s ", "June");
	if(month==6)
		printf("%s ", "July");
	if(month==7)
		printf("%s ", "August");
	if(month==8)
		printf("%s ", "September");
	if(month==9)
		printf("%s ", "October");
	if(month==10)
		printf("%s ", "November");
	if(month==11)
		printf("%s ", "December");

	printf("%d ", year);
	printf("%d", hour);
	printf(":");
	printf("%d", minute);
	printf(":");
	printf("%d", second);
	printf(" UTC\n");
}