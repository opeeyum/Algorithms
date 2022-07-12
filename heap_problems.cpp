// When we need to keep our data structure ordered, while fetching and adding elements to it.
// Heap is best to use

// Questions on heap:
// 1. Kth Smallest Element. - Done
// 2. K Larget Elements in array. - Done
// 3. Sort a K sorted Array | Sort Nearly Sorted array. - Done
// 4. K Closest numbers to given number. - Done
// 5. Top K Frequent Numbers.
// 6. Frequency Sort.
// 7. K Closest Points to Origin.
// 8. Connect Ropes to minimise the cost.
// 9. Sum of Elements between K1 smallest and K2 smallest numbers.

// Problem statement:
//      For a given array find Kth smallest element from the array.
// Algorithm:
//      1. Since we need smallest element, we create a max heap -> large number should get popped off;
//      2. Start iterating over given array, and push each element to the max heap;
//      3. Size of heap will be resitricted to k;
//      4. As size reaches k+1, pop the element;
//      5. After iteration is over, element at the top of the heap will be the answer;

// Problem statement:
//      For a given array find K larget element.
// Algorithm:
//      1. Since largest elements are needed create min heap -> small elements should get popped off;
//      2. Start iterating over given array, and push each element to the min heap;
//      3. Size of heap will be resitricted to k;
//      4. As size reaches k+1, pop the element;
//      5. After iteration is over, elements inside the heap will be the answer;

// Problem statement:
//      Sort a given array, where each element is at abs(k) difference from its actual index.
// Algorithm:
//      1. Since need to sort the array hence create min heap;
//      2. Start iterating over given array, and push each element to the min heap;
//      3. Size of heap will be resitricted to k;
//      4. As size reaches k+1, replace the element at [i-k] th index with element top of the heap and pop the element;
//      5. After iteration is over, replace all the elements form [n-1-k] to [n-1] th index in array with elements in the heap;

// Problem statement:
//      For a given array and a target, find K elements closest to the target.
//      Closest meaning abs difference between element and target is minimum.
// Algorithm:
//      1. Since difference needs to be minimum hence create min heap,
//         in this case element of heap will be pair, pair.first = abs(difference), pair.second = element itself;
//      2. Start iterating over given array, and push abs difference and the element to the min heap as pair;
//      3. Size of heap will be resitricted to k;
//      4. As size reaches k+1, pop the element;
//      5. After iteration is over, pair with min abs differnce will be in the heap;

// 8. Problem statement:
//      For a given array having length of ropes find the minimum cost to connect all the ropes.
//      Cost to join each rope is equal to sum of their length.
// Algorithm:
//      1. Since minimum cost needed hence create min heap.
//      2. Start iterating over given array, and push all elements to the min heap;
//      3. Now while heap size is greater than 1,
//         pop two elements, store their sum in a new variable and push that sum into heap again.
//      5. After iteration is over, variable with sum is the answer.