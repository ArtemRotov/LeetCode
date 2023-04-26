/*
258. Add Digits
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/

func addDigits(num int) int {
    
    for num > 9 {
        s := num
        num = 0
        for s > 0 {
            num += s % 10
            s /= 10
        }
    }

    return num
}
