#include <stdio.h>
#include <string.h>

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

// ==========================================
// STRUCT (PLACEHOLDER FOR HOURS AND ACTIONS)
// ==========================================

struct Days{
			long long int hours;
			char action[50];	
};

// =============
// MAIN FUNCTION
// =============

int main() {	

	int choice;

	do{
		menu(); // Shows menu
    	scanf("%d", &choice);

		switch (choice){
      
    		case 1:{
	    		show();
      		break;
				}
      
			case 2:{
	        	add();
          		break;
	      	}
	
        	case 3:{
      			edit();
      			break;
			}
      
       		case 4:{
      			remove();
     	 		break;
			}
			case 5:{
				search();
				break;
      }
      case 6:{
        break;
      }
    }
  	}	while(choice != 7);
}

// =================================================
// FUNCTION (DISPLAYING ALL FEATURES IN THE PROGRAM)
// =================================================

void menu(){
	
		printf("1. Show all schedules\n");
		printf("2. Add schedule\n");
		printf("3. Edit schedule\n");
		printf("4. Remove schedule\n");
		printf("5. Search specific schedule time\n");
		printf("6. Exit\n");

}

// ========================================
// FUNCTION (DISPLAYING ALL DAYS IN A WEEK)
// ========================================

void week(){

		printf("1. Monday\n");
		printf("2. Tuesday\n");
		printf("3. Wednesay\n");
		printf("4. Thursday\n");
		printf("5. Friday\n");
		printf("6. Saturday\n");
		printf("7. Sunday\n");

}

// ============================================
// FILE PROCESSING (SHOWING ALL SCHEDULES)
// ============================================

void show(){
	int c = 0;
	int count = 1;
	struct Days dy[50];
	FILE *f1 = fopen("monday.txt", "r");
	printf("Monday's Schedule :\n");
	while(fscanf(f1, "%lld %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		double hour = dy[c].hours / 100;
		int minu = dy[c].hours % 100;
		(minu == 0) ? printf("%d. %.2f %s\n", count, hour, dy[c].action) : printf("%d. %.0f.%d %s\n", count, hour, minu, dy[c].action);
		c++;
		count++;
	}
  printf("\n");
	count = 1;
    fclose(f1);
    
    FILE *f2 = fopen("tuesday.txt", "r");
	printf("Tuesday's Schedule :\n");
	while(fscanf(f2, "%lld %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		double hour = dy[c].hours / 100;
		int minu = dy[c].hours % 100;
		(minu == 0) ? printf("%d. %.2f %s\n", count, hour, dy[c].action) : printf("%d. %.0f.%d %s\n", count, hour, minu, dy[c].action);
		c++;
		count++;
	}
  printf("\n");
	count = 1;
    fclose(f2);
    
    FILE *f3 = fopen("wednesday.txt", "r");
	printf("Wednesday's Schedule :\n");
	while(fscanf(f3, "%lld %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		double hour = dy[c].hours / 100;
		int minu = dy[c].hours % 100;
		(minu == 0) ? printf("%d. %.2f %s\n", count, hour, dy[c].action) : printf("%d. %.0f.%d %s\n", count, hour, minu, dy[c].action);
		c++;
		count++;
	}
  printf("\n");
	count = 1;
    fclose(f3);
    
    FILE *f4 = fopen("thursday.txt", "r");
	printf("Thursday's Schedule :\n");
	while(fscanf(f4, "%lld %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		double hour = dy[c].hours / 100;
		int minu = dy[c].hours % 100;
		(minu == 0) ? printf("%d. %.2f %s\n", count, hour, dy[c].action) : printf("%d. %.0f.%d %s\n", count, hour, minu, dy[c].action);
		c++;
		count++;
	}
  printf("\n");
	count = 1;
    fclose(f4);
    
    FILE *f5 = fopen("friday.txt", "r");
	printf("Friday's Schedule :\n");
	while(fscanf(f5, "%lld %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		double hour = dy[c].hours / 100;
		int minu = dy[c].hours % 100;
		(minu == 0) ? printf("%d. %.2f %s\n", count, hour, dy[c].action) : printf("%d. %.0f.%d %s\n", count, hour, minu, dy[c].action);
		c++;
		count++;
	}
  printf("\n");
	count = 1;
    fclose(f5);
    
    FILE *f6 = fopen("saturday.txt", "r");
	printf("Saturday's Schedule :\n");
	while(fscanf(f6, "%lld %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		double hour = dy[c].hours / 100;
		int minu = dy[c].hours % 100;
		(minu == 0) ? printf("%d. %.2f %s\n", count, hour, dy[c].action) : printf("%d. %.0f.%d %s\n", count, hour, minu, dy[c].action);
		c++;
		count++;
	}printf("\n");
	count = 1;
    fclose(f6);
    
	FILE *f7 = fopen("sunday.txt", "r");
	printf("Sunday's Schedule :\n");
	while(fscanf(f7, "%lld %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		double hour = dy[c].hours / 100;
		int minu = dy[c].hours % 100;
		(minu == 0) ? printf("%d. %.2f %s\n", count, hour, dy[c].action) : printf("%d. %.0f.%d %s\n", count, hour, minu, dy[c].action);
		c++;
		count++;
	}
  printf("\n");
	count = 1;
    fclose(f7);
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
      printf("Which day would you like to choose (Number)\n");
      scanf("%d", &choose);
    
    FILE *fadd;
    
    if(choose == 1){
    	fadd = fopen("monday.txt", "a");
	}
	else if(choose == 2){
		fadd = fopen("tuesday.txt", "a");
	}
	else if(choose == 3){
		fadd = fopen("wednesday.txt", "a");
	}
	else if(choose == 4){
		fadd = fopen("thursday.txt", "a");
	}
	else if(choose == 5){
		fadd = fopen("friday.txt", "a");
	}
	else if(choose == 6){
		fadd = fopen("saturday.txt", "a");
	}
	else if(choose == 7){
		fadd = fopen("sunday.txt", "a");
	}
	else{
      	printf("Invalid input\n");
		add();
	}
    	int chs = choose;
      puts("What time? (ex: 1835 = 6 past 35 PM)");
			scanf("%lld", &ds.hours);
      
	  	puts("What to do? (ex: study)");
	  	getchar();
    	scanf("%[^\n]", &ds.action);
    	
      fprintf(fadd,"%lld %s\n", ds.hours, ds.action); 
      fclose(fadd);
    
    FILE *fadd1;
    
    if(choose == 1){
			fadd1 = fopen("monday.txt", "a+");
	}
    else if(choose == 2){
			fadd1 = fopen("tuesday.txt", "a+");
	}
    else if(choose == 3){
			fadd1 = fopen("wednesday.txt", "a+");
	}
    else if(choose == 4){
			fadd1 = fopen("thursday.txt", "a+");
	}
    else if(choose == 5){
			fadd1 = fopen("friday.txt", "a+");
	}
    else if(choose == 6){
			fadd1 = fopen("saturday.txt", "a+");
	}
    else if(choose == 7){
			fadd1 = fopen("sunday.txt", "a+");
	}
	else{
      	printf("Invalid input\n");
		add();
	}
	
      while(fscanf(fadd1, "%lld %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
        c++;
      }
      
      if (c > 1){
        sort(dy, c, chs);
      }
      
      else{
        fclose(fadd1);
      }
      
      fclose(fadd1);

        puts("Would you like to add again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		add();
		}
		else if (strcmp(jwb, n) == 0){
			main();
		}
		else{
			puts("Invalid input");
		}

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
    scanf("%d", &choose);
    
   	int chs = choose;
  	int c1 = 1;
    int c = 1;
    int lin;
    int counter = 0;
  	struct Days ds[50];
  	struct Days dy[50];
  	struct Days tmp;
    
    FILE *fp;
    
    if(choose == 1){
    	fp = fopen("./monday.txt", "r");
	}

	else if(choose == 2){
    	fp = fopen("./tuesday.txt", "r+");
	}
	
	else if(choose == 3){
    	fp = fopen("./wednesday.txt", "r+");
	}
	
	else if(choose == 4){
    	fp = fopen("./thursday.txt", "r+");
	}
	
	else if(choose == 5){
    	fp = fopen("./friday.txt", "r+");
	}
	
	else if(choose == 6){
    	fp = fopen("./saturday.txt", "r+");
	}
	
	else if(choose == 7){
    	fp = fopen("./sunday.txt", "r+");
	}
	
      
	while(fscanf(fp, "%lld %[^\n]\n", &ds[counter].hours, ds[counter].action) != EOF){
    	printf("%d. %lld %s\n", c, ds[counter].hours, ds[counter].action);
    	counter++;
    	c++;
		}
      
    puts("Which schedule would you like to change? (Insert schedule number)");
  	scanf("%d", &lin);
      
	puts("What time? (ex: 1835 = 6 past 35 PM)");
	scanf("%lld", &tmp.hours);
      
	puts("What to do? (ex: study)");
	getchar();
	scanf("%[^\n]", &tmp.action);
    
    while(1){
        char cnm[10];
        puts("Are you sure you want to update? (YES OR NO) (ALL CAPS)");
        scanf("%s", &cnm);
    	int len = strlen(cnm);
		bool ans = (len % 2 == 0);
		
		
    	if (ans == 0){
    		break;
		}
		else if (ans == 1){
			main();
			break;
		}
		else{
			continue;
		}
	}
    
    FILE *fc;
    
    if(choose == 1){
    	fc = fopen("./monday.txt", "w+");
	}

	else if(choose == 2){
    	fc = fopen("./tuesday.txt", "w+");
	}
	
	else if(choose == 3){
    	fc = fopen("./wednesday.txt", "w+");
	}
	
	else if(choose == 4){
    	fc = fopen("./thursday.txt", "w+");
	}
	
	else if(choose == 5){
    	fc = fopen("./friday.txt", "w+");
	}
	
	else if(choose == 6){
    	fc = fopen("./saturday.txt", "w+");
	}
	
	else if(choose == 7){
    	fc = fopen("./sunday.txt", "w+");
	}
	
   	for (int i = 1; i <= counter; i++){
        if (i == lin){
            fprintf(fc, "%lld %s\n", tmp.hours, tmp.action);
            c1++;
        }
        else{
            fprintf(fc, "%lld %s\n", ds[i-1].hours, ds[i-1].action);
            c1++;
        }
    }
  	fclose(fp);
	fclose(fc);
        
    FILE *fa;

    if(choose == 1){
    	fa = fopen("./monday.txt", "a+");
	}
	
	else if(choose == 2){
    	fa = fopen("./tuesday.txt", "a+");
	}
	
	else if(choose == 3){
    	fa = fopen("./wednesday.txt", "a+");
	}
	
	else if(choose == 4){
    	fa = fopen("./thursday.txt", "a+");
	}
	
	else if(choose == 5){
    	fa = fopen("./friday.txt", "a+");
	}
	
	else if(choose == 6){
    	fa = fopen("./saturday.txt", "a+");
	}
	
	else if(choose == 7){
    	fa = fopen("./sunday.txt", "a+");
	}
        
      	int count = 0;
      	while(fscanf(fa, "%lld %[^\n]\n", &dy[count].hours, dy[count].action) != EOF){
        count++;
    	  }
      
     		if (count > 1){
        	sort(dy, count, chs);
      	}
      
      	else{
        	fclose(fa);
      	}
      
      	fclose(fa);
      
        puts("Would you like to edit again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		edit();
		}
		else if (strcmp(jwb, n) == 0){
			main();
		}
		else{
			puts("Invalid input");
		}

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
    scanf("%d", &choose);
    
    FILE *fp;
    
    if(choose == 1){
    	fp = fopen("./monday.txt", "r");
	}
	else if(choose == 2){
    	fp = fopen("./tuesday.txt", "r");
	}
	
	else if(choose == 3){
    	fp = fopen("./wednesday.txt", "r");
	}
	
	else if(choose == 4){
    	fp = fopen("./thursday.txt", "r");
	}
	
	else if(choose == 5){
    	fp = fopen("./friday.txt", "r");
	}
	
	else if(choose == 6){
    	fp = fopen("./saturday.txt", "r");
	}
	
	else if(choose == 7){
    	fp = fopen("./sunday.txt", "r");
	}
	
  	int c1 = 1;
    int c = 1;
    int lin;
    int counter = 0;
	int count = 0;
	
  	struct Days ds[50];
  	struct Days tmp;
  	
	while(fscanf(fp, "%lld %[^\n]\n", &ds[counter].hours, ds[counter].action) != EOF){
    	printf("%d. %lld %s\n", c, ds[counter].hours, ds[counter].action);
    	counter++;
    	c++;
	}
  
    puts("Which schedule would you like to remove? (Insert schedule number)");
    scanf("%d", &lin);
        
    while(1){
        char cnm[10];
        puts("Are you sure you want to remove? (YES OR NO) (ALL CAPS)");
        scanf("%s", &cnm);
    	int len = strlen(cnm);
		bool ans = (len % 2 == 0);
		
		
    	if (ans == 0){
    		break;
		}
		else if (ans == 1){
			main();
			break;
		}
		else{
			continue;
		}
	}
        
    puts("Here is your new schedule :\n");
    
    FILE *fc;
    
    if(choose == 1){
    	fc = fopen("./monday.txt", "w+");
	}
	else if(choose == 2){
    	fc = fopen("./tuesday.txt", "w+");
	}
	
	else if(choose == 3){
    	fc = fopen("./wednesday.txt", "w+");
	}
	
	else if(choose == 4){
    	fc = fopen("./thursday.txt", "w+");
	}
	
	else if(choose == 5){
    	fc = fopen("./friday.txt", "w+");
	}
	
	else if(choose == 6){
    	fc = fopen("./saturday.txt", "w+");
	}
	
	else if(choose == 7){
    	fc = fopen("./sunday.txt", "w+");
	}

	for (int i = 1; i <= counter; i++){
        if (i == lin){
           continue;
        }
        else{
            fprintf(fc, "%lld %s\n", ds[i-1].hours, ds[i-1].action);
            printf("%d. %lld %s\n", c1, ds[i-1].hours, ds[i-1].action);
            c1++;
        }
        }
      	fclose(fp);
    	fclose(fc);
        
        printf("\n");
        
        puts("Would you like to remove again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		remove();
		}
		else if (strcmp(jwb, n) == 0){
			main();
		}
		else{
			puts("Invalid input");
		}
		
        break;
    }
}

// =============================================
// SCHEDULE SEARCH SYSTEM BASED ON SPECIFIC TIME
// =============================================

void search(){
	long long int num;

	puts("What time would you like to search in the schedule? (ex: 1835 = 6 past 35 PM)");
	scanf("%lld", &num);
	
	int choose;
	week();
    printf("Which day would you like to choose? (Number)\n");
    scanf("%d", &choose);
    
    FILE *fp;
    
    if(choose == 1){
    	fp = fopen("./monday.txt", "r");
	}
	else if(choose == 2){
    	fp = fopen("./tuesday.txt", "r");
	}
	
	else if(choose == 3){
    	fp = fopen("./wednesday.txt", "r");
	}
	
	else if(choose == 4){
    	fp = fopen("./thursday.txt", "r");
	}
	
	else if(choose == 5){
    	fp = fopen("./friday.txt", "r");
	}
	
	else if(choose == 6){
    	fp = fopen("./saturday.txt", "r");
	}
	
	else if(choose == 7){
    	fp = fopen("./sunday.txt", "r");
	}
    
    int c = 1;
    int counter = 0;
    struct Days ds[50];
    
    while(fscanf(fp, "%lld %[^\n]\n", &ds[counter].hours, ds[counter].action) != EOF){
    	counter++;
    	c++;
	}
	
	binary(ds, c, num);
    
    int idx = binary(ds, c, num);
    
    if (binary(ds, c, num) == -1){
    	puts("No schedule at this time in this day\n");
    	puts("Would you like to search again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		search();
		}
		else if (strcmp(jwb, n) == 0){
			main();
		}
		else{
			puts("Invalid input");
		}
	}
	
	else{
	    puts("Here is the schedule:");
	    printf("%s\n", ds[idx].action);
    	puts("Would you like to search again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		search();
		}
		else if (strcmp(jwb, n) == 0){
			main();
		}
		else{
			puts("Invalid input");
		}
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
		
		if (target < ds[mid].hours){
			max = mid - 1;
		}
		else if (target > ds[mid].hours){
			min = mid + 1;
		}
		else{
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
	
	if (ch == 1){
		fm = fopen("monday.txt", "r");
	}
	else if (ch == 2){
		fm = fopen("tuesday.txt", "r");
	}
	else if (ch == 3){
		fm = fopen("wednesday.txt", "r");
	}
	else if (ch == 4){
		fm = fopen("thursday.txt", "r");
	}
	else if (ch == 5){
		fm = fopen("friday.txt", "r");
	}
	else if (ch == 6){
		fm = fopen("saturday.txt", "r");
	}
	else if (ch == 7){
		fm = fopen("sunday.txt", "r");
	}
	
	int count = 0;
	
	while(fscanf(fm, "%d %[^\n]\n", &dy[count].hours, dy[count].action) != EOF){
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
        	//printf("arrL %d\n", arrL[idxL].age);
            dy[idx] = arrL[idxL];
            //printf("swa %d\n", swa[idx].age);
            idx++;
            idxL++;
        }
        else{
        	//printf("arrR %d\n", arrR[idxR].age);
            dy[idx] = arrR[idxR];
            //printf("swa %d\n", swa[idx].age);
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
    
	if (ch == 1){
		fs = fopen("monday.txt", "w+");
	}
	else if (ch == 2){
		fs = fopen("tuesday.txt", "w+");
	}
	else if (ch == 3){
		fs = fopen("wednesday.txt", "w+");
	}
	else if (ch == 4){
		fs = fopen("thursday.txt", "w+");
	}
	else if (ch == 5){
		fs = fopen("friday.txt", "w+");
	}
	else if (ch == 6){
		fs = fopen("saturday.txt", "w+");
	}
	else if (ch == 7){
		fs = fopen("sunday.txt", "w+");
	}
	
	for (int k = 0; k < count; k++){
		//printf("%d\n", swa[k]);
		fprintf(fs, "%d %s\n", dy[k].hours, dy[k].action);
	}
	fclose(fs);
	fclose(fm);
	
}
