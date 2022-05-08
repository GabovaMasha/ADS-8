// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCage(bool light) {
if ( !(first && last)) {
first = last = create(true);
} else {
last->next = create(true);
last->next->prev = last;
last = last->next;
last->next = first;
first->prev = last;
}}

int Train::getLength() {
Cage *temp = first;
int i = 0;
first->light = true;
while (temp) {
temp = temp->next;
i++;
countOp++;
if (temp->light == true) {
temp->light = false;
break;
}
}
for (int j = 0; j < i; j++) {
temp = temp->prev;
countOp++;
}
if (!temp->light) {
return i;
}
return getLength();
}

int Train::getOpCount() {
return countOp;
}
