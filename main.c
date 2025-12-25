#include<stdio.h>
#include<string.h>

#define File_name "save.txt"

//function delclare
void add(char task[][100],int *count);
void del(char task[][100],int *count);
void view(char task[][100],int count);
void save(char tasks[][100], int count);
void load(char tasks[][100], int *count);


//print of option
int main(){

int choice;
char task[100][100]; //array to hold tasks
int count=0; //to keep track of number of tasks

// load task at the start
load(task,&count);

 
printf("TO DO MANAGER\n");
printf("1.add task\n");
printf("2.view task\n");
printf("3.delete task\n");

printf ("Enter your choice: ");
scanf("%d",&choice);
getchar(); // consume newline
   
switch(choice){
    case 1:
        add(task,&count);
        save(task,count);
        break;
    case 2:
      view(task,count);
      break;                                    
    case 3:
      del(task,&count);
      save(task,count);
      break;                
    default:
    printf("Invalid choice\n");
    break;


}
}

//add task function
void add(char task[][100],int *count) {   

    printf("Enter task: ");
    fgets(task[*count],100, stdin);
    task[*count][strcspn(task[*count], "\n")] = '\0';

    printf("Task added successfully\n");
    (*count)++;
}

//view task function
void view(char task[][100],int count){
    if(count==0){
        printf("No task has been added\n");
    }
    else{
        printf("Tasks:\n");
        for(int i=0;i<count;i++){
            printf("%d. %s\n",i+1,task[i]);
        }
    }
}

//delete task function
void del(char task[][100],int *count){
    int del_index;
    if(*count==0){
        printf("No task to delete\n");
        return;
    }
    printf("Enter task number to delete: ");
    scanf("%d",&del_index);
    if(del_index<1 || del_index>*count){
        printf("Invalid task number\n");
        return;
    }
    for(int i=del_index-1;i<*count-1;i++){
        strcpy(task[i],task[i+1]);
    }
    (*count)--;
    printf("Task deleted successfully\n");
}
 
// save function
void save(char tasks[][100], int count){
    FILE* fp=fopen(File_name,"w");

    if(fp==NULL){
        printf("there is an error in saving \n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
       fprintf(fp, "%s\n", tasks[i]);
    }

    fclose(fp);
    
}
//load function
void load(char tasks[][100], int *count){
        
    FILE* fp=fopen(File_name,"r");
    if (fp==NULL)
      return ;
    


     while (fgets(tasks[*count], 100, fp)) {
        tasks[*count][strcspn(tasks[*count], "\n")] = '\0';
        (*count)++;
    }
    fclose(fp);
}

