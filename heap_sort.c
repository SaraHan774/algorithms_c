//
// Created by sarah on 2/1/2020.
// Optimized heap sort implementation with improved safety and performance
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Optimized swap macro with type safety
#define SWAP(type, x, y) do { \
    type temp_swap_var = (x); \
    (x) = (y); \
    (y) = temp_swap_var; \
} while(0)

// Maximum number of elements to prevent excessive memory allocation
#define MAX_ELEMENTS 1000000

/**
 * Maintains heap property by moving element down the heap
 * @param arr: array to heapify
 * @param parent_idx: starting index (parent)
 * @param heap_size: size of the heap (last valid index)
 */
static void downheap(int arr[], int parent_idx, int heap_size) {
    int parent_value = arr[parent_idx];
    int child_idx;
    
    // Continue until we reach a leaf node
    for (int parent = parent_idx; parent < (heap_size + 1) / 2; parent = child_idx) {
        int left_child = parent * 2 + 1;   // Left child index
        int right_child = left_child + 1;  // Right child index
        
        // Select the larger child (max heap property)
        if (right_child <= heap_size && arr[right_child] > arr[left_child]) {
            child_idx = right_child;
        } else {
            child_idx = left_child;
        }
        
        // If parent value is already larger than largest child, heap property is satisfied
        if (parent_value >= arr[child_idx]) {
            break;
        }
        
        // Move larger child up
        arr[parent] = arr[child_idx];
    }
    
    // Place the original parent value in its correct position
    arr[parent_idx] = parent_value;
}

/**
 * Heap sort algorithm - sorts array in ascending order
 * Time complexity: O(n log n), Space complexity: O(1)
 * @param arr: array to sort
 * @param size: number of elements in array
 */
void heapsort(int arr[], int size) {
    if (arr == NULL || size <= 1) {
        return; // Nothing to sort
    }
    
    // Build max heap from bottom up
    for (int i = (size - 1) / 2; i >= 0; i--) {
        downheap(arr, i, size - 1);
    }
    
    // Extract maximum elements one by one
    for (int i = size - 1; i > 0; i--) {
        SWAP(int, arr[0], arr[i]);  // Move current root to end
        downheap(arr, 0, i - 1);   // Restore heap property for reduced heap
    }
}

/**
 * Safely reads an integer with bounds checking
 * @param prompt: message to display to user
 * @param min_val: minimum allowed value
 * @param max_val: maximum allowed value
 * @return: validated integer input
 */
static int safe_read_int(const char* prompt, int min_val, int max_val) {
    int value;
    int result;
    
    do {
        printf("%s", prompt);
        result = scanf("%d", &value);
        
        // Clear input buffer on invalid input
        if (result != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        if (value < min_val || value > max_val) {
            printf("Value must be between %d and %d.\n", min_val, max_val);
            continue;
        }
        
        break;
    } while (1);
    
    return value;
}

/**
 * Prints array elements in a formatted way
 * @param arr: array to print
 * @param size: number of elements
 * @param label: description label
 */
static void print_array(const int arr[], int size, const char* label) {
    printf("\n%s:\n", label);
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    printf("\n");
}

int main(void) {
    printf("=== Optimized Heap Sort Implementation ===\n\n");
    
    // Get number of elements with validation
    int num_elements = safe_read_int(
        "Enter number of elements (1-1000000): ", 
        1, 
        MAX_ELEMENTS
    );
    
    // Allocate memory with error checking
    int* array = calloc(num_elements, sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for %d elements.\n", num_elements);
        return EXIT_FAILURE;
    }
    
    // Read array elements
    printf("\nEnter %d integers:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        char prompt[50];
        snprintf(prompt, sizeof(prompt), "Element %d: ", i + 1);
        array[i] = safe_read_int(prompt, INT_MIN, INT_MAX);
    }
    
    // Display original array
    print_array(array, num_elements, "Original array");
    
    // Perform heap sort
    printf("Sorting using heap sort algorithm...\n");
    heapsort(array, num_elements);
    
    // Display sorted array
    print_array(array, num_elements, "Sorted array (ascending order)");
    
    // Clean up
    free(array);
    
    printf("Program completed successfully.\n");
    return EXIT_SUCCESS;
}