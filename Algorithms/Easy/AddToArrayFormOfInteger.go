/*
989. Add to Array-Form of Integer

The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
*/

func addToArrayForm(num []int, k int) []int {
    
    tr := 0

    for i := len(num) - 1; i >= 0; i-- {

        if k <= 0 && tr == 0{
            break
        }

        n := k % 10
        k = k / 10

        n += num[i] + tr
        tr = n / 10
        num[i] = n % 10
    }

    for k > 0 || tr > 0 {
        n := tr
        if k > 0 {
            n += k % 10
            k /= 10
        }
        tr = n /10
        n = n%10
        num = append([]int{n}, num...)
    }

    return num
}
