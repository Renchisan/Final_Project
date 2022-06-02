#include<stdio.h>

typedef struct Pxaddress{
	char housenum[20];
	char street[20];
	char brgy[20];
	char city[20];
	char province[20];
}Pxaddress;
	
typedef struct Pxinfo{
	char category[5];
	char lastname[20];
	char firstname[20];
	char middlename[20];
	char contactnum[20];
	Pxaddress address;
	char sex[1];
	char birthdate[20];
	char vacmanu[20];
	char vacdate[20];
}Pxinfo;

void getDetails(FILE *file, Pxinfo a);
void importFile(FILE *file, FILE *importfile);
void displayRecords(FILE *file);

int main(){
	Pxinfo a;
	int c;
	
	printf("[1] - Add New Record\n[2] - Import Record\n[3] - Display All Records\n[4] - Exit\n");
	printf("What do you want to do? ");
	scanf("%d%*c", &c);
	FILE *file;
	FILE *importfile;
	
	switch(c){
		case 1:
			getDetails(file, a);
			break;
		case 2:
			importFile(file, importfile);
			break;
		case 3: 
			displayRecords(file);
			break;
		case 4:
			close();
			break;
		default:
			printf("Invalid Input! Please try again\n");
			system("pause");
			system("cls");
			main();
	}
	return 0;
}

void getDetails(FILE *file, Pxinfo a){
	file =  fopen("Vaxx.txt", "a");
	printf("\nPlease fill out the following.\n");
	printf("Category: ");
	gets(a.category);
	fprintf(file, "Category: %s\n",  a.category);
	printf("Last Name: ");
	gets(a.lastname);
	fprintf(file, "Last Name: %s\n",  a.lastname);
	printf("First Name: ");
	gets(a.firstname);
	fprintf(file, "First Name: %s\n",  a.firstname);
	printf("Middle Name: ");
	gets(a.firstname);
	fprintf(file, "Middle Name: %s\n",  a.firstname);
	printf("Contact Num.: ");
	gets(a.contactnum);
	fprintf(file, "Contact Num.: %s\n",  a.contactnum);
	
	printf("~~Address~~\nHouse Number: ");
	gets(a.address.housenum);
	fprintf(file, "~~Address~~\nHouse Number: %s\n",  a.address.housenum);
	printf("Street: ");
	gets(a.address.street);
	fprintf(file, "Street: %s\n",  a.address.street);
	printf("Barangay: ");
	gets(a.address.brgy);
	fprintf(file, "Barangay: %s\n",  a.address.brgy);
	printf("City: ");
	gets(a.address.city);
	fprintf(file, "City: %s\n",  a.address.city);
	printf("Province: ");
	gets(a.address.province);
	fprintf(file, "Province: %s\n",  a.address.province);
	
	printf("Sex(F/M): ");
	gets(a.sex);
	fprintf(file, "Sex: %s\n",  a.sex);
	printf("Birthdate: ");
	gets(a.birthdate);
	fprintf(file, "Birthdate: %s\n",  a.birthdate);
	printf("Vaccine Manufacturer: ");
	gets(a.vacmanu);
	fprintf(file, "Vaccine Manufacture: %s\n",  a.vacmanu);
	printf("Vaccination Date: ");
	gets(a.vacdate);
	fprintf(file, "Vaccination Date: %s\n\n",  a.vacdate);
	printf("\nAll of the information is stored successfully.\n\n");	
	
	fclose(file);
	main();
}

void importFile(FILE *file, FILE *importfile){
	char x[250];
	char import[50];
	printf("\nPlease enter the file (.txt) to be imported: ");
	scanf("%s", &import);
	file = fopen("Vaxx.txt", "a");
	importfile = fopen(import, "r");
	
	while(!feof(importfile)){
		fgets(x, 250, importfile); 
		fprintf(file, "%s", x);
	};
	fprintf(file, "\n\n");
	
	printf("\nThe file %s is appended to Vaxx.txt successfully.\n\n", &import);
	
	fclose(file);
	fclose(importfile);
	main();
}

void displayRecords(FILE *file){
	char x[250];
	file = fopen("Vaxx.txt", "r");
	
	printf("\n");
	while(!feof(file)){
		fgets(x, 250, file); 
		printf("%s", x);	
	};
	
	fclose(file);
	main();
}
