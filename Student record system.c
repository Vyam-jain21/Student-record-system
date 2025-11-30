#include<stdio.h>
	// student record system
		struct record
		{
			char name[10];
			int roll;
			char address[100];
		};
		 
	void addStudent()
	{ 
		struct record stud;
		FILE *ptr;
			fflush(stdin);
			
			  printf(" \n Enter the record=");
			  printf("\n Enter the name=");
			  	gets(stud.name);
			  
			  fflush(stdin);
			  printf("\n Enter the roll=");
			    scanf("%d",&stud.roll);
			    
			  fflush(stdin);
			  
			printf("\n Enter the address=");
			  gets(stud.address);
			  
		 ptr=fopen("Vyam.txt","a");
		fwrite((char*)&stud,sizeof(stud),1,ptr);
		fclose(ptr);
	}
	void deleteStudent()
	{
		struct record stud;
		FILE *ptr,*ptr1;
		int r,found=0;
		printf("\n Enter the roll number to delete record=");
		scanf("%d",&r);

		ptr=fopen("Vyam.txt","r");
		ptr1=fopen("temp.txt","w");
		while(fread((char*)&stud,sizeof(stud),1,ptr))
		{
			if(stud.roll!=r)
			{
				fwrite((char*)&stud,sizeof(stud),1,ptr1);
			}
			else
			{
				found=1;
			}
		}
		fclose(ptr);
		fclose(ptr1);

		if(found)
		{
			remove("sahilsharma.txt");
			rename("temp.txt","sahilsharma.txt");
			printf("\n Record deleted successfully");
		}
		else
		{
			printf("\n Record not found");
		}
	}
	void searchStudent()
	{
		struct record stud;
		FILE *ptr;
		int r, found=0;
		printf("\n Enter the roll number to search=");
		scanf("%d",&r);
		ptr=fopen("Vyam.txt","r");
		while(fread((char*)&stud,sizeof(stud),1,ptr))
		{
			if(stud.roll==r)
			{
				found=1;
				printf("\n Name=%s",stud.name);
				printf("\n Roll=%d",stud.roll);
				printf("\n Address=%s",stud.address);
			}
		}
		if(!found)
		{
			printf("\n Record not found");
		}
		fclose(ptr);
	}
	
	void displayStudent()
	{
		struct record stud;
		FILE *ptr;
		ptr=fopen("Vyam.txt","r");
		while(fread((char*)&stud,sizeof(stud),1,ptr))
		{
			printf("\n Name=%s",stud.name);
			printf("\n Roll=%d",stud.roll);
			printf("\n Address=%s",stud.address);
		}
		fclose(ptr);
	}
	main()
	{
		int choice;
		do
		{
				printf("\n\t\t\t\t\t\t Students Record System.....");
				printf("\n\t\t\t\t\t\t Press 1: for insert the record.....");
				printf("\n\t\t\t\t\t\t Press 2: for delete the record.....");
				printf("\n\t\t\t\t\t\t Press 3: for search the record.....");
				printf("\n\t\t\t\t\t\t Press 4: for display the record.....");
				printf("\n\t\t\t\t\t\t Press 5: for exit.....");
				printf("\n\t\t\t\t\t\t Enter your choice=.....");
				scanf("%d",&choice);
				
				switch(choice)
				{
					case 1:
						addStudent();
						break;
					case 2:
						deleteStudent();
						break;
					case 3:
						searchStudent();
						break;
					case 4:
						displayStudent();
						break;
					case 5:
						printf("\n\t\t\t\t\t\tExit.....");
						break;
					default:
						printf("\n\t\t\t\t\t\t Wrong choice ,Try again ");
				}
		}
		while(choice!=5);
			
	}
