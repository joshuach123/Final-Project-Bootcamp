#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char dayz[][50] = {"week/monday.txt", "week/tuesday.txt", "week/wednesday.txt", "week/thursday.txt", "week/friday.txt", "week/saturday.txt", "week/sunday.txt"}; // Global variable stores all test file in the week folder

// =========
// FUNCTIONS
// =========

void menu();
void week();
void show();
void add();
void edit();
void remove();
void search();
int binary(struct Days ds[], int x, int target);
void split(struct Days dy[], int left, int right, int ch);
void sort(struct Days dy[], int x, int ch);
void merge(struct Days dy[], int left, int mid, int right, int ch);
void ask(int x);
void confirm(int x);
void time();

// ==========================================
// STRUCT (PLACEHOLDER FOR HOURS AND ACTIONS)
// ==========================================

struct Days{
	double hours; // Stores the time of schedule
	char action[50]; // Stores the activity at the current schedule
};

// =============
// MAIN FUNCTION
// =============

int main() {	

	int choice;
	
	while(1){
    
	    char string[100000];
		
		
		FILE *art = fopen("ascii.txt", "r"); // Open ascii art file
	
		while(fscanf(art, "%[^\n]\n", string) != EOF){
			printf("%s\n", string); // Displays ascii art
		}
		
		fclose(art);
	
		menu(); // Shows menu
		scanf("%d", &choice);
		system("@cls||clear");

		switch (choice){
      
    		case 1:{
	    		show(); // Shows all existing schedules
      			break;
			}
      
			case 2:{
	        	add(); // Adds a schedule
          		break;
	      	}
	
        	case 3:{
      			edit(); // Edits a schedule
      			break;
			}
      
       		case 4:{
      			remove(); // Removes a schedule
     	 		break;
			}
			case 5:{
				search(); // Search a specific schedule with the time
				break;
      		}
      		case 6:{
      			exit(0); // Exits the program
				break;
			}
    	}
  	}	
}

// =================================================
// FUNCTION (DISPLAYING ALL FEATURES IN THE PROGRAM)
// =================================================

void menu(){
		
	printf("_____________________________________\n");
	printf("| 1.| Show all schedules             |\n");
	printf("|---|--------------------------------|\n");
	printf("| 2.| Add schedule                   |\n");
	printf("|---|--------------------------------|\n");
	printf("| 3.| Edit schedule                  |\n");
	printf("|---|--------------------------------|\n");
	printf("| 4.| Remove schedule                |\n");
	printf("|---|--------------------------------|\n");
	printf("| 5.| Search specific schedule time  |\n");
	printf("|---|--------------------------------|\n");
	printf("| 6.| Exit                           |\n");
	printf("======================================\n");
    puts("");
    time(); // Displays current date and time
    puts("");
    printf("Choose a number of the feature: ");
		

}

// ========================================
// FUNCTION (DISPLAYING ALL DAYS IN A WEEK)
// ========================================

void week(){
		
	printf("_________________\n");
	printf("| 1.| Monday    |\n");
	printf("| 2.| Tuesday   |\n");
	printf("| 3.| Wednesay  |\n");
	printf("| 4.| Thursday  |\n");
	printf("| 5.| Friday    |\n");
	printf("| 6.| Saturday  |\n");
	printf("| 7.| Sunday    |\n");
	printf("| 0.| Back      |\n");
	printf("=================\n");
	puts("");

}

// =======================================
// FILE PROCESSING (SHOWING ALL SCHEDULES)
// =======================================

void show(){
	
	int c = 0;
	int count = 1;
	struct Days dy[50];
	
	system("@cls||clear");
	
	FILE *f1 = fopen(dayz[0], "r");
	printf("===============================\n");
	printf("Monday's Schedule :\n");
	
	while(fscanf(f1, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
    	printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on monday
		c++;
		count++;
	}
	
	printf("\n");
	count = 1;
    fclose(f1);
    
    FILE *f2 = fopen(dayz[1], "r");
    printf("____________________\n");
	printf("Tuesday's Schedule :\n");
	
	while(fscanf(f2, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on tuesday
    	c++;
		count++;
	}
	
  	printf("\n");
	count = 1;
    fclose(f2);
    
    FILE *f3 = fopen(dayz[2], "r");
    printf("______________________\n");
	printf("Wednesday's Schedule :\n");
	
	while(fscanf(f3, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on wednesday
		c++;
		count++;
	}
  	printf("\n");
	count = 1;
    fclose(f3);
    
    FILE *f4 = fopen(dayz[3], "r");
    printf("_____________________\n");
	printf("Thursday's Schedule :\n");
	
	while(fscanf(f4, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on thursday
		c++;
		count++;
	}
	
  	printf("\n");
	count = 1;
    fclose(f4);
    
    FILE *f5 = fopen(dayz[4], "r");
    printf("___________________\n");
	printf("Friday's Schedule :\n");
	
	while(fscanf(f5, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on friday
		c++;
		count++;
	}
	
  	printf("\n");
	count = 1;
    fclose(f5);
    
    FILE *f6 = fopen(dayz[5], "r");
    printf("_____________________\n");
	printf("Saturday's Schedule :\n");
	
	while(fscanf(f6, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on saturday
		c++;
		count++;
	}
	
	printf("\n");
	count = 1;
    fclose(f6);
    
	FILE *f7 = fopen(dayz[6], "r");
	printf("___________________\n");
	printf("Sunday's Schedule :\n");
	
	while(fscanf(f7, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on sunday
		c++;
		count++;
	}
	
  	printf("\n");
  	printf("===============================\n");
	count = 1;
    fclose(f7);
    
    printf("Press Enter key to continue!\n");
    while(getchar()!='\n');
    getchar(); // Recieves the enter key from stdin
    system("@cls||clear");
}

// ============================================
// FILE PROCESSING (ADDING A SCHEDULE TO A DAY)
// ============================================

void add(){
	
	int c = 0;
	struct Days ds;
	struct Days dy[50];
  
	while(1){
	  	int choose;
	    week();
	    printf("Which day would you like to choose? (Number)\n");
		scanf("%d", &choose); // Inputs user's chosen day
		system("@cls||clear");
    	
    	FILE *fadd;
    	
    	if (choose > 0 && choose < 8){
	    	fadd = fopen(dayz[choose - 1], "a");
		}
		
		else if (choose == 0){
			main();
			break;
		}
		
		else{
	      	printf("Invalid input\n");
			add();
		} 
		
    	int chs = choose;
    	puts("================================================================================\n");
      	puts("What time? (ex: 6.35 = 6 past 35 AM, 18.35 = 6 past 35 PM)");
		scanf("%lf", &ds.hours); // Inputs user's activity time
      	
      	puts("");
      	
	  	puts("What to do? (ex: study)");
	  	getchar();
    	scanf("%[^\n]", &ds.action); // Inputs user's activity
    	system("@cls||clear");
    	
      	fprintf(fadd,"%lf %s\n", ds.hours, ds.action); // Appends user's previous inputs to file
      	fclose(fadd);
	    
	    FILE *fadd1;
	    FILE *fadd2;
	    
	    if(choose > 0 && choose < 8){
	    	fadd1 = fopen(dayz[choose - 1], "a+");
	    	fadd2 = fopen(dayz[choose - 1], "r");
		} 
		
		else{
	      	printf("Invalid input\n");
			add();
		} 
		  
    	while(fscanf(fadd1, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
	        c++;
	    }
	      
	    if (c > 1){
	    	sort(dy, c, chs); // Sorts the schedule's time from early to late
	    }
	      
	    else{
	        fclose(fadd1);
	    }
	      
	    int stuff = 0;
	    int c2 = 1;
	    
	    puts("================================================================================\n");
	    puts("Here is your new schedule :\n"); // Displays updated schedule
	    
	  	while(fscanf(fadd2, "%lf %[^\n]\n", &dy[stuff].hours, dy[stuff].action) != EOF){
	  		
	  		printf("%d. %.2f %s\n", c2, dy[stuff].hours, dy[stuff].action); // Displays updated schedule
	    	stuff++;
	    	c2++;
	    }
	    
	    fclose(fadd2);
	    fclose(fadd1);
			 
		puts("");
	    
	    int chos = 1;
	    
		ask(chos); // Asks user if they want to add another schedule
		
      	break;
    }
    
}

// =======================================================
// FILE PROCESSING (UPDATING A SPECIFIC SCHEDULE IN A DAY)
// =======================================================

void edit(){
  
  	int choose;
  
  	while(1){

		week();
		printf("Which day would you like to choose? (Number)\n"); 
		scanf("%d", &choose); // Inputs user's chosen day
		system("@cls||clear");
		
		int chs = choose;
		int c1 = 1;
		int c = 1;
		int lin;
		int counter = 0;
		struct Days ds[50];
		struct Days dy[50];
		struct Days tmp;
		
		FILE *fp;
		
		if(choose > 0 && choose < 8){
			fp = fopen(dayz[choose - 1], "r+");
		}
		
		else if (choose == 0){
			main();
			break;
		}
		
		else{
	      	printf("Invalid input\n");
			edit();
		} 
		  
		while(fscanf(fp, "%lf %[^\n]\n", &ds[counter].hours, ds[counter].action) != EOF){ // Getting all schedules from txt file (each schedule is within a single line)
		
			printf("%d. %.2f %s\n", c, ds[counter].hours, ds[counter].action); // Shows all current schedules within the chosen day
			counter++;
			c++;
		}
		puts("================================================================================\n");
		puts("Which schedule would you like to change? (Insert schedule number)");
		scanf("%d", &lin); // Inputs user's choice of schedule to be changed
		system("@cls||clear");
		
		puts("================================================================================\n");
		puts("What time? (ex: 6.35 = 6 past 35 AM, 18.35 = 6 past 35 PM)");
		scanf("%lf", &tmp.hours); // Inputs user's updated activity time
		
		puts("");
		
		puts("What to do? (ex: study)");
		getchar(); 
		scanf("%[^\n]", &tmp.action); // Inputs user's updated activity
		
		puts("");
    
		int cons = 1;
		
		confirm(cons); // Asks user's confirmation to update schedule
    	
    	puts("================================================================================\n");
    	puts("Here is your new schedule :\n"); // Displays updated schedule
    
    	FILE *fc;
    
	    if(choose > 0 && choose < 8){
	    	fc = fopen(dayz[choose - 1], "w+");
		}
		
	   	for (int i = 1; i <= counter; i++){
	        if (i == lin){
	            fprintf(fc, "%lf %s\n", tmp.hours, tmp.action);
	            c1++;
	        }
	        
	        else{
	            fprintf(fc, "%lf %s\n", ds[i-1].hours, ds[i-1].action);
	            c1++;
	        }
	    }
	    
	  	fclose(fp);
		fclose(fc);
	        
	    FILE *fa;
	    FILE *ff;
		
		if(choose > 0 && choose < 8){
			fa = fopen(dayz[choose - 1], "a+");
			ff = fopen(dayz[choose - 1], "r");
		}
		
        
      	int count = 0;
      	while(fscanf(fa, "%lf %[^\n]\n", &dy[count].hours, dy[count].action) != EOF){
        	count++;
    	}
    
     	if (count > 1){
        	sort(dy, count, chs); // Sorts the updated schedule's time from early to late
      	}
      
      	else{
        	fclose(fa);
      	}
      	
      	int stuff = 0;
      	int c2 = 1;
      	
      	
      	while(fscanf(ff, "%lf %[^\n]\n", &dy[stuff].hours, dy[stuff].action) != EOF){
      		
      		printf("%d. %.2f %s\n", c2, dy[stuff].hours, dy[stuff].action); // Displays updated schedule
        	stuff++;
        	c2++;
      	}
      	
      	fclose(ff);
      	fclose(fa);
      	
      	puts("");
	    
	    int chos = 2; 
	    
		ask(chos); // Asks user if they want to edit another schedule
        break;
    }
}

// =======================================================
// FILE PROCESSING (REMOVING A SPECIFIC SCHEDULE IN A DAY)
// =======================================================

void remove(){
	
	int choose;
  
	while(1){
		
	    week();
	    printf("Which day would you like to choose? (Number)\n");
	    scanf("%d", &choose); // Inputs user's chosen day
	    system("@cls||clear");
	    
	    FILE *fp;
	    
	    if(choose > 0 && choose < 8){
	    	fp = fopen(dayz[choose - 1], "r");
		}
		
		else if (choose == 0){
			main();
			break;
		}
		
		else{
	      	printf("Invalid input\n");
			remove();
		}
		
		
		
	  	int c1 = 1;
	    int c = 1;
	    int lin;
	    int counter = 0;
		int count = 0;
		
	  	struct Days ds[50];
	  	struct Days tmp;
	  	
		while(fscanf(fp, "%lf %[^\n]\n", &ds[counter].hours, ds[counter].action) != EOF){ // Getting all schedules from txt file (each schedule is within a single line)
	    	printf("%d. %.2f %s\n", c, ds[counter].hours, ds[counter].action); // Shows all current schedules within the chosen day
	    	counter++;
	    	c++;
		}
		
		puts("================================================================================\n");
	    puts("Which schedule would you like to remove? (Insert schedule number)");
	    scanf("%d", &lin); // Inputs user's choice of schedule to be removed
	    
	    puts("");
	    
		int cons = 2;
		
		confirm(cons); // Asks user's confirmation to remove schedule
	    
	    puts("================================================================================\n");
	    puts("Here is your new schedule :\n"); // Displays updated schedule
	    
	    FILE *fc;
	    
	    if(choose > 0 && choose < 8){
	    	fc = fopen(dayz[choose - 1], "w+");
		}
	
		for (int i = 1; i <= counter; i++){
	        if (i == lin){
	           continue;
	        }
	        
	        else{
	            fprintf(fc, "%lf %s\n", ds[i-1].hours, ds[i-1].action); // Writes updated schedule to file
	            printf("%d. %.2f %s\n", c1, ds[i-1].hours, ds[i-1].action); // Displays updated schedule
	            c1++;
	        }
	    }
	    
      	fclose(fp);
    	fclose(fc);
        
        puts("");
	    
	    int chos = 3;
	    
		ask(chos); // Asks user if they want to remove another schedule
		
        break;
    }
}

// =============================================
// SCHEDULE SEARCH SYSTEM BASED ON SPECIFIC TIME
// =============================================

void search(){
	
  	int trg;
	double num;

	puts("================================================================================\n");
	puts("What time would you like to search in the schedule? (ex: 1835 = 6 past 35 PM)");
	scanf("%lf", &num); // Inputs a specific time of schedule to be searched
	system("@cls||clear");
  
	trg = num*100.01;
	
	int choose;
	week();
    printf("Which day would you like to choose? (Number)\n");
    scanf("%d", &choose); // Inputs user's chosen day
    system("@cls||clear");
    
    FILE *fp;
    
    if(choose > 0 && choose < 8){
    	fp = fopen(dayz[choose - 1], "r");
	}
	
	else if (choose == 0){
		main();
	}
	
	else{
	    printf("Invalid input\n");
		search();
	}
    
    int c = 1;
    int counter = 0;
    struct Days ds[50];
    
    while(fscanf(fp, "%lf %[^\n]\n", &ds[counter].hours, ds[counter].action) != EOF){ // Getting all schedules from txt file (each schedule is within a single line)
    	counter++;
    	c++;
	}
	
	binary(ds, c, trg); // Binary Search System
    
    int idx = binary(ds, c, trg);
    
    if (binary(ds, c, trg) == -1){ // Condition if there is no match
    	puts("================================================================================\n");
    	puts("No schedule at this time in this day\n");
    	
    	puts("");
	    
	    int chos = 4; // Asks user if they want to search another schedule
	    
		ask(chos);
    	
    	
	}
	
	else{ // Condition if there is a match
		puts("================================================================================\n");
	    puts("Here is the schedule:");
	    puts("");
	    printf("%s\n", ds[idx].action);
	    
	    puts("");
	    
	    int chos = 4;
	    
		ask(chos); // Asks user if they want to search another schedule
	}
    
}

// ====================
// BINARY SEARCH SYSTEM
// ====================

int binary(struct Days ds[50], int x, int target){
	
	int min = 0;
	int max = x - 1;
	
	while(min <= max){
		int mid = (min + max) / 2;
		
		if (target < (int)(ds[mid].hours*100.01)){
			max = mid - 1;
		}
		
		else if (target > (int)(ds[mid].hours*100.01)){
			min = mid + 1;
		}
		
		else if (target == (int)(ds[mid].hours*100.01)){
			return mid;
		}
	}
	return -1;
}

// ===========
// SORT SYSTEM
// ===========

void sort(struct Days dy[100], int x, int ch){
	split(dy, 0, x - 1, ch);
}

// ============
// SPLIT SYSTEM
// ============

void split(struct Days dy[50], int left, int right, int ch){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    split(dy, left, mid, ch);
    split(dy, mid + 1, right, ch);

    merge(dy, left, mid, right, ch);
}

// =================
// MERGE SORT SYSTEM 
// =================

void merge(struct Days dy[50], int left, int mid, int right, int ch){
	
	FILE *fm;
	
	if (ch > 0 && ch < 8){
		fm = fopen(dayz[ch - 1], "r");
	}
	
	int count = 0;
	
	while(fscanf(fm, "%lf %[^\n]\n", &dy[count].hours, dy[count].action) != EOF){
    	count++;
    }
	
	long int sizeL = mid - left + 1;
	long int sizeR = right - mid;
	
	struct Days arrL[sizeL];
	struct Days arrR[sizeR];
	
	for (int i = 0; i < sizeL; i++){
		arrL[i] = dy[i + left];
	}
	
	for (int j = 0; j < sizeR; j++){
		arrR[j] = dy[j + mid + 1];
	}
	
	int idx = left;
	int idxL = 0;
	int idxR = 0;
	
    while(idxL < sizeL && idxR < sizeR){
        if(arrL[idxL].hours < arrR[idxR].hours){
            dy[idx] = arrL[idxL];
            idx++;
            idxL++;
        }
        else{
            dy[idx] = arrR[idxR];
            idx++;
            idxR++;
        }
    }

    while(idxL < sizeL){
        dy[idx] = arrL[idxL];
        idx++;
        idxL++;
    }

    while(idxR < sizeR){
        dy[idx] = arrR[idxR];
        idx++;
        idxR++;
    }
    
    FILE *fs;
    
	if (ch > 0 && ch < 8){
		fs = fopen(dayz[ch - 1], "w+");
	}

	
	for (int k = 0; k < count; k++){
		fprintf(fs, "%lf %s\n", dy[k].hours, dy[k].action);
	}
	fclose(fs);
	fclose(fm);
}

// ====================
// CONFIRMATION SYSTEMS
// ====================

void ask(int x){
	
	while(1){
		
		if(x == 1){
        	puts("Would you like to add again?");
    	}
    	
    	if(x == 2){
        	puts("Would you like to edit again?");
    	}
    	
    	if(x == 3){
        	puts("Would you like to remove again?");
    	}
    	
    	if(x == 4){
        	puts("Would you like to search again?");
    	}
    	
        puts("(Yes or No)");
    	
    	char *jwb;
		char y[] = {"yes"};
		char n[] = {"no"};
    	
    	scanf("%s", jwb);
    	
    	int len = strlen(jwb);
    	
    	for(int g = 0; g < len; g++){
    		jwb[g] = tolower((unsigned char) jwb[g]); // Changes user's input to lower characters
		}
    	
    	
    	system("@cls||clear");
    	
    	if (strcmp(jwb, y) == 0){
    		if(x == 1){
    			add();
    			break;
			}
			else if(x == 2){
    			edit();
    			break;
			}
			else if(x == 3){
    			remove();
    			break;
			}
			else if(x == 4){
    			search();
    			break;
			}
		}
		
		else if (strcmp(jwb, n) == 0){
			break;
		}
		
		else{
			puts("Invalid input\n");
			continue;
		}
	}
}

void confirm(int x){
	
	while(1){
		
		if(x == 1){
        	puts("Are you sure you want to update?");
    	}
    	
    	if(x == 2){
        	puts("Are you sure you want to remove?");
    	}	
    	
        puts("(Yes or No)");
    	
    	char *jwb;
		char y[] = {"yes"};
		char n[] = {"no"};
    	
    	scanf("%s", jwb);
    	
    	int len = strlen(jwb);
    	
    	for(int g = 0; g < len; g++){
    		jwb[g] = tolower((unsigned char) jwb[g]); // Changes user's input to lower characters
		}
    	
    	
    	system("@cls||clear");
    	
    	if (strcmp(jwb, y) == 0){
			break;
		}
		
		else if (strcmp(jwb, n) == 0){
			main();
			break;
		}
		
		else{
			puts("Invalid input\n");
			continue;
		}
	}
}

// =================
// DISPLAYS REALTIME
// =================

void time(){
 
    time_t x;
 
    time(&x);
 
    printf("Today is %s", ctime(&x));
}
