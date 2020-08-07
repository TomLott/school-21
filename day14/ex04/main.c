#include <stdio.h>

int ft_is_sort(int *tab, int length, int(*f)(int, int));

int the_function(int a, int b)
{
    return (a - b);
}

int f(int lhs, int rhs)
{
    return (lhs - rhs);
}

int ft_sort_two(int fir, int sec)
{
    return (fir - sec);
}

int main()
{
    int arr[4] = {1, 2, 2, 1};
    printf("%d\n", ft_is_sort(arr, 4, &f));
    printf("0 - right answer\n");
    int arr1[3] = {1, 1, 2};
    printf("%d\n", ft_is_sort(arr1, 3, &f));
    printf("1 - right answer\n");
    int arr2[3] = {2, 2, 1};
    printf("%d\n", ft_is_sort(arr2, 3, &f));
    printf("1 - right answer\n");
    int arr3[4] = {1, 2, 3, 4};
    printf("%d\n", ft_is_sort(arr3, 4, &f));
    printf("1 - right answer\n");
    int arr4[4] = {4, 3, 2, 1};
    printf("%d\n", ft_is_sort(arr4, 4, &f));
    printf("1 - right answer\n");
    int arr5[5] = {4, 3, 2, 1, 2};
    printf("%d\n", ft_is_sort(arr5, 5, &f));
    printf("0 - right answer\n");
    int arr6[3] = {1, 2, 2};
    printf("%d\n", ft_is_sort(arr6, 3, &f));
    printf("1 - right answer\n");
    int arr7[5] = {4, 3, 2, 2, 1};
    printf("%d\n", ft_is_sort(arr7, 5, &f));
    printf("1 - right answer\n");
    int arr8[3] = {0, 0, 0};
    printf("%d\n", ft_is_sort(arr8, 3, &f));
    printf("1 - right answer\n");
    int arr9[1] = {0};
    printf("%d\n", ft_is_sort(arr9, 0, &f));
    printf("1 - right answer\n");

    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int b[10] = {9,8,7,6,5,4,3,2,1,0};
    int c[5] = {1,4,6,1,3};
    int d[5] = {1,1,1,1,1};
    int e[5] = {-1, -2, -1, -4, 5};

    printf("answer: 1 | your answer: %d\n", ft_is_sort(a, 10, &ft_sort_two));
    printf("answer: 1 | your answer: %d\n", ft_is_sort(b, 10, &ft_sort_two));
    printf("answer: 0 | your answer: %d\n", ft_is_sort(c, 5, &ft_sort_two));
    printf("answer: 1 | your answer: %d\n", ft_is_sort(d, 5, &ft_sort_two));
    printf("answer: 0 | your answer: %d\n", ft_is_sort(e, 5, &ft_sort_two));

    int tab0[] = {1, 1, 2, 3, 4, 4, 4, 4, 4, 4};
    int tab1[] = {1, 1, 2, 3, 4, 4, 5, 4, 4, 4};
    int tab2[] = {7, 6, 5, 5, 4, 3, 2, 2, 2, -123456789};
    printf("answer: 1 | your answer: %d\n", ft_is_sort(tab0, 10, &ft_sort_two));
    printf("answer: 0 | your answer: %d\n", ft_is_sort(tab1, 10, &ft_sort_two));
    printf("answer: 1 | your answer: %d\n", ft_is_sort(tab2, 10, &ft_sort_two));
    
    int tab3[] = {1, 1, 2, 3, 4, 4, 4, 4, 4, 4};
    int tab4[] = {1, 1, 2, 3, 4, 4, 5, 4, 4, 4};
    int tab5[] = {7, 6, 5, 5, 4, 3, 2, 2, 2, -123456789};
    printf("True result: 1 0 1\n");
    printf("You result: ");
    printf("%d ", ft_is_sort(tab3, 10, the_function));
    printf("%d ", ft_is_sort(tab4, 10, the_function));
    printf("%d", ft_is_sort(tab5, 10, the_function));
}
