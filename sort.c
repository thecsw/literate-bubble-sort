#define DELAY 0 \

/*3:*/
#line 40 "sort.w"

/*4:*/
#line 51 "sort.w"

#include <ncurses.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <time.h> 

/*:4*/
#line 41 "sort.w"

/*6:*/
#line 69 "sort.w"

char*ch= "@";
char*space= " ";
int MAX_X;
int MAX_Y;

/*:6*/
#line 42 "sort.w"

/*13:*/
#line 169 "sort.w"

void init_arr(arr,size,max_value)
int*arr;
int size;
int max_value;
{
for(size_t i= 0;i<size;i++)
arr[i]= max_value*i/size;
}

/*:13*//*14:*/
#line 183 "sort.w"

void shuffle(arr,size)
int*arr;
int size;
{
srand(time(NULL));
for(size_t i= 0;i<size;i++){
int j= rand()%size;
/*15:*/
#line 199 "sort.w"

int temp= arr[i];
arr[i]= arr[j];
arr[j]= temp;

/*:15*/
#line 191 "sort.w"
;
}
}

/*:14*//*16:*/
#line 208 "sort.w"

void print_array(arr,size,y,wacky)
int*arr;
int size;
int y;
char wacky;
{
if(wacky){
/*17:*/
#line 228 "sort.w"

attron(A_BLINK);
attron(A_BOLD);

/*:17*/
#line 216 "sort.w"
;
}
for(size_t i= 0;i<size;i++)
for(int j= 0;j<arr[i];j++)
mvprintw(y-j,i,ch);
/*18:*/
#line 234 "sort.w"

attroff(A_BLINK);
attroff(A_BOLD);

/*:18*/
#line 221 "sort.w"
;
refresh();
}

/*:16*//*19:*/
#line 242 "sort.w"

void clear_x(y,x)
int y;
int x;
{
for(int i= 0;i<y;i++)
mvprintw(i,x,space);
}

/*:19*//*20:*/
#line 265 "sort.w"

void update_screen(y,ind1,ind2,val1,val2,swaps,comps)
int y;
int ind1;
int ind2;
int val1;
int val2;
int swaps;
int comps;
{
usleep(100*DELAY);

clear_x(y,ind1);
clear_x(y,ind2);

mvprintw(1,1,"Swaps: %d",swaps);
mvprintw(2,1,"Comparisons: %d",comps);

for(int i= 0;i<val1;i++)
mvprintw(y-i,ind1,ch);

attron(A_BOLD);
for(int i= 0;i<val2;i++)
mvprintw(y-i,ind2,ch);
attroff(A_BOLD);
refresh();
}

/*:20*/
#line 43 "sort.w"

/*22:*/
#line 305 "sort.w"

void bubble_sort(arr,size)
int*arr;
size_t size;
{
int swaps= 0,comps= 0;
for(size_t i= 0;i<size-1;i++)
for(size_t j= 0;j<size-i-1;j++){
if(arr[j]> arr[j+1]){
/*23:*/
#line 327 "sort.w"

int temp= arr[j];
arr[j]= arr[j+1];
arr[j+1]= temp;

/*:23*/
#line 314 "sort.w"
;
swaps++;
}
comps++;
update_screen(MAX_Y,j,j+1,arr[j],arr[j+1],
swaps,comps);
}
}

/*:22*/
#line 44 "sort.w"

/*7:*/
#line 77 "sort.w"

int main(void)
{
/*8:*/
#line 93 "sort.w"

initscr();
curs_set(0);
keypad(stdscr,TRUE);
noecho();
cbreak();
getmaxyx(stdscr,MAX_Y,MAX_X);


/*:8*/
#line 80 "sort.w"
;
/*9:*/
#line 109 "sort.w"

int arr_size= MAX_X;
int*arr= (int*)malloc(sizeof(int)*arr_size);
init_arr(arr,arr_size,MAX_Y);
shuffle(arr,arr_size);

/*:9*/
#line 81 "sort.w"
;
/*10:*/
#line 132 "sort.w"

print_array(arr,arr_size,MAX_Y,0);
clock_t start= clock();
bubble_sort(arr,arr_size);
clock_t end= clock();
print_array(arr,arr_size,MAX_Y,1);
double exec_time= ((double)(end-start)/CLOCKS_PER_SEC);

/*:10*/
#line 82 "sort.w"
;
/*11:*/
#line 150 "sort.w"

mvprintw(4,1,"Sorting algorithm:            Bubble Sort");
mvprintw(5,1,"Number of array elements:     %d",arr_size);
mvprintw(6,1,"Time taken to sort the array: %f",exec_time);
mvprintw(8,1,"Written by Sandy Urazayev");

/*:11*/
#line 83 "sort.w"
;
/*12:*/
#line 161 "sort.w"

free(arr);
getch();
endwin();

/*:12*/
#line 84 "sort.w"
;
return OK;
}

/*:7*/
#line 45 "sort.w"


/*:3*/
