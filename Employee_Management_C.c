#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct getemployee{
       int id;
       char myname[30];
                            
       char designation[30];
        int salary ; 
};

void addemp(){
                system("cls");
                struct getemployee newemp ;
                     printf("Enter the  Employee id \n");
                     scanf("%d" , &newemp.id);
                     printf("Enter the Employee name\n");
                     scanf("%s" , newemp.myname);
                     
                     printf("Enter the designation of the Employee : \n");
                     scanf("%s" , newemp.designation);
                     printf("Enter the salary of the Employee : \n");
                     scanf("%d" , &newemp.salary);
                     
                     
                     FILE *file = fopen("emp_detail.txt" , "a+");
                     if(file == NULL){
                        printf("Errors Opening file!\n");
                        return ;
                     }
                     fprintf(file , "%d %s %s %d \n" , newemp.id , newemp.myname , newemp.designation , newemp.salary);
                     printf("\nSucessfully Added\n");
                     fclose(file);
                  
}

void listemp(){
           system("cls");
           FILE *file = fopen("emp_detail.txt" , "r");

         if(file == NULL){
            printf("No Employee details Available \n");
            return ;
           }

           struct getemployee emp;

           while(fscanf(file , "%d %s %s %d \n" , &emp.id , emp.myname , emp.designation , &emp.salary)!= EOF)
            printf("\t\t\t\nEmployee ID : %d , Employee Name : %s  , Employee Designation : %s , Salary : %d \n\n" , emp.id , emp.myname , emp.designation , emp.salary );
           

            fclose(file);
           
}

void deleteemp(int _id){
     system("cls");
  
      FILE *file = fopen("emp_detail.txt", "r");
    if (file == NULL) {
        printf("No record available.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    struct getemployee emp;
   while(fscanf(file , "%d %s %s %d \n" , &emp.id , emp.myname , emp.designation , &emp.salary)!= EOF) {
        if (emp.id != _id) {
            fprintf(tempFile, "%d %s %s %d\n", emp.id , emp.myname , emp.designation , emp.salary);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("emp_detail.txt");
    rename("temp.txt", "emp_detail.txt");
}

void updateemp(int _id){
     system("cls");
      FILE *file = fopen("emp_detail.txt", "r");
    if (file == NULL) {
        printf("No employee available.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    struct getemployee emp;
    while (fscanf(file , "%d %s %s %d \n" , &emp.id , emp.myname , emp.designation , &emp.salary) != EOF) {
        if (emp.id == _id) {
            printf("\t\t\t\nEnter new Employee Name: ");
            scanf("%s", &emp.myname);
            printf("\t\t\t\nEnter new salary: ");
            scanf("%d" , &emp.salary);
        }
        fprintf(tempFile, "%d %s %s %d\n", emp.id , emp.myname , emp.designation , emp.salary);
    }

    fclose(file);
    fclose(tempFile);

    remove("emp_detail.txt");
    rename("temp.txt", "emp_detail.txt");
}

int main(){

  //  struct getstudent student[10];
    // int count  = -1;
   int c , _id;

    while(1){
      //  system("cls");
      
        printf("\t\t\tPerform the following operation\n");
        printf("\t\t\t\t1. Add a Employee \n\t\t\t\t 2. Delete a Employee \n\t\t\t\t 3. Update employee record \n\t\t\t\t 4. List all Employee \n\t\t\t\t 5. Exit \n");
        scanf("%d" , &c);

        switch(c){
                 
          case 1:    addemp();   //Run
                      break;

          case  2: 
                     printf("\t\t\t\n Enter the Employee id to delete  : \n");
                     scanf("%d" , &_id);
                     deleteemp(_id);  
                     printf("\t\t\tSucessfully deleted\t\t\t\n");     
                     
                     break;      
            
          case 3: 
                   printf("\t\t\t\nEnter the employee id to update : ");
                   scanf("%d" , &_id);
                   updateemp(_id);
                   printf("\n\t\t\tSucessfully Updated\t\n ");
                   break;

          case 4:     listemp();
                        break;
                    
          case 5:    exit(0);
                      break;
                     

         default:
                   printf("\t\t\t\nInvalid choice\n");  
                                
        }

    }

    return 0;

}