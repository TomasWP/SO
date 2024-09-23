#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "linked-list.h"

namespace base {

   Node* destroy(Node* list)
   {
      return NULL;
   }

   Node* append(Node* list, uint32_t nmec, char *name)
   {
      // Implement this function to append a new student to the end of the list.
      Node* newNode = (Node*)malloc(sizeof(Node));
      if (newNode == NULL) {
         fprintf(stderr, "Memory allocation failed\n");
         exit(EXIT_FAILURE);
      }
      newNode->reg.nmec = nmec;
      newNode->reg.name = name;

      newNode->next = NULL;

      if (list == NULL) {
         // If the list is empty, make the new node the head of the list.
         return newNode;
      }

      // Find the last node and link the new node to it.
      Node* current = list;
      while (current->next != NULL) {
         current = current->next;
      }
      current->next = newNode;

      return list;
   }

   void print(Node* list)
   {
      Node* current = list;
      while (current != NULL) {
            printf("NMEC: %u, Name: %s\n", current->reg.nmec, current->reg.name);
            current = current->next;
      }
   }

   int exists(Node* list, uint32_t nmec)
   {
      return 0;
   }

   Node* remove(Node* list, uint32_t nmec)
   {
      return NULL;
   }

   const char *search(Node* list, uint32_t nmec)
   {
      return NULL;
   }

   Node* sort_by_name(Node* list)
   {
      return NULL;
   }

   Node* sort_by_number(Node* list)
   {
      return NULL;
   }
}
