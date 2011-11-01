enum sort_t  { BUBBLE_SORT, INSERTION_SORT, MERGE_SORT, QUICK_SORT, SELECTION_SORT };
enum start_t { ASCENDING_ORDER, DESCENDING_ORDER, RANDOM_ORDER };
enum pivot_t { MEDIAN_OF_THREE_PIVOT, RANDOM_PIVOT, DEFAULT_PIVOT, NO_PIVOT }; //DEFAULT_PIVOT was NO_PIVOT

extern sort_t    classify_sort_arg(const string &in_str);
extern string    sort2string(sort_t sort_val);

extern start_t   classify_start_arg(const string &in_str);
extern string    start2string(start_t start_val);

extern pivot_t   classify_pivot_arg(const string &in_str);
extern string    pivot2string(pivot_t pivot_val);

extern DataType *create_data_set(int sample_size, start_t starting_conditions);

extern int       microsecond_difference(struct timeval *start, struct timeval *stop);

extern int       do_test(int sample_size, start_t starting_conditions, 
                         sort_t sort_selected, pivot_t pivot_selected);

/*
 * swaps two items of the specified type, assuming they have the
 * assignment operator overloaded if they are user-defined types.
 */
extern void swap(DataType& x, DataType& y);

