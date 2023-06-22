#include "../include/common.h"
#include "pa1.h"


// don't remove these globals
static struct record *record_arr = NULL;
static size_t max_capacity = 0;
static size_t num_records = 0;

// don't modify this function
struct record *get_record_arr()
{
  return record_arr;
}

// don't modify this function
// compare two uids
// return -1 if uid1 < uid2
// return 0 if uid1 == uid2
// return 1 if uid1 > uid2
static int cmp_uid(char *uid1, char *uid2)
{
  int i;

  for (i = 0; i < MAX_LEN; i++) {
    if (uid1[i] > uid2[i]) {
      return 1;
    }
    else if (uid1[i] < uid2[i]) {
      return -1;
    }
  }
  return 0;
}

// don't modify this function
// compare two records when uid is key
// return -1 if record1 < record2
// return 0 if record1 == record2
// return 1 if record1 > record2
static int cmp_record(struct record *r1, struct record *r2)
{
  return cmp_uid(r1->uid, r2->uid);
}

// don't modify this function
static void *allocate_memory(size_t size)
{
  return __mymalloc(size);
}

// don't modify this function
static void free_memory(void *ptr)
{
  __myfree(ptr);
}

// ---------------- Add your code below this line ----------------- //

#define NOT_IMPLEMENTED { printf("%s still needs to be implemented!\n", __func__); abort(); }

// return the total number of records in the
// record_arr
size_t get_num_records()
{
  return num_records;
}

// insert record r at the end of the record array
// if the record array is full, allocate
// a new buffer of double size, copy data
// from old buffer to the new buffer
// delete the old buffer
// make record_arr point to the new buffer
void insert_record(struct record r)
{
  if (record_arr == NULL) {
        record_arr = (struct record*)allocate_memory(32*sizeof(char) +sizeof(int));
        max_capacity++;
        num_records++;
    }
    else if (num_records == max_capacity) {
        struct record* new_head = (struct record*)allocate_memory(2*array.capacity*sizeof(struct record*));
        int i;
        for (i=0; i<max_capacity; i++) {
            new_head[i] = record_arr[i];
            free_memory(record_arr + i);
        }
        new_head[i] = r;
        array.capacity *= 2;
        num_records+= 1; 
        record_arr = new_head;
    }
    else {
        record_arr[num_records] = r;
        num_records +=1;
    }
    return;
}
struct record dummy;
dummy.status = -1;
dummy.name = "0";
dummy.uid = "0";
// return the record corresponding to the uid
// use the linear search algorithm
// you can also use cmp_uid routine defined earlier
// if none of the records contain the input uid
// return a dummy record with status == -1
struct record search_record_linear(char uid[MAX_LEN])
{
  int i = 0;
  while (i<num_records) {
    if (cmp_uid(record_arr[i].uid, uid)==0) {
      return record_arr[i];
    }
    i++;
  }
  return dummy;
}
// return the record corresponding to the uid
// use the binary search algorithm
// you can assume that the record_arr is alaredy sorted
// if none of the records contain the input uid
// return a dummy record with status == -1
int l = 0;
int h = num_records;
int search_binary_location(char uid[MAX_LEN])
{ 
  if (l==h) {
    l =0;
    h = num_records;
    return -1;
  }
  if (cmp_uid(record_arr[(h-l)/2], uid) ==0) {    
    struct record r = record_arr[(h-l)/2];
    h = num_reocrds;
    l =0;
    return (h-1)/2;
  }
  else if (cmp_uid(record_arr[num_records/2], uid) ==-1) {
    l = h/2+1;
    search_record_binary(char uid[MAX_LEN]);
  }
  else {
    h /= 2;
    search_record_binary(char uid[MAX_LEN]);
  }
}    

struct record search_record_binary(char uid[MAX_LEN])
{ 
  if (l==h) {
    l =0;
    h = num_records;
    return dummy;
  }
  if (cmp_uid(record_arr[(h-l)/2], uid) ==0) {    
    struct record r = record_arr[(h-l)/2];
    h = num_reocrds;
    l =0;
    return r;
  }
  else if (cmp_uid(record_arr[num_records/2], uid) ==-1) {
    l = h/2+1;
    search_record_binary(char uid[MAX_LEN]);
  }
  else {
    h /= 2;
    search_record_binary(char uid[MAX_LEN]);
  }
}    
// delete record correspondig to the uid
// if the corresponding record doesn't exist
// return a dummy record with status == -1
// Otherwise, return a copy of the record to the caller

// resize the record array in the following manner
// let's say, x is the size of the array
// and after deletion only x/4 
// space in the array is occupied, in this
// case, allocate an array of size x/2,
// copy records from old array to the new
// array, and delete the old array,
// make record_arr point to the new array

struct record delete_record(char uid[MAX_LEN])
{
  int i = search_binary_location(uid);
  if (i == -1) {
    return dummy;
  }
  struct record r = record_arr[i];
  if (num_records == max_capacity) {
        record_arr[i] = record_arr[num_reocrds-1];
        num_records-=1;
    }
  else if (max_capacity>= 4) {
        record_arr[i] = record_arr[num_records-1];
        num_records -= 1;
        if (num_records = max_capacity/4) {
            struct record* new_head = (struct record*)allocate_memory((max_capacity/2)*sizeof(struct record*));
            int j =0;
            for (j=0; j< max_capacity/4; j++) {
                new_head[j] = record_arr[j];
            }
            for (j=0; j < max_capacity; j++) {
                free_memory(record_arr + j);
            }
            record_arr = new_head;
            max_capacity /= 2;
        }
    }
   return r; 
}

// delete all records in the record_arr
// free record_arr
void delete_all_records()
{
  int i;
  for (i =0; i<max_capacity; i++) {
    free_memory(record_arr + i)
}
int lo = 0;
int hi = num_records -1;
// sort the record array using quick sort
// use cmp_record implementaion to compare two records
void sort_records_quick()
{
  if (lo >= hi) {
    return;
}

// sort the record_arr using merge sort
// use cmp_record implementaion to compare two records
void sort_records_merge()
{
  NOT_IMPLEMENTED;
}

// sort the record_arr using selection sort
// use cmp_record implementaion to compare two records
void sort_records_selection()
{
  NOT_IMPLEMENTED;
}

// return the number of records corresponding to the input name
// use linear search to obtain the results
size_t get_num_records_with_name_linear(char name[MAX_LEN])
{
  NOT_IMPLEMENTED;
}

// implement quick sort algorithm to sort the 
// record_arr using name as key
void rearrange_data()
{
  NOT_IMPLEMENTED;
}

// return the number of records corresponding to the input name
// use binary search to obtain the results
// you can assume that the caller has sorted
// data using name as key before making these queries
size_t get_num_records_with_name_binary(char name[MAX_LEN])
{
  NOT_IMPLEMENTED;
}
