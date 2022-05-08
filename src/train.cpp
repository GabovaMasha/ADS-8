// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCage(bool light) {
if (first && last) {
last->next = create(true);
last->next->prev = last;
last = last->next;
last->next = first;
first->prev = last;
} else {
first = last = create(true);
}}

int Train::getLength() {
Cage *temp = first;
int i = 0;
int ct = 0;
first->light = true;
while (true) {
temp = temp->next;
ct++;
countOp++;
if (temp->light == true) {
temp->light = false;
i = 0;
while (i < ct) {
temp = temp->prev;
countOp++;
i++
}
if (!temp->light) {
return ct;
}
ct = 0;
}
}
return i;
}

int Train::getOpCount() {
return countOp;
}
