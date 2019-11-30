#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// program will let the user enter his/her favorite presidents
// user has to input last, first, and first_elected  until EOF.
//In addition the user can get the program to sort either alphabetically or in order of first_elected (smallest to largest)

/**
 * commands:
 * e <lastName> <firstName> <year first_elected>
 * a -- sorts alphabetically 
 * f -- sort according to first elected.
 * p -- print out the list
 * q -- quit
 */ 
struct Box {
  char last[30];
  char first[20];
  int first_elected;
  struct Box *next;
};

typedef struct Box box;

void sortAlpha();
void sortFirstElectedYear();
void print();

box *head = 0;
box *b;

void sortFirstElectedYear() {
  box *sHead = 0;
while (head){
  box *biggest = head;
  for(box *curr = biggest->next; curr != 0; curr = curr->next){
      if(curr->first_elected > biggest->first_elected) {
            biggest = curr;
        }
    }

    box *curr=head;
    box *prev;
    while(curr) {
        if (curr == biggest) {
			break;
		} 
        prev = curr;
        curr = curr->next;
    }
    if (head != biggest) {
      prev->next = biggest->next;
    } else {
      head = biggest->next;
	}
    biggest->next = sHead;
    sHead = biggest;
    }
	head = sHead;
}

void sortAlpha() {
 box *sHead = 0;
while (head){
  box *biggest = head;
  for(box *curr = biggest->next; curr !=0; curr = curr->next){
      if(strcmp(biggest->last,curr->last) <= 0) {
            biggest = curr;
      }
    }

    box *curr = head;
    box *prev;
    while(curr) {
        if (curr == biggest) {
			break;
		} 
        prev = curr;
        curr = curr->next;
    }

    if (head != biggest) {  
      prev->next = biggest->next;
   } else {
      head = biggest->next;
   }
    biggest->next = sHead;
    sHead = biggest;
    }
	head = sHead;
}

void print() {
  box *curr = head;
  while (curr) {
	  printf("%s %s %d\n", curr->last, curr->first, curr->first_elected);
      curr = curr->next;	  
  }
}

//keeps getting characters ignore whitespace
int scan() {
  int c;
  while (c = getchar()) 
    if (c == ' '|| c == '\t' || c == '\n')
      continue;
    else
      break;
  return c;
}

int main() {
  //keep getting commands until q, then we quit
  //handle whitespace
  int c;
  while ((c = scan()) && c != 'q') {
    switch(c) {
      case 'e' :
	printf("Enter lastname firstname first year elected\n");
	box *nb = (box *)malloc(sizeof(box));
	scanf("%s", nb->last);
	scanf("%s", nb->first);
	scanf("%d", &nb->first_elected);
	//put box in linked list
	nb->next = head;
	head = nb;
	break;
      case 'a' :
	printf("sort alphabetically\n");
	sortAlpha();
	break;
      case 'f' :
	printf("sort by elected year (first - last)\n");
	sortFirstElectedYear();
	break;
      case 'p' :
	printf("print list\n");
	print();
	break;
      default:
	printf("Bad command\n");
        break;
    }
  }
}