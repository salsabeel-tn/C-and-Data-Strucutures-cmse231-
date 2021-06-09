#include <stdio.h>
struct studinfo {
	int stnr;
	char name[10];
	int grade;
};


void main() {
	int first, last, middle, search;
	int n=10;
	struct studinfo s[10];
	int cnt;
	FILE *stud_file;
	cnt=0 ;
	
	stud_file = fopen("C:\\Users\\CMPE117\\Desktop\\lab3.txt" , "r");
	while ( !feof(stud_file)) {   //eof = end of file
		fscanf(stud_file ,"%d %s %d" ,&s[cnt].stnr,&s[cnt].name,&s[cnt].grade); 
		cnt++;
	}
	fclose(stud_file);
	
	printf("Enter student number to find\n");
  	scanf("%d", &search);

	first = 0;
	last = n - 1;
	middle = (first+last)/2;

  	while (first <= last) {
	    if (s[middle].stnr < search) {
	    	first = middle + 1;
	    }
	    else if (s[middle].stnr== search) {
	    	printf("student number=%d name=%s grade=%d found at location= %d.\n",s[middle].stnr,s[middle].name,s[middle].grade , middle+1);
			break;
	    }
	    else {
	    	last = middle - 1;
	    }
	    middle = (first + last)/2;
	}
  	if (first > last)
    	printf("Not found! %d isn't present in the list.\n", search);
}

