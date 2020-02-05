cmake_minimum_required(VERSION 3.15)
project(algorithms_c C)

set(CMAKE_C_STANDARD 99)

add_executable(algorithms_c main.c bin_search.h search_sen.h)
add_executable(stack m_stack.c stack.h)
add_executable(bin_searh_comp bin_search_comp.h m_bin_search_comp.c)
add_executable(qsort qsort.c)
add_executable(IntStack IntStack.c IntStack.h IntStackMain.c)
add_executable(practiceQuestions 115_Q3.c 115_Q3.h)
add_executable(TwoWayStack TwoWayStack.c TwoWayStack.h TwoWayStackMain.c)
add_executable(IntQueue IntQueue.c IntQueue.h IntQueueMain.c using_qsort_struct.c)
add_executable(4c-1 4c-1.c)
add_executable(recursion recursion.c)
add_executable(recursion_prefix recursion_prefix.c)

add_executable(algorithms sedgewick/Test.c sedgewick/chapter5.h)
add_executable(fibo fibo.c)

add_executable(hanoi hanoi.c)
add_executable(182_Q5 182_Q5.c)

add_executable(sorting bubble_sort_naive.c)
add_executable(bubble_sort_improved_1 bubble_sort_improved_1.c)
add_executable(bubble_sort_improved_2 bubble_sort_improved_2.c)

add_executable(204_Q1 204_Q1.c)
add_executable(204_Q2 204_Q2.c)
add_executable(208_Q6 208_Q6.c)

add_executable(insertion 214_inserton_sort.c)
add_executable(216_Q10 216_Q10.c)

add_executable(shell_sort shell_sort.c testing.c testing.h)
add_executable(223_Q12 223_Q12.c)

add_executable(partition partition.c)
add_executable(quick_sort quick_sort.c)

add_executable(231_Q13 231_Q13.c)
add_executable(quicksort_non_recursive quicksort_non_recursive.c)
add_executable(using_qsort using_qsort.c)

add_executable(using_qsort_struct using_qsort_struct.c)
add_executable(246_Q19 246_Q19.c)
add_executable(246_Q20 246_Q20.c)
add_executable(merge merge.c)
add_executable(merge_sort merge_sort.c)

add_executable(binary dojang.c)
add_executable(minefield minefield.c)
add_executable(merge_ary merge_ary.c)
add_executable(merge_recap merge_recap.c)

add_executable(263_Q22 263_Q22.c)
add_executable(heap_sort heap_sort.c)
add_executable(SimpleHeap concepts/SimpleHeap.c concepts/SimpleHeap.h concepts/HeapMain.c)
add_executable(frequency_sort frequency_sort.c)
add_executable(sort_three_numbers sort_three_numbers.c)


add_executable(IntSet IntSet.c IntSet.h)