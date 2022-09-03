#include <stdio.h>
#include <stdlib.h>
//creating varables to read through file and store values 
struct spyInfo {
    int year;
    int day;
    int month;
    float ratio;
    int put_volume;
    int call_volume;
    int options_volume;
}*spy_object;
//reading through file using fopen 
int number_of_records(){
    FILE *fptr;
    fptr = fopen("SPY241Project.txt", "r");
    if (fptr == NULL)
    {//error checking for file 
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    //creating a loop to read values in file 
    int count = 0;
    char ch;
    while((ch = fgetc(fptr)) != EOF)
        {
            if(ch=='\n'){
                count++;
            }
        }
    
    return count;
}
//creating a table that will display all the values from file that were stored to an variable that was determined 
void display_all(int n){
    printf("Date\tTotal SPY Options Volume\tSPY Put Volume\tSPY Call Volume\tPut/Call Ratio\n");
    for(int i=0;i<n;i++){
        printf("%d/%d/%d\t\t",spy_object[i].day,spy_object[i].month,spy_object[i].year);
        printf("%d\t\t\t\t\t",spy_object[i].options_volume);
        printf("%d\t\t\t\t",spy_object[i].put_volume);
        printf("%d\t\t",spy_object[i].call_volume);
        printf("%f\n",spy_object[i].ratio);
    }
}
// allowing to search by an exact date 
void search(int n){
    int d,m,y;
    printf("Enter day :");
    scanf("%d",&d);
    printf("Enter month :");
    scanf("%d",&m);
    printf("Enter year :");
    scanf("%d",&y);
    
    for (int i=0; i<n; i++) {
        if(d==spy_object[i].day && m==spy_object[i].month && y==spy_object[i].year){
            printf("Date : %d/%d/%d\n",spy_object[i].day,spy_object[i].month,spy_object[i].year);
            printf("Put/Call Ratio: %f\n",spy_object[i].ratio);
            printf("SPY Put Volume: %d\n",spy_object[i].put_volume);
            printf("SPY Call Volume: %d\n",spy_object[i].call_volume);
            printf("Total SPY Options Volume: %d\n",spy_object[i].options_volume);
            return;
        }
    }//error checking 
    printf("Record not found!\n");
}
//creating an average  put to call ratio 
double average_put_call_ratio(int n){
    double avg = 0;
    for(int i=0;i<n;i++){
        avg += spy_object[i].ratio;
    }
    return (avg /= n);
}
//creating a put volume output 
double average_put_volume(int n){
    double avg = 0;
    for(int i=0;i<n;i++){
        avg += spy_object[i].put_volume;
    }
    return (avg /= n);
}
//creating a call volume output 
double average_call_valume(int n){
    double avg = 0;
    for(int i=0;i<n;i++){
        avg += spy_object[i].options_volume;
    }
    return (avg /= n);
}
//creating an aveage of the SPY volume 
double average_total_spy_option_volume(int n){
    double avg = 0;
    for(int i=0;i<n;i++){
        avg += spy_object[i].call_volume;
    }
    return (avg /= n);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//creating a display for the table to be displayed call from greatest to smallest call volume 
void sort_call_greates_to_smallest(int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++)
            if (spy_object[j].call_volume < spy_object[j+1].call_volume){
                swap(&spy_object[j].call_volume, &spy_object[j+1].call_volume);
                swap(&spy_object[j].put_volume, &spy_object[j+1].put_volume);
                float temp =spy_object[j].ratio;
                spy_object[j].ratio = spy_object[j+1].ratio;
                spy_object[j+1].ratio = temp;
                swap(&spy_object[j].day, &spy_object[j+1].day);
                swap(&spy_object[j].month, &spy_object[j+1].month);
                swap(&spy_object[j].year, &spy_object[j+1].year);
                swap(&spy_object[j].options_volume, &spy_object[j+1].options_volume);
            }
    }
    display_all(n);
}
//creating a display for the table to display put from greatest to smallest 
void sort_put_greates_to_smallest(int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++)
            if (spy_object[j].put_volume < spy_object[j+1].put_volume){
                swap(&spy_object[j].call_volume, &spy_object[j+1].call_volume);
                swap(&spy_object[j].put_volume, &spy_object[j+1].put_volume);
                float temp =spy_object[j].ratio;
                spy_object[j].ratio = spy_object[j+1].ratio;
                spy_object[j+1].ratio = temp;
                swap(&spy_object[j].day, &spy_object[j+1].day);
                swap(&spy_object[j].month, &spy_object[j+1].month);
                swap(&spy_object[j].year, &spy_object[j+1].year);
                swap(&spy_object[j].options_volume, &spy_object[j+1].options_volume);
            }
    }
    display_all(n);
}
//sorting the put from smallest to greatest volume 
void sort_put_smallest_greatest(int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++)
            if (spy_object[j].put_volume > spy_object[j+1].put_volume){
                swap(&spy_object[j].call_volume, &spy_object[j+1].call_volume);
                swap(&spy_object[j].put_volume, &spy_object[j+1].put_volume);
                float temp =spy_object[j].ratio;
                spy_object[j].ratio = spy_object[j+1].ratio;
                spy_object[j+1].ratio = temp;
                swap(&spy_object[j].day, &spy_object[j+1].day);
                swap(&spy_object[j].month, &spy_object[j+1].month);
                swap(&spy_object[j].year, &spy_object[j+1].year);
                swap(&spy_object[j].options_volume, &spy_object[j+1].options_volume);
            }
    }
    display_all(n);
}
//sorting call from smallest to greatest 
void sort_call_smallest_greatest(int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++)
            if (spy_object[j].call_volume > spy_object[j+1].call_volume){
                swap(&spy_object[j].call_volume, &spy_object[j+1].call_volume);
                swap(&spy_object[j].put_volume, &spy_object[j+1].put_volume);
                float temp =spy_object[j].ratio;
                spy_object[j].ratio = spy_object[j+1].ratio;
                spy_object[j+1].ratio = temp;
                swap(&spy_object[j].day, &spy_object[j+1].day);
                swap(&spy_object[j].month, &spy_object[j+1].month);
                swap(&spy_object[j].year, &spy_object[j+1].year);
                swap(&spy_object[j].options_volume, &spy_object[j+1].options_volume);
            }
    }
    display_all(n);
}
//allowing a menu to be created to interact with above functions and display infromation accoding to selection 
int menu(){
    printf("1-Search\n");
    printf("2-Average SPY Put/Call Ratio\n");
    printf("3-SPY Put Volume\n");
    printf("4-SPY Call Volume\n");
    printf("5-Total SPY Options Volume\n");
    printf("6-Sort call from geatest to smallest\n");
    printf("7-Sort put from geatest to smallest\n");
    printf("8-Sort call from smallest to greatest\n");
    printf("9-Sort put from smallest to greatest\n");
    printf("10-Display all in a table\n");
    printf("11-Exit program\n");
    int ch;
    scanf("%d",&ch);
    return ch;
}
//starting the program 
int main(int argc, const char * argv[]) {
    printf("Welome to SPY241Project\n");
    FILE *fptr;
    
    int no_of_record =number_of_records();
    printf("Record %d read\n",no_of_record);
    spy_object = (struct spyInfo*) malloc(no_of_record * sizeof(struct spyInfo));
    //opening the file 
    fptr = fopen("SPY241Project.txt", "r");
    if (fptr == NULL)
    {//error checking 
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    //sucessfull call of file 
    printf("The contents of %s file Read Successfully:\n", "SPY241Project.txt");
    char c[1000];
    float num[2];
    int call[2];
    fscanf(fptr, "%[^\n]", c);
    
    int i=0;
    int reader = 1;
    
    for(int j=0;j<no_of_record;j++){
        fscanf(fptr, "%[^,]", c);
        spy_object[i].day = c[reader] -'0';
        if(c[reader+1] != '/'){
            spy_object[i].day *= 10;
            spy_object[i].day +=c[reader+1] -'0';
            spy_object[i].month = c[reader+3] -'0';
            if(c[reader+4]!='/'){
                spy_object[i].month *= 10;
                spy_object[i].month +=c[reader+4] -'0';
                spy_object[i].year = c[reader+6] -'0';
                spy_object[i].year *= 10;
                spy_object[i].year += c[reader+7] -'0';
            }
            else{
                spy_object[i].year = c[reader+4] -'0';
                spy_object[i].year *= 10;
                spy_object[i].year += c[reader+5] -'0';}
        }else{
        spy_object[i].month = c[reader+2] -'0';
        if(c[reader+3]!='/'){
            spy_object[i].month *= 10;
            spy_object[i].month +=c[reader+3] -'0';
            spy_object[i].year = c[reader+5] -'0';
            spy_object[i].year *= 10;
            spy_object[i].year += c[reader+6] -'0';
        }
        else{
        spy_object[i].year = c[reader+4] -'0';
        spy_object[i].year *= 10;
            spy_object[i].year += c[reader+5] -'0';}}
        
        char get;
        while((get = fgetc(fptr)) != ','){}

        fscanf(fptr, "%f", &num[0]);
        spy_object[i].ratio = num[0];

        while((get = fgetc(fptr)) != ','){}

        fscanf(fptr, "%d", &call[0]);
        spy_object[i].put_volume = call[0];

        while((get = fgetc(fptr)) != ','){}

        fscanf(fptr, "%d", &call[0]);
        spy_object[i].call_volume = call[0];

        while((get = fgetc(fptr)) != ','){}

        fscanf(fptr, "%d", &call[0]);
        spy_object[i].options_volume = call[0];
        
        i++;
//        printf("Record %d read\n",i);
        if (i==1) {
            reader++;
        }
    }
    while (1) {
    //having menu selection select the right function to call for displayed values 2
    
    int ch = menu();
    if(ch==1)
        search(no_of_record);
    if(ch==2)
        printf("Average Put/Call Ratio : %f\n",average_put_call_ratio(no_of_record));
    if(ch==3)
        printf("Average Put Volume : %f\n",average_put_volume(no_of_record));
    if(ch==4)
        printf("Average Call Volume : %f\n",average_call_valume(no_of_record));
    if(ch==5)
        printf("Total SPY Options Volume : %f\n",average_total_spy_option_volume(no_of_record));
    if(ch==6)
        sort_call_greates_to_smallest(no_of_record);
    if(ch==7)
        sort_put_greates_to_smallest(no_of_record);
    if(ch==8)
        sort_call_smallest_greatest(no_of_record);
    if(ch==9)
        sort_put_smallest_greatest(no_of_record);
    if(ch==10)
        display_all(no_of_record);
    if(ch==11)
            break;
    }
    free(spy_object);
}
